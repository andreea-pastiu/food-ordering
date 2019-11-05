//
// Created by Andreea on 11/5/2019.
//

#include <stdio.h>
#define MAX_FOOD_NAME 10
#define MAX_FOOD_TYPES_NO 4
#define MAX_FOOD_TYPES_NAME 20
#define MAX_DRINKS_NAME 12

void showFoodOptions(int noOfFood, char food[][MAX_FOOD_NAME])
{
    printf("Please choose the food you feel like eating today:\n");
    for(int i=0;i<noOfFood;i++) {
        putchar('a'+i);
        printf(") %s\n",food[i]);
    }
    printf("%c) Go back\n",'a'+noOfFood);
}

void showFoodTypesOptions(int noOfFoodTypes[], char food[][MAX_FOOD_NAME], int foodChoice, char foodTypes[][MAX_FOOD_TYPES_NO][MAX_FOOD_TYPES_NAME], char foodPrices[][MAX_FOOD_TYPES_NO])
{
    printf("Please choose the type of %s\n", food[foodChoice]);
    for(int i=0;i<noOfFoodTypes[foodChoice];i++) {
        putchar('a'+i);
        printf(") %s (%d)\n",foodTypes[foodChoice][i], foodPrices[foodChoice][i]);
    }
    printf("%c) Go back\n",'a'+noOfFoodTypes[foodChoice]);
}

void showDrinksOptions(int noOfDrinks, char food[][MAX_FOOD_NAME], int foodChoice, char drinks[][MAX_DRINKS_NAME], int drinksPrices[])
{
    printf("Please choose a drink to go with your %s\n", food[foodChoice]);
    for(int i=0;i<noOfDrinks;i++) {
        putchar('a'+i);
        printf(") %s (%d)\n", drinks[i], drinksPrices[i]);
    }
    printf("%c) Go back\n",'a'+noOfDrinks);
}