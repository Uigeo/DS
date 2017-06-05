
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node{
  int item;
  _Node* rlink;
  _Node* llink;
}node;

typedef struct _DLinkedList{
    _Node* head;
}D_LinkedList;
