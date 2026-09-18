#include <stdio.h>
int max(int a, int b)
{
    return (a > b) ? a : b;
}
void knapsack(int n, int weight[], int profit[], int capacity)
{
    int i, w;
    int K[20][20]; // DP table
    // Build table K[][] in bottom-up manner
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weight[i - 1] <= w)
                K[i][w] = max(profit[i - 1] + K[i - 1][w - weight[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    printf("\nMaximum Profit = %d", K[n][capacity]);
    // Display selected items
    printf("\nSelected Items: ");
    w = capacity;
    for (i = n; i > 0 && w > 0; i--)
    {
        if (K[i][w] != K[i - 1][w])
        {
            printf("Item%d ", i);
            w = w - weight[i - 1];
        }
    }
}
void main()
{
    int n, i, capacity;
    int weight[10], profit[10];
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weights of items: ");
    for (i = 0; i < n; i++)
        scanf("%d", &weight[i]);
    printf("Enter profits of items: ");
    for (i = 0; i < n; i++)
        scanf("%d", &profit[i]);
    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);
    printf("\n--- 0/1 Knapsack using Dynamic Programming ---\n");
    knapsack(n, weight, profit, capacity);
    printf("\n\nProgram executed successfully!");
}