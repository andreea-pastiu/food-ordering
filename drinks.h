//
// Created by Andreea on 12/19/2019.
//

#ifndef FOOD_ORDERING_DRINKS_H
#define FOOD_ORDERING_DRINKS_H

typedef struct _drinks {
    int noOfDrinks;
    int *drinksPrices;
    char **drinks;
} drinks;

void loadDrinks(drinks *d, FILE *inputPtr);
void showDrinksOptions(drinks d, char *food);
void showDrinksChosen(int drinkChoice, drinks d);
#endif //FOOD_ORDERING_DRINKS_H
