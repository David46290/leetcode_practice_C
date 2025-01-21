#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize)
{
    int current_min=prices[0], best_profit=0;
    for (int i=1; i<pricesSize; i++)
    {
        int current_profit = prices[i] - current_min;
        // update best profit if reach one
        if (current_profit > best_profit) best_profit = current_profit;
        // update minimum buying price if reach one
        if (prices[i] < current_min) current_min = prices[i];
    }
    return best_profit;
}

int main(void)
{
    int pricesSize = 0;
    printf("length: ");
    scanf("%d", &pricesSize);
    int *prices = malloc(pricesSize * sizeof(int));

    for(int i=0; i<pricesSize; i++)
    {
        printf("nums[%d] = ", i);
        scanf("%d", prices+i); // prices+i is the address of nums[i]
    }

    printf("nums = [");
    for(int i=0; i<pricesSize-1; i++)
    {
        printf("%d,", *(prices+i));
    }
    printf("%d", *(prices+pricesSize-1));
    printf("]\n");

    int ans = maxProfit(prices, pricesSize);
    printf("max profit: %d", ans);

    return 0;
}