#include <stdio.h>
#include <string.h>
#include "file.h"

void addContact(Contact contacts[], int *count){
    if (*count >= MAX_CONTACT) {
        printf("Contact list is full.\n");
        return;
    }

    Contact new_contact;

    printf("Enter name:");
    scanf(" %[^\n]" , new_contact.name);

    printf("Enter phone:");
    scanf(" %[^\n]" , new_contact.phone);

    printf("Enter email:");
    scanf(" %[^\n]" , new_contact.email);

    contacts[*count] = new_contact;
    (*count)++;

    printf("\n");
    printf("Contact Added Succesfully!\n\n");

}

void searchContact(Contact contacts[] , int count) {
    char keyword[MAX_NAME];
    int found = 0;

    if (count == 0) {
        printf("Contact list is empty!\n");
        return;
    }

    printf("Enter name to search: ");
    scanf(" %[^\n]" , keyword);

    for (int i = 0 ; i < count ; i++) {
        if (strstr(contacts[i].name, keyword) != NULL) {
            printf("========================\n");
            printf("Name: %s\n" , contacts[i].name);
            printf("Phone: %s\n" , contacts[i].phone);
            printf("Email: %s\n" , contacts[i].email);
            found = 1;
        }
    }

    if (!found) {
        printf("There is no contact matching %s.\n\n",keyword);
    }
}

void deleteContact(Contact contacts[], int *count){
    char keyword[MAX_NAME];
    int index = -1;

    if (*count == 0) {
        printf("Contact list is empty!\n");
        return;
    }

}
