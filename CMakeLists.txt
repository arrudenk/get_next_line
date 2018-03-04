cmake_minimum_required(VERSION 3.8)
project(get_next_line)

set(CMAKE_C_STANDARD 99)

# You need to download and compile the Libft specificly for you machine
# put header file and .a file in "Libft" folder in your project
link_directories(${PROJECT_SOURCE_DIR}/libft)
include_directories(${PROJECT_SOURCE_DIR}/libft)

set(SOURCE_FILES get_next_line.c
        get_next_line.h src/main.c)

add_executable(get_next_line ${SOURCE_FILES})
target_link_libraries(get_next_line -lft)
