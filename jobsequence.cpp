#include<stdio.h>

struct job
{
    int id ;
    int deadline ;
    int profit ;
}joblist[100], temp;

int min(int a, int b){
    if(a<b) return a ;
    return b ;
}
int main()
{
    int n, i ;
    int result[100] ;
    bool slot[100] ;
    scanf("%d", &n) ;
    for(i = 0 ; i < n ; i++){
        scanf("%d %d %d", &joblist[i].id , &joblist[i].deadline, &joblist[i].profit) ;
    }
    for(i = 0 ; i < n ; i++){
        slot[i] = false ;
    }
    for(i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            if(joblist[i].profit < joblist[j].profit){
                temp = joblist[i] ;
                joblist[i] = joblist[j] ;
                joblist[j] = temp ;
            }
        }
    }


    for(i = 0 ; i < n ; i++){
        int  j ;
        for(j = min(n, joblist[i].deadline) - 1 ; j >= 0 ; j--){
            if(slot[j] == false){
                slot[j] = true ;
                result[j] = i ;
                break ;
            }
        }
    }
    for(i = 0 ; i < n ; i++){
        if(slot[i]){
            printf("%d ", joblist[result[i]].id) ;
        }
    }



    return 0 ;
}
