Aim:
To implement Quick Sort algorithm using randomized pivot selection in C to sort an array of integers efficiently.
 
Program:

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function (places pivot in correct position)
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];  // Pivot element
    int i = (low - 1);      // Index of smaller element

    for (int j = low; j < high; j++)
    {
        // If current element is smaller than pivot
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // Place pivot in correct position
    swap(&arr[i + 1], &arr[high]);

    return (i + 1);
}

// Quick Sort function with randomized pivot
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Select random pivot to avoid worst case
        int randomIndex = low + rand() % (high - low + 1);

        // Swap random pivot with last element
        swap(&arr[randomIndex], &arr[high]);

        // Partition the array
        int pi = partition(arr, low, high);

        // Recursively sort left and right subarrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n;

    // Seed random number generator
    srand(time(NULL));

    // Input number of elements
    printf("Enter number of elements: ");

    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int numbersToSort[n];

    // Input array elements
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &numbersToSort[i]);

    // Call Quick Sort
    quickSort(numbersToSort, 0, n - 1);

    // Print sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", numbersToSort[i]);

    return 0;
}

Output:
Enter number of elements: 4
Enter 4 integers: 2 5 7 9

Sorted array: 2 5 7 9 
