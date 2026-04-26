Aim:
To implement the First Fit algorithm for the Bin Packing problem in C and determine the minimum number of bins required to store items without exceeding bin capacity.

Program:
    
#include <stdio.h>

// Function to implement First Fit Bin Packing
void firstFit(int items[], int n, int capacity)
{
    int bin[n];        // Array to store remaining capacity of each bin
    int binCount = 0;  // Keeps track of number of bins used

    printf("\nExecuting First Fit Algorithm\n");

    // Initialize all bins as empty (0 used initially)
    for (int i = 0; i < n; i++)
        bin[i] = 0;

    // Traverse through each item
    for (int i = 0; i < n; i++)
    {
        // If item size exceeds bin capacity, it cannot be placed
        if(items[i] > capacity) {
            printf("Item %d with size %d cannot be placed in any bin\n", i + 1, items[i]);
            continue; 
        }
        
        int placed = 0;  // Flag to check if item is placed

        // Try to fit item into an existing bin
        for (int j = 0; j < binCount; j++)
        {
            // Check if current bin has enough space
            if (bin[j] >= items[i])
            {
                bin[j] -= items[i];  // Reduce remaining capacity
                printf("Item %d placed in Bin %d\n", items[i], j + 1);
                placed = 1;
                break;           
            }
        }

        // If item was not placed in any existing bin
        if (!placed)
        {
            // Create a new bin and place item in it
            bin[binCount] = capacity;
            bin[binCount] -= items[i];
            printf("Item %d placed in Bin %d\n", items[i], binCount + 1);
            binCount++;
        }
    }

    // Print total number of bins used
    printf("Total bins used = %d\n", binCount);
}


int main()
{
    int n, capacity;

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    int items[n];  // Array to store item sizes

    // Input item sizes
    printf("Enter item sizes:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d", &items[i]);
    }

    // Input bin capacity
    printf("Enter bin capacity: ");
    scanf("%d", &capacity);   

    // Call First Fit function
    firstFit(items, n, capacity);

    return 0;
}
Output:
Enter number of items: 6
Enter item sizes:
Item 1: 3
Item 2: 5
Item 3: 1
Item 4: 5
Item 5: 9
Item 6: 3
Enter bin capacity: 10

Executing First Fit Algorithm
Item 3 placed in Bin 1
Item 5 placed in Bin 1
Item 1 placed in Bin 1
Item 5 placed in Bin 2
Item 9 placed in Bin 3
Item 3 placed in Bin 2
Total bins used = 3
