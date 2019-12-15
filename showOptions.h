//
// Created by Andreea on 11/5/2019.
//

#ifndef FOOD_ORDERING_SHOWOPTIONS_H
#define FOOD_ORDERING_SHOWOPTIONS_H

#define MAX_FOOD_NAME 10
#define MAX_FOOD_TYPES_NO 4
#define MAX_FOOD_TYPES_NAME 20
#define MAX_DRINKS_NAME 12

void showFoodOptions(int noOfFood, char** food);
void showFoodTypesOptions(int noOfFoodTypes, char* food, char** foodTypes, double* foodPrices);
void showDrinksOptions(int noOfDrinks, char* food, char** drinks, int* drinksPrices);
void showCutleryOptions(int *cutlery, int *state);

#endif //FOOD_ORDERING_SHOWOPTIONS_H
