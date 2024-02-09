#include <stdio.h>
#include "MixedStack_t_0.c"

int main() {

int choice; // variable to store the menu input choice
union Data inputData; // data to be sent to the mixed stack
int type; // variable to determine whether the input is string or integer ( 0 = integer | 1 = string )
char tempString[64]; // variable to store the string input
stack stack1; // creating a stack to manipulate

do{
    // Displaying menu options
    printf("\n1.Initialise Mixed Stack\n2.De-Initialise Mixed Stack\n3.Push\n4.Pop\n5.Peek\n6.Clear\n7.Count\n8.Is Stack Empty?\n9.Is Stack Full? \n10.Exit\n");

    if(scanf("%d", &choice)==1) { // Requesting user's choice


        switch (choice) {

            case 1:

                stack1 = initMixedStack(); // initialising mixed stack

                break;

            case 2:

                deinitMixedStack(stack1); // de-initialising mixed stack

                break;

            case 3:
                if (initialised) {

                    printf("Choose integer (0) or string (1)");

                    if (scanf("%d", &type) == 0) { // requesting user input for data type choice

                        do {

                            while (getchar() != '\n'); // flushing buffer in case of non-integer input

                            printf("Enter a correct value:\n");

                        } while (scanf("%d", &type) == 0);

                    }
                    if (type == 0) {

                        printf("Enter an integer:\n");

                        if (scanf("%d", &inputData.integerData) ==0) { // requesting user input for the data to add to the stack
                            do {

                                while (getchar() != '\n'); // flushing buffer in case of non-integer input

                                printf("Enter a correct value:\n");

                            } while (scanf("%d", &inputData.integerData) == 0);
                        }
                        push(stack1, inputData); // pushing user input to the stack

                        stack1->topNode->unionType = 0; // indicating the union type as an integer

                    } else if (type == 1) {

                        printf("Enter a string:\n");

                        while (getchar() != '\n'); // Clearing buffer from previous input

                        fgets(tempString, sizeof tempString,stdin); // Limiting user string input to 64 characters INCLUDING the null terminator.

                        tempString[strlen(tempString) -1] = '\0'; // Adding a null terminator manually to the end of the string

                        strcpy(inputData.stringData, tempString); // adding the inputted data to

                        push(stack1, inputData); // pushing user input to stack

                        stack1->topNode->unionType = 1; // indicating the union type as a String / char[64]

                    } else {

                        printf("Incorrect input.\n");

                    }
                } else {

                    printf("Mixed Stack has not been initialised");

                }
                break;

            case 4:

                pop(stack1); // popping a node from the stack

                break;

            case 5:

                inputData = peek(stack1); // storing the data at the top of the stack in variable 'inputData'

                if(initialised) {

                    if (stack1->topNode != NULL) { // if stack is not empty

                        if (stack1->topNode->unionType == 0) { // if union is in 'int' mode

                            printf("%d", inputData.integerData); // outputting the data in 'inputData'

                        } else if (stack1->topNode->unionType == 1) { // if union is in 'char[64]' mode

                            printf("%s", inputData.stringData); // outputting the data in 'inputData'

                        }


                    } else {

                        printf("%d\n", inputData.integerData); // if stack is empty -1 is returned

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

        }
    }else{

        while(getchar() != '\n'); // Clearing buffer from previous input

    }

}while(choice!=10);

    return 0;

}
