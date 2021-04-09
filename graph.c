#include<stdio.h>
int a[10][10], visit[10], n;
void dfs(int i) {
    int j=0;
    visit[i] = 1;
    printf("\n%d", i);
    while(j<n) {
        if(!visit[j] && a[i][j]==1)
            dfs(j);
        j++;
    }
}
void main() {
    int i, j;
    printf("Enter the no. of nodes : ");
    scanf("%d", &n);
    for(i=0; i<n; i++)//Initialize visit array to 0
        visit[i]=0;
    printf("Enter the adjacency matrix : \n");
    for(i=0; i<n; i++)//Read adjacency matrix
        for(j=0; j<n; j++)
            scanf("%d", &a[i][j]);
    printf("Enter the starting node : ");
    scanf("%d", &i);
    printf("DFS : \n");
    dfs(i);
}