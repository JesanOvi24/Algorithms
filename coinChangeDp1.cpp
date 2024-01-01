

/*
Possible number of way to make the change.
Supply of each coins is infinite.
*/



#include<stdio.h>

int main()
{
    int a[100], sum, i, j, n ;
    scanf("%d", &n) ;

    for(i = 0 ; i < n ; i++){
        scanf("%d", &a[i]) ;
    }
    scanf("%d", &sum) ;
    int dp[100][100] ;

    dp[0][0] = 1 ;
    for(i = 1 ; i <= sum ; i++){
        dp[0][i] = 0 ;
    }
    for(i = 1 ; i <= n ; i++){
        dp[i][0] = 1 ;
    }

    for(i = 1 ; i <= n ; i++){
        for(j = 1 ; j <= sum ; j++){
            if(a[i-1] > j)
                dp[i][j] = dp[i-1][j] ;
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-a[i-1]] ;
        }
    }

    for(i = 0 ; i <= n ; i++){
        for(j = 0 ; j <= sum ; j++)
            printf("%d ", dp[i][j]) ;
        printf("\n") ;
    }

    printf("Possible way: %d\n", dp[n][sum]) ;


}
