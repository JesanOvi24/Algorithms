#include<stdio.h>

int dp[1001][2001] ;

int max(int a, int b)
{
    if(a>b) return a ;
    return b ;
}
int knapsack(int weight[], int val[], int cap, int n)
{
    int i, j ;
    for(i = 0 ; i <= n ; i++)
        dp[i][0] = 0 ;
    for(i = 0 ; i <= cap ; i++)
        dp[0][i] = 0 ;

    for(i = 1 ; i <= n ; i++){
        for(j = 1 ; j <= cap ; j++){
            if(weight[i] <= j){
                dp[i][j] = max(val[i]+dp[i-1][j-weight[i]] , dp[i-1][j]) ;
            }
            else{
                dp[i][j] = dp[i-1][j] ;
            }
        }
    }




    for(i = 0 ; i <= n ; i++){
        for(j = 0 ; j <= cap ; j++){
            printf("%d ", dp[i][j]) ;
        }
        printf("\n") ;
    }
    return dp[n][cap] ;
}
int main()
{
    int n, i, weight[100], val[100], cap ;

    scanf("%d", &n) ;
    for(i = 1 ; i <= n ; i++){
        scanf("%d %d", &weight[i], &val[i]) ;
    }
    scanf("%d", &cap) ;

    int profit = knapsack(weight, val, cap, n) ;
    printf("%d\n", profit) ;
    return 0 ;
}
/*
5
2 10
7 15
1 4
10 18
4 12

10

*/
