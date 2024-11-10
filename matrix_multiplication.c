#include<stdio.h>

void main() {
    int a[10][10], b[10][10], res[10][10]; // Matrices a, b and result matrix res
    int m, n, p, q, i, j, k;

    // Input rows and columns of the first matrix
    printf("Enter row and column of first matrix: ");
    scanf("%d%d", &m, &n);

    // Input elements of the first matrix
    printf("Enter first matrix: \n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Input rows and columns of the second matrix
    printf("Enter row and column of second matrix: ");
    scanf("%d%d", &p, &q);

    // Input elements of the second matrix
    printf("Enter second matrix: \n");
    for(i = 0; i < p; i++) {
        for(j = 0; j < q; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Check if matrix multiplication is possible
    if(n == p) { // Number of columns in first matrix must equal rows in second
        // Matrix multiplication logic
        for(i = 0; i < m; i++) {
            for(j = 0; j < q; j++) {
                res[i][j] = 0; // Initialize each element in result matrix to 0
                for(k = 0; k < n; k++) { // Perform dot product
                    res[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        // Display the result matrix
        printf("Result: \n");
        for(i = 0; i < m; i++) {
            for(j = 0; j < q; j++) {
                printf("%d ", res[i][j]);
            }
            printf("\n");
        }
    } else {
        // If matrices can't be multiplied, output error
        printf("Matrix multiplication not possible");
    }
}
