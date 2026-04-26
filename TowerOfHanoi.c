Aim:
To implement the Tower of Hanoi problem using recursion in C and display the sequence of moves required to transfer disks from source to destination.

Program:
#include <stdio.h>

// Function to solve Tower of Hanoi
void toh(int diskcount, char s, char d, char t){
    
    // Base case: if only one disk, move it directly
    if (diskcount == 1)
    {
        printf("\nMove disk %d from %c to %c", diskcount, s, d);
        return;
    }

    // Step 1: Move n-1 disks from source (s) to temporary (t)
    toh(diskcount - 1, s, t, d);

    // Step 2: Move the largest disk from source to destination
    printf("\nMove disk %d from %c to %c", diskcount, s, d);

    // Step 3: Move n-1 disks from temporary (t) to destination (d)
    toh(diskcount - 1, t, d, s);
}

int main() {
    int n;

    // Input number of disks
    printf("Enter number of disks: ");
    scanf("%d, &n);

    // Call Tower of Hanoi function
    toh(n, 'S', 'D', 'T');  // S = Source, D = Destination, T = Temporary

    return 0;
}
Output:
enter number of disks: 4
 
 move disk 1 from s to t 
 move disk 2 from s to d 
 move disk 1 from t to d 
 move disk 3 from s to t 
 move disk 1 from d to s 
 move disk 2 from d to t 
 move disk 1 from s to t 
 move disk 4 from s to d 
 move disk 1 from t to d 
 move disk 2 from t to s 
 move disk 1 from d to s 
 move disk 3 from t to d 
 move disk 1 from s to t 
 move disk 2 from s to d 
 move disk 1 from t to d
