#include <stdio.h>
#include <stdlib.h>


typedef int element;

void swap(element *e1 , element *e2);

void selectionSort(element* arr, int size){
  int min;
  for(int k = 0; k < size-1 ; k++ ){
    min = k;
    for(int i =k+1 ; i < size ; i++){
      if(arr[min] > arr[i]){
        min = i;
      }
    }
    swap(&arr[k], &arr[min]);
  }
}

void swap(element *e1 , element *e2){
  element temp;
  temp = *e1;
  *e1 = *e2;
  *e2 = temp;
}




int main(int argc, char const *argv[]) {

  element arr[] = {5,3,7,9,4,6,2,99,104,27,335,12,45,23,49,17,34,56};

  for(int i =0 ; i < sizeof(arr)/ sizeof(element); i++){
    printf("%d, ", arr[i]);
  }
  printf("\n" );

  selectionSort(arr, sizeof(arr)/ sizeof(arr[0]));

  for(int i =0 ; i < sizeof(arr)/ sizeof(element);i++){
    printf("%d, ", arr[i]);
  }
  printf("\n");

  return 0;
}
