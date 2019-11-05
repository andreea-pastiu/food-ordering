//
// Created by Andreea on 11/5/2019.
//

#include <stdio.h>

void readPersonalData(char username[], char password[], int *state)
{
    printf("Please sign in to continue!\n");
    printf("---Username\n");
    gets(username);
    printf("---Password\n");
    gets(password);
    (*state)++;
}