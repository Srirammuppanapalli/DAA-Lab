#include <stdio.h>
int fib(int n){  
    if (n==0){
        return 0;
    }
    if (n==1) {
        return 1;
    }
    fib(n-1)+fib(n-2);
    return fib(n-1)+fib(n-2); 
}  
int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    if (n<0){
        printf("invalid number");
        return 0;
    }
    printf("fibanoacci term is :%d",fib(n));
    return 0;
}

Output:
Enter the number of terms: 9
fibanoacci term is :34
