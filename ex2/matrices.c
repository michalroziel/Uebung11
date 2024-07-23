//
// Created by Michal Roziel on 21.07.24.
//
#include <stdio.h>
#include "matrices.h"

#include <stdlib.h>

/**
 * prints
 * @param rows
 * @param columns
 */
void printMatrix(int matrix[], const int rows, const int columns) {
    for (int i = 0; i < rows * columns; i++) {
        if (i % columns == 0) {
            if (i != 0) {
                printf("| \n");
            }
            printf("| %d ", matrix[i]);
        } else {
            printf("%d ", matrix[i]);
        }
    }
    printf("| \n");
}

int findMaxInCol(int matrix[], const int rows, const int cols, const int col) {
    // set a very small number as the max at the beginning
    int max = -10000;

    for (int row = 0; row < rows; row++) {
        // check visual in goodnotes

        // can this be a const?/
        int index = matrix[row * (rows - 2) + col];
        // printf("the current num checked is : %d\n", index);
        if (max < index) {
            max = index;
        }
    }
    printf("the maxinum element in the column %d is : %d\n", col, max);
    return max;
}

int findMinInRow(int *matrix, int rows, int cols, int row) {
    // setting the min to a very big number at the beginning
    int min = 10000;

    for (int col = 0; col < cols; col++) {
        int index = row * cols + col;

        if (matrix[index] < min) {
            min = matrix[index];
        }
    }

    printf("the minimum element in the row %d is : %d", row, min);
    return min;
}

void swapRows(int *matrix, int rows, int cols, int row1, int row2) {
    //int *newMatrix = (int *)malloc(rows * cols * sizeof(int));

    // first the new matrix to be the same as the old matrix
    //newMatrix = matrix;

    // now iterate over the new matrix and set new values

    // iterate over the columns

    int firstIndex, secondIndex, temporary;
    for (int i = 0; i < cols; i++) {
        firstIndex = row1 * cols + i;
        secondIndex = row2 * cols + i;

        temporary = matrix[firstIndex];

        // now writing to the new matrix

        matrix[firstIndex] = matrix[secondIndex];
        matrix[secondIndex] = temporary;
    }

    printMatrix(matrix, rows, cols);
}

/**
 *
 * @param matrix
 * @param rows
 * @param cols
 */
void transposeMatrix(int *matrix, const int rows, const int cols) {
    // zuerst uber cols dann rows und in ein neues int array schreiben
    // first iterate over rows and then columns and write into a new array
    // malloc and free it later

    // malloc of size int for rows*cols - many numbers
    int *newMatrix = (int *) malloc((rows * cols * sizeof(int)));

    // iterating over rows and columns
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // write into the new matrix
            newMatrix[(j * rows) + i] = matrix[(i * cols) + j];
        }
    }

    // use the previous printMatrix method to print it
    printMatrix(newMatrix, cols, rows);
    free(newMatrix);
}

/**
 * multiplies each element of the matrix by a scalar and prints it to the terminal
 * @param matrix
 * @param rows
 * @param cols
 * @param scalar
 */
void multiplyByScalar(int *matrix, int rows, int cols, int scalar) {
    // iterate over the matrix and multipy each element
    for (int index = 0; index < rows*cols; index++) {
        matrix[index] = matrix[ index ] * scalar;
    }

    printf(" now printing the matrix multiplied by the scalar %d :\n" , scalar);
    printMatrix(matrix,rows,cols);
}

void sum(int* m1, int* m2, int* res, int rows, int cols) {

     res = (int*) malloc(sizeof(m1));

     for (int i = 0; i < rows; i++) {
             res[i] = m1[i] + m2[i];
     }

    printf("the resulting matrix by addinbg both matrices is :\n");
    printMatrix(res,rows,cols);

    free(res);
}


int main(void) {
    int givenArray[] = {2, 18, 1, 27, 16, 24, 42, 18, 9, 5, 10, 42, 8, 7, 14};

    int rowsToPrint;
    int columnsToPrint;

    printf("Please Enter the number of rows for the Matrix:");
    scanf("%d", &rowsToPrint);

    printf("Please Enter the number of columns for the Matrix:");
    scanf("%d", &columnsToPrint);

    printMatrix(givenArray, rowsToPrint, columnsToPrint);

    printf("\n\n\n");

    //findMaxInCol(givenArray, 5, 3, 0);
    //findMinInRow(givenArray, rowsToPrint, columnsToPrint, 2);
    // transposeMatrix(givenArray, rowsToPrint, columnsToPrint);

    //swapRows(givenArray, rowsToPrint, columnsToPrint, 0, 1);
   //multiplyByScalar(givenArray,rowsToPrint,columnsToPrint,3);

    int* res = (int*)calloc(15,sizeof(int));

    sum(givenArray,givenArray,res,rowsToPrint,columnsToPrint);

    free(res);

    return 0;
}
