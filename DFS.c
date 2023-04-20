#include<stdio.h>

int n, g[10][10], visited[10];

int dfs(int v){
	int w;
    printf("%d-->", v);
    visited[v]=1;
    for(w=1; w<=n; w++)
    if(visited[w]==0 && g[v][w]==1)
    dfs(w);
}

void dft(){
	int i;
    for(i=1;i<=n;i++){
		if(visited[i]==0)
 		dfs(i);
	}
}

int main(){
	int v, w;
 	printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter matrix\n");
    for(v=1; v<=n; v++){
    	for(w=1; w<=n; w++)
    	scanf("%d", &g[v][w]);
    }
    
    for(v=1; v<=n; v++)
    visited[v]=0;
    
    printf("The possible order of depth first search is :\n");
    dft();
}


