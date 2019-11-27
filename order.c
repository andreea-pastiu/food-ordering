//
// Created by Andreea on 11/5/2019.
//

#include <stdio.h>
#include "customer.h"
#include "additionalInfo.h"
#define MAX_FOOD_NAME 10
#define MAX_FOOD_TYPES_NO 4
#define MAX_FOOD_TYPES_NAME 20
#define MAX_DRINKS_NAME 12

void showFoodChosen(char* foodTypes, double foodPrices)
{
    printf("Food items:\n");
    printf("---%s: %.2lf\n", foodTypes, foodPrices);
}

void showDrinksChosen(int drinkChoice, int noOfDrinks, char* drinks, int drinksPrices)
{
    if(drinkChoice == noOfDrinks - 1)
        printf("No drinks\n");
    else
        printf("---%s: %d\n", drinks, drinksPrices);
}

void showCutleryChosen(int cutlery)
{
    printf("Cutlery: %s\n", cutlery == 0 ? "no" : "yes");
}

void paymentConfirmation(double foodPrices, int drinksPrices, char username[], int *orderReady, int *state)
{
    double totalToPay;
    char choice;
    totalToPay = foodPrices + drinksPrices;
    printf("Payment amount: %.2lf\n", totalToPay);
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

void printOrder(char username[], char*** foodTypes, int foodChoice, int typeChoice, double** foodPrices, int drinkChoice, int noOfDrinks, char** drinks, int* drinksPrices, int cutlery, char* additionalInfo, int *orderReady, int *state)
{
    showCustomerData(username);
    showFoodChosen(foodTypes[foodChoice][typeChoice], foodPrices[foodChoice][typeChoice]);
    showDrinksChosen(drinkChoice, noOfDrinks, drinks[drinkChoice], drinksPrices[drinkChoice]);
    showCutleryChosen(cutlery);
    showAdditionalInfo(additionalInfo);
    paymentConfirmation(foodPrices[foodChoice][typeChoice], drinksPrices[drinkChoice], username, orderReady, state);
}