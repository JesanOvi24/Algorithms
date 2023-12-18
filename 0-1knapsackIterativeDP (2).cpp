#include<stdio.h>

void trace_back(int wi[],  int trace[100][100], int ln, int lcap)
{
    if(lcap == 0 || ln == 0) return;
    if(trace[ln][lcap] == 1){
        printf("Item %d %d\n", ln, wi[ln]) ;
        trace_back(wi, trace , ln-1, lcap-wi[ln]) ;
    }
    else trace_back(wi, trace, ln-1, lcap) ;
}
int main()
{
    int n, cap, i, w;
    int p[100][100], v[100], wi[100], trace[100][100] ;

    scanf("%d", &n) ;
    for(i = 1 ; i <= n ; i++)
        scanf("%d %d", &wi[i], &v[i]) ;
    scanf("%d", &cap) ;

    for(i = 0 ; i < 100 ; i++)
        p[0][i] = 0 ;

    for(i = 0 ; i < 100 ; i++)
        p[i][0] = 0 ;
    for(w = 1 ; w <= cap ; w++)
    {
        for(i = 1 ; i <= n ; i++)
        {
            if(w-wi[i]>=0)
            {
                if(v[i]+p[i-1][w-wi[i]]>= p[i-1][w])
                {
                    p[i][w] = v[i]+p[i-1][w-wi[i]] ;
                    trace[i][w] = 1 ;
                }
                else
                {
                    p[i][w] = p[i-1][w] ;
                    trace[i][w] = 0 ;
                }
                //p[i][w] = max(v[i]+p[i-1][w-wi[i]], p[i-1][w]) ;
            }
            else{
                 p[i][w] = p[i-1][w] ;
                 trace[i][w] = 0 ;
            }

        }
    }
    for(i = 0 ; i <= n ; i++)
    {
        for(int j = 0 ; j <= cap ; j++)
            printf("%d ", p[i][j]) ;
        printf("\n") ;
    }
    for(i = 0 ; i <= n ; i++)
    {
        for(int j = 0 ; j <= cap ; j++)
            printf("%d ", trace[i][j]) ;
        printf("\n") ;
    }
    trace_back(wi, trace, n, cap) ;
}
