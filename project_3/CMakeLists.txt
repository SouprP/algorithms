cmake_minimum_required(VERSION 3.25.1)
project(game_project)

add_library(game_lib 
        src/board.cpp
        )
target_include_directories(game_lib PUBLIC include/)

#set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5 COMPONENTS graphics audio network REQUIRED)


add_executable(exec_game
        src/main.cpp)

target_link_libraries(exec_game PUBLIC
        game_lib
        sfml-system
        sfml-window 
        sfml-graphics 
        sfml-audio 
        sfml-network
)

