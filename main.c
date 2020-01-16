#include <stdio.h>
#include <stdlib.h>
#include "choices.h"
#include "order.h"
#include "constants.h"
#include "food.h"
#include "drinks.h"
#include "user.h"
#include "finalOrder.h"
// am reusti sa citesc coca-cola, am facut si fara nr la foodtypes cu printscreenuri
int main() {
    int state = INPUT_PERSONAL_DATA_STEP;
    FILE *inputPtr = fopen("data.txt", "r");
    food f;
    loadFood(&f, inputPtr);
    drinks d;
    user u;
    finalOrder fo;
    fo.orderReady = 0;
    loadDrinks(&d, inputPtr);
    if(inputPtr != NULL)
        fclose(inputPtr);

    //loadData(&noOfFood, &noOfFoodTypes, &food, &foodTypes, &foodPrices, &noOfDrinks, &drinks, &drinksPrices);
    printf("Welcome to Andreea's Pizzeria!\n");
    while(!fo.orderReady){
        switch (state) {
            case INPUT_PERSONAL_DATA_STEP:{
                readPersonalData(&u, &state);
                break;}
            case CHOOSE_FOOD_STEP:{
                chooseFood(f, &fo, &state);
                break;}
            case CHOOSE_FOOD_TYPE_STEP:{
                chooseFoodType(f, &fo, &state);
                break;}
            case CHOOSE_DRINKS_STEP:{
                chooseDrinks(d, f, &fo, &state);
                break;}
            case CHOOSE_CUTLERY_STEP:{
                showCutleryOptions(&fo, &state);
                break;}
            case ADDITIONAL_INFO_STEP:{
                getAdditionalInfo(&fo, &state);
                break;}
            case PRINT_ORDER_STEP:{
                printOrder(u, f, d, &fo, &state);
                break;}
        }
    }
    for(int i=0; i< f.noOfFood; i++)
    {
        for(int j=0;j< f.noOfFoodTypes[i]; j++)
        {
            free(f.foodTypes[i][j]);
        }
        free(f.foodTypes[i]);
        free(f.food[i]);
        free(f.foodPrices[i]);
    }
    free(f.food);
    free(f.foodTypes);
    free(f.foodPrices);
    free(f.noOfFoodTypes);
    free(d.drinksPrices);
    for(int i = 0; i< d.noOfDrinks; i++)
    {
        free(d.drinks[i]);
    }
    free(d.drinks);
    free(fo.additionalInfo);
    free(&d);
    free(&f);
    free(&fo);
    return 0;}