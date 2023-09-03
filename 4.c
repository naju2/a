#include <stdio.h>

void swap(int arr[], int i, int j) {
    arr[i] = arr[i] ^ arr[j];
    arr[j] = arr[i] ^ arr[j];
    arr[i] = arr[i] ^ arr[j];
}
void insertionSort(int arr[], int n) {

    for(int i = 0; i < n-1; i++) {
        for(int j = i + 1; j > 0; j--) {
            if(arr[j] < arr[j-1]) {
                swap(arr, j, j-1);
            }
        }
    }
}
void main() {
    int arr[] = {7, 2, 5, 10, 22, 30};
    int n = 6;

    insertionSort(arr,n);

    for(int i = 0; i<n; i++) {
        printf("%d ", arr[i]);
    }
}