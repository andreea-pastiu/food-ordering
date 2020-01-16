//
// Created by Andreea on 12/19/2019.
//

#ifndef FOOD_ORDERING_FINALORDER_H
#define FOOD_ORDERING_FINALORDER_H

typedef struct _finalOrder {
    int foodChoice;
    int typeChoice;
    int drinkChoice;
    int cutlery;
    char *additionalInfo;
    int orderReady;
} finalOrder;

void showCutleryOptions(finalOrder *fo, int *state);
void getAdditionalInfo(finalOrder *fo, int *state);
void showCutleryChosen(finalOrder *fo);
void showAdditionalInfo(finalOrder *fo);
void paymentConfirmation(double foodPrices, int drinksPrices, char username[], finalOrder *fo, int *state);
#endif //FOOD_ORDERING_FINALORDER_H
