#include<stdio.h>

//int e[14][2]={{1,2},{1,3},{1,5},{2,3},{2,4},{2,5},{2,7},{4,5},{4,7},{4,8},{5,8},{6,7},{6,8},{7,8}};
//int cost[]={11,13,2,15,8,12,6,14,10,17,5,21,7,11};
//int n=8; gives cost-52


int ec,n;
int e[30][2];
int cost[30];
int arr[30][30];
void swap(int* a,int* b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void sort(){
    int i,min,j;
    for(i=0;i<ec;i++){
        min=i;
        for(j=i+1;j<ec;j++){
            if(cost[j]<cost[min])
                min=j;
        }
        if(min!=i){
        swap(&cost[i],&cost[min]);
        swap(&e[i][0],&e[min][0]);
        swap(&e[i][1],&e[min][1]);
   }
    }
}
int cost_of(int l,int m){
    int i;
     for(i=0;i<ec;i++)
          if((e[i][0]==l && e[i][1]==m)||(e[i][0]==m && e[i][1]==l))
                  return cost[i];
     return 1000;
}
void delete(){
   int i;
   for(i=0;i<ec-1;i++){
       cost[i]=cost[(i+1)];
       e[i][0]=e[(i+1)][0];
       e[i][1]=e[(i+1)][1];
   }
   cost[i]=e[i][0]=e[i][1]=0;
}
int find(int x){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(arr[i][j]==x)
                return i;
        }
    }
}
void union_of(int j,int k){
    int i,p=0,i2=0,x;
    for(i=0;i<n;i++){
        if(i==j){
           break;
        }
    }
    if(i<n){
        while(arr[i][p]!=0)
        p++;
        for(;p<n;p++)
        arr[i][p]=arr[k][i2++];
        for(x=0;x<n;x++)
        arr[k][x]=0;
    }
}
int kruskals(){
    arr[n][n];
    int i,j,k,mincost,te=ec,u,v,t[n+1][2];
    i=mincost=0;
    for(i=0;i<n;i++){
        arr[i][0]=(i+1);
    }
    i=0;
    sort();
    while(i<(n-1)&&(te!=0)){
        u=e[0][0];
        v=e[0][1];
        j=find(u);
        k=find(v);
        if(j!=k){
            i+=1;
            t[i][0]=u;
            t[i][1]=v;
            mincost+=cost_of(u,v);
            union_of(j,k);
        }
        //printf("i-%d,u-%d,v-%d,j-%d,k-%d,mincost-%d\n",i,u,v,j,k,mincost);
        delete();
        te--;
        
    }
    return mincost;
}
int main(){
    int r,i;
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    printf("Enter no. of edges:");
    scanf("%d",&ec);
    for(i=0;i<ec;i++){
        printf("Enter (x,y) and cost of edge:");
        scanf("%d %d %d",&e[i][0],&e[i][1],&cost[i]);
    }
    r=kruskals();
    printf("Posible minimum cost is %d",r);
    return 0;
}


