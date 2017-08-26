#include <stdio.h>
#define MAX 30

typedef int element;


element sorted[MAX];

void merge(element a[], int m, int middle, int n){

  int i, j, k ,t;
  i =m;
  j =middle +1;
  k = m;

  while(i<=middle && j <=n){
    if(a[i] <= a[j]) sorted[k++] = a[i++];
    else  sorted[k++] = a[j++];
  }
  if(i>middle){
    for(t=j; t<=n; t++, k++)sorted[k] = a[t];
  }
  else{
    for(t=i; t <= middle ; t++, k++)sorted[k] = a[t];
  }
  for(t =m ;t <= n ; t++, k++)a[t]= sorted[t];
}

void mergeSort(element a[], int m, int n){
  int middle;
  if(m<n){
    middle = (m+n)/2;
    mergeSort(a, m, middle);
    mergeSort(a, middle+1, n);
    merge(a,m,middle,n);
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
    printf("%d, ", arr[j]);
  }
  printf("\n" );

  return 0;
}
