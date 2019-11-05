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

int main() {
    printf("Welcome to Andreea's Pizzeria!\n");

    //food data
    int noOfFood = 3;
    char food[][MAX_FOOD_NAME] = {"Pizza","Pasta","Salad"};

    int noOfFoodTypes[] = {3,2,4};
    char foodTypes[][MAX_FOOD_TYPES_NO][MAX_FOOD_TYPES_NAME] = {
            {"Pizza Carbonara", "Pizza Diavolo", "Pizza Margherita"},
            {"Chicken alfredo", "Mac&cheese"},
            {"Tuna Salad", "Chicken Salad", "Greek Salad", "Cobb"}
    };
    int foodPrices[][MAX_FOOD_TYPES_NO] = {
            {21, 23, 19},
            {23, 21},
            {23, 22, 19, 21}
    };

    int noOfDrinks = 5;
    char drinks[][MAX_DRINKS_NAME] = {"Coca-Cola","Fanta","Lipton", "Water", "No, thanks!"};
    int drinksPrices[] = {5, 5, 5, 4, 0};

    int cutlery=0;
    char additionalInfo[MAX_ADDITIONAL_INFO];

    //user input
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    int choice, foodChoice, typeChoice, drinkChoice;

    int state = 0;
    int orderReady = 0;
    while(!orderReady){
        switch (state) {
            case 0: {
                // Input personal data
                readPersonalData(username, password, &state);
                break;
            }
            case 1: {
                // Choose food
                showFoodOptions(noOfFood, food);
                foodChoice = getChoiceIndex(noOfFood, &state);
                break;
            }
            case 2: {
                // Choose the food type
                showFoodTypesOptions(noOfFoodTypes, food, foodChoice, foodTypes, foodPrices);
                typeChoice = getChoiceIndex(noOfFoodTypes[foodChoice], &state);
                break;
            }
            case 3: {
                // Choose the drinks
                showDrinksOptions(noOfDrinks, food, foodChoice, drinks, drinksPrices);
                drinkChoice = getChoiceIndex(noOfDrinks, &state);
                break;
            }
            case 4: {
                //Cutlery or not
                showCutleryOptions(&cutlery, &state);
                break;
            }
            case 5: {
                //Additional info
                getAdditionalInfo(additionalInfo, &state);
                break;
            }
            case 6:{
                // Print order
                showCustomerData(username);
                showFoodChosen(foodTypes, foodChoice, typeChoice, foodPrices);
                showDrinksChosen(drinkChoice, noOfDrinks, drinks, drinksPrices);
                showCutleryChosen(cutlery);
                showAdditionalInfo(additionalInfo);
                paymentConfirmation(foodPrices, foodChoice, typeChoice, drinksPrices, drinkChoice, username, &orderReady, &state);
                break;
            }
        }
    }


    return 0;
}