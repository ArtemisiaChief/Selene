#pragma once

static const char *vertex_shader_source = 
"#version 330 core\n"
"layout (location = 0) in vec2 vertex;\n"
"layout (location = 1) in vec2 offset;\n"
"layout (location = 2) in vec3 color;\n"
"uniform mat4 projectionMatrix;\n"
"uniform mat4 cameraMatrix;\n"
"uniform bool isBorderColor;\n"
"out vec3 fColor;\n"
"void main() {\n"
"   gl_Position = projectionMatrix * cameraMatrix * vec4(vertex + offset, 0.0, 1.0);\n"
"	if (isBorderColor)\n"
"		fColor = vec3(0.0, 0.0, 0.0);\n"
"	else\n"
"		fColor = color / 255;\n"
"}\0";

static const char *fragment_shader_source =
"#version 330 core\n"
"in vec3 fColor;\n"
"out vec4 fragColor;\n"
"void main() {\n"
"	fragColor = vec4(fColor, 1.0f);\n"
"};\0";