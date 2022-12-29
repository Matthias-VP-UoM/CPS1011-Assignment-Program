#include <stdio.h>

void matrix_multiplication(void){
    // declaring integer variables used to store number of rows and columns of 2 matrices
    int num_rows_matrix2, num_cols_matrix2;
    int num_rows_matrix1, num_cols_matrix1;

    // Asking the user to input number of rows and columns for matrix 1
    printf("Enter number of rows for matrix 1: ");
    scanf("%d", &num_rows_matrix1);
    printf("Enter number of columns for matrix 1: ");
    scanf("%d", &num_cols_matrix1);

    // declaring matrix 1 and setting it to have the inputted number of rows and columns
    int matrix1[num_rows_matrix1][num_cols_matrix1];

    // Asking the user to input the required number of elements for matrix 1
    // place where it is to be stored is printed out by the program
    int num;
    for (int i = 0; i < num_rows_matrix1; i++) {
        for (int j = 0; j < num_cols_matrix1; j++) {
            num = 0;
            printf("Enter number in row %d, col %d: ", i, j);
            scanf("%d", &num);
            matrix1[i][j] = num;
        }
    }

    putchar('\n');

    // Asking the user to input number of rows and columns for matrix 1
    printf("Enter number of rows for matrix 2: ");
    scanf("%d", &num_rows_matrix2);
    printf("Enter number of columns for matrix 2: ");
    scanf("%d", &num_cols_matrix2);

    // declaring matrix 2 and setting it to have the inputted number of rows and columns
    int matrix2[num_rows_matrix2][num_cols_matrix2];

    //printf("Temp1: %d\nTemp2: %d\n", temp1, temp2);

    // Asking the user to input the required number of elements for matrix 2
    // place where it is to be stored is printed out by the program
    for (int i = 0; i < num_rows_matrix2; i++) {
        for (int j = 0; j < num_cols_matrix2; j++) {
            num = 0;
            printf("Enter number in row %d, col %d: ", i, j);
            scanf("%d", &num);
            matrix2[i][j] = num;
        }
    }

    // separating user input and printing of resultant matrix
    putchar('\n');

    /* declaring resultant_matrix and setting it to have the inputted number of rows
       for matrix 1 and the inputted number of columns for matrix 2, since that is what
       usually happens during matrix multiplication */
    int resultant_matrix[num_rows_matrix1][num_cols_matrix2];

    // setting each element in the resultant matrix as 0 to avoid any logical errors
    for(int i=0; i < num_rows_matrix1; i++){
        for(int j=0; j < num_cols_matrix2; j++) {
            resultant_matrix[i][j] = 0;
        }
    }

    putchar('\n');

    // check if number of columns in matrix 1 is equal to number of rows in matrix 2
    if (num_cols_matrix1 != num_rows_matrix2){  // if false, print out error message
        printf("Cannot perform matrix multiplication!\n");
    }else{  // if true, perform matrix multiplication
        puts("Resultant Matrix:");
        for(int i=0; i < num_rows_matrix1; i++){
            for(int j=0; j < num_cols_matrix2; j++){
                for(int k=0; k < num_cols_matrix1; k++){
                    resultant_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
                }
                // printing a tab to separate elements in each row of matrix
                printf("%d\t", resultant_matrix[i][j]);
            }
            // printing a line break to print out another row of elements
            putchar('\n');
        }
    }

    putchar('\n');
}
