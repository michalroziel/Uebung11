//
// Created by Michal Roziel on 21.07.24.
//
#include <stdio.h>
#include "matrices.h"


/**
 *
 * @param rows
 * @param columns
 */
void printMatrix(int matrix[], int rows, int columns) {

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

int findMaxInCol( int matrix[], int rows, int cols, int col) {




}





int main(void){

  int givenArray[] = {2, 18, 1, 27, 16, 24, 42, 18, 9, 5, 10, 42, 8, 7, 14};

  int rowsToPrint;
  int columnsToPrint;

  printf("Please Enter the number of rows for the Matrix:");
  scanf("%d", &rowsToPrint);

  printf("Please Enter the number of columns for the Matrix:");
  scanf("%d", &columnsToPrint);

  printMatrix(givenArray,rowsToPrint,columnsToPrint);

  printf("\n\n\n");


  return 0;
}