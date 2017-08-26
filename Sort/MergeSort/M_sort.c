#include <stdio.h>

typedef int element;
 element sorted[100];


void merge(element a[] , int begin, int middle, int end){
  int t ,j, k, i;
  i =begin;
  k =begin;
  j = middle+1;
  while(i <= middle && j<= end){
    if(a[i] < a[j]) sorted[k++] = a[i++];
    else sorted[k++] = a[j++];
  }
  if(i > middle){
    for(t=j ; t <= end ; t++) sorted[k++] = a[t];
  }
  else{
    for(t=i ; t<= middle ; t++)sorted[k++] = a[t];
  }
 for(t = begin; t <= end; t++, k++)a[t] = sorted[t];
}


void mergeSort(element a[], int begin, int end){
  int middle;
  if(begin < end){
    middle = (begin + end)/2;
    mergeSort(a , begin , middle);
    mergeSort(a, middle+1, end);
    merge(a, begin, middle, end);
  }
}

int main(int argc, char const *argv[]) {
  element arr[] = {5,3,7,9,4,6,2,99,104,23,335,12,45,23,45,12,34,56};

  for(int i =0 ; i < sizeof(arr)/ sizeof(element); i++){
    printf("%d, ", arr[i]);
  }
  printf("\n" );

  mergeSort(arr , 0, sizeof(arr) / sizeof(element)-1);

  for(int j =0 ; j < sizeof(arr)/ sizeof(element);j++){
    printf("%d, ", sorted[j]);
  }
    printf("\n" );

  for(int i =0 ; i < sizeof(arr)/ sizeof(element); i++){
    printf("%d, ", arr[i]);
  }


  printf("\n" );

  return 0;


  return 0;
}
