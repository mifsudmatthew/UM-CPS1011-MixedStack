//
// Created by Mifsud on 25/12/2022.
//

#ifndef TASK2_MIXEDSTACK_T_0_H
#define TASK2_MIXEDSTACK_T_0_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct nodeStruct{ // creating a new type for nodes called 'nodeType'

    // creating a union which can take the form of 1 of 2 data types, int or char [64].
    union Data {
        int integerData;
        char stringData[64];
    }nodeData;

    int unionType; // creating a variable to keep track which form the union 'nodeData' is taking form ( 0 = int , 1 = char [64] )

    struct nodeStruct * previousNode; // creating a pointer to point to the next node in the stack

}nodeType;

typedef nodeType * node; // defining a 'nodeType' pointer type due to the stack size being dynamic

typedef struct stackStruct{ // creating a new type for stacks called 'stackType'

    node topNode; // creating a node pointer which will be used to point towards the top node.

}stackType;

typedef stackType * stack; // defining a 'stackType' pointer type due to the stack size being dynamic

/* function prototypes */

/*
 * operation:       create a new node
 * preconditions:   variable 'data' contains the input from the user (int or char[64])
 * postconditions:  a new node is created containing the inputted data
 */

node createNode(union Data data);

/*
 * operation:       initialise a new mixed stack
 * postconditions:  an empty mixed stack is initialised and returned
 */

stack initMixedStack();

/*
 * operation:       add a new node at the top of the stack
 * preconditions:   variable 'stack' is the current stack being used, variable 'data' contains the input from the user (int or char[64])
 * postconditions:  the new node created is added to the top of the stack
 */

void push(stack stack, union Data data);

/*
 * operation:       remove node at the top of the stack
 * preconditions:   variable 'stack' is the current stack being used
 * postconditions:  the stack's top node is deleted, and the stack now points to the previous node
 */

void pop(stack stack);

/*
 * operation:       the stack is emptied from all nodes
 * preconditions:   variable 'stack' is the current stack being used
 * postconditions:  the stack executes the pop() function until the stack points to NULL
 */

void clear(stack stack);

/*
 * operation:       de-initialise a mixed stack
 * preconditions:   variable 'stack' is the current stack being used
 * postconditions:  the memory contains the stack is freed and therefore the stack is removed
 */

void deinitMixedStack(stack stack);

/*
 * operation:       get the data stored in the top node of the stack
 * preconditions:   variable 'stack' is the current stack being used
 * postconditions:  if the stack is not empty the data stored in the top node of the stack is returned
 */

union Data peek(stack stack);

/*
 * operation:       get the amount of nodes stored in the stack
 * preconditions:   variable 'stack' is the current stack being used
 * postconditions:  the number of nodes in the stack is returned after traversing through each node and counting each node
 */

int count(stack stack);

/*
 * operation:       check if stack is empty
 * preconditions:   variable 'stack' is the current stack being used
 * postconditions:  if the function stack() == 0, then true is returned otherwise false is returned
 */

bool isEmpty(stack stack);

/*
 * operation:       check if memory is full
 * preconditions:   variable 'stack' is the current stack being used
 * postconditions:  if a new node can be created then false is returned otherwise true is returned
 */

bool isFull();

#endif //TASK2_MIXEDSTACK2_H
