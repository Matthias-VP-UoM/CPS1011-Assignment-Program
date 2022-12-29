#include <stdio.h>

// header file containing main function prototypes
#include "task1.h"

int main(void)
{
    // declare and initializing choice variable to 0 in order to go through the do-while loop
    int choice = 0;

    do{
        // print menu and ask user to input his choice
        printf("1. Matrix multiplication\n");
        printf("2. Check Palindrome\n");
        printf("3. Quit\n");
        printf("Enter your choice here: ");
        scanf("%d", &choice);

        // perform operation based on the user's input
        switch(choice){
            case 1: matrix_multiplication(); break;
            case 2: enter_word(); break;
            case 3: printf("Thanks for using the program!\n"); break;

            // in case the user inputs an option not shown on the menu
            default: printf("Invalid option!\n"); putchar('\n');
        }
    }while(choice!=3);  // the condition of the do-while loop

    return 0;
}