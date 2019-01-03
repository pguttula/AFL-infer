#include<stdio.h>
#include<stdlib.h>
//Sort elements in the given array
int sortncount(int* array,int low,int mid,int high){
  int * arr1;
  int * arr2;
  int s1 =mid-low+1;
  int s2 = high-mid;
  arr1 = (int *)malloc(sizeof(int)*s1);
  arr2 = (int *)malloc(sizeof(int)*s2);
  for(int i=0;i<s1;i++){
    arr1[i] = array[low+i];
  }
  for(int i=0;i<s2;i++){
    arr2[i] = array[mid+i+1];
  }
  int i=0, j=0;
  for(int k=low;k<=high;k++){
    //copy the rest of the elements from second half
    if(i == s1 && j!=s2){
      array[k] = arr2[j];
      j++;
    }
    //copy the rest of the elements from the first half
    else if(j == s2 && i!=s1){
      array[k] = arr1[i];
      i++;
    }
    else if(arr1[i] <= arr2[j]){
      array[k] = arr1[i];
      i++;
    }
    else{
      array[k] = arr2[j];
      j++;
    }
  }
  return 0;
}

int * merge_sort(int* array, int low, int high){
  if(low < high){
    int mid;
    mid = (low + high)/2;
    merge_sort(array,low,mid);
    merge_sort(array, mid+1,high);
    sortncount(array,low,mid,high);
  }
 return array;
}

int main(){
  int n;
  int *arr;
  //Initialize a pointer to print sorted array
  int *p; 
  //enter the size of an array
  printf("Enter the size of array:");
  scanf("%d", &n);
  arr = (int *)malloc(sizeof(int)*n);
  //read numbers into array
  for(int i=0;i<n;i++){
   /*printf("Enter Element %d :",i);
    scanf("%d", &arr[i]);*/
   arr[i] =rand();
  }
  //print array values
  printf("Elements of the array: \n");
  for(int i=0;i<n;i++){
    printf("%d \n", arr[i]);
  }
 p = merge_sort(arr,0,n-1);
  printf("Elements in the array in sorted order are: \n");
  for(int i=0; i<n; i++){
    printf("%d \n",p[i]);
  }
  return 0;
}
