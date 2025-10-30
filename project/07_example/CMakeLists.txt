#TODO 1
cmake_minimum_required(VERSION 3.28.3)

# TODO 2
project(main)

# TODO 3
add_executable(main)

#TODO 4
target_sources(main
    PRIVATE
        ./sources/main.c
)

# TODO 5
add_library(example)

# TODO 6
target_sources(example
    PRIVATE
        ./sources/example.c
    
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            ./headers
        FILES
            ./headers/example.h   
)

# Link library to executable
target_link_libraries(main PRIVATE example)