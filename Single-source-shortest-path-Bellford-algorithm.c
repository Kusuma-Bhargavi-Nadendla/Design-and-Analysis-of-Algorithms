
#include <stdio.h>
int has_incoming_edge(int n,int cost[][n],int v){
    for(int i=0;i<n;i++){
        if (cost[i][v]!=1000 && i!=v){
        return 1;}
    }
    return 0;
}

void bellmanFordPath(int v,int n,int cost[][n],int dist[n]){
    int i,k,u;
    for(i=0;i<n;i++){
        dist[i]=cost[v][i];
    }
    
    for(k=2;k<n;k++){
        for(u=1;u<n;u++){
            if(u!=v && has_incoming_edge(n,cost,u)){
                for(i=0;i<n;i++){
                    if(u==2 && i==3){
                        
                    }
                    if(dist[i]!=1000 && dist[u]>(dist[i]+cost[i][u])){
                        dist[u]=dist[i]+cost[i][u];
                    }
                }
                
            }
        }
        
    }
}
int main()
{
    int i,j,n,sv,dist[n];

     printf("Enter n:");
     scanf("%d",&n);
     int graph[n][n];
     printf("Enter graph data in matrix form\n");
     for(i=0;i<n;i++)
     for(j=0;j<n;j++)
     scanf("%d",&graph[i][j]);
    /*n=7;
    sv=0;
    int graph[7][7]={
        {0,6,5,5,1000,1000,1000},
        {1000,0,1000,1000,-1,1000,1000},
        {1000,-2,0,1000,1,1000,1000},
        {1000,1000,-2,0,1000,-1,1000},
        {1000,1000,1000,1000,0,1000,3},
        {1000,1000,1000,1000,1000,0,3},
        {1000,1000,1000,1000,1000,1000,0}
    };*/
     bellmanFordPath(sv,n,graph,dist);
for(i=0;i<n;i++){
    printf("%d  ",dist[i]);
}
    return 0;
}



