
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
    _Node* tail;
    int count;
}D_LinkedList;


D_LinkedList* createList(){
  D_LinkedList* newList = (D_LinkedList*)malloc(sizeof(D_LinkedList));
  newList->head = NULL;
  newList->tail = NULL;
  newList->count = 0;
  return newList;
}

node* createNode(){
  node* newNode = (node*)malloc(sizeof(node));
  newNode->item =0;
  newNode->llink = NULL;
  newNode->rlink = NULL;
  return newNode;
}

void destroyList(D_LinkedList* list){

}

void insertToHead(D_LinkedList* list, int item){

}

void insertToTail(D_LinkedList* list, int item){

}

node* deleteNode(D_LinkedList* list, node* n){

}

node* searchNode(D_LinkedList* list, int item){

}

node* searchNodeR(D_LinkedList* list, int item){

}

D_LinkedList* getReverseList(){

}

D_LinkedList* getCopyList(){

}

void printForward(D_LinkedList* list){

}

void printReverse(D_LinkedList* list){

}
