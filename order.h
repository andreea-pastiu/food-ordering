//
// Created by Andreea on 11/5/2019.
//

#ifndef FOOD_ORDERING_ORDER_H
#define FOOD_ORDERING_ORDER_H

#include <stdio.h>
#define MAX_FOOD_NAME 10
#define MAX_FOOD_TYPES_NO 4
#define MAX_FOOD_TYPES_NAME 20
#define MAX_DRINKS_NAME 12

void showFoodChosen(char* foodTypes, double foodPrices);
void showDrinksChosen(int drinkChoice, int noOfDrinks, char* drinks, int drinksPrices);
void showCutleryChosen(int cutlery);
void showAdditionalInfo(char additionalInfo[]);
void paymentConfirmation(double foodPrices, int drinksPrices, char username[], int *orderReady, int *state);
void printOrder(char username[], char*** foodTypes, int foodChoice, int typeChoice, double** foodPrices, int drinkChoice, int noOfDrinks, char** drinks, int* drinksPrices, int cutlery, char* additionalInfo, int *orderReady, int *state);

#endif //FOOD_ORDERING_ORDER_H
