#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void matrixMultiplication(int r1, int c1, int r2, int c2, int array1[r1][c1], int array2[r2][c2], int resultArray[r1][c2]);
bool checkPalindrome_iterative(char input[]);
bool checkPalindrome_recursive(char input[], int first, int last);

int main() {

    int choice;
    char userInput[51];
    int lastLetter;

    int rows1 = 0; // rows of matrix 1
    int columns1 = 0; // columns of matrix 1
    int rows2 = 0; // rows of matrix 2
    int columns2 = 0; // columns of matrix 2

    do{

        printf("\n1. Matrix Multiplication\n2. Palindrome Checker (Iterative)\n3. Palindrome Checker (Recursive)\n4. Quit\n");

        if(scanf("%d",&choice) == 1) {

            switch (choice) {

                case 1:
                    // Setting the size (rows and columns) of each matrix

                        printf("Enter rows of matrix 1: (integer)\n");

                        if(scanf("%d", &rows1) == 0){

                            do{

                                while(getchar() != '\n'); // flushing buffer in case of non-integer input

                                printf("Enter a correct value:\n");

                            }while(scanf("%d", &rows1) == 0);

                        }

                        printf("Enter columns of matrix 1: (integer)\n");

                        if(scanf("%d", &columns1) == 0){
                            do{

                                while(getchar() != '\n'); // flushing buffer in case of non-integer input

                                printf("Enter a correct value:\n");

                            }while(scanf("%d", &columns1) == 0);

                        }

                        printf("Enter rows of matrix 2: (integer)\n");

                        if(scanf("%d", &rows2) == 0){

                            do{

                                while(getchar() != '\n'); // flushing buffer in case of non-integer input

                                printf("Enter a correct value:\n");

                            }while(scanf("%d", &rows2) == 0);

                        }

                        printf("Enter columns of matrix 2: (integer)\n");

                        if(scanf("%d", &columns2) == 0){

                            do{

                                while(getchar() != '\n'); // flushing buffer in case of non-integer input

                                printf("Enter a correct value:\n");

                            }while(scanf("%d", &columns2) == 0);

                        }

                    {
                        int matrix1[rows1][columns1]; // creating an array containing the width and height of matrix 1
                        int matrix2[rows2][columns2]; // creating an array containing the width and height of matrix 2
                        int resultMatrix[rows1][columns2]; // creating an array containing the resultant matrix

                        // Requesting user to fill matrix 1
                        for (int i = 0; i < rows1; i++) { // looping through matrix 1 rows

                            for (int j = 0; j < columns1; j++) { // looping through matrix 1 columns

                                printf("Enter the value of Row %d , Column %d\n", i + 1, j + 1);

                                if(scanf("%d", &matrix1[i][j]) == 0){ // filling each row and column

                                    do{

                                        while(getchar() != '\n'); // flushing buffer in case of non-integer input

                                        printf("Enter a correct value:\n");

                                    }while(scanf("%d", &matrix1[i][j]) == 0);

                                }

                            }
                        }
                        printf("\nMatrix 1: \n");
                        // Displaying matrix 1
                        for (int i = 0; i < rows1; i++) { // looping through matrix 1 rows

                            for (int j = 0; j < columns1; j++) { // looping through matrix 1 columns

                                printf(" %d ", matrix1[i][j]); // printing each row of the matrix

                            }

                            printf("\n"); // skipping a line for the new row

                        }

                        // Requesting user to fill matrix 2
                        for (int i = 0; i < rows2; i++) { // looping through matrix 2 rows

                            for (int j = 0; j < columns2; j++) { // looping through matrix 2 columns

                                printf("Enter the value of Row %d , Column %d\n", i + 1, j + 1);

                                if(scanf("%d", &matrix2[i][j]) == 0){ // filling each row and column

                                    do{

                                        while(getchar() != '\n'); // flushing buffer in case of non-integer input

                                        printf("Enter a correct value:\n");

                                    }while(scanf("%d", &matrix2[i][j]) == 0);

                                }

                            }
                        }
                        printf("\nMatrix 2: \n");
                        // Displaying matrix 2
                        for (int i = 0; i < rows2; i++) { // looping through matrix 2 rows

                            for (int j = 0; j < columns2; j++) { // looping through matrix 2 columns

                                printf(" %d ", matrix2[i][j]); // printing each row of the matrix

                            }

                            printf("\n"); // skipping a line for the new row

                        }

                        matrixMultiplication(rows1, columns1, rows2, columns2, matrix1, matrix2, resultMatrix);

                        break;
                    }

                case 2:

                    printf("\nEnter a string input: (50 Character Limit)\n");

                    while(getchar() != '\n'); // Clearing buffer from previous input

                   fgets(userInput,sizeof userInput,stdin); // Limiting user string input to 51 characters INCLUDING the null terminator.

                   userInput[strlen(userInput) - 1] = '\0'; // Adding a null terminator manually to the end of the string

                   if (checkPalindrome_iterative(userInput)) {

                       printf("%s , is a palindrome", userInput);

                   } else {

                       printf("%s , is not a palindrome", userInput);

                   }

                    break;

                case 3:

                    printf("\nEnter a string input: (50 Character Limit)\n");

                    while(getchar() != '\n'); // Clearing buffer from previous input

                    fgets(userInput,sizeof userInput,stdin); // Limiting user string input to 51 characters INCLUDING the null terminator.

                    userInput[strlen(userInput) - 1] = '\0'; // Adding a null terminator manually to the end of the string

                    lastLetter = strlen(userInput) - 1;

                    if (checkPalindrome_recursive(userInput, 0, lastLetter)) {

                        printf("%s , is a palindrome", userInput);

                    } else {

                        printf("%s , is not a palindrome", userInput);

                    }

                    break;

                case 4:

                    printf("Quitting...");

                    break;

                default: printf("Incorrect input, try again:");

            }
        }else{

            while(getchar() != '\n'); // flushing buffer in case of non-integer input

            printf("Incorrect input, try again:");

        }

    }while(choice!=4);

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

bool checkPalindrome_iterative(char input[]){

    int length = (int) strlen(input); // storing the amount of characters in the inputted string

    char stringFlipped[length]; // creating an array to store the inputted string flipped

    for(int i = length-1; i>=0 ; i--){ // looping from the end of the char[] string to the start

        stringFlipped[length-i-1] = input[i]; // storing the flipped string in 'stringFlipped[]'

    }

    for(int i = 0; i<length; i++) { // looping from the start to the end of the arrays

        if (stringFlipped[i] != input[i]) { // if any character in both the original and the flipped string is not the same

            return false;

        }

    }

    return true;

}

bool checkPalindrome_recursive(char input[], int first, int last){

    if(strlen(input) == 0){ // if nothing was inputted

        return true;

    }

    if(first == last){ // if it is a 1 letter input

        return true;

    }

    if(input[first]!=input[last]){ // if the first letter and the last letter are not equal

        return false;

    }

    if(first < last){ // if the position of the first character is less than the position of the last character

        checkPalindrome_recursive(input, first+1, last-1); // using recursion, testing with new positions for the first and last characters

    }

}