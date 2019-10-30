#include <stdio.h>

int main() {
    printf("Welcome to Andreea's pancakes!\n");

    //pancakes data
    int noOfFood = 3;
    char food[3][10] = {"Pizza","Pasta","Salad"};
    int noFoodTypes[] = {3,2,4};
    char foodTypes[3][4][20] = {
            {"Pizza Carbonara", "Pizza Diavolo", "Pizza Margherita"},
            {"Chicken alfredo", "Mac&cheese"},
            {"Tuna Salad", "Chicken Salad", "Greek Salad", "Cobb"}
    };
    int foodPrices[3][4] = {
            {21, 23, 19},
            {23, 21},
            {23, 22, 19, 21}
    };

    int noOfDrinks = 4;
    char drinks[4][10] = {"Coca-Cola","Fanta","Lipton", "Water"};
    int drinksPrices[4] = {5, 5, 4};


    return 0;
}