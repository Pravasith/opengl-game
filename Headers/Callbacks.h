#pragma once

#include "Utilities.h"
#include <GLFW/glfw3.h>
#include <cstdio>

static void glfw_error_callback(int error, const char *description) {
  fprintf(stderr, "Error: %s\n", description);
  write_log(description);
  throw("glfw error");
}

static void glfw_window_close_callback(GLFWwindow *window) {
  write_log("Window Closed");
}

static void glfw_framebuffer_size_callback(GLFWwindow *window, int w, int h) {
  glViewport(0, 0, w, h);
}
