cmake_minimum_required(VERSION 3.16)

project(Laboratorio2Final LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Laboratorio2Final main.cpp
    Problemas1.cpp
    Problemas1.h
    Problemas2.cpp
    Problemas2.h)

include(GNUInstallDirs)
install(TARGETS Laboratorio2Final
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
