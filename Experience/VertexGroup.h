#pragma once

/* clang-format off */
#include <glad/glad.h>
/* clang-format on */
#include <cmath>
#include <iostream>

class VertexGroup {
public:
  VertexGroup(GLfloat vertices[], int size) { CreateNew(vertices, size); }

  void ClearBuffers() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
  }

  void BindVAO() { glBindVertexArray(VAO); }
  void DrawArrays() { glDrawArrays(GL_TRIANGLES, 0, 3); }

private:
  void CreateNew(GLfloat vertices[], int size) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // bind the Vertex Array Object first, then bind and set vertex buffer(s),
    // and then configure vertex attributes(s).
    glBindVertexArray(VAO);
    /* std::cout << sizeof(vertices) << "-" << 2 * sizeof(GLfloat) << std::endl;
     */

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

    // clang-format off
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    // clang-format on
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered
    // VBO as the vertex attribute's bound vertex buffer object so afterwards we
    // can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
  }

  GLuint VBO, VAO;
};
