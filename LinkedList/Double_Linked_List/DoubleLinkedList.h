
#ifndef Double_Linked_List_h
#define Double_Linked_List_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 0
#define FALSE 0

typedef struct _Node{
  int item;
  _Node* rlink;
  _Node* llink;
}node;

typedef struct _DLinkedList{
    _Node* head;
    _Node* tail;
    int count;
}D_LinkedList;


D_LinkedList* createList();

node* createNode();

void destroyList(D_LinkedList* list);

void deallocateNode(node* n);

void insertToHead(D_LinkedList* list, int item);

void insertToTail(D_LinkedList* list, int item);

void insertIndex(D_LinkedList* list, int item, int index);

node* remove(D_LinkedList* list, node* n);

node* removeFirst(D_LinkedList* list);

node* removeLast(D_LinkedList* list);

node* searchNode(D_LinkedList* list, int item);

node* searchNodeR(D_LinkedList* list, int item);

D_LinkedList* getReverseList(D_LinkedList* list);

D_LinkedList* getCopyList(D_LinkedList* list);

node* indexOf(D_LinkedList* list, int index);

int countItem(D_LinkedList* list, int item);

void printForward(D_LinkedList* list);

void printReverse(D_LinkedList* list);

#endif /* Double_LinkedList_h */
