#include<stdio.h>

void showWelcome();
void showMenu();
int main(){
    showWelcome();
    showMenu();

    return 0;
}
void showWelcome()

{
    printf("C PROGRAMMING FUNCTION PRACTICE\n");
    printf("Student: ____________\n");

}
void showMenu()
{
    printf("===== MENU ===== \n");
    printf("1.Add\n");
    printf("2.Subtract\n");
    printf("3.Multiply\n");
    printf("4.Exit\n");
}