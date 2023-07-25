#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLUMNS 3

// Function to perform linear regression using Ordinary Least Squares (OLS)
void linearRegression(double X[ROWS][COLUMNS], double Y[ROWS], double coefficients[COLUMNS], double *constantTerm) {
    double X_transpose[COLUMNS][ROWS];
    double X_transpose_X[COLUMNS][COLUMNS];
    double X_transpose_Y[COLUMNS];

    // Transpose of matrix X
    for (int i = 0; i < COLUMNS; i++) {
        for (int j = 0; j < ROWS; j++) {
            X_transpose[i][j] = X[j][i];
        }
    }

    // X_transpose * X
    for (int i = 0; i < COLUMNS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            X_transpose_X[i][j] = 0.0;
            for (int k = 0; k < ROWS; k++) {
                X_transpose_X[i][j] += X_transpose[i][k] * X[k][j];
            }
        }
    }

    // X_transpose * Y
    for (int i = 0; i < COLUMNS; i++) {
        X_transpose_Y[i] = 0.0;
        for (int j = 0; j < ROWS; j++) {
            X_transpose_Y[i] += X_transpose[i][j] * Y[j];
        }
    }

    // Calculate the coefficients (B) using the formula: B = (X_transpose * X)^(-1) * (X_transpose * Y)
    double det = X_transpose_X[0][0] * (X_transpose_X[1][1] * X_transpose_X[2][2] - X_transpose_X[1][2] * X_transpose_X[2][1]) -
                 X_transpose_X[0][1] * (X_transpose_X[1][0] * X_transpose_X[2][2] - X_transpose_X[1][2] * X_transpose_X[2][0]) +
                 X_transpose_X[0][2] * (X_transpose_X[1][0] * X_transpose_X[2][1] - X_transpose_X[1][1] * X_transpose_X[2][0]);

    if (det == 0.0) {
        printf("The matrix X_transpose * X is singular. Cannot perform linear regression.\n");
        exit(EXIT_FAILURE);
    }

    coefficients[0] = (X_transpose_Y[1] * X_transpose_X[2][2] - X_transpose_Y[2] * X_transpose_X[1][2]) / det;
    coefficients[1] = (X_transpose_Y[2] * X_transpose_X[0][0] - X_transpose_Y[0] * X_transpose_X[2][0]) / det;
    coefficients[2] = (X_transpose_Y[0] * X_transpose_X[1][1] - X_transpose_Y[1] * X_transpose_X[0][1]) / det;

    // Calculate the constant term (c) using the formula: c = mean(Y) - (B * mean(X))
    double mean_X[COLUMNS] = {0.0};
    double mean_Y = 0.0;

    for (int i = 0; i < ROWS; i++) {
        mean_Y += Y[i];
        for (int j = 0; j < COLUMNS; j++) {
            mean_X[j] += X[i][j];
        }
    }

    mean_Y /= ROWS;

    for (int i = 0; i < COLUMNS; i++) {
        mean_X[i] /= ROWS;
    }

    *constantTerm = mean_Y - (coefficients[0] * mean_X[0] + coefficients[1] * mean_X[1] + coefficients[2] * mean_X[2]);
}

int main() {
    double X[ROWS][COLUMNS] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0},
        {2.0, 1.0, 3.0},
        {4.0, 5.0, 7.0}
    };

    double Y[ROWS] = {4.0, 9.0, 15.0, 7.0, 13.0};
    double coefficients[COLUMNS];
    double constantTerm;

    linearRegression(X, Y, coefficients, &constantTerm);

    printf("Coefficients (B): b1 = %.2f, b2 = %.2f, b3 = %.2f\n", coefficients[0], coefficients[1], coefficients[2]);
    printf("Constant term (c): %.2f\n", constantTerm);

    return 0;
}

