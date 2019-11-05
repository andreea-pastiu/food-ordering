#include <stdio.h>
#include "customer.h"
#include "choices.h"
#include "showOptions.h"

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
                printf("AICI %d\n",foodChoice);
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
                printf("Do you want cutlery?\n");
                printf("a) Yes\nb) No, thanks!\nc) Go back\n");
                choice = getchar();
                getchar();
                if(choice == 'c'){
                    state--;
                }
                else
                {
                    if(choice == 'a')
                        cutlery = 1;
                    if(choice == 'b')
                        cutlery = 0;
                    state++;
                }
                break;
            }
            case 5: {
                //Additional info
                printf("Any additional info? (ENTER for no comment)\n");
                gets(additionalInfo);
                state++;
                break;
            }
            case 6:{
                // Print order
                printf("This is your order:\n-------------------\n");
                printf("Name: %s\n", username);
                printf("Food items:\n");
                printf("---%s: %d\n", foodTypes[foodChoice][typeChoice], foodPrices[foodChoice][typeChoice]);
                if(drinkChoice == noOfDrinks - 1)
                    printf("No drinks\n");
                else
                    printf("---%s: %d\n", drinks[drinkChoice], drinksPrices[drinkChoice]);
                printf("Cutlery: %s\n", cutlery == 0 ? "no" : "yes");
                if (additionalInfo[0] != NULL)
                    printf("Additional info: %s\n", additionalInfo);
                printf("Payment amount: %d\n", foodPrices[foodChoice][typeChoice] + drinksPrices[drinkChoice]);
                printf("-------------------\na) Confirm order\nb) Go back\n");
                choice = getchar();
                getchar();
                if(choice == 'a'){
                    printf("Order confirmed! Thank you for buying from us, %s!\n", username);
                    orderReady = 1;
                }
                else
                    state = state - 2;
                break;
            }
        }
    }


    return 0;
}