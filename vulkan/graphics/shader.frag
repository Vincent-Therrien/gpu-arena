#version 450

layout(location = 0) in vec3 fragColor;
layout(location = 0) out vec4 outColor;

void main() {
    float levels = 10.0; // Number of discrete color levels
    vec3 quantizedColor = floor(fragColor.rgb * levels) / (levels - 1.0);
    outColor = vec4(quantizedColor, 1.0);
}