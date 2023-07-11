
#include <stdio.h>
int n;
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
void find_path(int graph[][n],int sv,int n){
    int dist[n],d,k,j,p;
    int s[n];
    for(int i=0;i<n;i++){
    s[i]=0;dist[i]=0;}
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
    printf("Shortest distances from %d to\n",sv+1);
    for(p=0;p<n;p++){
        
    if(dist[p]==1000){printf("%d - ~infinite~\n",p+1);continue;}
    printf("%d - %d\n",p+1,dist[p]);}
    
}
int main()
{    int i,j;

     printf("Enter n:");
     scanf("%d",&n);
     int graph[n][n];
     printf("Enter graph data in matrix form\n");
     for(i=0;i<n;i++)
     for(j=0;j<n;j++)
     scanf("%d",&graph[i][j]);
    //Sample input: 
    //int graph[6][6]={{0,50,45,10,0,0},{0,0,10,15,0,0},{0,0,0,0,30,0},{20,0,0,0,15,0},{0,20,35,0,0,0},{0,0,0,0,3,0}};
    
     find_path(graph,0,n);
}


