#pragma once

/* clang-format off */
#include <glad/glad.h>
/* clang-format on */

// Abstract class
class VertexBuffer {
public:
  /* VertexBuffer(GLfloat *bufferArray, GLsizeiptr size); */
  /* VertexBuffer(); */

  GLuint GetBufferObjectID() { return __id; }

  virtual void Bind() = 0;
  virtual void Unbind() = 0;
  virtual void Delete() = 0;

  /* protected: */
  GLuint __id = 0;
};

/* VBO class
 *  ------------------------------------------------------------------------
 */
class VBO : public VertexBuffer {
public:
  VBO(GLfloat *bufferArray, GLsizeiptr size);

  void Bind() override;
  void Unbind() override;
  void Delete() override;
};

/* VAO class
 *  ------------------------------------------------------------------------
 */
class VAO : public VertexBuffer {
public:
  VAO();

  void Bind() override;
  void Unbind() override;
  void Delete() override;

  virtual void LinkAttrib(VBO &VBO, GLuint layout, GLuint numComponents,
                          GLenum type, GLsizeiptr stride, void *offset);
};

/* EBO class
 *  ------------------------------------------------------------------------
 */
class EBO : public VertexBuffer {
public:
  EBO(GLuint *bufferArray, GLsizeiptr size);

  void Bind() override;
  void Unbind() override;
  void Delete() override;
};
