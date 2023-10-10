cmake_minimum_required(VERSION 3.26)
project(Lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab1 main.cpp
        Person.cpp
        Person.h
        Teacher.cpp
        Teacher.h
        Student.cpp
        Student.h)
