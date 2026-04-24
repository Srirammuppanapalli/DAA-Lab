#include <stdio.h>
void toh(int diskcount, char s, char d, char t){
    if (diskcount==1)
    {
        printf(" \n move disk %d from %c to %c",diskcount,s,d);
    return;
}
 toh(diskcount-1,s,t,d);
 printf(" \n move disk %d from %c to %c",diskcount,s,d);
 toh(diskcount-1,t,d,s);
}
int main() {
    int n;
    printf("enter number of disks: ");
    scanf("%d",&n);
    toh(n,'s','d','t');
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
