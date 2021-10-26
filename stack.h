#ifndef STACK_STACK_H
#define STACK_STACK_H

typedef void* TYPE;

typedef struct STRNODE Node;

typedef struct STRSTACK Stack;

Stack* newStack();
void push(Stack *stack, void *value);
void *pop(Stack *stack);
void *peek(Stack *stack);
void display(Stack *stack);

#endif