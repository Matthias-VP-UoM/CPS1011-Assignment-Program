#include <stdio.h>
#include <stdlib.h>

#include "stack_2.h"

/* prototype of function which is used to get the contents of a specific
 * element from the stack */
void displayElement(Item item);

/* prototype of function which is used to write the contents of an
 * element into a file */
void exportElementToFile(FILE *fp, Item item, char * strType);

int main(void) {
    MixedStack_t mixedStack;
    Item temp;

    /* create temporary variable to store element type until pushing
     * element onto stack is successful */
    int tempType;

    // Initialise stack and allocate memory resources
    initMixedStack(&mixedStack);

    // signal to the user that stack has been created
    printf("Stack has been created and initialized!\n");

    int choice = 0;

    // Check if stack is full
    if (isFull(&mixedStack))    // if yes, signal to the user that stack is full and exit program
    {
        fprintf(stderr,"No memory available! Bye!\n");
        exit(1);
    }

    // runs main menu until user exits the program by entering option 6
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

        // check the input from user and perform operation based on what was inputted
        switch(choice){
            case 1: {
                do{
                    // Add an element of some type into stack
                    puts("1. Integer");
                    puts("2. Double");
                    puts("3. Long Int");
                    puts("4. Long Long Int");
                    puts("5. Short");
                    puts("6. Unsigned Int");
                    puts("7. Long Double");
                    puts("8. Float");
                    puts("9. Character");
                    puts("10. String");
                    printf("Enter type number: ");
                    scanf("%d", &tempType);

                    /* if user inputs a number other than what is shown on the menu */
                    /* the program will ask the user to enter it again in order to validate input */
                    if (tempType <= 0 || tempType >= 11){
                        printf("Invalid type! Please enter valid type number!\n");
                    }
                }while (!(tempType > 0 && tempType <= 10));

                /* Accessing the element type entered previously in order to tell
                 * the program what variable type to use to store the element */
                printf("Enter element: ");
                switch(tempType){
                    case 1: {
                        // Declare an int variable to check whether input is an integer
                        int input;

                        // Input validation
                        do
                        {
                            scanf("%d", &input);
                        }while (sprintf(temp.stackElement, "%d", input) == 0);
                    }break;
                    case 2: {
                        // Declare an int variable to check whether input is an integer
                        double input;

                        // Input validation
                        do
                        {
                            scanf("%lf", &input);
                        }while (sprintf(temp.stackElement, "%lf", input) == 0);
                    }break;
                    case 3: {
                        // Declare an int variable to check whether input is an integer
                        long input;

                        // Input validation
                        do
                        {
                            scanf("%ld", &input);
                        }while (sprintf(temp.stackElement, "%ld", input) == 0);
                    }break;
                    case 4: {
                        // Declare an int variable to check whether input is an integer
                        long long input;

                        // Input validation
                        do
                        {
                            scanf("%lld", &input);
                        }while (sprintf(temp.stackElement, "%lld", input) == 0);
                    }break;
                    case 5: {
                        // Declare an int variable to check whether input is an integer
                        short input;

                        // Input validation
                        do
                        {
                            scanf("%hd", &input);
                        }while (sprintf(temp.stackElement, "%hd", input) == 0);
                    }break;
                    case 6: {
                        // Declare an int variable to check whether input is an integer
                        unsigned int input;

                        // Input validation
                        do
                        {
                            scanf("%u", &input);
                        }while (sprintf(temp.stackElement, "%u", input) == 0);
                    }break;
                    case 7: {
                        // Declare an int variable to check whether input is an integer
                        long double input;

                        // Input validation
                        do
                        {
                            scanf("%Lf", &input);
                        }while (sprintf(temp.stackElement, "%Lf", input) == 0);
                    }break;
                    case 8: {
                        // Declare an int variable to check whether input is an integer
                        float input;

                        // Input validation
                        do
                        {
                            scanf("%f", &input);
                        }while (sprintf(temp.stackElement, "%f", input) == 0);
                    }break;
                    case 9: {
                        // Declare an int variable to check whether input is an integer
                        char input[10];

                        // Input validation
                        scanf("%s", input);

                        temp.stackElement[0] = input[0];

                        for (int i = 1; i < STRSIZE; i++) {
                            temp.stackElement[i] = '\0';
                        }
                    }break;
                    case 10: {
                        scanf("%s", temp.stackElement);
                    } break;
                    default: printf("Invalid option!"); break;
                }

                temp.type = tempType; // set element type when adding element is successful

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
                export(&mixedStack, exportElementToFile);
                printf("Destroying stack...\n");
                deinitMixedStack(&mixedStack);
                printf("Stack has been destroyed\n");
                printf("Thank you for using this program!\n");
            } break;
            default: puts("Invalid choice!\n"); // Adds additional line to separate output and menu title
        }
    }while (choice != 6);

    return 0;
}

// prints the contents of last element whenever the pop or peek operations are called
// for types 1 to 10, the elements are typecasted into proper data type
void displayElement(Item item){
    if (item.type == 1){
        int output = atoi(item.stackElement);
        printf("Type: Integer\n");
        printf("Element: %d\n", output);
    }else if (item.type == 2){
        double output;
        sscanf(item.stackElement, "%lf", &output);
        printf("Type: Double\n");
        printf("Element: %lf\n", output);
    }else if (item.type == 3) {
        long output;
        sscanf(item.stackElement, "%ld", &output);
        printf("Type: Long Int\n");
        printf("Element: %ld\n", output);
    }else if (item.type == 4) {
        long long output;
        sscanf(item.stackElement, "%lld", &output);
        printf("Type: Long Long Int\n");
        printf("Element: %lld\n", output);
    }else if (item.type == 5) {
        short output;
        sscanf(item.stackElement, "%hd", &output);
        printf("Type: Short\n");
        printf("Element: %hd\n", output);
    }else if (item.type == 6) {
        unsigned int output;
        sscanf(item.stackElement, "%u", &output);
        printf("Type: Unsigned Int\n");
        printf("Element: %u\n", output);
    }else if (item.type == 7) {
        long double output;
        sscanf(item.stackElement, "%Lf", &output);
        printf("Type: Long Double\n");
        printf("Element: %Lf\n", output);
    }else if (item.type == 8){
        float output;
        sscanf(item.stackElement, "%f", &output);
        printf("Type: Float\n");
        printf("Element: %f\n", output);
    }else if (item.type == 9){
        char output;
        sscanf(item.stackElement, "%c", &output);
        printf("Type: Character\n");
        printf("Element: %c\n", output);
    }else if (item.type == 10){
        printf("Type: String\n");
        printf("Element: %s\n", item.stackElement);
    }
}

// writes item contents into file after file has been created
void exportElementToFile(FILE *fp, Item item, char * strType){
    fprintf(fp, "Type: %d - %s\n", item.type, strType);
    fprintf(fp, "Element: %s\n", item.stackElement);

    // separate each element with dashed lines
    fprintf(fp, "------------------------------------------\n");
}
