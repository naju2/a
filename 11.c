#include<stdio.h>
#include<stdlib.h>

typedef struct edge{
    int u,v,cost;
}Edge;


int find(int v, int parent[]) {
    if (parent[v] != v) {
        v = parent[v];
    }
    return v;
}

void unionVertices(int v1, int v2, int parent[]) {
    if(v1 < v2) parent[v2] = v1;
    else parent[v1] = v2;
}

int compareEdges(const void* a, const void* b) {
    return((Edge*)a) -> cost - ((Edge*)b)-> cost;
}


void kruskal(int n, Edge edge[], int edgecount) {
    // Sort the edges based on cost
    qsort(edge, edgecount, sizeof(Edge), compareEdges);

    int parent[n];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int count = 0, edgeIdx = 0, cost = 0;
    Edge minSpanningTree[n - 1]; // Minimum spanning tree has n-1 edges

    while (count != n - 1 && edgeIdx < edgecount) {
        int v1 = find(edge[edgeIdx].u, parent);
        int v2 = find(edge[edgeIdx].v, parent);

        if (v1 != v2) {
            minSpanningTree[count] = edge[edgeIdx];
            count++;
            cost = cost + edge[edgeIdx].cost;
            unionVertices(v1, v2, parent);
        }
        edgeIdx++;
    }

    if (count == n - 1) {
        printf("Min spanning tree found:\n");
        for (int i = 0; i < n - 1; i++) {
            printf("%d %d\n", minSpanningTree[i].u, minSpanningTree[i].v);
        }
        printf("The total cost is: %d\n", cost);
    } else {
        printf("No MST\n");
    }
}
void main() {

    int n;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);

    printf("Enter the number of edges: ");
    int edgecount;
    scanf("%d", &edgecount);

    Edge edge[edgecount];
    printf("Enter the edge list: ");
    for(int i = 0; i < edgecount; i++) {
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].cost);
    }

    kruskal(n,edge,edgecount);
}