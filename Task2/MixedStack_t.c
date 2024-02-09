//
// Created by Mifsud on 27/12/2022.
//

#include <stdio.h>
#include <stdlib.h>

#include "MixedStack_t.h"

bool initialised = false; // variable to keep track of initialisation

node createNode(void * data){

    node newNode; // creating a new node

    newNode = (node) malloc(sizeof(nodeType)); // allocating memory for the new node

    newNode -> previousNode = NULL; // setting the new node to point to NULL

    newNode -> Data = data; // setting the new node with the data inputted by the user

    return newNode;

}

stack initMixedStack(){

    stack newStack; // creating a new mixed stack

    newStack = (stack) malloc(sizeof(stackType)); // allocating memory for the new stack

    newStack -> topNode = NULL; // setting the new mixed stack's top node as NULL

    initialised = true; // updating the 'initialised' variable

    printf("Mixed Stack has been initialised\n");

    return newStack;

}

void push(stack stack, void * data){

    if(initialised) { // if mixed stack is initialised

        node newNode = createNode(data); // creating a new node with the inputted data

        newNode->previousNode = stack->topNode; // setting the node on top of the stack as the previous node

        stack->topNode = newNode; // setting the newly created node as the top node of the stack

    }else{

        printf("Mixed Stack has not been initialised\n");

    }

}

void pop(stack stack){

    if(initialised) { // if mixed stack is initialised

        node poppedNode;

        if (stack->topNode != NULL) { // if stack is not empty

            poppedNode = stack->topNode; // setting the variable 'poppedNode', as the node at the top of the stack

            stack->topNode = stack->topNode->previousNode; // updating the top node as the previous node in the stack

            free(poppedNode); // de-allocating memory for the node to be removed

            printf("Node popped from stack\n");

        }else{

            printf("Mixed Stack is empty\n");

        }

    }else{

        printf("Mixed Stack has not been initialised\n");

    }

}

void clear(stack stack){

    if(initialised) { // if mixed stack is initialised

        while (stack->topNode != NULL) { // looping until the stack is empty

            pop(stack); // removing the node at the top of the stack

        }

    }else{

        printf("Mixed Stack has not been initialised");

    }

}

void deinitMixedStack(stack stack){

    if(initialised) { // if mixed stack is initialised

        free(stack); // de-allocating the memory for the stack

        initialised = false;

        printf("Mixed Stack has been de-initialised\n");

    }else{

        printf("\nMixed Stack has not been initialised\n");

    }

}

void * peek(stack stack){

    if(initialised) { // if mixed stack is initialised

        if (stack->topNode == NULL) {

            void * emptyData = "-1"; // setting the data to return as "-1"

            return emptyData;

        } else {

            return stack->topNode->Data; // returning the data at the top of the stack

        }

    }else{

        void * emptyData = "-1"; // setting the data to return as "-1"

        printf("Mixed Stack has not been initialised\n");

        return emptyData;

    }

}

int count(stack stack){

    if(initialised) { // if mixed stack is initialised

        node currentNode;

        int nodes = 0;

        currentNode = stack->topNode; // creating a copy of the node at the top of the stack

        while (currentNode != NULL) { // looping until the end of the stack is reached

            currentNode = currentNode->previousNode; // updating 'currentNode' to the previous node in the stack

            nodes++; // adding 1 to variable nodes

        }

        return nodes;

    }else{

        printf("Mixed Stack has not been initialised\n");

        return -1;

    }

}

bool isEmpty(stack stack){

    if(initialised) { // if mixed stack is initialised

        if (count(stack) == 0) { // if stack is empty

            return true;

        } else {

            return false;

        }

    }else{

        printf("Stack has not been initialised\n");

        return true;

    }

}

bool isFull(){

    if(initialised) { // if mixed stack is initialised

        void * emptyData = "-1";

        node testNode = createNode(emptyData); // creating a temporary test node

        if (testNode == NULL) { // if a new node cannot be created, NULL is returned

            return true;

        } else {

            free(testNode); // de-allocating the memory for the test node

            return false;

        }

    }else{

        printf("Mixed Stack has not been initialised\n");

        return false;

    }

}

void export(stack stack){

    if(initialised) {

        FILE *filePointer; // creating a new FILE pointer

        node currentNode = stack->topNode;  // creating a copy of the node at the top of the stack

        filePointer = fopen("outputFile.txt","w"); // opening a file 'outputFile.txt' and storing its pointer in variable 'filePointer'

        while (currentNode != NULL) { // loop until the end of the stack is reached

            fwrite(currentNode->Data, sizeof(currentNode->Data), 1,filePointer); // write a textual representation of the data in 'currentNode' to 'outputFile.txt'

            fprintf(filePointer, "\n"); // skipping a line in 'outputFile.txt'

            currentNode = currentNode->previousNode; // updating 'currentNode' to the previous node in the stack

        }

        fclose(filePointer); // closing 'outputFile.txt'

    }else{

        printf("Mixed Stack has not been initialised\n");

    }

}