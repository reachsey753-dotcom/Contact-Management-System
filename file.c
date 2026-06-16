#include <stdio.h>
#include <string.h>
#include "file.h"

void addContact(Contact contacts[], int *count){
    if (count >= MAX_CONTACT) {
        printf("Contact list is full.\n");
        return;
    }

    Contact new_contact;

    printf("Enter name:");
    scanf(" %[^\n]" , new_contact.name);

    printf("Enter phone:");
    scanf(" %[^\n]" , new_contact.phone);

    printf("Enter email:");
    scanf(" %[^\n]" , new_contact.phone);

    contacts[*count] = new_contact;
    (*count)++;

    printf("Contact Added Succesfully!\n");

}