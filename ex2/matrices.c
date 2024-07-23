//
// Created by Michal Roziel on 21.07.24.
//
#include <stdio.h>
#include "matrices.h"

#include <stdlib.h>

/**
 *
 * @param rows
 * @param columns
 */
void printMatrix(int matrix[], const int rows, const int columns)
{

  for (int i = 0; i < rows * columns; i++)
  {
    if (i % columns == 0)
    {
      if (i != 0)
      {
        printf("| \n");
      }
      printf("| %d ", matrix[i]);
    }
    else
    {
      printf("%d ", matrix[i]);
    }
  }
  printf("| \n");
}

int findMaxInCol(int matrix[], const int rows, const int cols, const int col)
{

  int max = -1;

  for (int row = 0; row < rows; row++)
  {
    // check visual in goodnotes

    // can this be a const?/
    int index = matrix[row * (rows - 2) + col];
    // printf("the current num checked is : %d\n", index);
    if (max < index)
    {
      max = index;
    }
  }
  printf("the maxinum element in the column %d is : %d\n", col, max);
  return max;
}

void transposeMatrix(int *matrix, const int rows, const int cols)
{

  // zuerst uber cols dann rows und in ein neues int array schreiben
  // first iterate over rows and then columns and write into a new array
  // malloc and free it later

  // malloc of size int for rows*cols - many numbers
  int *newMatrix = (int *)malloc(sizeof(rows * cols * sizeof(int)));

  // iterating over rows and columns
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {

      // write into the new matrix
      newMatrix[(j * rows) + i] = matrix[(i * cols) + j];
    }
  }

  // use the previous printMatrix method to print it
  printMatrix(newMatrix, cols, rows);
  free(newMatrix);
}

int main(void)
{

  int givenArray[] = {2, 18, 1, 27, 16, 24, 42, 18, 9, 5, 10, 42, 8, 7, 14};

  int rowsToPrint;
  int columnsToPrint;

  printf("Please Enter the number of rows for the Matrix:");
  scanf("%d", &rowsToPrint);

  printf("Please Enter the number of columns for the Matrix:");
  scanf("%d", &columnsToPrint);

  printMatrix(givenArray, rowsToPrint, columnsToPrint);

  printf("\n\n\n");

  // findMaxInCol(givenArray,5,3,0);
  transposeMatrix(givenArray, rowsToPrint, columnsToPrint);

  return 0;
}