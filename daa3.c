//Fractional Knapsack
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int weight, value;
}Item;
int compare(const void *a, const void *b) {
    return ((Item *)b)->value - ((Item *)a)->value;
}
void fractionalKnapsack(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), compare);
    double totalValue = 0.0;
    int currentWeight = 0;
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += items[i].value * ((double)remainingCapacity / items[i].weight);
            break;
        }
    }
    printf("Maximum value in the knapsack: %.2lf\n", totalValue);
}
int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    Item items[n];
    printf("Enter the weight and value for each item:\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &items[i].weight, &items[i].value);
    fractionalKnapsack(items, n, capacity);
    return 0;
}