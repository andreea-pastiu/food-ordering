//
// Created by Andreea on 11/26/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
void loadData(int *noOfFood, int **noOfFoodTypes, char ***food, char ****foodTypes, double ***foodPrices, int *noOfDrinks, char ***drinks, int **drinksPrices)
{
    FILE *inputPtr = fopen("data.txt", "r");
    char line[MAX_LINE], *p, *q;
    if(inputPtr != NULL)
    {
        fscanf(inputPtr, "%s", line);
        fgetc(inputPtr);
    }
    else
    {
        printf("%s\n", LOAD_DATA);
        scanf("%s", line);
        getchar();
    }
    sscanf(line, "%d", noOfFood);
    *noOfFoodTypes = (int*) malloc(*noOfFood* sizeof(int));
    *food = (char**) malloc(*noOfFood * sizeof(char*));
    *foodTypes = (char***) malloc(*noOfFood * sizeof(char**));
    *foodPrices = (double**) malloc(*noOfFood * sizeof(double*));
    for(int i=0; i < *noOfFood; i++)
    {
        if(inputPtr != NULL)
            fgets(line, 100, inputPtr);
        else
            gets(line);
        p = strchr(line, ':');
        (*food)[i] = (char*) malloc(MAX_FOOD_NAME * sizeof(char));
        strncpy((*food)[i], line, p - line);
        (*food)[i][p-line] = '\0';
        q = strrchr((*food)[i], ' ');
        sscanf(q, "%d", &(*noOfFoodTypes)[i]);
        strncpy((*food)[i], line, q-(*food)[i]);
        (*food)[i][q-(*food)[i]] = '\0';
        (*foodTypes)[i] = (char**) malloc((*noOfFoodTypes)[i] * sizeof(char*));
        (*foodPrices)[i] = (double *) malloc((*noOfFoodTypes)[i] * sizeof(double));
        p = p+2;
        p = strtok(p, "(");
        int j = 0;
        while(p)
        {
            q = strstr(p, " - ");
            (*foodTypes)[i][j] = (char*) malloc(MAX_FOOD_TYPES_NAME*sizeof(char));
            strncpy((*foodTypes)[i][j], p, q-p);
            (*foodTypes)[i][j][q-p] = '\0';
            q = q+3;
            q[strlen(q)-2] = '\0';
            sscanf(q, "%lf", &(*foodPrices)[i][j]);
            p = strtok(NULL, "(");
            j++;
        }
    }
    if(inputPtr != NULL)
    {
        fscanf(inputPtr, "%s", line);
        fgetc(inputPtr);
    }
    else
    {
        scanf("%s", line);
        getchar();
    }
    sscanf(line, "%d", noOfDrinks);
    (*noOfDrinks)++;
    if(inputPtr != NULL)
        fgets(line, 100, inputPtr);
    else
        gets(line);
    *drinks = (char**) malloc(*noOfDrinks * sizeof(char*));
    *drinksPrices = (int*) malloc(*noOfDrinks * sizeof(int));
    p = strtok(line, "(");
    int i = 0;
    while(p)
    {
        (*drinks)[i] = (char*) malloc(MAX_DRINKS_NAME * sizeof(char));
        q = strstr(p, " - ");
        strncpy((*drinks)[i], p, q-p);
        (*drinks)[i][q-p] = '\0';
        q = q + 3;
        sscanf(q, "%d", &(*drinksPrices)[i]);
        p = strtok(NULL, "(");
        i++;
    }
    (*drinks)[(*noOfDrinks)-1] = "No, thanks!";
    (*drinksPrices)[(*noOfDrinks)-1] = 0;
    if(inputPtr != NULL)
        fclose(inputPtr);
}