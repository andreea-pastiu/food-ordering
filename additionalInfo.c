//
// Created by Andreea on 11/5/2019.
//

#include <stdio.h>

#define MAX_ADDITIONAL_INFO 200

void getAdditionalInfo(char additionalInfo[MAX_ADDITIONAL_INFO], int *state)
{
    printf("Any additional info? (ENTER for no comment)\n");
    gets(additionalInfo);
    (*state)++;
}

void showAdditionalInfo(char additionalInfo[])
{
    if (additionalInfo[0] != NULL)
        printf("Additional info: %s\n", additionalInfo);
}