cmake_minimum_required(VERSION 3.10)
project(PlagiarismDetector)

set(CMAKE_CXX_STANDARD 17)

# Add the include directory
include_directories(include)

# Create executable
add_executable(PlagiarismChecker main.cpp)