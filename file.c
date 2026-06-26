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

    // email validation must have '@' and '.'
    char *at = strchr(new_contact.email, '@');
    char *dot = strchr(new_contact.email, '.');

    if (at == NULL || dot == NULL || dot < at)
    {
        printf("\n======Invalid email format!======\n\n");
        return;
    }

    contacts[*count] = new_contact;
    (*count)++;

    printf("\n");
    // printf("Contact Added Succesfully!\n");
}

void searchContact(Contact contacts[], int count)
{
    char keyword[MAX_NAME];
    int found = 0;

    if (count == 0)
    {
        printf("=======Contact list is empty!======\n");
        return;
    }

    printf("Enter name to search: ");
    scanf(" %[^\n]", keyword);

    for (int i = 0; i < count; i++)
    {
        if (strstr(contacts[i].name, keyword) != NULL)
        {
            printf("\n    CONTACT FOUND!  \n");
            printf("========================\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            printf("========================\n\n");
            found = 1;
        }
    }

    if (!found)
    {
        printf("\nThere is no contact matching %s.\n\n", keyword);
        return;
    }
}

void deleteContact(Contact contacts[], int *count)
{
    char keyword[MAX_NAME];
    int index = -1;

    if (*count == 0)
    {
        printf("\n======Contact list is empty!======\n\n");
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
        printf("\nNo contact found matching %s.\n\n", keyword);
        return;
    }

    printf("\n  Contact Found!  \n");
    printf("========================\n");
    printf("Name: %s\n", contacts[index].name);
    printf("Phone: %s\n", contacts[index].phone);
    printf("Email: %s\n", contacts[index].email);
    printf("========================\n\n");

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
        printf("\n======Contact deleted succesfully!======\n\n");
    }
    else
    {
        printf("\n======Deletion Canceled!======\n\n");
    }
}

void editContact(Contact contacts[], int count)
{
    char keyword[MAX_NAME];
    int index = -1;

    if (count == 0)
    {
        printf("\n======Contact list is empty!======\n\n");
        return;
    }

    printf("Enter name to edit: ");
    scanf(" %[^\n]", keyword);

    for (int i = 0; i < count; i++)
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

    printf("\nContact Found!\n\n");
    printf("========================\n");
    printf("Name: %s\n", contacts[index].name);
    printf("Phone: %s\n", contacts[index].phone);
    printf("Email: %s\n\n", contacts[index].email);
    printf("========================\n\n");

    printf("What do you want to edit?\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("Enter option:");

    int choice;

    scanf("%d", &choice);

    switch (choice)
    {

    case 1:
        printf("Enter new name: ");
        scanf(" %[^\n]", contacts[index].name);
        break;
    case 2:
        printf("Enter new phone: ");
        scanf(" %[^\n]", contacts[index].phone);
        break;
    case 3:
        printf("Enter new email: ");
        scanf(" %[^\n]", contacts[index].email);

        char *at = strchr(contacts[index].email, '@');
        char *dot = strchr(contacts[index].email, '.');

        if (at == NULL || dot == NULL || dot < at)
        {
            printf("\n======Invalid email format!======\n\n");
            return;
        }
        break;
    default:
        printf("Invalid option, no change made.\n\n");
        return;
    }
}

void saveContact(Contact contacts[], int count)
{

    FILE *file = fopen(FILENAME, "w");

    if (file == NULL)
    {
        printf("Error! Could not open file for saving.\n\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%s,%s,%s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }
    fclose(file);
    printf("Contact saved successfully!\n");
}

void loadContact(Contact contacts[], int *count)
{

    FILE *file = fopen(FILENAME, "r");
    if (file == NULL)
    {
        return;
    }

    *count = 0;
    while (*count < MAX_CONTACT)
    {
        int result = fscanf(file, "%49[^,],%19[^,],%49[^\n]", contacts[*count].name, contacts[*count].phone, contacts[*count].email);

        if (result != 3)
            break;
        (*count)++;
    }

    fclose(file);
    printf("Loaded %d contact(s).\n", *count);
}
