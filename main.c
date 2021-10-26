#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void invertStack(Stack *s)
{
}

int main()
{
    Stack *stack = newStack();
    int nums[] = {1,2,3,4,5};
    
    for(int i=0; i<5;i++)
    {
        push(stack, nums+i);
    }

    pop(stack); // perdemos el 5

    while(peek(stack) != NULL)
    {
        printf("[%d]", *(int*)pop(stack));
    }

    return 0;
}