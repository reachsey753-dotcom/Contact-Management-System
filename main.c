#include <stdio.h>
#include "file.h"

int main()
{
    Contact contacts[MAX_CONTACT];
    int count = 0;
    int choice = 0;
    int running = 1;

    loadContact(contacts, &count);

    while (running)
    {
        printf("======Contact Management System======\n");
        printf("1. Add\n");
        printf("2. Edit\n");
        printf("3. Delete\n");
        printf("4. Search Contact\n");
        printf("5. Exit\n");
        printf("=====================================\n\n");

        printf("Enter Option:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addContact(contacts, &count);
            saveContact(contacts, count);
            break;
        case 2:
            editContact(contacts, count);
            saveContact(contacts, count);
            break;
        case 3:
            deleteContact(contacts, &count);
            saveContact(contacts, count);
            break;
        case 4:
            searchContact(contacts, count);
            break;
        case 5:
            printf("Exiting......\n");
            running = 0;
            break;
        default:
            printf("Invalid, try again!\n");
        }
    }

    return 0;
}
