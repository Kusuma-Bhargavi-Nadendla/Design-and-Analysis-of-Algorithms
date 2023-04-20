#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}tnode;
tnode* newNode(int x){
    tnode *t;
    t=(tnode*)malloc(sizeof(tnode));
    if(t==NULL){
        printf("memory error");
        return NULL;
    }
    t->data=x;
    t->left=t->right=NULL;
    return t;
}
tnode* insertNode(tnode *root,tnode *t){
    if(root==NULL)return t;
    if(root->left==NULL){
        root->left=t;
       
    }
    else if(root->right==NULL){
        root->right=t;
       
    }
    else if(root->left->left==NULL|| root->left->right==NULL){
        root->left=insertNode(root->left,t);
    }
    else if(root->right->left==NULL|| root->right->right==NULL){
        root->right=insertNode(root->right,t);
    }
    else{
        root->left=insertNode(root->left,t);
        root->right=insertNode(root->right,t);
        
    }
    return root;
}
void preOrder(tnode *root){
    if(root==NULL)
    return;
    printf("%d  ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(tnode *root){
    if(root==NULL)
    return;
    
    postOrder(root->left);
    postOrder(root->right);
    printf("%d  ",root->data);
}
void inOrder(tnode *root){
    if(root==NULL)
    return;
    
    inOrder(root->left);
    printf("%d  ",root->data);
    inOrder(root->right);
}
int main(){
    int i,j,k,opt;
    tnode *root=NULL,*temp;
    while(1){
        printf("1.insert node\n2.Pre order\n3.In order\n4.Post order\n5.exit\nchoose option:");
        scanf("%d",&opt);
        switch(opt){
            case 1:printf("Enter element to insert:");
                   scanf("%d",&k);
                   temp=newNode(k);
                   root=insertNode(root,temp);
                   printf("Inserted successfully\n");
                   break;
            case 2:printf("Pre order traversal of tree is\n");
                   preOrder(root);
                   break;
            case 3:printf("In order traversal of tree is\n");
                   inOrder(root);
                   break;
            case 4:printf("Post order traversal of tree is\n");
                   postOrder(root);
                   break;
            case 5:exit(0);
                   
        }
    }
    return 0;
}


