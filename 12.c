#include <stdio.h>

int n;

int choose(int distance[], int visited[]) {
    int minvertex = 1;
    int minval = 100;
    
    for(int i = 1; i<= n; i++) {
        if(distance[i] < minval && !visited[i]) {
            minval = distance[i];
            minvertex = i;
        }
    }
    return minvertex;
}

void shortestPath(int source, int cost[][n+1], int distance[]) {
    int visited[n+1];

    for(int i = 1; i<=n; i++) {
        visited[i] = 0;
        distance[i] = cost[source][i];
    }
    visited[source] = 0;
    distance[source] = 0;

    for(int i = 2; i<=n; i++) {

        int result = choose(distance,visited);
        visited[result] = 1;

        for(int v = 1; v<=n; v++) {
            if(distance[result] + cost[result][v] < distance[v] && !visited[v]) {
                distance[v] = distance[result] + cost[result][v];
            }
        }
    }
}

void main() {
    printf("Enter the number of vetices: ");
    scanf("%d",&n);

    printf("Enter the source vertex: ");
    int source;
    scanf("%d",&source);

    int cost[n+1][n+1];
    printf("Enter the cost matrix: \n");
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
            scanf("%d",&cost[i][j]);
        }
    }

    int distance[n+1];

    shortestPath(source,cost,distance);

    for(int i = 1; i<=n; i++) {
        printf("%d to %d = %d \n", source, i, distance[i]);
    }
}