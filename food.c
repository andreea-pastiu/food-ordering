//
// Created by Andreea on 12/19/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "food.h"

void loadFood(food *f, FILE *inputPtr) {
    char line[MAX_LINE], *p, *q;
    if (inputPtr != NULL) {
        fscanf(inputPtr, "%s", line);
        fgetc(inputPtr);
    } else {
        printf("%s\n", LOAD_DATA);
        scanf("%s", line);
        getchar();
    }
    sscanf(line, "%d", &f->noOfFood);
    f->noOfFoodTypes = (int *) malloc(f->noOfFood * sizeof(int));
    f->food = (char **) malloc(f->noOfFood * sizeof(char *));
    f->foodTypes = (char ***) malloc(f->noOfFood * sizeof(char **));
    f->foodPrices = (double **) malloc(f->noOfFood * sizeof(double *));
    for (int i = 0; i < f->noOfFood; i++) {
        if (inputPtr != NULL)
            fgets(line, 100, inputPtr);
        else
            gets(line);
        p = strchr(line, ':');
        (f->food)[i] = (char *) malloc(MAX_FOOD_NAME * sizeof(char));
        strncpy((f->food)[i], line, p - line);
        (f->food)[i][p - line] = '\0';
        q = strrchr((f->food)[i], ' ');
        sscanf(q, "%d", &(f->noOfFoodTypes)[i]);
        strncpy((f->food)[i], line, q - (f->food)[i]);
        (f->food)[i][q - (f->food)[i]] = '\0';
        (f->foodTypes)[i] = (char **) malloc((f->noOfFoodTypes)[i] * sizeof(char *));
        (f->foodPrices)[i] = (double *) malloc((f->noOfFoodTypes)[i] * sizeof(double));
        p = p + 2;
        p = strtok(p, "(");
        int j = 0;
        while (p) {
            q = strstr(p, " - ");
            (f->foodTypes)[i][j] = (char *) malloc(MAX_FOOD_TYPES_NAME * sizeof(char));
            strncpy((f->foodTypes)[i][j], p, q - p);
            (f->foodTypes)[i][j][q - p] = '\0';
            q = q + 3;
            q[strlen(q) - 2] = '\0';
            sscanf(q, "%lf", &(f->foodPrices)[i][j]);
            p = strtok(NULL, "(");
            j++;
        }
    }
}

void showFoodOptions(food f)
{
    printf("Please choose the food you feel like eating today:\n");
    for(int i=0;i<f.noOfFood;i++) {
        putchar('a'+i);
        printf(") %s\n",f.food[i]);
    }
    printf("%c) Go back\n",'a'+f.noOfFood);
}

void showFoodTypesOptions(food f, int foodChoice)
{
    printf("Please choose the type of %s\n", f.food[foodChoice]);
    for(int i=0;i<f.noOfFoodTypes[foodChoice];i++) {
        putchar('a'+i);
        printf(") %s (%.2lf)\n",f.foodTypes[foodChoice][i], f.foodPrices[foodChoice][i]);
    }
    printf("%c) Go back\n",'a'+f.noOfFoodTypes[foodChoice]);
}

void showFoodChosen(food f, int foodChoice, int typeChoice)
{
    printf("Food items:\n");
    printf("---%s: %.2lf\n", f.foodTypes[foodChoice][typeChoice], f.foodPrices[foodChoice][typeChoice]);
}