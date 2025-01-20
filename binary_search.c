#include <stdio.h>
#include <stdlib.h>

int search(int* nums, int numsSize, int target)
{
    for (int i=0; i<numsSize; i++)
    {
        if (nums[i] == target) return i;
    }
    return -1;
}

int search2(int* nums, int numsSize, int target) // split-in-half method (time O(logn))
{
    int left_idx = 0, right_idx = numsSize - 1;
    int loop_count = 0;
    while (left_idx <= right_idx)
    {
        int middle_idx = (left_idx + right_idx) / 2;
        // check whether the middle element is target
        // if it's bigger than the target => we need to go backward (left side)
        //      left_idx not changed, but new right_idx becomes the middle_idx
        // if it's smaller than the target => we need to go forward (right side)
        //      right_idx not changed, but new left_idx becomes the middle_idx
        if (nums[middle_idx] == target)
        {
            loop_count++;
            return middle_idx;
        }  
        // if no -/+ 1 for right/left idx
        // the loop will stuck at where middle_idx = left idx
        // and the left_idx will always be smaller than right_idx
        else if (nums[middle_idx] > target)
        {
            right_idx = middle_idx - 1 ; // -1 because the current middle_idx is out of search range
        }
        else
        {
            left_idx = middle_idx + 1 ; // +1 because the current middle_idx is out of search range
        }

        loop_count++;
    }
    printf("it takes %d loops to finish the job\n", loop_count);
    return -1;
}

int main(void)
{
    int numsSize = 0;
    printf("length: ");
    scanf("%d", &numsSize);
    int *nums = malloc(numsSize * sizeof(int));

    for(int i=0; i<numsSize; i++)
    {
        printf("nums[%d] = ", i);
        scanf("%d", nums+i); // nums+i is the address of nums[i]
    }

    printf("nums = [");
    for(int i=0; i<numsSize-1; i++)
    {
        printf("%d,", *(nums+i));
    }
    printf("%d", *(nums+numsSize-1));
    printf("]\n");

    int target = 0;
    printf("target: ");
    scanf("%d", &target);

    int ans = search2(nums, numsSize, target);

    if (ans == -1)
    {
        printf("target %d is not in nums", target);
    }
    else
    {
        printf("target %d is nums[%d]", target, ans);
    }

    return 0;
}