#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack_2.h"

/* interface functions   */
/* set the stack to empty */
void initMixedStack(MixedStack_t * pstack)
{
    * pstack = NULL;
}

/* returns true if stack is empty */
bool isEmpty(const MixedStack_t * pstack)
{
    if (*pstack == NULL)
        return true;
    else
        return false;
}

/* returns true if stack is full */
bool isFull(const MixedStack_t * pstack)
{
    Node * pt;
    bool full;

    pt = (Node *) malloc(sizeof(Node));

    if (pt == NULL)
        full = true;
    else
        full = false;

    free(pt);

    return full;
}

/* returns number of nodes in the stack*/
unsigned int count(const MixedStack_t * pstack)
{
    unsigned int count = 0;
    Node * pnode = *pstack;    /* set to start of stack */

    while (pnode != NULL)
    {
        ++count;
        pnode = pnode->next;  /* set to next node     */
    }

    return count;
}

/* creates node to hold item and adds it to the end of */
/* the stack pointed to by pstack (slow implementation)  */
bool push(Item item, MixedStack_t * pstack)
{
    Node * pnew;
    Node * scan = *pstack;

    pnew = (Node *) malloc(sizeof(Node));

    if (pnew == NULL)
        return false;     /* quit function on failure  */

    pnew->item = item;
    pnew->next = NULL;

    if (isEmpty(pstack))          /* empty stack, so place */
        *pstack = pnew;         /* pnew at head of stack */
    else
    {
        while (scan->next != NULL)
            scan = scan->next;  /* find end of stack    */

        scan->next = pnew;      /* add pnew to end     */
    }

    return true;
}

/* creates item variable to hold last item so that it gets printed before getting removed */
/* also creates node to hold second to last item and removes the last item after it is printed*/
/* takes in a function called pfunc() as an argument which performs the printing of the last item */
bool pop(MixedStack_t * pstack, void (*pfunc)(Item item))
{
    Item plast;
    Node * scan = *pstack;
    Node * prev = NULL; // create node which points to the previous node of the current one being accessed

    if (isEmpty(pstack))          /* empty stack, so do not remove item */
        return false;
    else
    {
        while (scan->next != NULL) {
            prev = scan;
            scan = scan->next;  /* find end of stack    */
        }

        plast = scan->item;

        putchar('\n');

        (*pfunc)(plast); /* display contents of last item using pfunc()*/

        putchar('\n');

        prev->next = NULL;

        free(scan);
    }

    return true;
}

/* creates item variable to hold last item so that it gets printed */
/* also takes in a function called pfunc() as an argument which */
/* performs the printing of the last item */
bool peek(MixedStack_t * pstack, void (*pfunc)(Item item)){
    Item plast;
    Node * scan = *pstack;

    if (isEmpty(pstack))          /* empty stack, so do not check */
        return false;
    else
    {
        while (scan->next != NULL)
            scan = scan->next;  /* find end of stack    */

        plast = scan->item;

        putchar('\n');

        (*pfunc)(plast); /* display contents of last item using pfunc()*/

        putchar('\n');
    }

    return true;
}

/* sets the whole stack to NULL without freeing up memory resources */
void clear(MixedStack_t * pstack){
    * pstack = NULL;
}

/* free memory allocated by malloc() */
/* set stack pointer to NULL          */
void deinitMixedStack(MixedStack_t * pstack)
{
    Node * psave;

    while (*pstack != NULL)
    {
        psave = (*pstack)->next; /* save address of next node */
        free(*pstack);           /* free current node         */
        *pstack = psave;         /* advance to next node      */
    }
}

/* exports mixed stack elements into a text file */
/* that contains element type and actual element */
void export(MixedStack_t * pstack, void (* pfunc)(FILE *fp, Item item, char * strType)){
    FILE *fp;
    Node * current = *pstack;

    int counter = 0;

    /* declare character array variable which is a string that stores
       the type that the element has e.g. Integer, Character, Double, etc. */
    char stringType[20];

    //text I/O - check whether there is an error after opening file
    if((fp=fopen("mixed_stack.txt","w"))==NULL) // if yes, exit program and print error
    {
        fputs("Something went wrong with mixed_stack.txt!\n", stderr);
        exit(1);
    }

    // if no error is generated, then proceed with while loop

    /* checks whether the current node is empty (NULL) */
    /* if it is not empty, set stringType variable to */
    /* the right type in string form depending on the */
    /* item type of the element */
    while (current->next != NULL) {
        current = current->next;
        counter++;
    }

    for(int i = counter; i >= 0; i--){
        switch(current->item.type){
            case 1: strcpy(stringType, "Integer"); break;
            case 2: strcpy(stringType, "Double"); break;
            case 3: strcpy(stringType, "Long Int"); break;
            case 4: strcpy(stringType, "Long Long Int"); break;
            case 5: strcpy(stringType, "Short"); break;
            case 6: strcpy(stringType, "Unsigned Int"); break;
            case 7: strcpy(stringType, "Long Double"); break;
            case 8: strcpy(stringType, "Float"); break;
            case 9: strcpy(stringType, "Character"); break;
            case 10: strcpy(stringType, "String"); break;
            default: printf("Type error!");
        }

        // perform function pfunc on the item stored in the current node
        pfunc(fp, current->item, stringType);

        counter--;

        current = *pstack;

        int j = 0;
        while (current->next != NULL && j < counter){
            current = current->next;
            j++;
        }
    }



    fclose(fp);

}
