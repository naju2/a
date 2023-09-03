# include <stdio.h>

void quicksort(int arr[], int low, int high) {
    if(low >= high) {
        return;
    }
    int s = low;
    int e = high;
    int m = (low + high)/2;
    int pivot = arr[m];

    while(s <= e) {
        while(arr[s] < pivot) {
            s++;
        }
        while(arr[e] > pivot) {
            e--;
        }

        if(s <= e) {
            int t = arr[s];
            arr[s] = arr[e];
            arr[e] = t;

            s++;
            e--;
        }
    }
    quicksort(arr,low,e);
    quicksort(arr,s,high);
}

void main() {
    int arr[] = {7,6,5,4,3,2,1};
    int n = 7;

    quicksort(arr, 0, n-1);

    for(int i = 0; i<n; i++) {
        printf("%d ", arr[i]);
    }
}