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

// estas funciones YA estan implementadas para su conveniencia (de nada)
// si lo desean pueden implementar sus propios contenedores (ah hackers).

Stack* newStack(); // inicializa un stack nuevo
void*  pop(Stack *s);  // obtiene el siguiente elemento del stack. regresa NULL si este esta vacio.
void   push(Stack *s, void *data); // agrega el elemento data al stack.
void*  peek(Stack *s);  // obtiene el siguiente elemento del stack SIN ELIMINARLO. regresa NULL si este esta vacio.
void invertStack(Stack *s)
{   
    Stack *s2 = newStack();
    Stack *s3 = newStack();

    while(peek(s) != NULL)
    {
        push(s2, pop(s));
    }

    while (peek(s2) != NULL)
    {
        push(s3, pop(s2));
    }
    

    while(peek(s3) != NULL)
    {
        push(s, pop(s3));
    }
}