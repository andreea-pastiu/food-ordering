//
// Created by Andreea on 11/5/2019.
//

#ifndef FOOD_ORDERING_SHOWOPTIONS_H
#define FOOD_ORDERING_SHOWOPTIONS_H

#define MAX_FOOD_NAME 10
#define MAX_FOOD_TYPES_NO 4
#define MAX_FOOD_TYPES_NAME 20
#define MAX_DRINKS_NAME 12

void showFoodOptions(int noOfFood, char food[][MAX_FOOD_NAME]);
void showFoodTypesOptions(int noOfFoodTypes[], char food[][MAX_FOOD_NAME], int foodChoice, char foodTypes[][MAX_FOOD_TYPES_NO][MAX_FOOD_TYPES_NAME], int foodPrices[][MAX_FOOD_TYPES_NO]);
void showDrinksOptions(int noOfDrinks, char food[][MAX_FOOD_NAME], int foodChoice, char drinks[][MAX_DRINKS_NAME], int drinksPrices[]);
void showCutleryOptions(int *cutlery, int *state);

#endif //FOOD_ORDERING_SHOWOPTIONS_H
