#version 330 core
out vec4 FragColor;

in vec3 u_color;
in vec2 u_texCoord;

uniform sampler2D texture0;
uniform sampler2D texture1;

void main()
{
   FragColor = mix(
       texture(texture1, u_texCoord),
       texture(texture1, u_texCoord),
       0.2
   ) * vec4(u_color, 1.);
};
