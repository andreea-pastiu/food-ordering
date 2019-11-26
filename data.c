//
// Created by Andreea on 11/26/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"

void loadFood(int *noOfFood, int *noOfFoodTypes, char **food, char ***foodTypes, double **foodPrices)
{
    char line[MAX_LINE], *p, *q;
    scanf("%s", line);
    getchar();
    sscanf(line, "%d", noOfFood);
    noOfFoodTypes = (int*) malloc(*noOfFood* sizeof(int));
    food = (char**) malloc(*noOfFood * sizeof(char*));
    foodTypes = (char***) malloc(*noOfFood * sizeof(char**));
    foodPrices = (double**) malloc(*noOfFood * sizeof(double*));
    for(int i=0; i < *noOfFood; i++)
    {
        gets(line);
        noOfFoodTypes[i]= 0;
        p = strchr(line, '(');
        while(p)
        {
            noOfFoodTypes[i]++;
            p = strchr(p+1, '(');
        }
        foodTypes[i] = (char**) malloc(noOfFoodTypes[i] * sizeof(char*));
        foodPrices[i] = (double *) malloc(noOfFoodTypes[i] * sizeof(double));
        p = strchr(line, ':');
        food[i] = (char*) malloc(MAX_FOOD_NAME * sizeof(char));
        strncpy(food[i], line, p - line);
        food[i][p-line] = '\0';
        p = p+2;
        p = strtok(p, "(");
        int j = 0;
        while(p)
        {
            q = strstr(p, " - ");
            foodTypes[i][j] = (char*) malloc(MAX_FOOD_TYPES_NAME*sizeof(char));
            strncpy(foodTypes[i][j], p, q-p);
            foodTypes[i][j][q-p] = '\0';
            q = q+3;
            q[strlen(q)-2] = '\0';
            sscanf(q, "%lf", &foodPrices[i][j]);
            p = strtok(NULL, "(");
            j++;
        }
    }
}
void loadDrinks(int *noOfDrinks, char **drinks, int *drinksPrices)
{
    char line[MAX_LINE], *p, *q;
    scanf("%s", line);
    getchar();
    sscanf(line, "%d", noOfDrinks);
    gets(line);
    drinks = (char**) malloc(*noOfDrinks * sizeof(char*));
    drinksPrices = (int*) malloc(*noOfDrinks * sizeof(int));
    p = strtok(line, "(");
    int i = 0;
    while(p)
    {
        drinks[i] = (char*) malloc(MAX_DRINKS_NAME * sizeof(char));
        q = strstr(p, " - ");
        strncpy(drinks[i], p, q-p);
        drinks[i][q-p] = '\0';
        q = q + 3;
        sscanf(q, "%d", &drinksPrices[i]);
        p = strtok(NULL, "(");
        i++;
    }
}
void loadData(int *noOfFood, int *noOfFoodTypes, char **food, char ***foodTypes, double **foodPrices, int *noOfDrinks, char **drinks, int *drinksPrices)
{
    printf("%s\n", LOAD_DATA);
    loadFood(noOfFood, noOfFoodTypes, food, foodTypes, foodPrices);
    loadDrinks(noOfDrinks, drinks, drinksPrices);
}