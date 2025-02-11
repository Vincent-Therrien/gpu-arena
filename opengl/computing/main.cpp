#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Compute shader source (performs parallel reduction sum)
const char* computeShaderSource = R"(
#version 430 core
layout(local_size_x = 256) in;  // Workgroup size

layout(std430, binding = 0) buffer Data {
    float data[];
};

void main() {
    uint index = gl_GlobalInvocationID.x;
    uint stride = gl_NumWorkGroups.x * gl_WorkGroupSize.x;

    // Parallel reduction: sum every element in stride
    for (uint s = stride / 2; s > 0; s >>= 1) {
        if (index < s) {
            data[index] += data[index + s];
        }
        barrier();  // Synchronize threads
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
    std::vector<float> input = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
    size_t dataSize = input.size() * sizeof(float);

    // Create SSBO
    GLuint ssbo;
    glGenBuffers(1, &ssbo);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, ssbo);
    glBufferData(GL_SHADER_STORAGE_BUFFER, dataSize, input.data(), GL_DYNAMIC_COPY);
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, ssbo);

    // Create and run compute shader
    GLuint computeProgram = createComputeShader(computeShaderSource);
    glUseProgram(computeProgram);
    glDispatchCompute(input.size() / 256 + 1, 1, 1); // Dispatch workgroups
    glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT); // Ensure memory sync

    // Retrieve result
    float* result = (float*)glMapBuffer(GL_SHADER_STORAGE_BUFFER, GL_READ_ONLY);
    std::cout << "Sum: " << result[0] << std::endl;
    glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);

    // Cleanup
    glDeleteProgram(computeProgram);
    glDeleteBuffers(1, &ssbo);
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
