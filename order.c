//
// Created by Andreea on 11/5/2019.
//

#include <stdio.h>
#include "user.h"
#include "food.h"
#include "drinks.h"
#include "finalOrder.h"
#define MAX_FOOD_NAME 10
#define MAX_FOOD_TYPES_NO 4
#define MAX_FOOD_TYPES_NAME 20
#define MAX_DRINKS_NAME 12

void printOrder(user u, food f, drinks d, finalOrder *fo, int *state)
{
    showCustomerData(u);
    showFoodChosen(f, (*fo).foodChoice, (*fo).typeChoice);
    showDrinksChosen((*fo).drinkChoice, d);
    showCutleryChosen(fo);
    showAdditionalInfo(fo);
    paymentConfirmation(f.foodPrices[(*fo).foodChoice][(*fo).typeChoice], d.drinksPrices[(*fo).drinkChoice], u.username, fo, state);
}