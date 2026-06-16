#include <stdio.h>
#include <string.h>
#include "file.h"

void addContact(Contact contacts[], int *count)
{
    if (*count >= MAX_CONTACT)
    {
        printf("Contact list is full.\n");
        return;
    }

    Contact new_contact;

    printf("Enter name:");
    scanf(" %[^\n]", new_contact.name);

    printf("Enter phone:");
    scanf(" %[^\n]", new_contact.phone);

    printf("Enter email:");
    scanf(" %[^\n]", new_contact.email);

    contacts[*count] = new_contact;
    (*count)++;

    printf("\n");
    printf("Contact Added Succesfully!\n\n");
}

void searchContact(Contact contacts[], int count)
{
    char keyword[MAX_NAME];
    int found = 0;

    if (count == 0)
    {
        printf("Contact list is empty!\n");
        return;
    }

    printf("Enter name to search: ");
    scanf(" %[^\n]", keyword);

    for (int i = 0; i < count; i++)
    {
        if (strstr(contacts[i].name, keyword) != NULL)
        {
            printf("========================\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            printf("========================\n");
            found = 1;
        }
    }

    if (!found)
    {
        printf("There is no contact matching %s.\n\n", keyword);
    }
}

void deleteContact(Contact contacts[], int *count)
{
    char keyword[MAX_NAME];
    int index = -1;

    if (*count == 0)
    {
        printf("Contact list is empty!\n");
        return;
    }

    printf("Enter name to delete: ");
    scanf(" %[^\n]", keyword);

    for (int i = 0; i < *count; i++)
    {
        if (strstr(contacts[i].name, keyword) != NULL)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        printf("No contact found matching %s.\n", keyword);
        return;
    }

    printf("\nContact Found!\n");
    printf("Name: %s\n", contacts[index].name);
    printf("Phone: %s\n", contacts[index].phone);
    printf("Email: %s\n", contacts[index].email);

    printf("Delete this contact? (Y/N)\n");
    char confirm;
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y')
    {
        for (int i = 0; i < *count + 1; i++)
        {
            contacts[i] = contacts[i + 1];
        }
        (*count)--;
        printf("Contact deleted succesfully!\n");
    }
    else
    {
        printf("\n======Deletion Canceled!======\n\n");
    }
}

void editContact(Contact contacts[], int count) {
    char keyword[MAX_NAME];
    int index = -1;

    if (count == 0) {
        printf("Contact list is empty!\n");
        return;
    }

    printf("Enter name to edit: ");
    scanf(" %[^\n]" , keyword);

    for (int i = 0; i < count; i++) {
        if (strstr(contacts[i].name, keyword) != NULL) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("No contact found matching %s.\n" , keyword);
        return;
    }

    printf("\nContact Found!\n\n");
    printf("Name: %s\n" , contacts[index].name);
    printf("Phone: %s\n" , contacts[index].phone);
    printf("Email: %s\n\n" , contacts[index].email);

    printf("What do you want to edit?\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");

    int choice;

    scanf("%d" , &choice);

    switch (choice) {

        case 1: 
            printf("Enter new name: ");
            scanf(" %[^\n]" , contacts[index].name);
            break;
        case 2:
            printf("Enter new phone: ");
            scanf(" %[^\n]" , contacts[index].phone);
            break;
        case 3:
            printf("Enter new email:");
            scanf(" %[^\n]" , contacts[index].email);
            break;
        default :
            printf("Invalid option, no change made.\n\n");
            return;
    }
} 
