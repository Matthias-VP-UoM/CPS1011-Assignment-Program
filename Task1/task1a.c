#include <stdio.h>

void matrix_multiplication(void){
    int num_rows_matrix2, num_cols_matrix2;
    int num_rows_matrix1, num_cols_matrix1;

    printf("Enter number of rows for matrix 1: ");
    scanf("%d", &num_rows_matrix1);
    printf("Enter number of columns for matrix 1: ");
    scanf("%d", &num_cols_matrix1);

    int matrix1[num_rows_matrix1][num_cols_matrix1];

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

    printf("Enter number of rows for matrix 2: ");
    scanf("%d", &num_rows_matrix2);
    printf("Enter number of columns for matrix 2: ");
    scanf("%d", &num_cols_matrix2);

    int matrix2[num_rows_matrix2][num_cols_matrix2];

    //printf("Temp1: %d\nTemp2: %d\n", temp1, temp2);

    for (int i = 0; i < num_rows_matrix2; i++) {
        for (int j = 0; j < num_cols_matrix2; j++) {
            num = 0;
            printf("Enter number in row %d, col %d: ", i, j);
            scanf("%d", &num);
            matrix2[i][j] = num;
        }
    }

    putchar('\n');

    int resultant_matrix[num_rows_matrix1][num_cols_matrix2];

    for(int i=0; i < num_rows_matrix1; i++){
        for(int j=0; j < num_cols_matrix2; j++) {
            resultant_matrix[i][j] = 0;
        }
    }

    putchar('\n');

    if (num_cols_matrix1 != num_rows_matrix2){
        printf("Cannot perform matrix multiplication!\n");
    }else{
        // to add code for entering numbers of 2 matrices
        puts("Resultant Matrix:");
        for(int i=0; i < num_rows_matrix1; i++){
            for(int j=0; j < num_cols_matrix2; j++){
                for(int k=0; k < num_cols_matrix1; k++){
                    resultant_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
                }
                printf("%d\t", resultant_matrix[i][j]);
            }
            putchar('\n');
        }
    }

    putchar('\n');
}
