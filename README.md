#### Developed by Matthew Mifsud.

The directory contains the following folders:

* **Task1**

    * cmake-build-debug

* **Task2**

    * cmake-build-debug

## 1. Problem Solving. (Task1)

The Task1 folder contains the following files:

* **1a.c :** Implementation of a function that computes integer matrix multiplication.

* **1b.c :** Implementations of an iterative and recursive function that test whether an input is a palindrome or not.

* **1c.c :** A program that repeatedly asks the user the execute either of the functions created in '`1a.c`' and '`1b.c`'.

* **CMakeLists.txt**

## 2. A Mixed Stack Library. (Task2)

The Task2 folder contains the following files:

* **2a.c :** A test driver program for question 2(a), which tests a Mixed Stack data type (using `MixedStack_t_0.h` and `MixedStack_t_0.c`) supporting a mix of integers and fixed-sized 64 character strings.

* **MixedStack_t_0.h :** Declarations of all functions and structs. 

    Types defined:
    * **nodeType :** A struct which is used as a new node type.
        * **nodeData :** A union which stores `int` or `char[64]` data.
        * **unionType :** An integer variable which is used to indicate the current state of the union. If `unionType = 0` then union is `int`, otherwise if `unionType = 1` the union is `char[64]`.
        * **previousNode :** A pointer used to point at the previous node in the stack.
    * **stackType :** A struct which is used as a new stack type.
        * **topNode :** A pointer used to point to the node at the top of the stack. 

    Methods defined:
    *  **createNode :** Creates a new node containing the user's input.
    * **initMixedStack :** Initialises a mixed stack and returns it.
    * **deinitMixedStack :** De-initialises a mixed stack.
    * **push :** Adds a new node at the top of the stack.
    * **pop :** Removes the node at the top of the stack.
    * **peek :** Returns the data stored in the node at the top of the stack.
    * **clear :** Removes all nodes currently in the stack.
    * **count :** Returns the number of nodes that are currently in the stack.
    * **isEmpty :** Returns whether the stack is empty `true` or not `false`.
    * **isFull :** Returns whether memory is full `true` or  not `false`.

* **MixedStack_t_0.c :** Implementation of the functions defined in `MixedStack_t_0.h`
    *  **createNode :** Allocates memory for a new node, fills it with the user's input and returns it.
    * **initMixedStack :** Allocates memory for a new mixed stack and returns it.
    * **deinitMixedStack :** De-allocates memory being used for the stack.
    * **push :** Creates a new node and changes the stack pointer towards the new node.
    * **pop :** If the stack is not empty the stack pointer is set to point towards the previous node and the memory allocated for the popped node is freed.
    * **peek :** Returns the data stored in the node at the top of the stack.
    * **clear :** Each node in the stack is popped until the stack is empty.
    * **count :** The stack is traversed and each node is counted until the end is reached. The count is then returned.
    * **isEmpty :** If the stack size is 0 then `true` is returned, otherwise `false` is returned.
    * **isFull :** If a new node cannot be created `true` is returned otherwise `false` is returned. 

* **2b.c :** A test driver program for questions 2(b) & 2(c), which tests a Mixed Stack data type (using `MixedStack_t.h` and `MixedStack_t.c`) supporting any data type.

* **MixedStack_t.h :** Declarations of all functions and structs.

    Types defined:
    * **nodeType :** A struct which is used as a new node type.
        * **nodeData :** A void pointer used to store any data type.
        * **previousNode :** A pointer used to point at the previous node in the stack.
    * **stackType :** A struct which is used as a new stack type.
        * **topNode :** A pointer used to point to the node at the top of the stack. 

    Methods defined:
    *  **createNode :** Creates a new node containing the user's input.
    * **initMixedStack :** Initialises a mixed stack and returns it.
    * **deinitMixedStack :** De-initialises a mixed stack.
    * **push :** Adds a new node at the top of the stack.
    * **pop :** Removes the node at the top of the stack.
    * **peek :** Returns the data stored in the node at the top of the stack.
    * **clear :** Removes all nodes currently in the stack.
    * **count :** Returns the number of nodes that are currently in the stack.
    * **isEmpty :** Returns whether the stack is empty `true` or not `false`.
    * **isFull :** Returns whether memory is full `true` or  not `false`.
    * **export :** Creates a `.txt` file with a textual representation of the contents in the stack.

* **MixedStack_t.c :** Implementation of the functions defined in `MixedStack_t.h`
  
    *  **createNode :** Allocates memory for a new node, fills it with the user's input and returns it.
    * **initMixedStack :** Allocates memory for a new mixed stack and returns it.
    * **deinitMixedStack :** De-allocates memory being used for the stack.
    * **push :** Creates a new node and changes the stack pointer towards the new node.
    * **pop :** If the stack is not empty the stack pointer is set to point towards the previous node and the memory allocated for the popped node is freed.
    * **peek :** Returns the data stored in the node at the top of the stack.
    * **clear :** Each node in the stack is popped until the stack is empty.
    * **count :** The stack is traversed and each node is counted until the end is reached. The count is then returned.
    * **isEmpty :** If the stack size is 0 then `true` is returned, otherwise `false` is returned.
    * **isFull :** If a new node cannot be created `true` is returned otherwise `false` is returned. 
    * **export :** The stack is traversed until the end is reached, and the contents of each node are written to the text file `outputFile.txt`.
* **CMakeLists.txt**

The cmake-build-debug folder in Task2 contains 3 important files:

* **`libMixedStack_t.dll` :** Mixed stack library.

* **`libMixedStack_t.dll.a` :** Mixed stack library.

* **`outputFile.txt` :** Text file containing a textual representation of the data exported from the mixed stack.