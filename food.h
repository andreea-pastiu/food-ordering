//
// Created by Andreea on 12/19/2019.
//

#ifndef FOOD_ORDERING_FOOD_H
#define FOOD_ORDERING_FOOD_H
typedef struct _food {
    int noOfFood;
    int *noOfFoodTypes;
    char **food;
    char ***foodTypes;
    double **foodPrices;
} food;

void loadFood(food *f, FILE *inputPtr);
void showFoodOptions(food f);
void showFoodTypesOptions(food f, int foodChoice);
void showFoodChosen(food f, int foodChoice, int typeChoice);
#endif //FOOD_ORDERING_FOOD_H
