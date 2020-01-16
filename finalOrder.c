//
// Created by Andreea on 12/19/2019.
//

#include "finalOrder.h"
#include <stdlib.h>
#include <stdio.h>

void showCutleryOptions(finalOrder *fo, int *state)
{
    char choice;
    printf("Do you want cutlery?\n");
    printf("a) Yes\nb) No, thanks!\nc) Go back\n");
    choice = getchar();
    getchar();
    if(choice == 'c'){
        (*state)--;
    }
    else
    {
        if(choice == 'a')
            (*fo).cutlery = 1;
        if(choice == 'b')
            (*fo).cutlery = 0;
        (*state)++;
    }
}

void getAdditionalInfo(finalOrder *fo, int *state)
{
    fo->additionalInfo = (char*) malloc(100 * sizeof(char));
    printf("Any additional info? (ENTER for no comment)\n");
    gets(fo->additionalInfo);
    (*state)++;
}

void showCutleryChosen(finalOrder *fo)
{
    printf("Cutlery: %s\n", fo->cutlery == 0 ? "no" : "yes");
}

void showAdditionalInfo(finalOrder *fo)
{
    if (fo->additionalInfo[0] != NULL)
        printf("Additional info: %s\n", fo->additionalInfo);
}

void paymentConfirmation(double foodPrices, int drinksPrices, char username[], finalOrder *fo, int *state)
{
    double totalToPay;
    char choice;
    totalToPay = foodPrices + drinksPrices;
    printf("Payment amount: %.2lf\n", totalToPay);
    printf("-------------------\na) Confirm order\nb) Go back\n");
    choice = getchar();
    getchar();
    if(choice == 'a'){
        printf("Order confirmed! Thank you for buying from us, %s!\n", username);
        (*fo).orderReady = 1;
    }
    else
        *state = (*state) - 2;
}