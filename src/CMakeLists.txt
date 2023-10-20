cmake_minimum_required(VERSION 3.5)

project(throneSemaphoreObj LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(throneSemaphoreObj main.cpp Subject.cpp globals.cpp King.cpp King.h globals.h)
