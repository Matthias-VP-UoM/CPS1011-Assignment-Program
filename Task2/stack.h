//
// Created by mvass on 22/12/2022.
//

#ifndef TASK2_STACK_H
#define TASK2_STACK_H

#include <stdbool.h>     /* C99 feature         */


/* program-specific declarations */

#define STRSIZE      64    /* size of array to hold string element  */

/* setting a struct called element which stores the element in both integer and string format
   up to the maximum size initialized by the constant STRSIZE above */

typedef struct element
{
    int type;
    int elementInt;
    char elementStr[STRSIZE];
} Element;

/* general type definitions */

typedef Element Item;

typedef struct node
{
    Item item;
    struct node * next;
} Node;



typedef Node * MixedStack_t;



/* function prototypes */



/* operation:        initialize a stack                          */

/* preconditions:    pstack points to a stack                     */

/* postconditions:   the stack is initialized to empty           */

void initMixedStack(MixedStack_t * pstack);



/* operation:        determine if stack is empty                 */

/*                   pstack points to an initialized mixed stack        */

/* postconditions:   function returns True if mixed stack is empty     */

/*                   and returns False otherwise                */

bool isEmpty(const MixedStack_t *pstack);



/* operation:        determine if mixed stack is full                  */

/*                   pstack points to an initialized mixed stack        */

/* postconditions:   function returns True if mixed stack is full      */

/*                   and returns False otherwise                */

bool isFull(const MixedStack_t *pstack);



/* operation:        determine number of items in mixed stack          */

/*                   pstack points to an initialized mixed stack        */

/* postconditions:   function returns number of items in mixed stack   */

unsigned int count(const MixedStack_t *pstack);



/* operation:        add item to end of mixed stack                    */

/* preconditions:    item is an item to be added to mixed stack        */

/*                   pstack points to an initialized mixed stack        */

/* postconditions:   function adds item to end of mixed stack    */

/*                   and returns True; otherwise the    */

/*                   function returns False                     */

bool push(Item item, MixedStack_t * pstack);



/* operation:        print out and remove last item from mixed stack    */

/* preconditions:    pstack points to an initialized mixed stack        */

/*                   pfunc points to a function that takes an    */

/*                   Item argument and has no return value      */

/* postcondition:    the function pointed to by pfunc is         */

/*                   executed once for the last item in the mixed stack    */

/*                   which is removed after its contents are printed out    */

bool pop(MixedStack_t * pstack, void (*pfunc)(Item item));



/* operation:        print out but NOT remove last item from mixed stack    */

/* preconditions:    pstack points to an initialized mixed stack        */

/*                   pfunc points to a function that takes an    */

/*                   Item argument and has no return value      */

/* postcondition:    the function pointed to by pfunc is         */

/*                   executed once for the last item in the mixed stack    */

bool peek(MixedStack_t * pstack, void (*pfunc)(Item item));



/* operation:        remove all items from mixed stack                  */

/* preconditions:    pstack points to a mixed stack                     */

/* postconditions:   the state of the mixed stack is reset to empty     */

void clear(MixedStack_t * pstack);



/* operation:        free allocated memory, if any              */

/*                   pstack points to an initialized mixed stack        */

/* postconditions:   any memory allocated for the mixed stack is freed   */

/*                   and the mixed stack is set to empty               */

void deinitMixedStack(MixedStack_t * pstack);


#endif //TASK2_STACK_H
