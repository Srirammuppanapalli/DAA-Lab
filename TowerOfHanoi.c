Program:
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
