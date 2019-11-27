//
// Created by Andreea on 11/5/2019.
//

#ifndef FOOD_ORDERING_CHOICES_H
#define FOOD_ORDERING_CHOICES_H
#define MAX_FOOD_NAME 10
#define MAX_FOOD_TYPES_NO 4
#define MAX_FOOD_TYPES_NAME 20
#define MAX_DRINKS_NAME 12
int getChoiceIndex(int noOfChoices, int *state);
void chooseFood(int noOfFood, char** food, int *foodChoice, int *state);
void chooseFoodType(int* noOfFoodTypes, char** food, int foodChoice, char*** foodTypes, double** foodPrices, int *typeChoice, int *state);
void chooseDrinks(int noOfDrinks, char** food, int foodChoice, char** drinks, int* drinksPrices, int *drinkChoice, int *state);

#endif //FOOD_ORDERING_CHOICES_H
