#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node
{
  void* data;
  struct node* next;
};
typedef struct node Node;

struct stack
{
  Node* head;
};
typedef struct stack Stack;

void display(Stack *stack)
{
    Node *focusNode = stack->head;

    while(focusNode != NULL)
    {
        printf("%d ", *(int*)(focusNode->data));
        focusNode = focusNode->next;
    }
    printf("\n");
}

Stack* newStack()
{
  Stack *s = malloc(sizeof(Stack));
  s->head = NULL;
  return s;
}

Node* newNode(void *data)
{
  Node* n = malloc(sizeof(Node));
  n->data = data;
  n->next = NULL;
  return n;
}

void push(Stack* s, void* data)
{
  Node* n = newNode(data);
  n->next = s->head;
  s->head = n;
}

void* pop(Stack* s)
{
  if(s->head == NULL)
    return NULL;

  Node* toDel = s->head;
  void* toRet = s->head->data;
  s->head = s->head->next;
  free(toDel);

  return toRet;
}

void* peek(Stack* s)
{
  if(s->head == NULL)
    return NULL;
  return s->head->data;
}

void invertStack(Stack *s)
{   
    Stack *s2 = s;

    while(peek(s) != NULL)
    {
        push(s2, pop(s));
    }

    while(peek(s2) != NULL)
    {
        push(s, pop(s2));
    }
}