
#include<stdio.h>
#include <string.h>

int dp[1001][2001] ;

int max(int a, int b){
    if(a>b) return a ;
    return b ;
}
int knapsack(int weight[], int val[] , int cap, int n)
{
    if(n == 0 || cap == 0) return 0 ;

    if(dp[n][cap] != -1) return dp[n][cap] ;

    if(weight[n] <= cap){
        return dp[n][cap] = max(val[n]+knapsack(weight, val, cap-weight[n], n-1) , knapsack(weight, val, cap, n-1)) ;
    }
    else if(weight[n] > cap){
        return dp[n][cap] = knapsack(weight, val, cap, n-1) ;
    }
}
int main()
{
    int weight[100], val[100], cap , i , n ;
    memset(dp, -1, sizeof(dp)) ;

    scanf("%d", &n) ;
    for(i = 1 ; i <= n ; i++){
        scanf("%d %d", &weight[i], &val[i]) ;
    }
    scanf("%d", &cap) ;
    int profit = knapsack(weight, val, cap, n) ;
    printf("Max Profit: %d\n", profit) ;
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
