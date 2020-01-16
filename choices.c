//
// Created by Andreea on 11/5/2019.
//

#include <stdio.h>
#include "food.h"
#include "finalOrder.h"
#include "drinks.h"

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

void chooseFood(food f, finalOrder *fo, int *state)
{
    showFoodOptions(f);
    (*fo).foodChoice = getChoiceIndex(f.noOfFood, state);
}

void chooseFoodType(food f, finalOrder *fo, int *state)
{
    showFoodTypesOptions(f, (*fo).foodChoice);
    (*fo).typeChoice = getChoiceIndex(f.noOfFoodTypes[(*fo).foodChoice], state);
}

void chooseDrinks(drinks d, food f, finalOrder *fo, int *state)
{
    showDrinksOptions(d, f.food[(*fo).foodChoice]);
    (*fo).drinkChoice = getChoiceIndex(d.noOfDrinks, state);
}