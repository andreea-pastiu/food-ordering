//
// Created by Andreea on 11/5/2019.
//

#include <stdio.h>

#include <stdio.h>
#define MAX_FOOD_NAME 10
#define MAX_FOOD_TYPES_NO 4
#define MAX_FOOD_TYPES_NAME 20
#define MAX_DRINKS_NAME 12

void showFoodChosen(char foodTypes[][MAX_FOOD_TYPES_NO][MAX_FOOD_TYPES_NAME], int foodChoice, int typeChoice, int foodPrices[][MAX_FOOD_TYPES_NO])
{
    printf("Food items:\n");
    printf("---%s: %d\n", foodTypes[foodChoice][typeChoice], foodPrices[foodChoice][typeChoice]);
}

void showDrinksChosen(int drinkChoice, int noOfDrinks, char drinks[][MAX_DRINKS_NAME], int drinksPrices[])
{
    if(drinkChoice == noOfDrinks - 1)
        printf("No drinks\n");
    else
        printf("---%s: %d\n", drinks[drinkChoice], drinksPrices[drinkChoice]);
}

void showCutleryChosen(int cutlery)
{
    printf("Cutlery: %s\n", cutlery == 0 ? "no" : "yes");
}

void paymentConfirmation(int foodPrices[][MAX_FOOD_TYPES_NO], int foodChoice, int typeChoice, int drinksPrices[], int drinkChoice, char username[], int *orderReady, int *state)
{
    int totalToPay;
    char choice;
    totalToPay = foodPrices[foodChoice][typeChoice] + drinksPrices[drinkChoice];
    printf("Payment amount: %d\n", totalToPay);
    printf("-------------------\na) Confirm order\nb) Go back\n");
    choice = getchar();
    getchar();
    if(choice == 'a'){
        printf("Order confirmed! Thank you for buying from us, %s!\n", username);
        *orderReady = 1;
    }
    else
        *state = (*state) - 2;
}