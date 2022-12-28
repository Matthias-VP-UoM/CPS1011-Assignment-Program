#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool palindrome_iterative(char word[], int size);
bool palindrome_recursive(char word[], int i, int size, char og_word[]);


void enter_word(void) {
    char original_word[30], word_copy1[30];

    printf("Enter word: ");
    scanf("%s", original_word);

    strncpy(word_copy1, original_word, strlen(original_word));

    printf("Using iteration:\n");

    if(palindrome_iterative(original_word, strlen(original_word)-1)){
        printf("The word is a palindrome!\n");
    }else{
        printf("The word is not a palindrome!\n");
    }

    char word_copy2[strlen(word_copy1)];
    strncpy(word_copy2, word_copy1, strlen(word_copy1));

    printf("\nUsing recursion:\n");

    if(palindrome_recursive(word_copy1, 0, strlen(original_word)-1, word_copy2)){
        printf("The word is a palindrome!\n");
    }else{
        printf("The word is not a palindrome!\n");
    }

    putchar('\n');
}

bool palindrome_iterative(char word[], int size) {
    char og_word[strlen(word)];
    strncpy(og_word, word, strlen(word));
    int i = 0;
    while (i < size) {
        char temp = word[i];
        word[i] = word[size];
        word[size] = temp;
        i++;
        size--;
    }

    if (strcmp(og_word, word) == 0){
        return true;
    }else{
        return false;
    }
}

bool palindrome_recursive(char word[], int i, int size, char og_word[]){
    if (i >= size){
        if (strcmp(og_word, word) == 0){
            return true;
        }else{
            return false;
        }
    }else{
        char temp = word[i];
        word[i] = word[size];
        word[size] = temp;
        return palindrome_recursive(word, ++i, --size, og_word);
    }
}