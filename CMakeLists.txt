cmake_minimum_required(VERSION 3.22)
project(LinkedIn VERSION 1.0.0)

# specify the C++ standard set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON) set(CMAKE_CXX_EXTENSIONS OFF)

set(GLFW_BUILD_DOCS
    OFF
    CACHE BOOL "" FORCE)

set(GLFW_BUILD_TESTS
    OFF
    CACHE BOOL "" FORCE)

set(GLFW_BUILD_EXAMPLES
    OFF
    CACHE BOOL "" FORCE)

# add_subdirectory(/home/pravas/useful_libraries/glfw
# /home/pravas/useful_libraries/glfw/src)

add_subdirectory(Messages)
add_subdirectory(CopyPaste)
add_subdirectory(ResumeContent)
add_subdirectory(Algorithms)
add_subdirectory(vendor)

# find_package(OpenGL REQUIRED)
set(SOURCE_FILES main.cpp)

add_executable(LinkedIn ${SOURCE_FILES})

# Set the path to your GLFW installation set(glfw3_DIR
# /home/pravas/useful_libraries/glfw/build/src)

# Now you can use find_package to locate GLFW3 find_package(glfw REQUIRED)

# find_library(glfw3 libglfw3.a PATHS
# /home/pravas/useful_libraries/glfw/build/src)

# find_library(glfw3 libglfw3.a PATHS Deps/GLFW)

find_package(glfw3 REQUIRED)

target_link_libraries(LinkedIn PUBLIC Messages CopyPaste CraftResume)
target_link_libraries(LinkedIn PUBLIC Algorithms)
target_link_libraries(LinkedIn PUBLIC glad glfw)

# target_include_directories( LinkedIn PUBLIC "${PROJECT_SOURCE_DIR}/Messages"
# /home/pravas/useful_libraries/glfw/src /home/pravas/useful_libraries/glfw)

target_compile_features(LinkedIn PUBLIC cxx_std_17)

set(ENV{DATABASE_PATH} 'Database/')
