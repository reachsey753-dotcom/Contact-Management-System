#include <stdio.h>

int main()
{

    int choice = 0;
    int running = 1;

    
    while (running)
    {
        printf("------Contact Management System------\n");
        printf("1. Add\n");
        printf("2. Edit\n");
        printf("3. Delete\n");
        printf("4. Search Contact\n");
        printf("5. Save New Contact\n");
        printf("6. Exit\n\n");
    
        printf("Enter Option:");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("1. Add\n");
            break;
        case 2:
            printf("2. Edit\n");
            break;
        case 3:
            printf("3. Delete\n");
            break;
        case 4:
            printf("4. Search Contact\n");
            break;
        case 5:
            printf("5. Save New Contact\n");
            break;
        case 6:
            printf("Exiting......\n");
            running = 0;
            break;
        default:
            printf("Invalid, try again!\n");
        }
    }

    return 0;
}