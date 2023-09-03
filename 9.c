#include<stdio.h>
int n;
int min(int a, int b) {
    return a<b ? a : b;
}
void floyd(int arr[n][n]) {
    
    for(int k = 0; k<n; k++) {
        for(int i = 0; i<n; i++) {
           for(int j = 0; j< n; j++) {
                arr[i][j] = min(arr[i][j], (arr[i][k] + arr[k][j]));
            }
        }
    }
}

void main() {
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);

    // adjacency matrix:
    int arr[n][n];
    printf("Enter the adjacency matrix: ");

    for(int i = 0; i< n; i++) {
        for(int j = 0; j<n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    floyd(arr);

    printf("The resulting graph matrix is: ");
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

