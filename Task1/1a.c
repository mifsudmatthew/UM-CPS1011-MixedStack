#include <stdio.h>

void matrixMultiplication(int r1, int c1, int r2, int c2, int array1[r1][c1], int array2[r2][c2], int resultArray[r1][c2]);

int main() {
    return 0;
}
// Function computing integer matrix multiplication
void matrixMultiplication(int r1, int c1, int r2, int c2, int array1[r1][c1], int array2[r2][c2], int resultArray[r1][c2]) {

    if(c1 == r2) { // if matrices are compatible

        int total = 0;

        for (int i = 0; i < r1; i++) {

            for (int j = 0; j < c2; j++) {

                for (int k = 0; k < r2; k++) {

                    // multiplying each entry/element in matrix 1's rows with matrix 2's columns
                    total = total + array1[i][k] * array2[k][j];

                }

                resultArray[i][j] = total; // storing the result of matrix entry/element [i][j]

                total = 0; // resetting 'total' to 0

            }

        }

        printf("\nResultant Matrix: \n");

        // Displaying the resultant matrix
        for (int i = 0; i < r1; i++) { // looping through resultant matrix rows

            for (int j = 0; j < c2; j++) { // looping through resultant matrix columns

                printf(" %d ", resultArray[i][j]); // printing each row of the matrix

            }

            printf("\n"); // skipping a line for the new row

        }

    }else{

        printf("Matrices are not compatible.");

    }

}
