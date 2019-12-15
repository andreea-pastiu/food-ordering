//
// Created by Andreea on 11/5/2019.
//

#include <stdio.h>
#include "showOptions.h"

int getChoiceIndex(int noOfChoices, int *state)
{
    int choiceIndex;
    char choice;
    choice = getchar();
    getchar();
    if(choice == 'a'+noOfChoices) {
        (*state)--;
    }
    else
    {
        choiceIndex = choice - 'a';
        (*state)++;
    }
    return choiceIndex;
}

void chooseFood(int noOfFood, char** food, int *foodChoice, int *state)
{
    showFoodOptions(noOfFood, food);
    (*foodChoice) = getChoiceIndex(noOfFood, state);
}

void chooseFoodType(int* noOfFoodTypes, char** food, int foodChoice, char*** foodTypes, double** foodPrices, int *typeChoice, int *state)
{
    showFoodTypesOptions(noOfFoodTypes[foodChoice], food[foodChoice], foodTypes[foodChoice], foodPrices[foodChoice]);
    (*typeChoice) = getChoiceIndex(noOfFoodTypes[foodChoice], state);
}

void chooseDrinks(int noOfDrinks, char** food, int foodChoice, char** drinks, int* drinksPrices, int *drinkChoice, int *state)
{
    showDrinksOptions(noOfDrinks, food[foodChoice], drinks, drinksPrices);
    (*drinkChoice) = getChoiceIndex(noOfDrinks, state);
}