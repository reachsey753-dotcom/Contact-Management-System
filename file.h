#ifndef FILE_H
#define FILE_H

#define MAX_NAME 50
#define MAX_PHONE 20
#define MAX_EMAIL 50
#define MAX_CONTACT 100

typedef struct {

    char name[MAX_NAME];
    char phone[MAX_PHONE];
    char email[MAX_EMAIL];

}   Contact;   

void addContact(Contact contacts[], int *count);
void searchContact(Contact contacts[] , int count);
void deleteContact(Contact contacts[], int *count);


#endif
