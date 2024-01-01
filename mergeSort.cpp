#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 15

void Merge(int arr[], int aux[], int low, int mid, int high)
{
    int k = low, i = low, j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j]) {
            aux[k++] = arr[i++];
        }
        else {
            aux[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        aux[k++] = arr[i++];
    }
    for (int i = low; i <= high; i++) {
        arr[i] = aux[i];
    }
}

void mergesort(int arr[], int aux[], int low, int high)
{
    if (high == low) {
        return;
    }

    int mid = (low+high) / 2 ;


    mergesort(arr, aux, low, mid);          // split/merge left half
    mergesort(arr, aux, mid + 1, high);     // split/merge right half

    Merge(arr, aux, low, mid, high);        // merge the two half runs.
}
int main(void)
{
    int arr[N], aux[N];
    srand(time(NULL));

    // generate random input of integers
    for (int i = 0; i < N; i++) {
        aux[i] = arr[i] = (rand() % 100) - 50;
    }


    mergesort(arr, aux, 0, N - 1);



    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }


    return 0;
}
