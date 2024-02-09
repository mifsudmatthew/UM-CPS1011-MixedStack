#include <stdbool.h>
#include <string.h>


bool checkPalindrome_iterative(char input[]);
bool checkPalindrome_recursive(char input[], int first, int last);

int main() {
    return 0;
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