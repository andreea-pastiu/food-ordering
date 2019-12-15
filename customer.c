//
// Created by Andreea on 11/5/2019.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
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

void readUsernamesAndPasswords(int *encryptionKey, int *usersNumber,char ***usernames, char ***passwords)
{
    FILE *usersFile = fopen("users.txt", "r");
    if(usersFile != NULL)
    {
        fscanf(usersFile, "%d", encryptionKey);
        fscanf(usersFile, "%d", usersNumber);
        fgetc(usersFile);
        char *line = (char*) malloc(100 * sizeof(char));
        *usernames = (char **) malloc(*usersNumber * sizeof(char*));
        *passwords = (char **) malloc(*usersNumber * sizeof(char*));
        for(int i = 0; i< *usersNumber; i++)
        {
            fgets(line, 100, usersFile);
            (*usernames)[i] = (char*) malloc(100 * sizeof(char));
            (*passwords)[i] = (char*) malloc(100 * sizeof(char));
            char* password = (char*) malloc(100 * sizeof(char));
            char* user = (char*) malloc(100 * sizeof(char));
            user = strtok(line, ",");
            strcpy((*usernames)[i], user);
            password = strtok(NULL, ",");
            int length = 0;
            for(int j = 0; j< strlen(password); j++)
            {
                if(password[j] != '&')
                    length++;
            }
            char** encryptedPasswordHelper = (char**) malloc(*encryptionKey * sizeof(char*));
            for(int j = 0; j < *encryptionKey; j++)
            {
                encryptedPasswordHelper[j] = (char*) malloc(length * sizeof(char));
                for(int k = 0; k < length; k++)
                {
                    encryptedPasswordHelper[j][k] = ' ';
                }
            }
            int k = 0;
            int direction = 1;
            for(int j = 0; j < length; j++)
            {
                encryptedPasswordHelper[k][j] = '-';
                if(direction == 1)
                    k++;
                else
                    k--;
                if(k == *encryptionKey)
                {
                    k-=2;
                    direction = 2;
                }
                else
                {
                    if(k == -1)
                    {
                        k+=2;
                        direction = 1;
                    }
                }
            }
            int l = 0;
            for(int j = 0; j < *encryptionKey; j++)
            {
                for(int k = 0; k < length; k++)
                {
                    if(encryptedPasswordHelper[j][k]=='-')
                    {
                        while(password[l] == '&')
                            l++;
                        encryptedPasswordHelper[j][k] = password[l++];
                    }
                }
            }

            k = 0;
            direction = 1;
            l = 0;
            for(int j = 0; j < length; j++)
            {
                if(encryptedPasswordHelper[k][j] != '\n' && encryptedPasswordHelper[k][j] != '&')
                {
                    (*passwords)[i][l++] = encryptedPasswordHelper[k][j];
                }
                if(direction == 1)
                    k++;
                else
                    k--;
                if(k == *encryptionKey)
                {
                    k-=2;
                    direction = 2;
                }
                else
                {
                    if(k == -1)
                    {
                        k+=2;
                        direction = 1;
                    }
                }
            }
            (*passwords)[i][l] = '\0';
        }
        fclose(usersFile);
    }
}

void saveUsernameAndPassword(char* username, char* password, int encryptionKey,int users)
{
    FILE *usersFile = fopen("users.txt", "r+");
    if(usersFile != NULL)
    {
        char** encryptedPasswordHelper;
        char* encryptedPassword;
        int length;

        if(strlen(password)%encryptionKey == 0)
            length = strlen(password);
        else
            length = (strlen(password)/encryptionKey)*encryptionKey + encryptionKey;

        encryptedPasswordHelper = (char**) malloc(encryptionKey * sizeof(char*));
        encryptedPassword = (char*) malloc((encryptionKey + 1) * sizeof(char));

        for(int i = 0; i < encryptionKey; i++)
        {
            encryptedPasswordHelper[i] = (char*) malloc(length *sizeof(char));
        }
        for(int i = 0; i< encryptionKey; i++)
        {
            for(int j = 0; j< length; j++)
            {
                encryptedPasswordHelper[i][j] = ' ';
            }
        }
        int j = 0;
        int direction = 1;
        for(int i = 0; i < length; i++)
        {
            if(i < strlen(password))
            {
                encryptedPasswordHelper[j][i] = password[i];
            }
            else
            {
                encryptedPasswordHelper[j][i] = '&';
            }
            if(direction == 1)
                j++;
            else
                j--;
            if(j == encryptionKey)
            {
                j-=2;
                direction = 2;
            }
            else
            {
                if(j == -1)
                {
                    j+=2;
                    direction = 1;
                }
            }
        }
        int k = 0;
        for(int i = 0; i< encryptionKey; i++)
        {
            for(int j = 0; j< length; j++)
            {
                if(encryptedPasswordHelper[i][j] != ' ')
                    encryptedPassword[k++] = encryptedPasswordHelper[i][j];
            }
        }
        encryptedPassword[k] = '\0';
        fseek(usersFile, 0, SEEK_END);
        fprintf(usersFile, "%s,%s\n", username, encryptedPassword);
        fseek(usersFile, 3, SEEK_SET);
        fprintf(usersFile, "%d\n", users+1);
    }
    fclose(usersFile);
}

void readPersonalData(char username[], char password[], int *state)
{
    char** usernames;
    char** passwords;
    int encryptionKey;
    int users;
    readUsernamesAndPasswords(&encryptionKey, &users, &usernames, &passwords);
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
                int i = 0;
                for(i = 0; i < users && strcmp(username, usernames[i]) != 0;i++);
                if(i == users)
                {
                    exit = 1;
                    printf("%s\n", USER_NOT_FOUND);
                }
                else
                {
                    if (strcmp(password, passwords[i]) != 0)
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
                int i = 0;
                for(i = 0; i < users && strcmp(username, usernames[i]) != 0;i++);
                if (i != users)
                {
                    printf("%s\n", DUPLICATE_USER);
                }
                else
                {
                    exit = validate(&isLength, password, username, ERROR_PASSWORD_LONG) && validate(&isNotUsername, password, username, ERROR_PASSWORD_NOT_USERNAME) && validate(&containsChar, password, username, ERROR_PASSWORD_SPECIAL_CHAR) && validate(&containsDigit, password, username, ERROR_PASSWORD_DIGITS);
                    ok = exit;
                }
            }
            saveUsernameAndPassword(username, password, encryptionKey, users);
            (*state)++;
        }
    }
}

void showCustomerData(char username[])
{
    printf("This is your order:\n-------------------\n");
    printf("Name: %s\n", username);
}