#include <stdio.h>

struct Item {
    int value;
    int weight;
    float ratio;
};

void sortItems(struct Item items[], int n) {
    int i, j;
    struct Item temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    float W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    float x[n];

    for (i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);

        items[i].ratio = (float)items[i].value / items[i].weight;
        x[i] = 0.0;
    }

    printf("Enter maximum capacity: ");
    scanf("%f", &W);

    sortItems(items, n);

    float totalWeight = 0.0, totalValue = 0.0;

    for (i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= W) {
            x[i] = 1.0;
            totalWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            x[i] = (W - totalWeight) / items[i].weight;
            totalValue += x[i] * items[i].value;
            totalWeight = W;
            break;
        }
    }

    printf("\nItem\tValue\tWeight\tFraction Taken\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%.2f\n", i + 1, items[i].value, items[i].weight, x[i]);
    }

    printf("\nTotal Value = %.2f\n", totalValue);

    return 0;
}
