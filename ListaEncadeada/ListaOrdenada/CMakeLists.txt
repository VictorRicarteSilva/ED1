cmake_minimum_required(VERSION 3.24)
project(ListaOrdenada C)

set(CMAKE_C_STANDARD 17)
set(Headers listaOrdenada.h)
add_executable(ListaOrdenada ${PROJECT_SOURCE_DIR}/ main.c listaOrdenada.c)