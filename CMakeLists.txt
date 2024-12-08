cmake_minimum_required(VERSION 3.0)

PROJECT(cpp-training VERSION 0.1.0)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "-Wno-deprecated-declarations -Wall -Werror -Wnon-virtual-dtor -Woverloaded-virtual")
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)


ENABLE_TESTING()
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(tests)
