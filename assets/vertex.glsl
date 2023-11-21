#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 u_color;
out vec2 u_texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    // gl_Position = vec4(aPos, 1.0);
     gl_Position = projection * view * model * vec4(aPos, 1.0);
    u_color = aColor;
    u_texCoord = aTexCoord;
}
