cmake_minimum_required(VERSION 3.22)
project(complicated_shit VERSION 1.0.0)

# specify the C++ standard set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON) set(CMAKE_CXX_EXTENSIONS OFF)

# STATIC stuff (Windows)
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
  set(BUILD_FOR_WIN TRUE)
  # Include the toolchain file for cross-compilation
  include(${CMAKE_TOOLCHAIN_FILE})
endif()
option(STATIC_BUILD "Build a static binary." ${BUILD_FOR_WIN})

if(STATIC_BUILD)
  set(CMAKE_EXE_LINKER_FLAGS "-static")
  set(CMAKE_FIND_LIBRARY_SUFFIXES ".a" CONFIG)
  set(BUILD_SHARED_LIBS OFF)
endif()

set(GLFW_BUILD_DOCS
    OFF
    CACHE BOOL "" FORCE)

set(GLFW_BUILD_TESTS
    OFF
    CACHE BOOL "" FORCE)

set(GLFW_BUILD_EXAMPLES
    OFF
    CACHE BOOL "" FORCE)

add_subdirectory(CopyPaste)
add_subdirectory(Algorithms)
add_subdirectory(DataStructures)
add_subdirectory(Experience)
add_subdirectory(Shaders)

# Include libraries like GLAD
add_subdirectory(vendor)

set(SOURCE_FILES main.cpp)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

if(${BUILD_FOR_WIN})
  target_include_directories(glad PUBLIC ${WINDOWS_BINARIES_DIR}/glad)
endif()

# find_library(glad REQUIRED)
find_package(glm REQUIRED)
# find_package(assimp REQUIRED)

add_executable(complicated_shit ${SOURCE_FILES})

target_link_libraries(CopyPaste PRIVATE glfw)
target_link_libraries(Experience PRIVATE glfw glad glm)
target_link_libraries(Shaders PRIVATE glfw glad)

target_link_libraries(complicated_shit PUBLIC CopyPaste Algorithms
                                              DataStructures Experience Shaders)

# glm assimp
target_link_libraries(complicated_shit PUBLIC glfw glad glm OpenGL::GL)

target_compile_features(complicated_shit PUBLIC cxx_std_17)
