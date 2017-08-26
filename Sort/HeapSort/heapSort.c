#include <stdio.h>
#include <stdlib.h>

typedef int element;

void swap(element* e1, element*e2);
void adjust(element arr[], int h, int m);

void heapSort(element arr[], int n){
  n--;
  for(int i = n/2; i > 0; i-- ){
    adjust(arr, i, n);
  }
  for(int i = n-1; i > 0 ; i--){
    swap(&arr[1], &arr[i+1]);
    adjust(arr, 1 ,i);
  }
}

void adjust(element arr[], int root, int n){
  int child, rootkey;
  element temp = arr[root];
  rootkey = arr[root];
  child = 2*root;
  while(child <= n){
    if((child < n) && (arr[child] < arr[child+1])) //right child is larger
      child++;
    if(rootkey > arr[child]){
      break;
    }
    else{
      arr[child/2] = arr[child];
      child *=2;
    }
  }
  arr[child/2] = temp;
}

void swap(element* e1, element*e2){
  element temp;
  temp = *e1;
  *e1 = *e2;
  *e2 = temp;
}


int main(int argc, char const *argv[]) {

  element arr[] = {0,3,7,9,4,6,2,99,104,23,335,12,45,23,45,12,34,56};
  for(int i =0 ; i < sizeof(arr)/ sizeof(element); i++){
    printf("%d, ", arr[i]);
  }
  printf("\n" );

  heapSort(arr ,sizeof(arr)/ sizeof(element));

  for(int i =0 ; i < sizeof(arr)/ sizeof(element);i++){
    printf("%d, ", arr[i]);
  }
  printf("\n");


  return 0;
}
