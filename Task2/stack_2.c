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
    Node * pnode = *pstack;    /* set to start of list */

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

    if (isEmpty(pstack))          /* empty list, so place */
        *pstack = pnew;         /* pnew at head of list */
    else
    {
        while (scan->next != NULL)
            scan = scan->next;  /* find end of list    */

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

    if (isEmpty(pstack))          /* empty list, so do not remove item */
        return false;
    else
    {
        while (scan->next != NULL) {
            prev = scan;
            scan = scan->next;  /* find end of list    */
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

    if (isEmpty(pstack))          /* empty list, so place */
        return false;
    else
    {
        while (scan->next != NULL)
            scan = scan->next;  /* find end of list    */

        plast = scan->item;

        putchar('\n');

        (*pfunc)(plast); /* display contents of last item using pfunc()*/

        putchar('\n');
    }

    return true;
}

/* visit each node and execute function pointed to by pfunc */
void Traverse  (const MixedStack_t * pstack, void (* pfunc)(Item item) )
{
    Node * pnode = *pstack;    /* set to start of list   */

    while (pnode != NULL)
    {
        (*pfunc)(pnode->item); /* apply function to item */
        putchar('\n');
        pnode = pnode->next;  /* advance to next item   */
    }
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
/* contains element type and actual element         */
void export(MixedStack_t * pstack, void (* pfunc)(FILE *fp, Item item, char * strType)){
    FILE *fp;
    Node * current = *pstack;

    char stringType[20];

    //text I/O
    if((fp=fopen("mixed_stack.txt","w"))==NULL)
    {
        fputs("Something went wrong with mixed_stack.txt!\n", stderr);
        exit(1);
    }

    while (current != NULL){
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
        pfunc(fp, current->item, stringType);
        current = current->next;
    }

    fclose(fp);

}
