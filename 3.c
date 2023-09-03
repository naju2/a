#include <stdio.h>
#include <time.h>

void getInput(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        arr[i] = rand() % 100;
    }
}

void printCustomers(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        printf("%d ", arr[i]);
    }
}

void sort(int arr[], int n) {
    for(int i = 0; i<n-1; i++) {
        for(int j = 0; j<n-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int n, int t) {
    int s = 0;
    int e = n-1;

    while(s <= e) {
        int m = s+(e-s)/2;

        if(arr[m] > t) {
            e = m-1;
        } else if(arr[m] < t) {
            s = m+1;
        } else {
            return m;
        }
    }
    return -1;
}

void main() {
    int n;
    clock_t s, e;

    printf("Enter the number of customers\n");
    scanf("%d", &n);

    int arr[n];
    getInput(arr,n);

    printf("The customers id are: ");
    printCustomers(arr,n);

    sort(arr,n);

    printf("Enter the target: ");
    int target;
    scanf("%d",&target);
    s = clock();
    int result = binarySearch(arr,n,target);
    e = clock();
    if(result == -1) {
        printf("The given customer is not present\n");
    } else {
        printf("Customer found at the position %d", result+1);
    }
    printf("The runtime is: %f", (double) (e-s)/CLOCKS_PER_SEC);
    

}
	
