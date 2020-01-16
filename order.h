//
// Created by Andreea on 11/5/2019.
//

#ifndef FOOD_ORDERING_ORDER_H
#define FOOD_ORDERING_ORDER_H

#include <stdio.h>
#include "user.h"
#include "food.h"
#include "drinks.h"
#include "finalOrder.h"
#define MAX_FOOD_NAME 10
#define MAX_FOOD_TYPES_NO 4
#define MAX_FOOD_TYPES_NAME 20
#define MAX_DRINKS_NAME 12

void printOrder(user u, food f, drinks d, finalOrder *fo, int *state);

#endif //FOOD_ORDERING_ORDER_H
