
#include<stdio.h>

struct job
{
    int no ;
    int time ;
    double loss ;
    double lt ;
}jobList[100], temp;

int main()
{
    int i, j, n ;
    scanf("%d", &n) ;
    for(i = 0 ; i < n ; i++){
        jobList[i].no = i+1 ;
        scanf("%lf %d", &jobList[i].loss, &jobList[i].time) ;
        jobList[i].lt = jobList[i].loss/jobList[i].time ;
    }

    for(i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            if(jobList[i].lt < jobList[j].lt){
                temp = jobList[i] ;
                jobList[i] = jobList[j] ;
                jobList[j] = temp ;
            }
        }
    }

    for(i = 0 ; i < n ; i++){
        printf("%d ", jobList[i].no) ;
    }
}
