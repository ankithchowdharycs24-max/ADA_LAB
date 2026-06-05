#include <stdio.h>

struct Item {
    int profit;
    int weight;
    float ratio;
};

int main() {
    int n;
    float capacity, totalProfit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item item[n];

    printf("Enter profit and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &item[i].profit, &item[i].weight);
        item[i].ratio = (float)item[i].profit / item[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (item[i].ratio < item[j].ratio) {
                struct Item temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (capacity >= item[i].weight) {
            totalProfit += item[i].profit;
            capacity -= item[i].weight;
        } else {
            totalProfit += item[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum Profit = %.2f\n", totalProfit);

    return 0;
}