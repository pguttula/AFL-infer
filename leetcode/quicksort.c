#include<stdio.h>
#include<stdlib.h>
//quicksort with pivot as the first element of the array
int partition(int* array, int pivot, int high){
  int i=pivot;
  for(int j=i+1; j<= high; j++){
    if(array[j] < array[pivot]){
      //swap array[i] and array[j]
      i++;
      int temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
  }
  int temp1 = array[pivot];
  array[pivot] = array[i];
  array[i] = temp1;
  return i;
}
void quicksort(int* array, int low, int high){
  if(low<high){
    int pivot= low;
  //  int position = (low+high)/2;
    int position = partition(array,pivot,high);
    quicksort(array,low,position);
    quicksort(array,position+1,high);
  }
}
void printvalues(int* array,int n){
  for(int i=0;i<n;i++){
    printf("%d \n",array[i]);
  }
}
int main(){
  int n;
  int * arr;
  int *p;
  printf("Enter the number of elements in the array: \n");
  scanf("%d", &n);
  int l=0, h=n-1;
  arr = (int *)malloc(sizeof(int) * n);
  for(int i=0;i<n;i++){
    /*printf("Enter array input %d \n",i);
    scanf("%d",&arr[i]);*/
    arr[i] = rand(); 
 }
  printf("Elements in the array are: \n");
  printvalues(arr,n);
  quicksort(arr,l,h);
  printf("Elements in the array after sorting: \n");
  printvalues(arr,n);
}
