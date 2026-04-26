Aim
To implement the Best Fit Bin Packing Algorithm in C, which places each item into the bin that leaves the least remaining space after insertion, thereby optimizing space utilization and minimizing the number of bins used.
#include <stdio.h>

// Function to implement Best Fit algorithm
void bestFit(int items[], int n, int capacity)
{
    printf("\nBest Fit Algorithm\n");

    // Array to store remaining capacity of bins
    int bin[n];

    // Tracks number of bins used
    int binCount = 0;

    // Initialize all bins with full capacity
    for (int i = 0; i < n; i++)
        bin[i] = capacity;

    // Traverse through each item
    for (int i = 0; i < n; i++)
    {
        int bestIndex = -1;          // Stores index of best bin
        int minSpace = capacity + 1; // Minimum leftover space

        // Check all existing bins
        for (int j = 0; j < binCount; j++)
        {
            // If item fits and leaves minimum space
            if (bin[j] >= items[i] && (bin[j] - items[i]) < minSpace)
            {
                bestIndex = j;
                minSpace = bin[j] - items[i];
            }
        }

        // If a suitable bin is found
        if (bestIndex != -1)
        {
            bin[bestIndex] -= items[i]; // Reduce available space
            printf("Item %d (weight: %d) placed in Bin %d\n", i + 1, items[i], bestIndex + 1);
        }
        else
        {
            // Create a new bin
            bin[binCount] -= items[i];
            printf("Item %d (weight: %d) placed in Bin %d\n", i + 1, items[i], binCount + 1);
            binCount++;
        }
    }

    // Print total bins used
    printf("Total bins used = %d\n", binCount);
}

int main()
{
    int n, capacity, itemSize;

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    // Input bin capacity
    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    int items[n];

    printf("Enter item sizes:\n");

    // Input item sizes with validation
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d", &itemSize);

        // Ensure item does not exceed bin capacity
        if (itemSize <= capacity)
        {
            items[i] = itemSize;
        }
        else
        {
            printf("Item size exceeds bin capacity. Please enter again.\n");
            i--; // Repeat input for same item
        }
    }

    // Call Best Fit function
    bestFit(items, n, capacity);

    return 0;
}

Output:

Enter number of items: 5
Enter bin capacity: 7
Enter item sizes:
Item 1: 2
Item 2: 3
Item 3: 4
Item 4: 5
Item 5: 1

Best Fit Algorithm
Item 1 (weight: 2) placed in Bin 1
Item 2 (weight: 3) placed in Bin 1
Item 3 (weight: 4) placed in Bin 2
Item 4 (weight: 5) placed in Bin 3
Item 5 (weight: 1) placed in Bin 1
Total bins used = 3






