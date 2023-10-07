cmake_minimum_required(VERSION 3.22)

# specify the C++ standard set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON) set(CMAKE_CXX_EXTENSIONS OFF)

project(LinkedIn VERSION 1.0.0)

add_subdirectory(Messages)

add_executable(LinkedIn main.cpp)

target_link_libraries(LinkedIn PUBLIC Recruiter)

target_include_directories(LinkedIn PUBLIC "${PROJECT_SOURCE_DIR}/Messages")

target_compile_features(LinkedIn PUBLIC cxx_std_17)
