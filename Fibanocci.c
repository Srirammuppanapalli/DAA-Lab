Aim:
To write a C program that calculates the n-th Fibonacci number using recursion.
Program:
#include <stdio.h>

// Function to calculate Fibonacci number using recursion
int fib(int n){  
    // Base case: if n is 0, return 0
    if (n == 0){
        return 0;
    }

    // Base case: if n is 1, return 1
    if (n == 1) {
        return 1;
    }

    // Recursive case: sum of previous two Fibonacci numbers
    return fib(n-1) + fib(n-2); 
}  

int main() {
    int n;

    // Prompt user to enter number
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Check for invalid input (negative number)
    if (n < 0){
        printf("Invalid number");
        return 0;
    }

    // Display the nth Fibonacci term
    printf("Fibonacci term is: %d", fib(n));

    return 0;
}

Output:
Enter the number of terms: 9
fibanoacci term is :34
