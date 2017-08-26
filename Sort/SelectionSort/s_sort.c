#include <stdio.h>



typedef int element;

void swap(element* e1, element* e2);

void selectionSort(element arr[], int n){
  int i ,j, min_index;

  for( i =0; i < n-1 ; i++){
    min_index = i;
    for( j = i+1 ; j < n ; j++ ){
      if(arr[min_index] > arr[j]) min_index = j;
    }
    swap(&arr[min_index], &arr[i]);
  }
}

void swap(element* e1, element* e2){
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
