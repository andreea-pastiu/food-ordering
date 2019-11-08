#include <stdio.h>
#include "customer.h"
#include "choices.h"
#include "showOptions.h"
#include "additionalInfo.h"
#include "order.h"
#define MAX_FOOD_NAME 10
#define MAX_FOOD_TYPES_NO 4
#define MAX_FOOD_TYPES_NAME 20
#define MAX_DRINKS_NAME 12
#define MAX_ADDITIONAL_INFO 200
#define MAX_USERNAME 20
#define MAX_PASSWORD 20
#define INPUT_PERSONAL_DATA_STEP 0
#define CHOOSE_FOOD_STEP 1
#define CHOOSE_FOOD_TYPE_STEP 2
#define CHOOSE_DRINKS_STEP 3
#define CHOOSE_CUTLERY_STEP 4
#define ADDITIONAL_INFO_STEP 5
#define  PRINT_ORDER_STEP 6
int main() {
    printf("Welcome to Andreea's Pizzeria!\n");
    int noOfFood = 3, noOfFoodTypes[] = {3,2,4}, noOfDrinks = 5, drinksPrices[] = {5, 5, 5, 4, 0}, cutlery=0, choice, foodChoice, typeChoice, drinkChoice, state = INPUT_PERSONAL_DATA_STEP, orderReady = 0;
    char food[][MAX_FOOD_NAME] = {"Pizza","Pasta","Salad"};
    char foodTypes[][MAX_FOOD_TYPES_NO][MAX_FOOD_TYPES_NAME] = {
            {"Pizza Carbonara", "Pizza Diavolo", "Pizza Margherita"},
            {"Chicken alfredo", "Mac&cheese"},
            {"Tuna Salad", "Chicken Salad", "Greek Salad", "Cobb"}};
    int foodPrices[][MAX_FOOD_TYPES_NO] = {
            {21, 23, 19},
            {23, 21},
            {23, 22, 19, 21}};
    char drinks[][MAX_DRINKS_NAME] = {"Coca-Cola","Fanta","Lipton", "Water", "No, thanks!"};
    char additionalInfo[MAX_ADDITIONAL_INFO], username[MAX_USERNAME], password[MAX_PASSWORD];
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