#include <stdio.h>
#include <stdlib.h>
#include "customer.h"
#include "choices.h"
#include "showOptions.h"
#include "additionalInfo.h"
#include "order.h"
#include "constants.h"
#include "data.h"

int main() {
    int noOfFood = 3, *noOfFoodTypes, noOfDrinks = 5, cutlery=0, choice, foodChoice, typeChoice, drinkChoice, state = INPUT_PERSONAL_DATA_STEP, orderReady = 0;
    int *drinksPrices;
    char **food;
    char ***foodTypes;
    double **foodPrices;
    char **drinks;
    char additionalInfo[MAX_ADDITIONAL_INFO], username[MAX_USERNAME], password[MAX_PASSWORD];

    loadData(&noOfFood, noOfFoodTypes, food, foodTypes, foodPrices, &noOfDrinks, drinks, drinksPrices);
    printf("Welcome to Andreea's Pizzeria!\n");
    while(!orderReady){
        switch (state) {
            case INPUT_PERSONAL_DATA_STEP:{
                readPersonalData(username, password, &state);
                break;}
            case CHOOSE_FOOD_STEP:{
                chooseFood(noOfFood, food, &foodChoice, &state);
                break;}
            case CHOOSE_FOOD_TYPE_STEP:{
                chooseFoodType(noOfFoodTypes, food, foodChoice, foodTypes, foodPrices, &typeChoice, &state);
                break;}
            case CHOOSE_DRINKS_STEP:{
                chooseDrinks(noOfDrinks, food, foodChoice, drinks, drinksPrices, &drinkChoice, &state);
                break;}
            case CHOOSE_CUTLERY_STEP:{
                showCutleryOptions(&cutlery, &state);
                break;}
            case ADDITIONAL_INFO_STEP:{
                getAdditionalInfo(additionalInfo, &state);
                break;}
            case PRINT_ORDER_STEP:{
                printOrder(username, foodTypes, foodChoice, typeChoice, foodPrices, drinkChoice, noOfDrinks, drinks, drinksPrices, cutlery, additionalInfo, &orderReady, &state);
                break;}
        }
    }
    return 0;}