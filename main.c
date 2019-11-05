#include <stdio.h>


#define MAX_FOOD_NAME 10
#define MAX_FOOD_TYPES_NO 4
#define MAX_FOOD_TYPES_NAME 20
#define MAX_DRINKS_NAME 12


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
    char additionalInfo[200];

    //user input
    char username[20];
    char password[20];
    int choice, foodChoice, typeChoice, drinkChoice;

    int state = 0;
    int orderReady = 0;
    while(!orderReady){
        switch (state) {
            case 0: {
                // Input personal data
                printf("Please sign in to continue!\n");
                printf("---Username\n");
                gets(username);
                printf("---Password\n");
                gets(password);
                state++;
                break;
            }
            case 1: {
                // Choose food
                printf("Please choose the food you feel like eating today:\n");
                for(int i=0;i<noOfFood;i++) {
                    putchar('a'+i);
                    printf(") %s\n",food[i]);
                }
                printf("%c) Go back\n",'a'+noOfFood);

                choice = getchar();
                getchar();
                if(choice == 'a'+noOfFood) {
                    state--;
                }
                else
                {
                    foodChoice = choice - 'a';
                    state++;
                }
                break;
            }
            case 2: {
                // Choose the food type
                printf("Please choose the type of %s\n", food[foodChoice]);
                for(int i=0;i<noOfFoodTypes[foodChoice];i++) {
                    putchar('a'+i);
                    printf(") %s (%d)\n",foodTypes[foodChoice][i], foodPrices[foodChoice][i]);
                }
                printf("%c) Go back\n",'a'+noOfFoodTypes[foodChoice]);

                choice = getchar();
                getchar();
                if(choice == 'a'+noOfFoodTypes[foodChoice]) {
                    state--;
                }
                else {
                    typeChoice = choice - 'a';
                    state++;
                }
                break;
            }
            case 3: {
                // Choose the drinks
                printf("Please choose a drink to go with your %s\n", food[foodChoice]);
                for(int i=0;i<noOfDrinks;i++) {
                    putchar('a'+i);
                    printf(") %s (%d)\n", drinks[i], drinksPrices[i]);
                }
                printf("%c) Go back\n",'a'+noOfDrinks);

                choice = getchar();
                getchar();
                if(choice == 'a'+noOfDrinks) {
                    state--;
                }
                else {
                    drinkChoice = choice - 'a';
                    state++;
                }
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