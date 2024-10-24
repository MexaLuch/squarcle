cmake_minimum_required(VERSION 3.22)

set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_GENERATOR "MinGW Makefiles")

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

project(Squarcle)

add_library(fnc functions.c)

add_executable(tests tests.c)
add_executable(main main.c)

target_link_libraries(tests PRIVATE fnc)
target_link_libraries(main PRIVATE fnc)

# Добавляем команду для запуска tests.exe после его компиляции
add_custom_command(TARGET tests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "test.exe:"
    COMMAND $<TARGET_FILE:tests>
    COMMENT "Starting tests"
)