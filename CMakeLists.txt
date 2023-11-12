cmake_minimum_required(VERSION 3.27)
project(lang2test C)

set(CMAKE_C_STANDARD 11)

#add_executable(lang2test
#        WIN32
#        src/lexer.c
#        src/parser.c
#        src/interpreter.c
#        src/compiler.c
#        src/main.c
#        include/lexer.h
#        include/parser.h
#        include/interpreter.h
#        include/compiler.h
#)

add_executable(lang2test
        src/lexer.c
        src/parser.c
        src/interpreter.c
        src/compiler.c
        include/lexer.h
        include/parser.h
        include/interpreter.h
        include/compiler.h
        tests/general.c
)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g")
