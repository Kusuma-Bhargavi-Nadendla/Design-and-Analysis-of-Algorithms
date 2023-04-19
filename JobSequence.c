#include<stdio.h>
#include<stdlib.h>


//n=5 p1,p2,p3,p4,p5 =20,15,10,5,1 d1,d2,d3,d4,d5=2,2,1,3,3 
//profit-40
//n=7 p1,p2,p3,p4,p5,p6,p7=3,5,20,18,1,6,30 d1,d2,d3,d4,d5,d6,d7=1,3,4,3,2,1,2 
//profit-74


void swap(int* a,int* b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void sort(int profit[],int deadline[],int n){
    int i,j,max;
    for(i=1;i<=n-1;i++){
          max=i;
          for(j=i+1;j<=n;j++){
                if(profit[j]>profit[max]){
                    max=j;
                }        
              }swap(&profit[i],&profit[max]);
                   swap(&deadline[i],&deadline[max]);
              
         }
}
int max(int deadline[],int n){
    int i,max_d=0;
    for(i=1;i<=n;i++)
    if(deadline[i]>max_d)
    max_d=deadline[i];
    return max_d;
}
int is_empty(int tim[],int r){
    int i;
    for(i=1;i<=r;i++)
    if(tim[i]==0)
    return 1;
    return 0;
}
int job_sequence(int profit[],int deadline[],int n){
    int total_profit=0,r,i,j,d,*tim;
    r=max(deadline,n);
    tim=(int*)malloc((r+1)*sizeof(int));
    if(tim==NULL){
    printf("Memory allocation error");
    return 1;
    }
    for(i=1;i<=r || is_empty(tim,r);i++){
        d=deadline[i];
        for(j=d;j>0;j--){
            if(tim[j]==0){
                tim[j]=i;
                total_profit+=profit[i];
                printf("Job-%d at hour %d with profit %d\n",i,j,profit[i]);
                break;
            }
        }
    }return total_profit;
    
}
int main(){
    int n,i,deadline[30],profit[30],j,r,d,*tim,total_profit=0;
    printf("Enter no. of jobs:");
    scanf("%d",&n);
    printf("Enter deadlines:");
    for(i=1;i<=n;i++)
    scanf("%d",&deadline[i]);
    printf("Enter profits:");
    for(i=1;i<=n;i++)
    scanf("%d",&profit[i]);
    sort(profit,deadline,n);
    total_profit=job_sequence(profit,deadline,n);
    printf("Maximum profit can be obtained is %d",total_profit);
    return 0;
}





