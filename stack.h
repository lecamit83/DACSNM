#ifndef _stack_h_
#define _stack_h_
#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
struct stack {
  char* value;
  struct stack* next;
};

struct stack* create () {
  struct stack* s = NULL; 
  return s;
}

int isEmpty (struct stack* s) {
  return s == NULL;
}

char* pop(struct stack** s) {
  if(isEmpty(*s)) {
    return "$";
  }
  struct stack* node = *s;
  (*s) = (*s)->next;
  node->next = NULL;
  char* value = strdup(node->value);
  free(node);
  return value;
}

char* peek (struct stack* s) {
  if(isEmpty(s)) return "$";
  return s->value;
}

void push(struct stack** s, char* op) {
  struct stack* node = (struct stack*) malloc(sizeof(struct stack)); 
  struct stack* last = *s;
  node->value = strdup(op);
  node->next = last;
  *s = node;
}



void printStack (struct stack* s) {
  // check for stack underflow 
  while (s != NULL) { 
    printf("%s", s->value);
    // assign temp link to temp 
    s = s->next; 
  } 
  printf("\n");
}




#endif 