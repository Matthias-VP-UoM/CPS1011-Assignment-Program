/* repeat.c -- main() with arguments */
#include <stdio.h>

#include "task1.h"

int main(void)
{
    int choice = 0;

    do{
        printf("1. Matrix multiplication\n");
        printf("2. Check Palindrome\n");
        printf("3. Quit\n");
        printf("Enter your choice here: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: matrix_multiplication(); break;
            case 2: enter_word(); break;
            case 3: printf("Thanks for using the program!\n"); break;
            default: printf("Invalid option!\n"); putchar('\n');
        }
    }while(choice!=3);

    return 0;
}