cmake_minimum_required(VERSION 3.10)

project(HesapMakinesi C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

set(SOURCES
    test.c
    wrapper.c
    file1.c
    file2.c
    file3.c
)

set(HEADERS
    file1.h
    file2.h
    file3.h
)

add_executable(hesap_makinesi ${SOURCES} ${HEADERS})
