#include<stdio.h>
void GreedyKnapsack(float w[],int m,int n,float* res){
    int u=m,i;
    for(i=0;i<n;i++)
        res[i]=0;
    for(i=0;i<n;i++){
          if(w[i]>u)
              break;
          res[i]=1;
          u=u-w[i];
    }
    if(i<=n){
          res[i]=(float)(u/w[i]);
          }
}
void swap(float* a,float* b){
    float t;
    t=*a;
    *a=*b;
    *b=t;
}
void sort(float r[],float w[],float p[],int n){
    int i,j,max;
    for(i=0;i<n-1;i++){
          max=i;
          for(j=i+1;j<n;j++){
                if(r[j]>r[max]){
                    max=j;
                }        
              }swap(&r[i],&r[max]);
                   swap(&w[i],&w[max]);
                   swap(&p[i],&p[max]);
              
         }
}
int main(){
    int n,m,i;
    float w[30],r[30],p[30];
    float res[30],profit=0.0;
    printf("Enter count:");
    scanf("%d",&n);
    printf("Enter capacity of knapsack:");
    scanf("%d",&m);
    printf("Enter profits:");
    for(i=0;i<n;i++)
        scanf("%f",&p[i]);
    printf("Enter weights:");
    for(i=0;i<n;i++)
        scanf("%f",&w[i]);
    //Finding ratios...
    for(i=0;i<n;i++){
          r[i]=(float)p[i]/w[i];
          }
    //sorting ratios..
    sort(r,w,p,n);
    //finding knapsack...
    GreedyKnapsack(w,m,n,res);
    //calculate profit
    for(i=0;i<n;i++)
          profit+=(res[i]*p[i]);
    printf("Maximum profit that can be obtained is %f ",profit);
    return 0;
}

