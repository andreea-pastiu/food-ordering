//
// Created by Andreea on 11/5/2019.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ERROR_PASSWORD_LONG "The password must be at least 7 chars long"
#define ERROR_PASSWORD_NOT_USERNAME "The password must not contain the username"
#define ERROR_PASSWORD_SPECIAL_CHAR "The password must contain one of the following characters: {'.','_','!'}"
#define ERROR_PASSWORD_DIGITS "The password must contain digits"
#define SIGN_IN_UP "Do you want to sign in or sign up?"
#define SIGN_IN "Sign in"
#define SIGN_UP "Sign up"
#define SIGNING_IN "Signing in!"
#define SIGNING_UP "Signing up!"
#define USER_NOT_FOUND "Username doesn't exist"
#define DUPLICATE_USER "Please choose another username!"
#define INCORRECT_PASSWORD "Incorrect password"
#define MIN_PASSWORD_LENGTH 7

int isLength(char password[], char username[])
{
    return strlen(password) > MIN_PASSWORD_LENGTH;
}

int isNotUsername(char password[], char username[])
{
    return strstr(password, username) == NULL;
}

int containsDigit(char password[], char username)
{
    for(int i= 0; i< strlen(password); i++)
        if(isdigit((password[i])))
            return 1;
    return 0;
}

int containsChar(char password[], char username)
{
    for(int i= 0; i< strlen(password); i++)
        if(password[i] == '.' || password[i] == '_' || password[i] == '!')
            return 1;
    return 0;
}

int validate(int (*fullfillsCondition)(char [], char[]), char password[], char username[], char message[]) {
    if (fullfillsCondition(password, username)) {
        return 1;
    } else {
        printf("%s\n", message);
    }
    return 0;
}

void readPersonalData(char username[], char password[], int *state)
{
    int ok = 0;
    char option;
    while(ok == 0)
    {
        printf("%s\n", SIGN_IN_UP);
        printf("a) %s\n", SIGN_IN);
        printf("b) %s\n", SIGN_UP);
        option = getchar();
        if(option == 'a')
        {
            int exit = 0;
            while(exit == 0)
            {
                printf("%s\n", SIGNING_IN);
                printf("---Username\n");
                scanf("%s", username);
                printf("---Password\n");
                scanf("%s", password);
                if (strcmp(username, "admin") != 0)
                {
                    exit = 1;
                    printf("%s\n", USER_NOT_FOUND);
                }
                else
                {
                    if (strcmp(password, "admin") != 0)
                    {
                        exit = 0;
                        printf("%s\n", INCORRECT_PASSWORD);
                    }
                    else
                    {
                        ok = 1;
                        exit = 1;
                        (*state)++;
                        getchar();
                    }
                }
            }
        }
        else if(option == 'b')
        {
            int exit = 0;
            while(exit == 0)
            {
                printf("%s\n", SIGNING_UP);
                printf("---Username\n");
                scanf("%s", username);
                printf("---Password\n");
                scanf("%s", password);
                if (strcmp(username, "admin") == 0)
                {
                    printf("%s\n", DUPLICATE_USER);
                }
                else
                {
                    exit = validate(&isLength, password, username, ERROR_PASSWORD_LONG) && validate(&isNotUsername, password, username, ERROR_PASSWORD_NOT_USERNAME) && validate(&containsChar, password, username, ERROR_PASSWORD_SPECIAL_CHAR) && validate(&containsDigit, password, username, ERROR_PASSWORD_DIGITS);
                    ok = exit;
                }
            }
            (*state)++;
        }
    }
}

void showCustomerData(char username[])
{
    printf("This is your order:\n-------------------\n");
    printf("Name: %s\n", username);
}