//0-1 knapsack
#include <stdio.h>
int max(int a, int b) 
{
    return (a > b) ? a : b;
}
int knapsack(int capacity, int weights[], int values[], int n) {
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++)
        for (int w = 0; w <= capacity; w++)
            dp[i][w] = (i == 0 || w == 0) ? 0 : (weights[i - 1] <= w) ? max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]) : dp[i - 1][w];

    return dp[n][capacity];
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];

    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; scanf("%d", &weights[i++]));

    printf("Enter the values of the items:\n");
    for (int i = 0; i < n; scanf("%d", &values[i++]));

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    printf("Maximum value in the knapsack: %d\n", knapsack(capacity, weights, values, n));

    return 0;
}