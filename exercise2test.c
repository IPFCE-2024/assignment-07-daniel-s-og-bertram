#include <stdio.h>
#include "stack.h"
#include <assert.h>

stack *copystack(stack *s){ // Function which copies a stack
    
    stack *copy = malloc(sizeof(stack));
    node *current = s->head;

    if(current == NULL){
        initialize(copy);
        return copy;
    }
    node *copyhead = malloc(sizeof(node));
    node *copynext = copyhead;
    copynext->data = current->data;
    copynext->next = NULL;

    while(current->next != NULL){
        copynext->next = malloc(sizeof(node));
        copynext = copynext->next;
        current = current->next;
        copynext->data = current->data;
        copynext->next = NULL;
    }

    copy->head = copyhead;

    return copy;
}

int main(void){
    stack *s = malloc(sizeof(stack));

    // (1) Initialize stack:
    initialize(s);
    assert(s->head == NULL);
    printf("Test 1 successful: Stack initalized successfully.");


    // (2) Test push and pop
    int x = 5;
    int y;
    stack *s0;
    s0 = copystack(s); // Copies stack s

    push(x, s);
    y = pop(s);

    node *s0node = s0->head;
    node *snode = s->head;

    while(s0node != NULL && snode != NULL){ // Compares stack before and after test
        assert(s0node->data == snode->data);
        s0node = s0node->next;
        snode = snode->next;
    }
    assert(s0node == NULL && snode == NULL); // Check if they ended at same length

    

    assert(x == y);

    printf("\nTest 2 successful: x == y and s is the same as before push and pop");

    // (3) Test push, push and pop
    int x0 = 5;
    int x1 = 10;
    int y0;
    int y1;
    s0 = copystack(s);

    push(x0, s);
    push(x1, s);

    y0 = pop(s);
    y1 = pop(s);

    s0node = s0->head;
    snode = s->head;

    while(s0node != NULL && snode != NULL){ // Compares stack before and after test
        assert(s0node->data == snode->data);
        s0node = s0node->next;
        snode = snode->next;
    }
     assert(s0node == NULL && snode == NULL); // Check if they ended at same length

    assert(x0 == y1);
    assert(x1 == y0);

    printf("\nTest 3 successful: x0 == y1 and x1 == y0 and s is the same as before testing");

}
