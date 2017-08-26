#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int Element;

typedef struct Node{
  Element item;
  struct Node * link;
}Qnode;

typedef struct _Queue{
  Qnode* head;
  Qnode* tail;
}Queue;


Queue* createQueue(){
  Queue* newQ;
  newQ = (Queue*)malloc(sizeof(Queue));
  newQ->head = NULL;
  newQ->tail = NULL;
  return newQ;
}

Qnode* createNode(Element item){
  Qnode* newNode = (Qnode*)malloc(sizeof(Qnode));
  newNode->item = item;
  newNode->link = NULL;
}

void push(Queue* q, Element item){
  Qnode* newNode = createNode(item);
  if(isEmpty(q)){
    q->head = newNode;
    q->tail = newNode;
  }
  else{
    q->tail->link = newNode;
    tail = newNode;
  }
}

void printQ(Queue* q){
  Qnode* cur;
  printf("[");
  for(cur = q->head ; cur != NULL ; cur=cur->link){
    printf("%d, ",cur->item);
  }
  printf("]");
}

Element pop(Queue* q){
  Element temp;
  Qnode* cur;
  temp = q->head->item;
  cur = q->head;
  q->head = q->head->link;
  free(cur);
  return temp;
}

int isEmpty(Queue* q){
  if(q->head == NULL || q->tail ==NULL)return TRUE;
  return FALSE;
}

int getCount(Queue* q){
  Qnode* cur;
  int count = 0;
  p
  for(cur = q->head ; cur != NULL ; cur=cur->link){
    count++;
  }
  return count;
}

int main(int argc, char const *argv[]) {

  return 0;
}
