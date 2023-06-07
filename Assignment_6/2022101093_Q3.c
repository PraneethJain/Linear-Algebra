// Write a program in C to check if a given vector is an eigenvector for a matrix.
// Save the file as <RollNo>_Q3.c
// Use the following matrix and vector to test your program.
// Matrix = {{1, 2}, {3, 4}}
// Vector = {2, 1}
// Expected Output: The vector is an eigenvector for the matrix.

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MATRIX_SIZE 3
#define MAX_ITERATIONS 100
#define EPSILON 1e-6

void matrix_vector_multiply(double matrix[MATRIX_SIZE][MATRIX_SIZE], double vector[MATRIX_SIZE], double result[MATRIX_SIZE])
{
  for (int res_idx = 0; res_idx < MATRIX_SIZE; ++res_idx)
  {
    double res = 0;
    for (int i = 0; i < MATRIX_SIZE; ++i)
      res += matrix[res_idx][i] * vector[i];
    result[res_idx] = res;
  }
}

void normalize_vector(double vector[MATRIX_SIZE])
{
  double sum = 0;
  for (int i = 0; i < MATRIX_SIZE; ++i)
    sum += pow(vector[i], 2);
  double magnitude = sqrt(sum);
  for (int i = 0; i < MATRIX_SIZE; ++i)
    vector[i] /= magnitude;
}

bool is_eigenvector(double matrix[MATRIX_SIZE][MATRIX_SIZE], double vector[MATRIX_SIZE])
{
  double product[MATRIX_SIZE];
  matrix_vector_multiply(matrix, vector, product);
  normalize_vector(product);
  normalize_vector(vector);
  bool parallel = true;
  for (int i = 0; i < MATRIX_SIZE; ++i)
  {
    if (abs(vector[i] - product[i]) > EPSILON)
    {
      parallel = false;
      break;
    }
  }

  bool antiparallel = true;
  for (int i = 0; i < MATRIX_SIZE; ++i)
  {
    if (abs(vector[i] + product[i]) > EPSILON)
    {
      antiparallel = false;
      break;
    }
  }
  
  return parallel || antiparallel;
}

int main()
{
  double matrix[MATRIX_SIZE][MATRIX_SIZE];
  double vector[MATRIX_SIZE];

  if (is_eigenvector(matrix, vector))
    printf("The vector is an eigenvector for the matrix.\n");
  else
    printf("The vector is not an eigenvector for the matrix.\n");
  printf("\n");

  return 0;
}
