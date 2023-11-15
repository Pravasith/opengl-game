#pragma once

/* clang-format off */
#include <glad/glad.h>
/* clang-format on */
#include <cmath>
#include <iostream>

class VertexGroup {
public:
  VertexGroup(GLfloat vertexArray[], int vertexArraySize, GLuint elementArray[],
              int elementArraySize) {
    CreateNew(vertexArray, vertexArraySize, elementArray, elementArraySize);
  }

  void ClearBuffers() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
  }

  void BindVAO() { glBindVertexArray(VAO); }
  void DrawArrays() {
    /* glDrawArrays(GL_TRIANGLES, 0, 3);  */
    glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
  }

private:
  void CreateNew(GLfloat vertexArray[], int vertexArraySize,
                 GLuint elementArray[], int elementArraySize) {
    glGenVertexArrays(1, &VAO);

    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    // bind the Vertex Array Object first, then bind and set vertex buffer(s),
    // and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexArraySize, vertexArray, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, elementArraySize, elementArray,
                 GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
                          (void *)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered
    // VBO as the vertex attribute's bound vertex buffer object so afterwards we
    // can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  }

  GLuint VBO, VAO, EBO;
};
