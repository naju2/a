#include <stdio.h>

int max(int a, int b) {
    return a>b?a:b;
}
int knapsack(int n, int weight[], int profit[], int capacity) {

    int v[n+1][capacity+1];

    for(int i = 0; i<= n; i++) {
        for(int j = 0; j <= capacity; j++) {
            
            if(i == 0 || j == 0) {
                v[i][j] = 0;
            } else if(j < weight[i]) {
                v[i][j] = v[i-1][j];
            } else {
                v[i][j] = max(v[i-1][j], v[i-1][j-weight[i]] + profit[i]);
            }
        }
    }
    printf("The table is: \n");
    
    for(int i = 0; i<= n; i++) {
        for(int j = 0; j <= capacity; j++) {
            printf("%d\t",v[i][j]);
        }
        printf("\n");
    }
    return v[n][capacity];
} 

void main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d",&n);

    printf("Enter the weight matrix: \n");
    int weight[n];
    for(int i = 1; i<=n; i++) {
        scanf("%d",&weight[i]);
    }

    printf("Enter the profit values: \n");
    int profit[n];
    for(int i = 1; i<= n; i++) {
        scanf("%d",&profit[i]);
    }

    int capacity;
    printf("Enter the capacity of knapsack: ");
    scanf("%d",&capacity);

    int result = knapsack(n,weight,profit,capacity);

    printf("The optimal solution is: %d", result);

}