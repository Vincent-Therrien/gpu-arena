#include "glad.h"  // Load OpenGL functions
#include <GLFW/glfw3.h>  // Window management
#include <iostream>
#include <chrono>

// Vertex shader source code. This modifies the position of the vertices.
const char* vertexShaderSource = R"(
    #version 330 core

    layout(location = 0) in vec3 inPos;
    layout(location = 1) in vec4 inColor;

    out vec4 fragColor;

    uniform float angle;

    void main() {
        mat2 rotation = mat2(
            cos(angle), -sin(angle),
            sin(angle),  cos(angle)
        );
        vec2 rotatedPos = rotation * inPos.xz;
        gl_Position = vec4(rotatedPos.x, inPos.y, rotatedPos.y, 1.0);
        fragColor = inColor;
    }
)";

// Fragment (i.e. pixel most of the time) shader source code. This determines the final colors.
const char* fragmentShaderSource = R"(
    #version 330 core

    in vec4 fragColor;
    out vec4 outColor;

    void main() {
        float levels = 10.0;
        vec3 quantizedColor =
            floor(fragColor.rgb * levels)
            / (levels - 1.0);
        outColor = vec4(quantizedColor, 1.0);
    }
)";

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    // Set OpenGL version (3.3 Core Profile)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a window
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL!", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Load OpenGL functions using GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        return -1;
    }

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Vertex Data
    float vertices[] = {
       //  Positions        // Colors
        0.0f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // Top (Red)
       -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // Left (Green)
        0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // Right (Blue)
    };

    // Create a Vertex Buffer Object (VBO) and Vertex Array Object (VAO)
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // Bind the VAO
    glBindVertexArray(VAO);

    // Bind and fill VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Define vertex attributes (location = 0)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Color attribute (location = 1)
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Create and compile Vertex Shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // Create and compile Fragment Shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // Link shaders into a Shader Program
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Cleanup
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Render Loop
    float rotationAngle = 0.0f;
    auto now = std::chrono::steady_clock::now();
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);  // Clear screen

        int angleLocation = glGetUniformLocation(shaderProgram, "angle");
        glUniform1f(angleLocation, rotationAngle);
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);  // Draw triangle

        glfwSwapBuffers(window);
        glfwPollEvents();

        auto end = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - now).count() / 1000.0;
        rotationAngle += duration * 0.5;
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        now = end;
    }

    // Cleanup
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
