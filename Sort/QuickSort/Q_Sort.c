#include <stdio.h>
#define SWAP( x, y ) { x=x^y; y=x^y; x=x^y; }



typedef int element;


void quickSort(element arr[], int left, int right){
  int pivot, i, j;
  if(left < right){
    i = left;
    j = right+1;
    pivot = arr[left];
    do {
      do { i++;}while(arr[i] < pivot && left < right);
      do { j--;}while(arr[j] > pivot && left < right);
      if(i<j) SWAP(arr[i], arr[j]);
    } while(i < j);
    SWAP(arr[i], arr[j]);

    quickSort(arr, left, j-1);
    quickSort(arr, j+1, right);
  }
}


int main(int argc, char const *argv[]) {

  element arr[] = {5,3,7,9,4,6,2,99,104,23,335,12,45,23,45,12,34,56};

  for(int i =0 ; i < sizeof(arr)/ sizeof(element); i++){
    printf("%d, ", arr[i]);
  }
  printf("\n" );

  quickSort(arr , 0, (sizeof(arr) / sizeof(element))-1);

  for(int j =0 ; j < sizeof(arr)/ sizeof(element);j++){
    printf("%d, ", arr[j]);
  }
  printf("\n" );

  return 0;
}
