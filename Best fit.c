#include <stdio.h>
void bestFit(int items[], int n, int capacity)
{
    printf("\nBest Fit Algorithm\n");
    int bin[n];
    int binCount = 0;
    for (int i = 0; i < n; i++)
        bin[i] = capacity;
    for (int i = 0; i < n; i++)
    {
        int bestIndex = -1;
        int minSpace = capacity + 1;
        for (int j = 0; j < binCount; j++)
        {
            if (bin[j] >= items[i] && (bin[j] - items[i]) < minSpace)
            {
                bestIndex = j;
                minSpace = bin[j] - items[i];
            }
        }
        if (bestIndex != -1)
        {
            bin[bestIndex] -= items[i];
            printf("Item %d (weight: %d) placed in Bin %d\n", i + 1, items[i], bestIndex + 1);
        }
        else
        {
            bin[binCount] -= items[i];
            printf("Item %d (weight: %d) placed in Bin %d\n", i + 1, items[i], binCount + 1);
            binCount++;
        }
    }
    printf("Total bins used = %d\n", binCount);
}
int main()
{
    int n, capacity,itemSize;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter bin capacity: ");
    scanf("%d", &capacity);
    int items[n];
    printf("Enter item sizes:\n");
    for (int i = 0; i < n; i++)
    {
         printf("Item %d: ", i + 1);
            scanf("%d", &itemSize);
            if (itemSize <= capacity)
            {
                items[i] = itemSize;
            }
            else
            {
                printf("Item size exceeds bin capacity. Please enter again.\n");
            }
        }
   
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






