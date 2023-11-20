#include "../Headers/Texture.h"
#include "../vendor/stb_image/stb_image.cpp"
#include <iostream>

Texture::Texture(const char *imagePath, GLenum texType) {
  SetGLenum(texType);
  SetTexture(imagePath);
}

void Texture::SetGLenum(GLenum texType) { __texType = texType; }

void Texture::SetTexture(const char *path) {
  glGenTextures(1, &__id);

  // activate the texture unit first before binding texture
  glActiveTexture(GL_TEXTURE0);

  Bind();

  // set the texture wrapping/filtering options (on the currently bound
  // texture object)
  glTexParameteri(__texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(__texType, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(__texType, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(__texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  stbi_set_flip_vertically_on_load(true);

  // load and generate the texture
  int width, height, nrChannels;
  unsigned char *data = stbi_load(path, &width, &height, &nrChannels, 0);

  if (data) {
    glTexImage2D(__texType, 0, GL_RGB, width, height, 0, GL_RGB,
                 GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  } else {
    std::cout << "Failed to load texture" << std::endl;
  }

  stbi_image_free(data);
}

void Texture::Bind() { glBindTexture(__texType, __id); }

void Texture::Unbind() { glBindTexture(__texType, 0); }

void Texture::Delete() { glDeleteTextures(1, &__id); }

Texture::~Texture() {}
