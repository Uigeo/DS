#include <stdio.h>
#include <stdlib.h>

typedef int elements;

void swap(elements* e1, elements* e2);
int partition(elements arr[], int begin, int end);

void quickSort(elements arr[], int begin, int end){
  int p;
  if(begin < end){
    p = partition(arr, begin, end);
    quickSort(arr, begin, p-1);
    quickSort(arr, p+1, end);
  }
}

int partition(elements arr[], int begin, int end){
  int pivot, left, right;
  left = begin;
  right = end;
  pivot = (int)((begin + end)/2.0);

  while(left < right){
    while(arr[left] < arr[pivot] && left < right)left++;
    while(arr[pivot] <= arr[right] && left < right)right--;
    if(left < right){
      swap(&arr[left], &arr[right]);
      if(left == pivot) pivot = right;
    }
  }
  swap(&arr[pivot], &arr[right]);
  return right;
}

void swap(elements* e1, elements* e2){
  elements temp;
  temp = *e1;
  *e1 = *e2;
  *e2 = temp;
}



int main(int argc, char const *argv[]) {

  elements arr[] = {5,3,7,9,4,6,2,99,104,23,335,12,45,23,45,12,34,56};

  for(int i =0 ; i < sizeof(arr)/ sizeof(elements); i++){
    printf("%d, ", arr[i]);
  }
  printf("\n" );

  quickSort(arr , 0, sizeof(arr) / sizeof(elements)-1);

  for(int j =0 ; j < sizeof(arr)/ sizeof(elements);j++){
    printf("%d, ", arr[j]);
  }
  printf("\n" );

  return 0;
}
