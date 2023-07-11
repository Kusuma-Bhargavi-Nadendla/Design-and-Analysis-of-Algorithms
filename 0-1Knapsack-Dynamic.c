
#include <stdio.h>
typedef struct{
    int p;
    int w;
}pw;
pw record(int x,int y){
    pw t;
    t.p=x;
    t.w=y;
    return t;
}

int Merge(pw si[],pw si1[],pw si2[],int t,int capacity){
    int rem_count=0;
    for(int i=0;i<t;i++){
        if(si1[i].w>capacity){
            rem_count+=1;
        continue;
        }
        si2[i]=record(si1[i].p,si1[i].w);
        
    }
    for(int j=0;j<t;j++){
        if(si[j].w>capacity){
        rem_count+=1;
        continue;}
        si2[j+t]=record(si[j].p,si[j].w);
        
    }
    return (2*t)-rem_count;
}
void removeDominance(pw series[],int t){
    for(int p=0;p<t;p++){
        for(int q=p+1;q<t;q++){ 
            if((series[p].p<=series[q].p && series[p].w>=series[q].w)){
                //printf("Dominance found for %d %d and %d %d \n",series[p].p,series[p].w,series[q].p,series[q].w);
                for(int k=p;k<t;k++){
                    series[k]=series[k+1];
                    t--;
                }
            }
        }
    }
}
int is_exist(pw series[],pw rec,int m){
    for(int i=0;i<m;i++){
        if(series[i].p==rec.p && series[i].w==rec.w){
            return 1;
        }
    }
    return 0;
}
void dynamicKnapsack(int p[],int w[],int n,int m,pw s[][m+1],int x[]){
    
    int i,t,j;
    pw si1[m+1],rec;
    s[0][0]=record(0,0);
    t=1;
    //printf(" S^0 is %d %d\n",s[0][0].p,s[0][0].w);
    for(i=1;i<=n;i++){
        //finding si 
        for(j=0;j<t;j++){
            si1[j]=record(s[i-1][j].p+p[i-1],s[i-1][j].w+w[i-1]);
             //printf("rec-%d %d\n",si1[j].p,si1[j].w);
        }
        
        //Merging si and si1 to get si+1 
        t=Merge(si1,s[i-1],s[i],t,m);//t is count in si 
        removeDominance(s[i],t);
        for(int p=0;p<t;p++){
           // printf("si-%d %d\n",s[i][p].p,s[i][p].w);
        }
        
    }
    printf("Maximum profit can be obtained is %d with weight %d\n",s[n][t-1].p,s[n][t-1].w);
    rec=record(s[n][t-1].p,s[n][t-1].w);
    for(i=n;i>0;i--){           //Traceback to find optimal solution
        if (is_exist(s[i-1],rec,m)){
            x[i]=0;
        }
        else{
            x[i]=1;
            rec.p-=p[i-1];
            rec.w-=w[i-1];
        }
        //printf("x-%d is %d\n",i,x[i]);
    }
}
int main()
{
    int i,n,m;
    
    //m=40;n=4;
    //int w[]={30,10,40,20}, p[]={10,20,30,40}, x[n];
    //gives result-60 and solution is (0,1,0,1)
    
    printf("Enter n: ");
    scanf("%d", &n);
    
  
    printf("Enter capacity: ");
    scanf("%d", &m);
    
    int w[n], p[n], x[n];
    pw s[n+1][m+1];
    
    printf("Enter weights:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    
    printf("Enter profits:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    
    dynamicKnapsack(p,w,n,m,s,x);
    
    printf("Optimal solution for the problem is:");
    for(i=1;i<=n;i++){
        printf("%d ",x[i]);
    }

    return 0;
}




