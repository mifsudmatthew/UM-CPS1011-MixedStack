#include <stdio.h>

#include "MixedStack_t.h"
#include "MixedStack_t.c"

int main() {

int choice; // variable to store the menu input choice
int dataType; // variable used to choose data type to input
float input_f; // float variable as a test input
int input_i; // integer variable as a test input
void * inputData; // variable which is used to push data to the stack
stack stack1; // creating a stack to manipulate

do{

    // Displaying menu options
    printf("\n1.Initialise Mixed Stack\n2.De-Initialise Mixed Stack\n3.Push\n4.Pop\n5.Peek\n6.Clear\n7.Count\n8.is Empty?\n9.is Full?\n10.Export\n11.Exit\n");

    if(scanf("%d", &choice)==1) {// Requesting user's choice

        switch (choice) {

            case 1:

                stack1 = initMixedStack(); // initialising mixed stack

                break;

            case 2:

                deinitMixedStack(stack1); // de-initialising mixed stack

                break;

            case 3:

                if (initialised) {

                    printf("What data type to float (0) or integer (1) ?");

                    if (scanf("%d", &dataType) == 0) {

                        do {

                            while (getchar() != '\n'); // flushing buffer in case of non-integer input

                            printf("Enter a correct value:\n");

                        } while (scanf("%d", &dataType) == 0);

                    }

                    {
                        if (dataType == 0) {

                            float *floatPointer = malloc(sizeof(float)); // allocating memory for an integer data type value

                            printf("Enter an float number:\n");

                            if (scanf("%f", &input_f) == 0) {// requesting user input

                                do {

                                    while (getchar() != '\n'); // flushing buffer in case of non-integer input

                                    printf("Enter a correct value:\n");

                                } while (scanf("%f", &input_f) == 0);

                            }

                            *floatPointer = input_f; // de-referencing 'floatPointer' and storing user input

                            push(stack1, floatPointer); // pushing 'floatPointer' to the stack

                            stack1->topNode->dataType = 0;

                        } else if (dataType == 1) {

                            int *intPointer = malloc(sizeof(int));

                            printf("Enter an integer number:\n");

                            if (scanf("%d", &input_i) == 0) {// requesting user input

                                do {

                                    while (getchar() != '\n'); // flushing buffer in case of non-integer input

                                    printf("Enter a correct value:\n");

                                } while (scanf("%d", &input_i) == 0);

                            }

                            *intPointer = input_i; // de-referencing 'floatPointer' and storing user input

                            push(stack1, intPointer); // pushing 'floatPointer' to the stack

                            stack1->topNode->dataType = 1;

                        } else {

                            printf("Incorrect input.");

                        }

                    }
                } else {

                    printf("Mixed Stack has not been initialised");

                }

                break;

            case 4:

                pop(stack1);  // popping a node from the stack

                break;

            case 5:

                inputData = peek(stack1); // storing the data at the top of the stack in variable 'inputData'

                if(initialised) {

                    if (stack1->topNode != NULL) { // if stack is not empty

                        if (stack1->topNode->dataType == 0) {
                            printf("%.2f\n",*((float *) inputData)); // type casting 'inputData' to the correct data type and outputting it
                        }

                        if (stack1->topNode->dataType == 1) {
                            printf("%d\n",*((int *) inputData)); // type casting 'inputData' to the correct data type and outputting it
                        }

                    } else {

                        printf("Stack is empty\n");

                    }
                }

                break;

            case 6:

                clear(stack1); // emptying the entire stack

                break;

            case 7:

                printf("Count: %d\n", count(stack1)); // outputting the number of nodes in the stack

                break;

            case 8:

                if (isEmpty(stack1)) { // checking whether stack is empty

                    printf("Mixed Stack is empty\n");

                } else {

                    printf("Mixed Stack is not empty\n");

                }

                break;

            case 9:

                if (isFull()) { // checking whether there is enough memory left to create a new node

                    printf("Memory is full\n");

                } else {

                    printf("Memory is not full\n");

                }

                break;

            case 10:

                export(stack1); // exporting stack contents to 'outputFile.txt'

                break;
        }
    }else{

        while (getchar() != '\n'); // flushing buffer in case of non-integer input

    }

}while(choice!=11);

    return 0;
}
