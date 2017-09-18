cmake_minimum_required(VERSION 3.8)
project(Examen2Zebra_master)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Evaluador.cpp
        Evaluador.h
        Examen2.cbp
        Libro.cpp
        Libro.h
        LICENSE
        main.cpp
        Makefile
        NodoBinario.cpp
        NodoBinario.h)

add_executable(Examen2Zebra_master ${SOURCE_FILES})