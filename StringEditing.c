
#include <stdio.h>
#include<string.h>
int insert_cost,delete_cost,swap_cost;
//int cost[5][6];
int change_cost(char x[],char y[],int i,int j){
    if (x[i]==y[j])
    return 0;
    return swap_cost;
}
int editString(char x[],char y[],int xl,int yl,int cost[][strlen(y)+1]){
    if(xl==0 && yl==0){
        return 0;
    }
    if(yl==0 && xl>0){
        return xl*delete_cost;
    }
    if(xl==0 && yl>0){
        return yl*insert_cost;
    }
    //int a=editString(x,y,xl-1,yl)+delete_cost;
    //int b=editString(x,y,xl,yl-1)+insert_cost;
    //int c=editString(x,y,xl-1,yl-1)+change_cost(x,y,xl,yl);
    int a=cost[xl-1][yl]+delete_cost;
    int b=cost[xl][yl-1]+insert_cost;
    int c=cost[xl-1][yl-1]+change_cost(x,y,xl,yl);
    return (a<b&&a<c)?a:(b<c)?b:c;
    
}
int main()
{
    //char y[]="-aabab";
    //char x[]="-babb";
    //insert_cost=delete_cost=1;
    // int cost[5][6];
    char fx[50],fy[50],x[50]="-",y[50]="+";
   
    printf("Enter first string:");
    scanf("%s",fx);
    strcat(x,fx);
    
    printf("Enter second string:");
    scanf("%s",fy);
    strcat(y,fy);
    
    printf("Enter cost for insertion,deletion,swap:");
    scanf("%d %d %d",&insert_cost,&delete_cost,&swap_cost);
    int cost[strlen(x)+1][strlen(y)+1];
   
    for(int i=0;i<strlen(x)+1;i++){
    for(int j=0;j<strlen(y)+1;j++){
    cost[i][j]=editString(x,y,i,j,cost);
    //printf("%d ",cost[i][j]);}printf("\n");}
    }}
    printf("Minimum opearations possible to transform %s as %s are %d",fx,fy,
    
    cost[strlen(x)][strlen(y)]);

    return 0;
}



