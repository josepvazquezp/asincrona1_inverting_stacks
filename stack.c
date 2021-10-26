#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct STRNODE{
    TYPE data;
    struct STRNODE *prior;
};

struct STRSTACK{
    struct STRNODE *top;
    int size;
};

Stack* newStack()
{
    Stack *newStack = malloc(sizeof(Stack));

    newStack->top = NULL;
    newStack->size = 0;

    return newStack;
}

void display(Stack *stack)
{
    Stack *focusNode = stack;
    int i = focusNode->size;

    while(i != 0 && focusNode->top->prior != NULL)
    {
        printf("%d\n", (int)(focusNode->top->data));
        focusNode->top = focusNode->top->prior;
        i--;
    }
}

void push(Stack *stack, void *value)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->prior = stack->top;

    stack->size += 1;
    stack->top = newNode;
}

void *pop(Stack *stack)
{
    if(stack->size != 0)
    {
        Node *temp = stack->top;
        void *n = stack->top->data;

        stack->top = stack->top->prior;
        free(temp);
        stack->size--;

        return n;
    }
    else
        return NULL;
}

void *peek(Stack *stack)
{
    if(stack == NULL)
        printf("Esta vacia\n");
    else
        return stack->top->data;

    return NULL;
}