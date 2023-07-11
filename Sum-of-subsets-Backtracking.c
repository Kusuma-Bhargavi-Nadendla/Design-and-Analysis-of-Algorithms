
#include <stdio.h>
int weight;
void findSubset(int n,int m,int w[],int sol[]){
    int i,weight=0;
    for(i=0;i<n;i++){
        weight+=w[i];
        if(weight==m){
            sol[i]=1;
            return;
        }
        else if(weight>m){
            weight-=w[i];
            continue;
        }
        else{
            sol[i]=1;
        }
        
    }
}
int main()
{
     int n,i,m;
     printf("Enter n:");
     scanf("%d",&n);
     int w[n],sol[n];
     
     printf("Enter m:");
     scanf("%d",&m);
     printf("Enter elements\n");
     for(i=0;i<n;i++)
     scanf("%d",&w[i]);
     
     printf("Best possible subset is:");
     findSubset(n,m,w,sol);
     for(i=0;i<n;i++)
     printf("%d  ",sol[i]);

    return 0;
}
