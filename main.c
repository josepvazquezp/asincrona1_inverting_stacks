#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    Stack *stack = newStack();
    int nums[] = {1,2,3,4,5};
    
    for(int i=0; i<5;i++)
    {
        push(stack, nums + i);
    }

    display(stack);
    
    invertStack(stack);
 
    display(stack);
    

    return 0;
}