//
// Created by Andreea on 12/19/2019.
//

#ifndef FOOD_ORDERING_USER_H
#define FOOD_ORDERING_USER_H

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

typedef struct _user {
    char* username;
    char* password;
} user;

void readPersonalData(user *u, int *state);
void saveUsernameAndPassword(user *u, int encryptionKey,int users);
void readUsernamesAndPasswords(int *encryptionKey, int *usersNumber,user **users);
int validate(int (*fullfillsCondition)(user *u), user *u, char message[]);
int containsChar(user *u);
int containsDigit(user *u);
int isNotUsername(user *u);
int isLength(user *u);
void showCustomerData(user u);

#endif //FOOD_ORDERING_USER_H
