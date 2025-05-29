// Given an array of binary digits, find the maximum number of consecutive 1s in the array.

#include <stdio.h>
#include <stdlib.h>

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int max1s = 0, c = 0;
    for (int i=0; i<numsSize; i++) {
        if (nums[i]==1) {
            c++;
            continue;
        }
        max1s = (max1s<c) ? c : max1s;
        c = 0;
    }
    max1s = (max1s<c) ? c : max1s;
    return max1s;
}