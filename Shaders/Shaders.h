// clang-format off
#include <glad/glad.h>
// clang-format on
#include "../Headers/Utilities.h"
#include <string>

class Shaders {
public:
  Shaders() {}

private:
  void init() {
    gladLoadGL();

    /* Load Vertex Shader */
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    std::string vertexShaderSrc = load_shader("./vertex.glsl");

    const GLchar *vertexShaderSource = vertexShaderSrc.c_str();
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    /* Load Fragment Shader */
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    std::string fragmentShaderSrc = load_shader("./fragment.glsl");

    const GLchar *fragmentShaderSource = fragmentShaderSrc.c_str();
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
  }
};
