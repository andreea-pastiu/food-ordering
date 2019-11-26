//
// Created by Andreea on 11/26/2019.
//

#ifndef FOOD_ORDERING_DATA_H
#define FOOD_ORDERING_DATA_H
void loadData(int *noOfFood, int *noOfFoodTypes, char **food, char ***foodTypes, double **foodPrices, int *noOfDrinks, char **drinks, int *drinkPrices);
void loadFood(int *noOfFood, int *noOfFoodTypes, char **food, char ***foodTypes, double **foodPrices);
void loadDrinks(int *noOfDrinks, char **drinks, int *drinksPrices);
#endif //FOOD_ORDERING_DATA_H
