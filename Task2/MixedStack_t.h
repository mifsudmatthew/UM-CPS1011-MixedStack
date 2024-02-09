//
// Created by Mifsud on 24/12/2022.
//

#ifndef TASK2_MIXEDSTACK_T_H
#define TASK2_MIXEDSTACK_T_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct nodeStruct{ // creating a new type for nodes called 'nodeType'

    void * Data; // creating a void pointer in order to accept any data type

    int dataType; // creating a variable to keep track as to what data typed is being used

    struct nodeStruct * previousNode; // creating a pointer to point to the next node in the stack

}nodeType;

typedef nodeType * node; // creating a pointer node due to the stack size being dynamic

typedef struct stackStruct{ // creating a new type for stacks called 'stackType'

    node topNode; // creating a node pointer which will be used to point towards the top node.

}stackType;

typedef stackType * stack; // creating a pointer stack due to the stack size being dynamic

/* function prototypes */

/*
 * operation:       create a new node
 * preconditions:   variable 'data' contains the input from the user (any data type)
 * postconditions:  a new node is created containing the inputted data
 */

node createNode(void * data);

/*
 * operation:       initialise a new mixed stack
 * postconditions:  an empty mixed stack is initialised and returned
 */

stack initMixedStack();

/*
* operation:       add a new node at the top of the stack
* preconditions:   variable 'stack' is the current stack being used, variable 'data' contains the input from the user (any data type)
* postconditions:  the new node created is added to the top of the stack
*/

void push(stack stack, void * data);

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

void * peek(stack stack);

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

/*
 * operation:       print a textual representation of the data in each node of the stack
 * preconditions:   variable 'stack' is the current stack being used
 * postconditions:  a new '.txt' file is created containing a textual representation of the data stored in each node
 */

void export(stack stack);


#endif //TASK2_MIXEDSTACK_T_H
