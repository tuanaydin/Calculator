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
    donusum1.c
    donusum2.c
    donusum3.c
    istatistik1.c
    istatistik2.c
    istatistik3.c
    exponentfile2.c
    exponentwrapper.c
    exponentfile3.c //eksik var mı kontrol et

    factorfile1.c
    factorfile2.c
    factorfile3.c
)

set(HEADERS
    file1.h
    file2.h
    file3.h
    donusum1.h
    donusum2.h
    donusum3.h
    istatistik1.h
    istatistik2.h
    istatistik3.h
    exponentfile2.h
    exponentfunc1.h
    exponentfile3.h //eksik var mı kontrol et

    factorfile1.h
    factorfile2.h
    factorfile3.h
)

add_executable(hesap_makinesi ${SOURCES} ${HEADERS})
