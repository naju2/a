
// bfs

#include <stdio.h>

void bfs(int arr[10][10], int total, int start) {

    int front = 0, rear = 0;
    int queue[total];
    int visited[total];
    for(int i = 0; i < total; i++) {
        visited[i] = 0;
    }
    
    visited[start] = 1;
    queue[rear++] = start;

    while(front <= rear) {
        int current = queue[front++];
        

        for(int i = 0; i<total; i++) {
            if(arr[current][i] == 1 && !visited[i]) {
                printf("%d %d", current, i);
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

void main() {
    int graph[10][10];
    int cities;
    printf("Enter the total cities: ");
    scanf("%d", &cities);
    printf("Enter the adjacency matrix: \n");
    for(int i = 0; i<cities; i++) {
        for(int j = 0; j<cities; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int start;
    printf("Enter the start city: ");
    scanf("%d", &start);

    bfs(graph,cities,start);
}