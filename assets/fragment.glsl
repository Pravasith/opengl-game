#version 330 core
out vec4 FragColor;

in vec3 color;
in vec2 texCoord;

uniform sampler2D texSampler;

void main()
{
   FragColor = texture(texSampler, texCoord);
};
