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
    Node *focusNode = stack->top;
    int i = stack->size;

    while(i != 0 && focusNode != NULL)
    {
        printf("%d ", *(int*)(focusNode->data));
        focusNode = focusNode->prior;
        i--;
    }
    printf("\n");
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

void invertStack(Stack *s)
{   
    void *temp;
    int i = 0;
    int backup = s->size;
    Node *focusNode = s->top;
    int a[100];

    while(focusNode != NULL)
    {
        a[i] = *(int*)focusNode->data;
        focusNode= focusNode->prior ;
        i++;
    }

    for(i = 0 ; i < backup ; i++)
        pop(s);

    for(i = 0 ; i < backup ; i++)
    {
        temp = &a[i];
        push(s, temp);
    }
}