cmake_minimum_required(VERSION 3.22)
project(ANDRA VERSION 1.0.0)

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

add_subdirectory(CopyPaste)
add_subdirectory(Algorithms)
add_subdirectory(DataStructures)
add_subdirectory(Experience)
add_subdirectory(vendor)

# find_package(OpenGL REQUIRED)
set(SOURCE_FILES main.cpp)

add_executable(ANDRA ${SOURCE_FILES})

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

target_link_libraries(ANDRA PUBLIC CopyPaste)
target_link_libraries(ANDRA PUBLIC Algorithms DataStructures)
target_link_libraries(ANDRA PUBLIC Experience)
target_link_libraries(ANDRA PUBLIC glad glfw)
target_link_libraries(ANDRA PUBLIC OpenGL::GL)

target_compile_features(ANDRA PUBLIC cxx_std_17)

# set(ENV{DATABASE_PATH} 'Database/')
