//
// Created by Andreea on 12/19/2019.
//

#include "user.h"
#include "constants.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int isLength(user *u)
{
    return strlen(u->password) > MIN_PASSWORD_LENGTH;
}

int isNotUsername(user *u)
{
    return strstr(u->password, u->username) == NULL;
}

int containsDigit(user *u)
{
    for(int i= 0; i< strlen(u->password); i++)
        if(isdigit((u->password[i])))
            return 1;
    return 0;
}

int containsChar(user *u)
{
    for(int i= 0; i< strlen(u->password); i++)
        if(u->password[i] == '.' || u->password[i] == '_' || u->password[i] == '!')
            return 1;
    return 0;
}

int validate(int (*fullfillsCondition)(user*), user *u, char message[]) {
    if (fullfillsCondition(u)) {
        return 1;
    } else {
        printf("%s\n", message);
    }
    return 0;
}

void saveUsernameAndPassword(user *u, int encryptionKey,int users)
{
    FILE *usersFile = fopen("users.txt", "r+");
    if(usersFile != NULL)
    {
        char** encryptedPasswordHelper;
        char* encryptedPassword;
        int length;

        if(strlen(u->password)%encryptionKey == 0)
            length = strlen(u->password);
        else
            length = (strlen(u->password)/encryptionKey)*encryptionKey + encryptionKey;

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
            if(i < strlen(u->password))
            {
                encryptedPasswordHelper[j][i] = u->password[i];
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
        fprintf(usersFile, "%s,%s\n", u->username, encryptedPassword);
        fseek(usersFile, 3, SEEK_SET);
        fprintf(usersFile, "%d\n", users+1);
    }
    fclose(usersFile);
}

void readUsernamesAndPasswords(int *encryptionKey, int *usersNumber,user **users) {
    FILE *usersFile = fopen("users.txt", "r");
    if (usersFile != NULL) {
        fscanf(usersFile, "%d", encryptionKey);
        fscanf(usersFile, "%d", usersNumber);
        fgetc(usersFile);
        char *line = (char *) malloc(100 * sizeof(char));
        *users = (user *) malloc(*usersNumber * sizeof(user));
        for (int i = 0; i < *usersNumber; i++) {
            fgets(line, 100, usersFile);
            (*users)[i].username = (char *) malloc(100 * sizeof(char));
            (*users)[i].password = (char *) malloc(100 * sizeof(char));
            char *password = (char *) malloc(100 * sizeof(char));
            char *user = (char *) malloc(100 * sizeof(char));
            user = strtok(line, ",");
            strcpy((*users)[i].username, user);
            password = strtok(NULL, ",");
            int length = 0;
            for (int j = 0; j < strlen(password); j++) {
                if (password[j] != '&')
                    length++;
            }
            char **encryptedPasswordHelper = (char **) malloc(*encryptionKey * sizeof(char *));
            for (int j = 0; j < *encryptionKey; j++) {
                encryptedPasswordHelper[j] = (char *) malloc(length * sizeof(char));
                for (int k = 0; k < length; k++) {
                    encryptedPasswordHelper[j][k] = ' ';
                }
            }
            int k = 0;
            int direction = 1;
            for (int j = 0; j < length; j++) {
                encryptedPasswordHelper[k][j] = '-';
                if (direction == 1)
                    k++;
                else
                    k--;
                if (k == *encryptionKey) {
                    k -= 2;
                    direction = 2;
                } else {
                    if (k == -1) {
                        k += 2;
                        direction = 1;
                    }
                }
            }
            int l = 0;
            for (int j = 0; j < *encryptionKey; j++) {
                for (int k = 0; k < length; k++) {
                    if (encryptedPasswordHelper[j][k] == '-') {
                        while (password[l] == '&')
                            l++;
                        encryptedPasswordHelper[j][k] = password[l++];
                    }
                }
            }

            k = 0;
            direction = 1;
            l = 0;
            for (int j = 0; j < length; j++) {
                if (encryptedPasswordHelper[k][j] != '\n' && encryptedPasswordHelper[k][j] != '&') {
                    (*users)[i].password[l++] = encryptedPasswordHelper[k][j];
                }
                if (direction == 1)
                    k++;
                else
                    k--;
                if (k == *encryptionKey) {
                    k -= 2;
                    direction = 2;
                } else {
                    if (k == -1) {
                        k += 2;
                        direction = 1;
                    }
                }
            }
            (*users)[i].password[l] = '\0';
        }
        fclose(usersFile);
    }
}

void readPersonalData(user *u, int *state)
{
    user * _users;
    int encryptionKey;
    int users;
    readUsernamesAndPasswords(&encryptionKey, &users, &_users);
    int ok = 0;
    char option;
    u->username = (char *) malloc(100 * sizeof(char));
    u->password = (char *) malloc(100 * sizeof(char));
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
                scanf("%s", u->username);
                printf("---Password\n");
                scanf("%s", u->password);
                int i = 0;
                for(i = 0; i < users && strcmp(u->username, _users[i].username) != 0;i++);
                if(i == users)
                {
                    exit = 1;
                    printf("%s\n", USER_NOT_FOUND);
                }
                else
                {
                    if (strcmp(u->password, _users[i].password) != 0)
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
                scanf("%s", u->username);
                printf("---Password\n");
                scanf("%s", u->password);
                int i = 0;
                for(i = 0; i < users && strcmp(u->username, _users[i].username) != 0;i++);
                if (i != users)
                {
                    printf("%s\n", DUPLICATE_USER);
                }
                else
                {
                    exit = validate(&isLength, u, ERROR_PASSWORD_LONG) && validate(&isNotUsername, u, ERROR_PASSWORD_NOT_USERNAME) && validate(&containsChar, u, ERROR_PASSWORD_SPECIAL_CHAR) && validate(&containsDigit, u, ERROR_PASSWORD_DIGITS);
                    ok = exit;
                }
            }
            saveUsernameAndPassword(u, encryptionKey, users);
            (*state)++;
        }
    }
    printf("done");
}

void showCustomerData(user u)
{
    printf("This is your order:\n-------------------\n");
    printf("Name: %s\n", u.username);
}