#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    
    result[0] = 0;
    result[1] = 1;
    return result;
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
        scanf("%d", nums+i);
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
    int ansSize = 2;
    int *returnSize = &ansSize;
    int *ans = twoSum(nums, numsSize, target, returnSize);

    printf("result = [");
    for(int i=0; i<ansSize-1; i++)
    {
        printf("%d,", *(ans+i));
    }
    printf("%d", *(ans+ansSize-1));
    printf("]\n");

    free(nums);
    free(ans);
    return 0;
}