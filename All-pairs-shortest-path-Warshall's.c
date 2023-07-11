#include <stdio.h>
int n;
// Function to calculate the shortest distances between all pairs of vertices
void floydWarshall_find_path(int graph[][n], int n) {
    int distance[n][n];

    for (int i=0;i<n;i++){
        for (int j = 0;j<n; j++) {
            distance[i][j] = graph[i][j];
        }
    }

    // shortest distances between all pairs using dynamic programming
    for (int k=0;k<n;k++) {
        for (int i= 0; i<n; i++) {
            for (int j = 0; j < n; j++) {
                if (distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }
    printf("Shortest distances between all pairs:\n");
    for (int i = 0; i <n; i++) {
        for (int j = 0; j <n; j++) {
            printf("%d\t", distance[i][j]);
        }
        printf("\n");
    }
}

// Driver code
int main() {
    /*int graph[4][4] = {
        {0, 5, 9999, 10},
        {9999, 0, 3, 9999},
        {9999, 9999, 0, 1},
        {9999, 9999, 9999, 0}
    };*/
    int i,j;

     printf("Enter n:");
     scanf("%d",&n);
     int graph[n][n];
     printf("Enter graph data in matrix form\n");
     for(i=0;i<n;i++)
     for(j=0;j<n;j++)
     scanf("%d",&graph[i][j]);
    //int graph[n][n]={{0,50,45,10,9999,9999},{9999,0,10,15,9999,9999},{9999,9999,0,9999,30,9999},{20,9999,9999,0,15,9999},{9999,20,35,9999,0,9999},{9999,9999,9999,9999,3,0}};
     floydWarshall_find_path(graph,n);

    return 0;
}

