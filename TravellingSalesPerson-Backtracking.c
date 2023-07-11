#include <stdio.h>
int n,sv;

int  travelPath(int cv,int depth,int cost[n][n],int visited[]){
    
    visited[cv]=1;
    int i,c,mincost=1000;
    if(depth==n-1){
        visited[cv]=0;
        return cost[cv][sv];
    }
    
    for(i=0;i<n;i++){
        
        if(visited[i]==0&&cost[cv][i]!=0){
            c=travelPath(i,depth+1,cost,visited)+cost[cv][i];
            
            if(c<mincost){
                mincost=c;
            }
        }
    }
    
    visited[cv]=0;
    return mincost;
    
}
int main()
{
    int i,j,final_cost,depth=0;
    int visited[n];
    
    int mincost[n];int path[n];
    printf("Enter no. of nodes:");
    scanf("%d",&n);
    
    int cost[n][n];
    
    
    for(i=0;i<n;i++)
    visited[i]=0;
    
    printf("Enter cost of edges in graph in matrix form\n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d",&cost[i][j]);
    
    
    printf("Enter starting vertex:");
    scanf("%d",&sv);
    
    visited[sv]=1;
    
    
    final_cost=travelPath(sv,depth,cost,visited);
    printf("Optimal cost:%d",final_cost);
      return 0;
}

