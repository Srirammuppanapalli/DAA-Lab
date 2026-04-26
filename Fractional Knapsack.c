Aim:
To implement the Fractional Knapsack algorithm using a greedy approach in C to maximize profit based on value-to-weight ratio.

Program:
#include <stdio.h>

// Structure to store item details
struct Item {
    int weight;   // वजन (weight of item)
    int value;    // मूल्य (value of item)
    float ratio;  // value/weight ratio
};

// Function to sort items in descending order of ratio (Greedy step)
void sort(struct Item items[], int n) {
    struct Item temp;

    // Bubble sort based on ratio
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            // Swap if current item's ratio is less than next
            if (items[j].ratio < items[j + 1].ratio) {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    int capacity;

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    // Input weight and value of each item
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value of item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);

        // Calculate value-to-weight ratio
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    // Input knapsack capacity
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort items based on ratio (highest first)
    sort(items, n);

    float totalProfit = 0.0;  // Store maximum profit

    // Apply greedy approach
    for (int i = 0; i < n; i++) {

        // If item can be fully included
        if (capacity >= items[i].weight) {
            totalProfit += items[i].value;
            capacity -= items[i].weight;
        } 
        else {
            // Take fractional part of item
            totalProfit += items[i].ratio * capacity;
            break;  // Knapsack is full
        }
    }

    // Output maximum profit
    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}

Output:
Enter number of items: 6
Enter weight and value of item 1: 3 4
Enter weight and value of item 2: 2 3
Enter weight and value of item 3: 5 6
Enter weight and value of item 4: 7 8
Enter weight and value of item 5: 2 20
Enter weight and value of item 6: 9 91
Enter knapsack capacity: 20
Maximum profit = 122.80
