#include<stdio.h>
#include<stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *sol = (int*)malloc(2*sizeof(int));
    int i=0;
    while(i<numsSize) {
        int j;
        for(j=i; j<numsSize; j++) {
            if(nums[i]+nums[j] == target) {
                sol[0] = i;
                sol[1] = j;
                return sol;
            }
        }
        i++;
    }
    printf("Failed!");
    exit(0);
}

int main() {
  int nums[4] = {2, 7, 11, 15};
  int *sol = twoSum(nums, 4, 9);
  printf("[%d,%d]\n",sol[0],sol[1]);
  free(sol);
  return 0;
}
