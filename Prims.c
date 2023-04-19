#include<stdio.h>
#include<stdlib.h>
int ec;
int e[30][2];
int cost[30];
//function to find cost of an edge if exist
int cost_of(int l,int m){
    int i;
     for(i=0;i<ec;i++)
          if((e[i][0]==l && e[i][1]==m)||(e[i][0]==m && e[i][1]==l))
                  return cost[i];
     return 1000;
}
int prims(int e[][2],int cost[],int n){
    int m=0,i,j,mincost=0,minj,m_cost;
    int near[ec+1],k=0,l=0;
    int t[ec][2];
    for(i=0;i<n;i++)
             if(cost[i]<cost[m])
                   m=i;
    k=e[m][0];
    l=e[m][1];
    t[0][0]=k;
    t[0][1]=l;
    mincost=cost[m];
    for(i=1;i<=n;i++){
          //finding near vertices
           if(cost_of(i,l)<cost_of(i,k))
                   near[i]=l;
           else
                   near[i]=k;
            
    }
     near[k]=0;
     near[l]=0;
     minj=-1;
     
     for(i=2;i<n;i++){
         m_cost=1000;
         for(j=1;j<=n;j++){
         
            if(near[j]!=0){
              if(cost_of(j,near[j])<m_cost){
                   m_cost=cost_of(j,near[j]);
                   minj=j;
             }}}
      
         t[i][0]=minj;
         t[i][1]=near[minj];
         mincost=mincost+cost_of(minj,near[minj]);
         near[minj]=0;
         for(k=1;k<=n;k++){
              if(near[k]!=0 && cost_of(k,near[k])>cost_of(k,minj))
                       near[k]=minj;
         }
   
     } 
       return mincost;
}
int main(){
    int n,r,i;
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    printf("Enter no. of edges:");
    scanf("%d",&ec);
    for(i=0;i<ec;i++){
        printf("Enter (x,y) and cost of edge:");
        scanf("%d %d %d",&e[i][0],&e[i][1],&cost[i]);
    }
    r=prims(e,cost,n);
    printf("Posible minimum cost is %d",r);
    return 0;
}

        
