cmake_minimum_required(VERSION 3.24)
project(VectoresDinamicosB)

set(CMAKE_CXX_STANDARD 17)

add_executable(VectoresDinamicosB main.cpp  VDinamico.h Aeropuerto.cpp Aeropuerto.h UTM.cpp UTM.h)
