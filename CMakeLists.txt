cmake_minimum_required(VERSION 3.27)
project(lang2test C)

set(CMAKE_C_STANDARD 11)

add_executable(lang2test main.c
        src/lexer.c
        src/parser.c
        src/interpreter.c
        src/compiler.c
        src/main.c
        include/lexer.h
        include/parser.h
        include/interpreter.h
        include/compiler.h
        tests/lexer_test.c
        tests/parser_test.c
        tests/interpreter_test.c
        tests/compiler_test.c
)
