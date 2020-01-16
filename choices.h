//
// Created by Andreea on 11/5/2019.
//

#ifndef FOOD_ORDERING_CHOICES_H
#define FOOD_ORDERING_CHOICES_H
#define MAX_FOOD_NAME 10
#define MAX_FOOD_TYPES_NO 4
#define MAX_FOOD_TYPES_NAME 20
#define MAX_DRINKS_NAME 12

#include "food.h"
#include "finalOrder.h"
#include "drinks.h"

int getChoiceIndex(int noOfChoices, int *state);
void chooseFood(food f, finalOrder *fo, int *state);
void chooseFoodType(food f, finalOrder *fo, int *state);
void chooseDrinks(drinks d, food f, finalOrder *fo, int *state);

#endif //FOOD_ORDERING_CHOICES_H
