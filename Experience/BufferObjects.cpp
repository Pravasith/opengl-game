
#include "../Headers/BufferObjects.h"

/* VBO class
 *  ------------------------------------------------------------------------
 */
// Constructor that generates a Vertex Buffer Object and links it to vertices
VBO::VBO(GLfloat *vertices, GLsizeiptr size) {
  glGenBuffers(1, &__id);
  glBindBuffer(GL_ARRAY_BUFFER, __id);
  glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

// Binds the VBO
void VBO::Bind() { glBindBuffer(GL_ARRAY_BUFFER, __id); }

// Unbinds the VBO
void VBO::Unbind() { glBindBuffer(GL_ARRAY_BUFFER, 0); }

// Deletes the VBO
void VBO::Delete() { glDeleteBuffers(1, &__id); }

/* VAO class
 *  ------------------------------------------------------------------------
 */

// Constructor that generates a VAO ID
VAO::VAO() { glGenVertexArrays(1, &__id); }

// Links a VBO Attribute such as a position or color to the VAO
void VAO::LinkAttrib(VBO &VBO, GLuint layout, GLuint numComponents, GLenum type,
                     GLsizeiptr stride, void *offset) {
  VBO.Bind();
  glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
  glEnableVertexAttribArray(layout);
  VBO.Unbind();
}

// Binds the VAO
void VAO::Bind() { glBindVertexArray(__id); }

// Unbinds the VAO
void VAO::Unbind() { glBindVertexArray(0); }

// Deletes the VAO
void VAO::Delete() { glDeleteVertexArrays(1, &__id); }

/* EBO class
 *  ------------------------------------------------------------------------
 */
// Constructor that generates a Elements Buffer Object and links it to indices
EBO::EBO(GLuint *indices, GLsizeiptr size) {
  glGenBuffers(1, &__id);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, __id);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

// Binds the EBO
void EBO::Bind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, __id); }

// Unbinds the EBO
void EBO::Unbind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

// Deletes the EBO
void EBO::Delete() { glDeleteBuffers(1, &__id); }
