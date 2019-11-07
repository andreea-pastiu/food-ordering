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

void chooseFood(int noOfFood, char food[][MAX_FOOD_NAME], int *foodChoice, int *state)
{
    showFoodOptions(noOfFood, food);
    (*foodChoice) = getChoiceIndex(noOfFood, state);
}

void chooseFoodType(int noOfFoodTypes[], char food[][MAX_FOOD_NAME], int foodChoice, char foodTypes[][MAX_FOOD_TYPES_NO][MAX_FOOD_TYPES_NAME], int foodPrices[][MAX_FOOD_TYPES_NO], int *typeChoice, int *state)
{
    showFoodTypesOptions(noOfFoodTypes, food, foodChoice, foodTypes, foodPrices);
    (*typeChoice) = getChoiceIndex(noOfFoodTypes[foodChoice], state);
}

void chooseDrinks(int noOfDrinks, char food[][MAX_FOOD_NAME], int foodChoice, char drinks[][MAX_DRINKS_NAME], int drinksPrices[], int *drinkChoice, int *state)
{
    showDrinksOptions(noOfDrinks, food, foodChoice, drinks, drinksPrices);
    (*drinkChoice) = getChoiceIndex(noOfDrinks, state);
}