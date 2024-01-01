
/*
Minimum numbers of coin to make the change using dp.
Coin supply is infinite.
*/


#include<stdio.h>
int a[100], dp[100][100] ;
int min(int x, int y){
    if(x < y) return x ;
    return y ;
}
void trace(int i, int j){
    if(dp[i][j] == 0) return ;
    if(dp[i][j] == dp[i-1][j])
        i-- ;
    else
    {
        printf("%d ", a[i-1]) ;
        int temp = dp[0][j] ;
        j = temp - a[i-1] ;
    }
    trace(i , j) ;

}
int main()
{
    int  sum, i, j, n ;
    scanf("%d", &n) ;

    for(i = 0 ; i < n ; i++){
        scanf("%d", &a[i]) ;
    }
    scanf("%d", &sum) ;


    for(i = 1 ; i <= sum ; i++){
        dp[0][i] = i ;
    }
    for(i = 0 ; i <= n ; i++){
        dp[i][0] = 0 ;
    }

    for(i = 1 ; i <= n ; i++){
        for(j = 1 ; j <= sum ; j++){
            if(a[i-1] > j)
                dp[i][j] = dp[i-1][j] ;
            else
                dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-a[i-1]] );
        }
    }

    for(i = 0 ; i <= n ; i++){
        for(j = 0 ; j <= sum ; j++)
            printf("%d ", dp[i][j]) ;
        printf("\n") ;
    }

    printf("minimum number of coin: %d\n", dp[n][sum]) ;

    trace(n, sum) ;
}
