#include <stdio.h>
#include <string.h>
#include <stdbool.h>


// function prototypes
bool palindrome_iterative(char word[], int size);
bool palindrome_recursive(char word[], int i, int size, char og_word[]);


void enter_word(void) {
    /* declaring two strings, 1 to store the original word and 1 to which is used
       to copy the unmodified form of the same word in order to
       eliminate any possible errors */
    char original_word[30], word_copy1[30];

    // asking user to enter the word to check if it is a palindrome
    printf("Enter word: ");
    scanf("%s", original_word);

    // copying the inputted word onto word_copy1
    strncpy(word_copy1, original_word, strlen(original_word));

    // signifying that the iterative function will be used to perform the palindrome checking
    printf("Using iteration:\n");

    // checking if word is a palindrome using iterative function
    if(palindrome_iterative(original_word, strlen(original_word)-1)){   // if true, print that it is a palindrome
        printf("The word is a palindrome!\n");
    }else{  // if false, print that it is not a palindrome
        printf("The word is not a palindrome!\n");
    }

    // declaring a string to store the unmodified version of the word being processed
    char word_copy2[strlen(word_copy1)];

    // copying the unmodified word onto word_copy2
    strncpy(word_copy2, word_copy1, strlen(word_copy1));

    // signifying that the recursive function will be used to perform the palindrome checking
    printf("\nUsing recursion:\n");

    // checking if word is a palindrome using recursive function
    if(palindrome_recursive(word_copy1, 0, strlen(original_word)-1, word_copy2)){   // if true, print that it is a palindrome
        printf("The word is a palindrome!\n");
    }else{  // if false, print that it is not a palindrome
        printf("The word is not a palindrome!\n");
    }

    putchar('\n');
}

bool palindrome_iterative(char word[], int size) {
    char og_word[strlen(word)];
    strncpy(og_word, word, strlen(word));
    int i = 0;

    // swapping the nth character with the (size-n)th character
    while (i < size) {
        char temp = word[i];
        word[i] = word[size];
        word[size] = temp;
        i++;
        size--;
    }

    // check if modified word is equal to the unmodified word
    if (strcmp(og_word, word) == 0){    // return true if strcmp() returns 0
        return true;
    }else{  // return false otherwise
        return false;
    }
}

bool palindrome_recursive(char word[], int i, int size, char og_word[]){
    // checking if function has gone through the whole word characters
    if (i >= size){ // if yes, check if modified word is equal to the unmodified word
        if (strcmp(og_word, word) == 0){    // return true if strcmp() returns 0
            return true;
        }else{  // return false otherwise
            return false;
        }
    }else{  // if no, swap nth character with (size-n)th character
        char temp = word[i];
        word[i] = word[size];
        word[size] = temp;

        // recall the recursive function after swapping characters
        return palindrome_recursive(word, ++i, --size, og_word);
    }
}