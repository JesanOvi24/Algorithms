
#include<stdio.h>
#include<math.h>
int main()
{
    double amount, coin[100], temp ;
    int i, j, n, num ;
    scanf("%lf %d", &amount, &n) ;
    for(i = 0 ; i < n ; i++){
        scanf("%lf", &coin[i]) ;
    }

    for(i = 0 ; i < n ; i++){
        for(j = i+1 ; j < n ; j++){
            if(coin[i] < coin[j]){
                temp = coin[i] ;
                coin[i] = coin[j] ;
                coin[j] = temp ;
            }
        }
    }
    double s = amount ;
    i = 0 ;
    double res ;
    while(s > 0.0 && i < n){
        double c = coin[i] ;
        res = s/c ;
        num = (int)res ;
        printf("res = %.4lf num = %d\n", res, num) ;
        s = s -  num*c;

        if(num>0)
            printf("Coin %.2lf is given %d amount\n", c, num) ;
        i++ ;
       // printf("s = %lf\n", s) ;

    }

    return 0 ;
}

/*
5.64
6
1 .25 .10 .05 .04 .01
*/
