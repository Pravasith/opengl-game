#pragma once
#include "glad/glad.h"

class Texture {
public:
  Texture(const char *imagePath, GLenum texType);
  ~Texture();

  // Binds a texture
  void Bind();
  // Unbinds a texture
  void Unbind();
  // Deletes a texture
  void Delete();

private:
  void SetGLenum(GLenum texType);
  void SetTexture(const char *path);

  GLenum __texType;
  GLuint __id;
};
