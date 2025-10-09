/*
 * Exercise 2: Stack Implementation using Linked List
 * Assignment 7 - IPFCE 2025
 * 
 * Implement all the stack functions declared in include/stack.h
 * The stack should be implemented using a linked list structure.
 * 
 * Functions to implement:
 * - initialize: Create an empty stack
 * - push: Insert an item at the top of the stack
 * - pop: Remove and return the top item
 * - full: Check if stack is full (always false for linked list)
 * - empty: Check if stack is empty
 * - print: Print all items in the stack
 */

#include "stack.h"

/* Create an empty stack */
void initialize(stack *s)
{
    /* pre-condition: true */
    assert(s != NULL);
    s->head = NULL;
    /* post-condition: stack is empty */
}

/* Insert item x at the top of stack s */
void push(int x, stack *s)
{
    /* pre-condition: true (linked list can always accept more items) */
    node *t = malloc(sizeof(node));

    t->data = x;
    t->next = s->head;
    s->head = t;
    /* post-condition: x is added to top of stack */

}

/* Return (and remove) the top item of stack s */
int pop(stack *s)
{
  /* pre-condition: stack must not be empty */
  /* post-condition: top item is removed and returned */
    assert(s != NULL);
    assert(s->head != NULL);

    node *t = s->head;
    int top = t->data;
    s->head = t->next;
    free(t);

    return top;
}

/* Test whether a stack can accept more pushes */
bool full(stack *s)
{
    /* pre-condition: true */
    /* post-condition: Returns true if stack is full, false otherwise */
    return false; /* linked list has no fixed size */
}

/* Test whether a stack can accept more pops */
bool empty(stack *s)
{
    /* pre-condition: true */
    /* post-condition: returns true if stack is empty, false otherwise */
    return(s->head == NULL);
}

/* Print the contents of the stack */
void print(stack *s)
{
    /* pre-condition: true */
    /* post-condition: prints all items in the stack */

    node *t = s->head;

    while(t != NULL){
        printf("%d", t->data);
        t = t->next;
    }
    printf("\n");
}
