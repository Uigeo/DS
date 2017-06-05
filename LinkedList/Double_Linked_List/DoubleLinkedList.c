
#include <string.h>

typedef struct _Node{
#include "DoubleLinkedList.h"

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
  deallocateNode(list->head);
  free(list);
}

void deallocateNode(node* n){
  if(n){
    deallocateNode(n->rlink);
    free(n);
  }
}

void insertToHead(D_LinkedList* list, int item){
  node* newNode = createNode();
  newNode->item = item;
  if(list->head == NULL){
    list->head = newNode;
    list->tail = newNode;
  }
  else{
    list->head->llink = newNode;
    newNode->rlink = list->head;
    list->head = newNode;
  }
  list->count++;
}

void insertToTail(D_LinkedList* list, int item){
  node* newNode = createNode();
  newNode->item = item;
  if(list->head == NULL){
    list->head = newNode;
    list->tail = newNode;
  }
  else{
    list->tail->rlink = newNode;
    newNode->llink = list->tail;
    list->tail = newNode;
  }
  list->count++;
}

void insertIndex(D_LinkedList* list, int item, int index){
  if(index > count || index < 0){
    fprintf(stderr, "NoSuchIndex\n" );
    exit(-1);
  }
  node* newNode = createNode();
  newNode->item = item;
  if(index == 0){
    insertToHead(list, item);
  }
  else if(index == list->count){
    insertToTail(list, item);
  }
  else{
    node* cur = list->head;
    for(int i =0 ; i< index ; i++)cur = cur->rlink;
    newNode->llink = cur->llink;
    newNode->rlink = cur;
    cur->llink->rlink = newNode;
    cur->llink = newNode;
  }
}

node* remove(D_LinkedList* list, node* n){
  if(list->head == NULL && list->tail == NULL){
    fprintf(stderr, "NoElementList\n");
    exit(-1);
  }
  node* cur = list->head;
  if(list->head == list->tail){
    free(cur);
    list->head = NULL;
    list->tail = NULL;
  }
  else{
    for( ; cur != n ; cur = cur->rlink);
    cur->rlink->llink = cur->llink;
    cur->llink->rlink = cur->rlink;
    free(cur);
  }
  return cur;
}

node* removeFirst(D_LinkedList* list){
  if(list->head == NULL && list->tail == NULL){
    fprintf(stderr, "NoElementList\n");
    exit(-1);
  }
  node* cur = list->head;
  if(list->head == list->tail){
    free(cur);
    list->head = NULL;
    list->tail = NULL;
  }
  else{
  list->head = cur->rlink;
  cur->rlink->llink = NULL;
  free(cur);
  }
  return cur;
}

node* removeLast(D_LinkedList* list){
  if(list->head == NULL && list->tail == NULL){
    fprintf(stderr, "NoElementList\n");
    exit(-1);
  }
  node* cur = list->tail;
  if(list->head == list->tail){
    free(cur);
    list->head = NULL;
    list->tail = NULL;
  }
  else{
  list->tail = cur->llink;
  cur->llink->rlink = NULL;
  free(cur);
  }
  return cur;
}

node* searchNode(D_LinkedList* list, int item){
  if(list->head == NULL && list->tail == NULL){
    fprintf(stderr, "NoElementList\n");
    exit(-1);
  }
  node* cur;
  for(cur= list->head; cur != NULL; cur = cur->rlink){
    if(cur->item == item ) return cur;
  }
  return cur;
}

node* searchNodeR(D_LinkedList* list, int item){
  if(list->head == NULL && list->tail == NULL){
    fprintf(stderr, "NoElementList\n");
    exit(-1);
  }
  node* cur;
  for(cur= list->tail; cur != NULL; cur = cur->llink){
    if(cur->item == item ) return cur;
  }
  return cur;
}

D_LinkedList* getReverseList(D_LinkedList* list){
  D_LinkedList* newList = createList();
  node* cur = list->head;
  for(;cur != NULL; cur= cur->rlink){
    insertToHead(newList, cur->item);
  }
  return newList;
}

D_LinkedList* getCopyList(D_LinkedList* list){
  D_LinkedList* newList = createList();
  node* cur = list->head;
  for(;cur != NULL; cur= cur->rlink){
    insertToTail(newList, cur->item);
  }
  return newList;
}

node* indexOf(D_LinkedList* list, int index){
  if(list->head == NULL && list->tail == NULL){
    fprintf(stderr, "NoElementList\n");
    exit(-1);
  }
  if(index < 0 || index > list->count){
    fprintf(stderr, "NoSuchIndex\n");
    exit(-1);
  }
  node* cur = list->head;
  for(int i=0 ; i < index ; i++)cur = cur->rlink;
  return cur;
}

int countItem(D_LinkedList* list, int item){
  int count = 0;
  node* cur = list->head;
  for(;cur != NULL; cur = cur->rlink){
    if(cur->item == item)count++;
  }
  return count;
}

void printForward(D_LinkedList* list){
  node* cur = list->head;
  printf("[");
  for(;cur != NULL ; cur = cur->rlink){
    printf("%d", cur->item );
  }
  printf("]\n");
}

void printReverse(D_LinkedList* list){
  node* cur = list->tail;
  printf("[");
  for(;cur != NULL ; cur = cur->llink){
    printf("%d", cur->item );
  }
  printf("]\n");
}
