#include<stdio.h>

int partitionOfQuickSort(int a[], int p, int r)
{
    int x = a[r] ;
    int i = p-1 ;
    for(int j = p ; j <= r-1 ; j++){
        if(a[j] <= x){
            i = i+1 ;
            int temp = a[j] ;
            a[j] = a[i] ;
            a[i] = temp ;
        }
    }
        i = i+1 ;
        int temp = a[r] ;
        a[r] = a[i] ;
        a[i] = temp ;

    return i ;
}

void quickSort(int a[] , int p , int r)
{
    if(p < r){
        int q = partitionOfQuickSort(a, p, r) ;
        quickSort(a, p, q-1) ;
        quickSort(a, q+1, r) ;
    }
}
int main()
{
    int n, i, j, a[100] ;
    scanf("%d", &n) ;
    for(i = 0 ; i < n ; i++){
        scanf("%d", &a[i]) ;
    }

    quickSort(a, 0, n-1) ;

    for(i = 0 ; i < n ; i++)
        printf("%d ", a[i]) ;
    printf("\n") ;
}

/*
8
2 8 7 1 3 5 6 4

*/
