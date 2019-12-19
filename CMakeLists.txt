cmake_minimum_required(VERSION 3.15)
project(food_ordering C)

set(CMAKE_C_STANDARD 99)

add_executable(food_ordering main.c choices.c choices.h order.c order.h constants.h data.c data.h food.h food.c drinks.h drinks.c user.h user.c finalOrder.h finalOrder.c)