#include<stdio.h>
#include<string.h>

int max(int a, int b){
    if(a>b) return a ;
    return b ;
}
int lcs(char x[], char y[], int n, int m){

    if(n == 0 || m == 0){
        return 0 ;
    }

    if(x[n-1] == y[m-1]){
        return 1+lcs(x, y, n-1, m-1) ;
    }
    else return max(lcs(x, y, n, m-1), lcs(x, y, n-1, m)) ;
}
int main()
{
    char x[100], y[100] ;
    int n, m;
    gets(x) ;
    gets(y) ;

    n = strlen(x) ;
    m = strlen(y) ;

    int len = lcs(x, y, n, m) ;
    printf("%d", len) ;
}
