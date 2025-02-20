#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <chrono>

#define ARRAY_SIZE 10240000

// Compute shader source (performs parallel reduction sum)
const char* computeShaderSource = R"(
#version 310 es
#define ARRAY_SIZE 1024
#define HALF_ARRAY_SIZE 512u

layout(std430, binding = 0) buffer InputBuffer {
    float inputData[];
};

layout(std430, binding = 1) buffer OutputBuffer {
    float outputData[];
};

shared float groupData[ARRAY_SIZE];

layout(local_size_x = ARRAY_SIZE) in;

void main() {
    uint index = gl_GlobalInvocationID.x;
    uint local_index = gl_LocalInvocationID.x;
    uint groupID = gl_WorkGroupID.x;

    groupData[local_index] = inputData[index];
    barrier();

    for (uint s = HALF_ARRAY_SIZE; s != 0u; s >>= 1) {
        if (local_index < s) {
            groupData[local_index] += groupData[local_index + s];
        }
        barrier();
    }

    if (local_index == 0u) {
        outputData[groupID] = groupData[0];
    }
}
)";

GLuint createComputeShader(const char* source) {
    GLuint shader = glCreateShader(GL_COMPUTE_SHADER);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    // Check for errors
    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char log[512];
        glGetShaderInfoLog(shader, 512, nullptr, log);
        std::cerr << "Compute Shader Compilation Error:\n" << log << std::endl;
    }

    GLuint program = glCreateProgram();
    glAttachShader(program, shader);
    glLinkProgram(program);

    glDeleteShader(shader);
    return program;
}

void peek_buffer()
{
    float* mappedData = (float*)glMapBuffer(GL_SHADER_STORAGE_BUFFER, GL_READ_ONLY);
    std::vector<float> outputData(16, 0.0f);
    if (mappedData) {
        std::copy(mappedData, mappedData + 16, outputData.begin());
        glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);
    }
    for (unsigned int i = 0; i < 16; i++) {
        std::cout << i << "    " << outputData[i] << std::endl;
    }
}

int main()
{
    // Initialize GLFW (no window needed)
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE); // Hide window
    GLFWwindow* window = glfwCreateWindow(100, 100, "Compute Shader", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW\n";
        return -1;
    }

    // Input data
    std::vector<float> inputData;
    for (unsigned int i = 0; i < ARRAY_SIZE; i++) {
        inputData.push_back(1);
    }
    size_t dataSize = inputData.size() * sizeof(float);

    GLuint inputBuffer, outputBuffer;
    glGenBuffers(1, &inputBuffer);
    glGenBuffers(1, &outputBuffer);

    glBindBuffer(GL_SHADER_STORAGE_BUFFER, inputBuffer);
    glBufferData(GL_SHADER_STORAGE_BUFFER, dataSize, inputData.data(), GL_DYNAMIC_COPY);

    glBindBuffer(GL_SHADER_STORAGE_BUFFER, outputBuffer);
    glBufferData(GL_SHADER_STORAGE_BUFFER, dataSize / 1024, nullptr, GL_DYNAMIC_COPY);

    // Create and run compute shader
    GLuint computeProgram = createComputeShader(computeShaderSource);
    glUseProgram(computeProgram);

    auto begin = std::chrono::steady_clock::now();
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, inputBuffer);
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, outputBuffer);

    int numWorkgroups = ARRAY_SIZE / 1024;
    numWorkgroups = numWorkgroups ? numWorkgroups : 1;

    glUseProgram(computeProgram);
    glDispatchCompute(numWorkgroups, 1, 1);
    glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);

    // Retrieve result
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, outputBuffer);
    auto end = std::chrono::steady_clock::now();
    float* mappedData = (float*)glMapBuffer(GL_SHADER_STORAGE_BUFFER, GL_READ_ONLY);
    float total = 0;
    for (unsigned int i = 0; i < numWorkgroups; i++) {
        total += mappedData[i];
    }
    glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);

    double duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000.0;

    std::cout << "Result: " << total << std::endl;
    std::cout << "Duration (s): " << duration << std::endl;

    // Cleanup
    glDeleteProgram(computeProgram);
    glDeleteBuffers(1, &inputBuffer);
    glDeleteBuffers(1, &outputBuffer);
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
