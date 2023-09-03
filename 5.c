# include <stdio.h>

void merge(int arr[], int s, int m, int e) {
    int i = s;
    int j = m;
    int k = 0;
    int mix[e-s];
    while(i < m && j < e) {
        if(arr[i] < arr[j]) {
            mix[k] = arr[i];
            i++;
        } else {
            mix[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i < m) {
        mix[k] = arr[i];
        i++;
        k++;
    } 
    while(j < e) {
        mix[k] = arr[j];
        j++;
        k++;
    }

    for(int x = 0; x < (e-s); x++) {
        arr[x+s] = mix[x];
    }
}

void mergesort(int arr[], int s, int e) {
    if(e-s == 1) return; 
    int m = (e+s)/2;
    mergesort(arr,s,m);
    mergesort(arr,m,e);
    merge(arr,s,m,e);
}

void main() {
    int arr[] = {7,6,5,4,3,2,1};
    int n = 7;
    mergesort(arr,0,n);

    for(int i = 0; i<n; i++) {
        printf("%d ", arr[i]);
    }
}