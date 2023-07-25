#include <stdio.h>

// Multiplies two matrices mat1[][] and mat2[][] and stores the result in res[][]
// (m1) x (m2) and (n1) x (n2) are dimensions of given matrices.
void multiply(int m1, int m2, int mat1[][m2], int n1,
              int n2, int mat2[][n2], int res[][n2])
{
    int x, i, j;
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n2; j++) {
            res[i][j] = 0;
            for (x = 0; x < m2; x++) {
                res[i][j] += mat1[i][x] * mat2[x][j];
            }
        }
    }
}

// Function to initialize a matrix with zeros
void initializeMatrix(int rows, int cols, int mat[][cols])
{
	int i = 0;
	int j = 0;
    for ( i=0 ;i < rows; i++) {
        for (j=0 ;j < cols; j++) {
            mat[i][j] = 0;
        }
    }
}

// Function to print a matrix
void printMatrix(int rows, int cols, int mat[][cols])
{
	int i = 0;
	int j = 0; 
    for ( i=0;i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int mat1[][3] = { { 2, 4, 5 }, { 3, 4, 5 } };
    int mat2[][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
    int m1 = 2, m2 = 3, n1 = 2, n2 = 3;

    // Create a third matrix to store the result and initialize it with zeros
    int result[m1][n2];
    initializeMatrix(m1, n2, result);

    // Function call to multiply matrices and store result in 'result' matrix
    multiply(m1, m2, mat1, n1, n2, mat2, result);

    // Print the result matrix
    printf("Result matrix:\n");
    printMatrix(m1, n2, result);

    return 0;
}
