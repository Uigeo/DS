#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define IS_EMPTY(Lstack) (!(Lstack->top))

typedef int element;

typedef struct _Node{
  element item;
  struct _Node* link;
}node;

typedef struct LinkedListSatck{
  node* top;
}L_stack;

L_stack* createStack(){
  L_stack* newStack = (L_stack*)malloc(sizeof(L_stack));
  if(newStack == NULL){
    printf("It's failed to initilize to memory");
    exit(-1);
  }
  newStack->top = NULL;
  return newStack;
}

node* createNode(element item){
  node* newNode = (node*)malloc(sizeof(node));
  if(newNode == NULL){
    printf("It's failed to initilize to memory");
    exit(-1);
  }
  newNode->link = NULL;
  newNode->item = item;
  return newNode;
}

void push(L_stack* s ,element item){
  node* newNode = createNode(item);
  newNode->link = s->top;
  s->top = newNode;
}

element pop(L_stack* s){
  if(IS_EMPTY(s)){
    printf("The Stack is empty");
    exit(-1);
  }
  node* cur = s->top;
  element temp = cur->item;
  s->top = cur->link;
  free(cur);
  return temp;
}

element peek(L_stack* s){
  if(IS_EMPTY(s)){
    printf("The Stack is empty");
    exit(-1);
  }
  return s->top->item;
}

int length(L_stack* s){
  int l;
  node* cur;
  for(cur = s->top, l =0; cur != NULL ; cur=cur->link , l++);
  return l;
}

void printStack(L_stack* s){
  node* cur;
   printf("[" );
  for(cur = s->top; cur != NULL; cur= cur->link){
    printf("%d, ", cur->item );
  }
  printf("]\n" );
}


int main(int argc, char const *argv[]) {
  L_stack* s = createStack();
  push(s, 2);
  printStack(s);
  push(s, 5);
  printStack(s);
  push(s, 1);
  printStack(s);
  push(s, 9);
  printStack(s);
  push(s, 11);
  printStack(s);
  push(s, 15);
  printStack(s);

  printf("%d\n", length(s));

  pop(s);
  printStack(s);
  pop(s);
  printStack(s);
  pop(s);
  printStack(s);
  pop(s);
  printStack(s);

  printf("%d\n",peek(s) );

  return 0;
}
