#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "stack.h"

/* prototype of function which is used to get the contents of a specific
 * element from the stack*/
void displayElement(Item item);

int main() {
    //printf("Let us create a mixed stack!\n");
    //printf("Task 1: Supporting integers and up to size 64 character strings\n");
    MixedStack_t mixedStack;
    Item temp;

    // Initialise stack and allocate memory resources
    initMixedStack(&mixedStack);

    printf("Stack has been created and initialized!\n");

    int choice = 0;

    // Check if stack is full
    if (isFull(&mixedStack))
    {
        fprintf(stderr,"No memory available! Bye!\n");
        exit(1);
    }

    do{
        printf("Stack Menu\n");
        printf("----------------------------------------\n");
        printf("1. Push an item onto stack\n");
        printf("2. Pop top item from stack\n");
        printf("3. Peek stack\n");
        printf("4. Clear stack\n");
        printf("5. Count number of elements in stack\n");
        printf("6. Destroy stack and exit\n");
        printf("Enter your choice here: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: {
                do{
                    // Add an element of some type into stack
                    printf("Enter type number (1 for int, 2 for size 64 strings): ");
                    scanf("%d", &temp.type);

                    if (temp.type <= 0 || temp.type >= 3){
                        printf("Invalid type! Please enter valid type number!\n");
                    }
                }while (!(temp.type > 0 && temp.type <= 2));

                /* Accessing the element type entered previously in order to tell
                 * the program what variable type to use to store the element */
                printf("Enter element: ");
                switch(temp.type){
                    case 1: {
                        // Declare a char * variable to check whether input is an integer
                        char input[5];

                        /* Set first character to any letter to avoid program generating
                           a random number as the element */
                        input[0] = 'K';

                        // Input validation
                        while (sscanf(input, "%d", &temp.elementInt) == 0)
                        {
                            scanf("%s", input);
                            if (!isdigit(input[0])) {   // input is of type string - invalid
                                puts("Invalid input! Please enter whole number!");
                                printf("Enter new element here: ");
                            }
                        }
                        printf("%d\n", temp.elementInt);
                        for(int i = 0; i < STRSIZE; i++)
                            temp.elementStr[i] = '\0'; //set string to empty
                    }break;
                    case 2: {
                        scanf("%s" ,temp.elementStr);
                        temp.elementInt = 0; //set integer variable to an unassigned number (0)
                    } break;
                }

                // Checks whether the adding of an element into stack has been successful
                // Otherwise, it will print out an error
                if (push(temp, &mixedStack)==false)
                {
                    fprintf(stderr,"Problem allocating memory\n");
                    exit(EXIT_FAILURE);
                }

                // Checks whether the mixed stack is full after adding a number of items
                if (isFull(&mixedStack))
                {
                    puts("The list is now full.");
                }
            }break;
            case 2: {
                if (pop(&mixedStack, displayElement) == true)
                    printf("Top item has been removed from stack!\n");
                else
                    printf("Cannot remove item since it is an empty stack!\n");
            }break;
            case 3: {
                if (peek(&mixedStack, displayElement) == false)
                    printf("Cannot display last item since it is an empty stack!\n");
            }break;
            case 4: {
                clear(&mixedStack);
                printf("Stack has been cleared!\n");
            }break;
            case 5: {
                unsigned int numOfElements = count(&mixedStack);
                printf("There are %d elements on the stack!\n", numOfElements);
            }break;
            case 6: {
                Traverse(&mixedStack, displayElement);
                printf("Destroying stack...\n");
                deinitMixedStack(&mixedStack);
                printf("Stack has been destroyed\n");
                printf("Thank you for using this program!\n");
            } break;
            default: puts("Invalid choice!\n"); // Adds additional line to separate output and menu title
        }
    }while (choice != 6);

    /* Traverses the stack and prints the contents of each element in the stack
     * using the displayElements() function */
    //Traverse(&mixedStack, displayElement);

    // Destroys stack and frees up all associated memory resources
    /*deinitMixedStack(&mixedStack);

    printf("Task 2: No limitations to supported data types\n");
    printf("Task 3: Compile program as a SHARED Library\n");*/

    return 0;
}

void displayElement(Item item){
    if (item.type == 1){
        printf("Type: Integer\n");
        printf("Element: %d\n", item.elementInt);
    }else if (item.type == 2){
        printf("Type: Size-64 Character String\n");
        printf("Element: %s\n", item.elementStr);
    }
}
