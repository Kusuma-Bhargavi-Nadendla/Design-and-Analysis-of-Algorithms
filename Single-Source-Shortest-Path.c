
#include <stdio.h>
#define n 6
void print(int dist[])
{
    for (int i = 0; i < n; i++)
        printf("%d - %d\n", i, dist[i]);
}
int minimum(int dist[n],int s[n]){
    int min=1000,mi=-1;
    for(int i=0;i<n;i++){
        if(s[i]==0&&dist[i]<=min){
            min=dist[i];
            mi=i;
        }
    }
    return mi;
}
void find_path(int graph[n][n],int sv){
    int dist[n]={0},s[n]={0},d,k,j,p;
    for(int i=0;i<n;i++){
        if(graph[sv][i]!=0)
        dist[i]=graph[sv][i];
        else
        dist[i]=1000;
    }
    dist[sv]=0;
    s[sv]=1;
    for(k=0;k<n-1;k++){
        d=minimum(dist,s);
        s[d]=1;
        
        for(j=0;j<n;j++){
            if(graph[d][j]!=0 && dist[j]>dist[d]+graph[d][j]){
                dist[j]=dist[d]+graph[d][j];
            }
        }
    }
  printf("Cost 1000 indicates no path exist to that vertex\n");
    printf("Shortest distances from %d to\n",sv+1);
    for(p=0;p<n;p++)
    printf("%d - %d\n",p+1,dist[p]);
    
}
int main()
{
    int graph[n][n]={{0,50,45,10,0,0},{0,0,10,15,0,0},{0,0,0,0,30,0},{20,0,0,0,15,0},{0,20,35,0,0,0},{0,0,0,0,3,0}};
     find_path(graph,0);
}

