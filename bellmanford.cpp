#include<stdio.h>
#include<vector>
#define inf 999999

using namespace std ;
struct edge
{
    int src, dst, weight ;
}ed;
int d[100], par[100] ;
vector<edge>edgelist ;

void path(int src, int dst)
{
    if(src == dst){
        printf("%d ", dst) ;
        return ;
    }

    path(src, par[dst]);
    printf("%d ", dst) ;

}


int main()
{
    int i, n, e , w ;
    scanf("%d %d", &n, &e) ;

    for(i = 0 ; i < e ; i++){
        int u, v ;
        scanf("%d %d %d", &u, &v, &w) ;
        ed.src = u ;
        ed.dst = v ;
        ed.weight = w ;
        edgelist.push_back(ed) ; // Directed Graph
    }
    int s ;
    printf("Source: ") ;
    scanf("%d", &s) ;
    for(i = 0 ; i < n ; i++){
        d[i] = inf ;
    }
    d[s] = 0 ;

    for(i = 0 ; i < n-1 ; i++){
        for(int j = 0 ; j < edgelist.size() ; j++){
            ed = edgelist[j] ;
            if(d[ed.src] + ed.weight < d[ed.dst]){
                d[ed.dst] = d[ed.src] + ed.weight ;
                par[ed.dst] = ed.src ;
            }
        }
    }

    for(int j = 0 ; j < edgelist.size() ; j++){
            ed = edgelist[j] ;
            if(d[ed.src] + ed.weight < d[ed.dst]){
                printf("Negative Cycle detected\n") ;
                return 0 ;

            }
        }

    for(i = 0 ; i < n ; i++){
        path(s, i) ;
        printf(" Cost: %d\n", d[i]) ;
    }



    return 0 ;
}

/*
Directed Graph consider as u v w

4 5
0 1 5
0 2 4
1 2 -3
1 3 1
2 3 2
0




*/
