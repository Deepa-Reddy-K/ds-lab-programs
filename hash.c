#include<stdio.h>
#define m 10
int ht[m];
int hash(int key) { return key%m; }
void linear_probe(int hk, int key) {
    int i, flag = 0;
    for(i = hk+1; i<m; i++)
        if(ht[i]==-1) {
            ht[i] = key;
            return;
        }
    for(i=0; i<hk; i++)
        if(ht[i]==-1) {
            ht[i] = key;
            return;
        }
    printf("HASH Table is FULL.\n");
}
void main() {
    int n, i, key, hk; FILE *fp; char name[100];
    for(i=0; i<m; i++)
        ht[i] = -1;
    fp = fopen("test.txt", "r");
    while(!feof(fp)) {
        fscanf(fp, "%d%s", &key, name);
        hk = hash(key);
        if(ht[hk]==-1)
            ht[hk] = -1;
        else {
            printf("Collision for key %d\nSolved\n\n", key);
            linear_probe(hk, key);
        }
    }
    printf("----------------------\n");
    printf("       HashTable      \n");
    printf("----------------------\n");
    printf("Address\tKeys\n");
    for(i=0; i<m; i++)
        printf("%2d\t%d\n", i, ht[i]);
}