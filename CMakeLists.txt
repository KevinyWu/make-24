cmake_minimum_required(VERSION 3.21)
project(24_card_game)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(24_card_game
        card.cpp
        card.h
        deck.cpp
        deck.h
        parser.cpp
        parser.h
        solver.cpp
        solver.h
        play.cpp)
