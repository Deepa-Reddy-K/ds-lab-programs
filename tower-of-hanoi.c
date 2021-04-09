#include<stdio.h>
int count = 0;
void toh(int n, char source, char temp, char dest) {
    if(n==1)
    {
        printf("Move disk 1 from %c to %c.\n", source, dest); count++;
        return;
    }
    toh(n-1, source, dest, temp);
    printf("Move disk %d from %c to %c.\n", n, source, dest); count++;
    toh(n-1, temp, source, dest);
}
void main() {
    int n; char std[4];
    printf("Enter the no. of disks : ");
    scanf("%d", &n);
    printf("Enter the names of Source, Temporary and Destination : ");
    scanf("%s", std);
    toh(n, std[0], std[1], std[2]);
    printf("Total no. of moves : %d", count);
}