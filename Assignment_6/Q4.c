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
#define MATRIX_SIZE 5
void get_cofactor(int matrix[MATRIX_SIZE][MATRIX_SIZE], int cofactor[MATRIX_SIZE - 1][MATRIX_SIZE - 1], int p, int q) 
{
 // Implementation of get_cofactor function...
}
int determinant_recursive(int matrix[MATRIX_SIZE][MATRIX_SIZE], int size) 
{
 // Implementation of determinant_recursive function...
}
int laplace_expansion(int matrix[MATRIX_SIZE][MATRIX_SIZE], int n) 
{
 // Implementation of laplace_expansion function...
}


int main() 
{
  int matrix[MATRIX_SIZE][MATRIX_SIZE];
  int n;
  printf("Enter the elements of the matrix:\n");
  for (int i = 0; i < MATRIX_SIZE; i++) 
  {
    for (int j = 0; j < MATRIX_SIZE; j++) 
    {
    scanf("%d", &matrix[i][j]);
    }
  }
  printf("Enter the value of n:\n");
  scanf("%d", &n);
  printf("The determinant of the matrix is %d.\n", laplace_expansion(matrix, n));
  return 0;
}