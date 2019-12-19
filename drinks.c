//
// Created by Andreea on 12/19/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "drinks.h"

void loadDrinks(drinks *d, FILE *inputPtr)
{
    char line[MAX_LINE], *p, *q;
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
    sscanf(line, "%d", &d->noOfDrinks);
    (d->noOfDrinks)++;
    if(inputPtr != NULL)
        fgets(line, 100, inputPtr);
    else
        gets(line);
    d->drinks = (char**) malloc(d->noOfDrinks * sizeof(char*));
    d->drinksPrices = (int*) malloc(d->noOfDrinks * sizeof(int));
    p = strtok(line, "(");
    int i = 0;
    while(p)
    {
        (d->drinks)[i] = (char*) malloc(MAX_DRINKS_NAME * sizeof(char));
        q = strstr(p, " - ");
        strncpy((d->drinks)[i], p, q-p);
        (d->drinks)[i][q-p] = '\0';
        q = q + 3;
        sscanf(q, "%d", &(d->drinksPrices)[i]);
        p = strtok(NULL, "(");
        i++;
    }
    (d->drinks)[(d->noOfDrinks)-1] = "No, thanks!";
    (d->drinksPrices)[(d->noOfDrinks)-1] = 0;
    if(inputPtr != NULL)
        fclose(inputPtr);
}

void showDrinksOptions(drinks d, char *food)
{
    printf("Please choose a drink to go with your %s\n", food);
    for(int i=0;i<d.noOfDrinks;i++) {
        putchar('a'+i);
        printf(") %s (%d)\n", d.drinks[i], d.drinksPrices[i]);
    }
    printf("%c) Go back\n",'a'+d.noOfDrinks);
}

void showDrinksChosen(int drinkChoice, drinks d)
{
    if(drinkChoice == d.noOfDrinks - 1)
        printf("No drinks\n");
    else
        printf("---%s: %d\n", d.drinks[drinkChoice], d.drinksPrices[drinkChoice]);
}