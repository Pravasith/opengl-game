#pragma once

/* clang-format off */
#include <glad/glad.h>
/* clang-format on */
#include <cmath>

class VertexGroup {
public:
  VertexGroup(GLfloat vertices[]) { CreateNew(vertices); }

  void ClearBuffers() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
  }

  void BindVAO() { glBindVertexArray(VAO); }
  void DrawArrays() { glDrawArrays(GL_TRIANGLES, 0, 3); }

private:
  void CreateNew(GLfloat vertices[]) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), vertices,
                 GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
                          (void *)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
  }

  GLuint VBO, VAO;
};
