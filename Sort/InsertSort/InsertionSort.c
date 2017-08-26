#include <stdio.h>

typedef int element;

void insertionSort(element arr[], int n){
  int i, j;
  element next;
  for(i = 1 ; i < n; i++){
    next = arr[i];
    for(j = i-1; j >= 0 && arr[j] > next ; j--) arr[j+1] = arr[j]; //shift
    arr[j+1] = next;
  }
}


int main(int argc, char const *argv[]) {

  element arr[] = {5,3,7,9,4,6,2,99,104,27,335,12,45,23,49,17,34,56};

  for(int i =0 ; i < sizeof(arr)/ sizeof(element); i++){
    printf("%d, ", arr[i]);
  }
  printf("\n" );

  insertionSort(arr, sizeof(arr)/ sizeof(arr[0]));

  for(int i =0 ; i < sizeof(arr)/ sizeof(element);i++){
    printf("%d, ", arr[i]);
  }
  printf("\n");

  return 0;
}
