#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Compute shader source (performs parallel reduction sum)
const char* computeShaderSource = R"(
#version 310 es

layout(std430, binding = 0) buffer InputBuffer {
    float inputData[];
};

layout(std430, binding = 1) buffer OutputBuffer {
    float outputData[];
};

shared float data[256];

layout(local_size_x = 256) in;

void main() {
    uint index = gl_GlobalInvocationID.x;
    uint stride = gl_NumWorkGroups.x * gl_WorkGroupSize.x;

    data[index] = inputData[index];
    barrier();

    for (uint s = 128u; s != 0u; s >>= 1) {
        if (index < s) {
            //data[index] = float(s);
            data[index] += data[index + s];
        }
        barrier();
    }

    //if (index == 0u) {
        outputData[index] = data[index];
    //}
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

int main() {
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
    for (unsigned int i = 0; i < 256; i++) {
        inputData.push_back(1);
    }
    size_t dataSize = inputData.size() * sizeof(float);

    GLuint inputBuffer, outputBuffer;
    glGenBuffers(1, &inputBuffer);
    glGenBuffers(1, &outputBuffer);

    glBindBuffer(GL_SHADER_STORAGE_BUFFER, inputBuffer);
    glBufferData(GL_SHADER_STORAGE_BUFFER, 256 * sizeof(float), inputData.data(), GL_DYNAMIC_COPY);

    glBindBuffer(GL_SHADER_STORAGE_BUFFER, outputBuffer);
    glBufferData(GL_SHADER_STORAGE_BUFFER, 256 * sizeof(float), nullptr, GL_DYNAMIC_COPY);

    // Create and run compute shader
    GLuint computeProgram = createComputeShader(computeShaderSource);
    glUseProgram(computeProgram);

    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, inputBuffer);
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, outputBuffer);

    glDispatchCompute(inputData.size(), 1, 1); // Dispatch workgroups
    glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT); // Ensure memory sync

    // Retrieve result
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, outputBuffer);
    float* mappedData = (float*)glMapBuffer(GL_SHADER_STORAGE_BUFFER, GL_READ_ONLY);
    std::vector<float> outputData(256, 0.0f);
    if (mappedData) {
        std::copy(mappedData, mappedData + 256, outputData.begin());
        glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);
    }
    for (unsigned int i = 0; i < 256; i++) {
        std::cout << outputData[i] << ", ";
    }

    // Cleanup
    glDeleteProgram(computeProgram);
    glDeleteBuffers(1, &inputBuffer);
    glDeleteBuffers(1, &outputBuffer);
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
