#include<stdio.h>
char str[100], pat[100], rep[100];
void fnr() {
    int i, j, c, k, m, occ = 0;
    char res[100];
    i = m = c = j = 0;
    while(str[c]!='\0') {
        if(str[m]==pat[i]) {
            i++; m++;
            if(pat[i]=='\0') {//If found
                occ++;
                printf("\nPattern found at %d\n\n", c);
                for(k=0; rep[k]!='\0'; k++, j++)//Cpoy replace string to result
                    res[j] = rep[k];
                i = 0; c = m;
            }
        }
        else {
            res[j] = str[c];
            j++; c++;
            m = c;
            i = 0;
        }
    }
    res[j] = '\0';
    if(occ) {
        printf("Occurences : %d\n", occ);
        printf("Resultant :\n%s\n", res);
    }
    else
        printf("Not Found\n");
}
void main() {
    printf("Enter the Main string : ");
    scanf("%s", str);
    printf("Enter the pattern : ");
    scanf("%s", pat);
    printf("Enter the string to replace : ");
    scanf("%s", rep);
    fnr();
}
