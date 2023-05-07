#include<stdio.h>
#include<stdlib.h>
int n;
void strassen(int a[][n] ,int b[][n] ,int res[][n]);
int** add(int a[n/2][n/2],int b[n/2][n/2]){
     
     
    int** res;
    res=(int**)malloc(n/2*sizeof(int*));
    if(res==NULL)return NULL;
    for(int i=0;i<n/2;i++){
    res[i]=(int*)malloc(n/2*sizeof(int));
    if(res[i]==NULL)return NULL;}
      
    int i,j;
    for(i=0;i<n/2;i++)
    for(j=0;j<n/2;j++)
    res[i][j]=a[i][j]+b[i][j];
    return res;
}
int** subtract(int a[n/2][n/2],int b[n/2][n/2]){
      
      int** res;
    res=(int**)malloc(n/2*sizeof(int*));
    if(res==NULL)return NULL;
    for(int i=0;i<n/2;i++){
    res[i]=(int*)malloc(n/2*sizeof(int));
    if(res[i]==NULL)return NULL;}
      
    int i,j;
    for(i=0;i<n/2;i++)
    for(j=0;j<n/2;j++)
    res[i][j]=a[i][j]-b[i][j];
    return res;
}
int** multiply(int **a,int **b){
    int** res;
    res=(int**)malloc(n/2*sizeof(int*));
    if(res==NULL)return NULL;
    for(int i=0;i<n/2;i++){
    res[i]=(int*)malloc(n/2*sizeof(int));
    if(res[i]==NULL)return NULL;}
    if(n/2==1){
        res[0][0]=a[0][0]*b[0][0];
        
    }
    else if(n/2==2){
        res[0][0]=a[0][0]*b[0][0]+a[0][1]*b[1][0];
        res[0][1]=a[0][0]*b[0][1]+a[0][1]*b[1][1];
        res[1][0]=a[1][0]*b[0][0]+a[1][1]*b[1][0];
        res[1][1]=a[1][0]*b[0][1]+a[1][1]*b[1][1];
    }
    return res;
}
void strassen(int a[][n] ,int b[][n] ,int res[][n]){
    
    int i,j,k=0,l=0,ri=0,rj=0;
    int a1[n/2][n/2],a2[n/2][n/2],a3[n/2][n/2],a4[n/2][n/2];
    int temp[n/2][n/2];
    int b1[n/2][n/2],b2[n/2][n/2],b3[n/2][n/2],b4[n/2][n/2],c1[n/2][n/2],c2[n/2][n/2],c3[n/2][n/2],c4[n/2][n/2];
    int **p,**q,**r,**s,**t,**u,**v;
    for(i=0;i<n/2;i++)for(j=0;j<n/2;j++)temp[i][j]=0;
    
    
    //Split a and b matrices
    for(i=0,k=0;i<n/2;i++,k++)for(j=0,l=0;j<n/2;j++,l++){a1[k][l]=a[i][j];b1[k][l]=b[i][j];}
    for(i=0,k=0;i<n/2;i++,k++)for(j=n/2,l=0;j<n;j++,l++){a2[k][l]=a[i][j];b2[k][l]=b[i][j];}
    for(i=n/2,k=0;i<n;i++,k++)for(j=0,l=0;j<n/2;j++,l++){a3[k][l]=a[i][j];b3[k][l]=b[i][j];}
    for(i=n/2,k=0;i<n;i++,k++)for(j=n/2,l=0;j<n;j++,l++){a4[k][l]=a[i][j];b4[k][l]=b[i][j];}
    
   //Calculate p,q,r,s,t,u,v- 7 n/2 matrices 
    p=multiply(add(a1,a4),add(b1,b4));
    q=multiply(add(a3,a4),add(b1,temp));
    r=multiply(add(a1,temp),subtract(b2,b4));
    s=multiply(add(a4,temp),subtract(b3,b1));
    t=multiply(add(a1,a2),add(b4,temp));
    u=multiply(subtract(a3,a1),add(b1,b2));
    v=multiply(subtract(a2,a4),add(b3,b4));
    
    
    //find c1,c2,c3,c4 : sub-matrices of result
    for(i=0;i<n/2;i++)for(j=0;j<n/2;j++){
        c1[i][j]=p[i][j]+s[i][j]-t[i][j]+v[i][j];
        c4[i][j]=p[i][j]+r[i][j]-q[i][j]+u[i][j];
    }
    for(i=0;i<n/2;i++)for(j=0;j<n/2;j++){
        c2[i][j]=r[i][j]+t[i][j]; 
        c3[i][j]=q[i][j]+s[i][j];
    }
    
    
    //Combine all into res matrix
    for(i=0;i<n/2;i++)for(j=0;j<n/2;j++)res[i][j]=c1[i][j];
    for(i=0;i<n/2;i++)for(j=0;j<n/2;j++)res[i][j+n/2]=c2[i][j];
    for(i=0;i<n/2;i++)for(j=0;j<n/2;j++)res[i+n/2][j]=c3[i][j];
    for(i=0;i<n/2;i++)for(j=0;j<n/2;j++)res[i+n/2][j+n/2]=c4[i][j];
}

int main(){
    
   
    int i,j,k;
    printf("Enter order of matrix:");
    scanf("%d",&n);
    
    int a[n][n];
    int b[n][n];
    int c[n][n];
    
    printf("Enter matrix 1:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
           scanf("%d",&a[i][j]);
     printf("Enter matrix 2:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
           scanf("%d",&b[i][j]);
    strassen(a,b,c);
    
    printf("Result of multiplication\n");
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
       printf("%d  ",c[i][j]);
      }
     printf("\n");
    }
    return 0;
}









