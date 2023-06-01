// Write a program in C to check if a given vector is an eigenvector for a matrix.
// Save the file as <RollNo>_Q3.c
// Use the following matrix and vector to test your program.
// Matrix = {{1, 2}, {3, 4}}
// Vector = {2, 1}
// Expected Output: The vector is an eigenvector for the matrix.

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MATRIX_SIZE 2
#define MAX_ITERATIONS 100
#define EPSILON 1e-6

void matrix_vector_multiply(int matrix[MATRIX_SIZE][MATRIX_SIZE], int vector[MATRIX_SIZE], int result[MATRIX_SIZE]) 
{
 // Implementation of matrix_vector_multiply function...
}

void normalize_vector(int vector[MATRIX_SIZE]) 
{
 // Implementation of normalize_vector function...
}

bool is_eigenvector(int matrix[MATRIX_SIZE][MATRIX_SIZE], int vector[MATRIX_SIZE]) 
{
 // Implementation of is_eigenvector function...
 
}

int main() 
{
  int matrix[MATRIX_SIZE][MATRIX_SIZE];
  int vector[MATRIX_SIZE];


  if (is_eigenvector(matrix, vector)) 
    printf("The vector is an eigenvector for the matrix.\n");
  else 
    printf("The vector is not an eigenvector for the matrix.\n");
  printf("\n");

 return 0;
}
