#include<stdio.h>


using namespace std ;

int grid[100][100], col[100][100] ;
int n, m ;
struct coordinate
{
    int x, y ;
}par[100][100], temp;
void dfs(int i, int j)
{
    col[i][j] = 1 ;

    if(j-1 >=0 && grid[i][j-1] == 1 && col[i][j-1] == 0){
        temp.x = i ;
        temp.y = j ;
        par[i][j-1] = temp ;
        dfs(i, j-1) ;
    }
    if(j+1 < m && grid[i][j+1] == 1 && col[i][j+1] == 0){
        temp.x = i ;
        temp.y = j ;
        par[i][j+1] = temp ;

        dfs(i, j+1) ;
    }

    if(i-1>=0 && grid[i-1][j] == 1 && col[i-1][j] == 0){
        temp.x = i ;
        temp.y = j ;
        par[i-1][j] = temp ;

        dfs(i-1, j) ;
    }
    if(i+1 < n && grid[i+1][j] == 1 && col[i+1][j] == 0){
        temp.x = i ;
        temp.y = j ;
        par[i+1][j] = temp ;

        dfs(i+1, j) ;
    }

}

void printPath(int sti, int stj, int endi, int endj){
    if((sti == endi) && (stj == endj)){
        printf("(%d %d)->", sti, stj) ;
        return ;
    }
    printPath(sti, stj, par[endi][endj].x, par[endi][endj].y) ;
    printf("(%d %d)->", endi, endj) ;

}
int main(){
    int  i, j, sti, stj, endi, endj ;
    scanf("%d %d", &n, &m) ;
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < m ; j++){
            scanf("%d", &grid[i][j]) ;
            col[i][j] = 0 ;
        }
    }

    scanf("%d %d %d %d", &sti, &stj, &endi, &endj) ;
    dfs(sti, stj) ;
    if(col[endi][endj] == 1){
        printPath(sti, stj, endi, endj) ;
    }
    else
        printf("not possible\n") ;
}


/*
8 8
1 1 1 1 1 0 0 1
1 1 1 0 1 1 1 0
0 1 1 1 1 1 0 1
1 1 0 0 1 1 1 1
0 0 1 1 1 1 1 1
1 1 1 0 0 0 1 1
1 0 0 0 1 1 1 1
1 1 1 1 1 0 0 1





*/
