#include<stdio.h>

void dfs(int arr[10][10], int start, int visited[10], int edge[10][10], int n) {

    int k = 0;
    visited[start] = 1;

    for(int i = 0; i<n; i++) {
        if(arr[start][i] == 1 && visited[i] == 0) {
            edge[k][0] = start;
            edge[k][1] = i;
            k++;
            dfs(arr,i,visited,edge,n);
        }
    }
}
void main() {
    int n = 4;
    int arr[10][10];
    int visited[10];
    int edge[10][10];

    printf("Enter the adj matrix: \n");
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int start;
    printf("Enter start: ");
    scanf("%d", &start);

    
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    dfs(arr,start,visited,edge,n);

    for (int i = 0; i < n; i++) {
        if (visited[i] == 1) {
            printf("%d is reachable\n", i);
        } else {
            printf("%d is not reachable\n", i);
        }
    }

    printf("DFS traversal: Edges visited\n");
    for (int i = 0; i < n - 1; i++) {
        printf("%d %d\n", edge[i][0], edge[i][1]);
    }
}
