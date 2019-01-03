//Given an array of integers, return indices of the two numbers such that they add up to a specific target
#include<stdio.h>
int main(){
int nums[4] = {12,7,11,2};
int numsSize = 2;
int target = 9;
  for(int i=0;i<4;i++){
    for(int j=1;j<3;j++){
      if(nums[i] + nums[j] == target){
        printf("array ele at position %d is %d \n",i,nums[i]);
        printf("array ele at position %d is %d \n",j,nums[j]);
      }
    }
  }
int *num;
num = &nums[0];
num++;
printf("%d \n", *num);
return 0;
}
