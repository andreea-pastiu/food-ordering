//
// Created by Andreea on 11/5/2019.
//

#include <stdio.h>
#define MAX_FOOD_NAME 10
#define MAX_FOOD_TYPES_NO 4
#define MAX_FOOD_TYPES_NAME 20
#define MAX_DRINKS_NAME 12

void showFoodOptions(int noOfFood, char** food)
{
    printf("Please choose the food you feel like eating today:\n");
    for(int i=0;i<noOfFood;i++) {
        putchar('a'+i);
        printf(") %s\n",food[i]);
    }
    printf("%c) Go back\n",'a'+noOfFood);
}

void showFoodTypesOptions(int noOfFoodTypes, char* food, char** foodTypes, double* foodPrices)
{
    printf("Please choose the type of %s\n", food);
    for(int i=0;i<noOfFoodTypes;i++) {
        putchar('a'+i);
        printf(") %s (%.2lf)\n",foodTypes[i], foodPrices[i]);
    }
    printf("%c) Go back\n",'a'+noOfFoodTypes);
}

void showDrinksOptions(int noOfDrinks, char* food, char** drinks, int* drinksPrices)
{
    printf("Please choose a drink to go with your %s\n", food);
    for(int i=0;i<noOfDrinks;i++) {
        putchar('a'+i);
        printf(") %s (%d)\n", drinks[i], drinksPrices[i]);
    }
    printf("%c) Go back\n",'a'+noOfDrinks);
}

void showCutleryOptions(int *cutlery, int *state)
{
    char choice;
    printf("Do you want cutlery?\n");
    printf("a) Yes\nb) No, thanks!\nc) Go back\n");
    choice = getchar();
    getchar();
    if(choice == 'c'){
        (*state)--;
    }
    else
    {
        if(choice == 'a')
            *cutlery = 1;
        if(choice == 'b')
            *cutlery = 0;
        (*state)++;
    }
}