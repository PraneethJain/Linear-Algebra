/* Write a program in C to find the determinant of a matrix based
on Laplace Expansion Theorem. Choose a matrix of shape 5x5 and you
need to expand using the nth row or column based on your roll number :
n = roll_numbder%5.

If the last digit of your roll number is ODD, Go for Row Expansion,
otherwise go for Column Expansion.
*/

// Save the file as <RollNo>_Q4.c

// Use the following matrix to test your program.
// Matrix = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10},
// {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20},
// {21, 22, 23, 24, 25}}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MATRIX_SIZE 5

int **create_matrix(int size)
{
  int **m = (int **)malloc(sizeof(int *)*size);
  for (int i = 0; i < MATRIX_SIZE; ++i)
    m[i] = (int *)malloc(sizeof(int)*size);

  return m;
}

void get_cofactor(int **matrix, int **cofactor, int p, int q, int size)
{
  // Implementation of get_cofactor function...
  for (int i = 0; i < size; ++i)
  {
    for (int j = 0; j < size; ++j)
    {
      if (i == p || j == q)
        continue;

      if (i < p)
        if (j < q)
          cofactor[i][j] = matrix[i][j];
        else
          cofactor[i][j - 1] = matrix[i][j];
      else if (j < q)
        cofactor[i - 1][j] = matrix[i][j];
      else
        cofactor[i - 1][j - 1] = matrix[i][j];
    }
  }
}
int determinant_recursive(int **matrix, int size)
{
  // Implementation of determinant_recursive function...
  if (size == 1)
    return matrix[0][0];

  int det = 0;
  for (int j = 0; j < size; ++j)
  {
    int cofactor = j % 2 ? 1 : -1;
    cofactor *= matrix[0][j];
    int **cofactor_matrix = create_matrix(size-1);
    get_cofactor(matrix, cofactor_matrix, 0, j, size);
    cofactor *= determinant_recursive(cofactor_matrix, size - 1);
    det += cofactor;
  }
  return det;
}
int laplace_expansion(int **matrix, int n)
{
  // Implementation of laplace_expansion function...
  int det = 0;
  for (int j = 0; j < MATRIX_SIZE; ++j)
  {
    int cofactor = (n + j) % 2 ? 1 : -1;
    cofactor *= matrix[n][j];
    int **cofactor_matrix = create_matrix(MATRIX_SIZE - 1);
    get_cofactor(matrix, cofactor_matrix, n, j, MATRIX_SIZE);
    cofactor *= determinant_recursive(cofactor_matrix, MATRIX_SIZE - 1);
    det += cofactor;
  }

  return det;
}

int main()
{
  int **matrix = create_matrix(MATRIX_SIZE);
  int n;
  printf("Enter the elements of the matrix:\n");
  for (int i = 0; i < MATRIX_SIZE; i++)
    for (int j = 0; j < MATRIX_SIZE; j++)
      scanf("%d", &matrix[i][j]);

  printf("Enter the value of n:\n");
  scanf("%d", &n);
  printf("The determinant of the matrix is %d.\n", laplace_expansion(matrix, n));
  return 0;
}