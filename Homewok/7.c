
#include <stdlib.h>
#include <stdio.h>
 
typedef int elementType;
typedef struct _treeNode
{
    elementType inf;
    struct _treeNode *left, *right;
} treeNode;
 
treeNode *maketreenode(elementType X)
{
    treeNode *t = (treeNode*)malloc(sizeof(treeNode));
    if(t==NULL) return NULL;
    t->inf = X;
    t->left = NULL;
    t->right = NULL;
    return t;
}
 
void preOrder(treeNode *root)
{
    if(root==NULL) return;
    else
    {
        printf("%d ", root->inf);
        if(root->left!=NULL)
            preOrder(root->left);
        if(root->right!=NULL)
            preOrder(root->right);
    }
}
 
void inOrder(treeNode *root)
{
    if(root==NULL) return;
    else
    {
        if(root->left!=NULL)
            inOrder(root->left);
        printf("%d ", root->inf);
        if(root->right!=NULL)
            inOrder(root->right);
    }
}
 
void postOrder(treeNode *root)
{
    if(root==NULL) return;
    else
    {
        if(root->left!=NULL)
            postOrder(root->left);
        if(root->right!=NULL)
            postOrder(root->right);
        printf("%d ", root->inf);
    }
}
 
 
int countNodes(treeNode *root)
{
    if(root==NULL) return 0;
    else
    {
        int i = 0,j = 0;
        if(root->left!=NULL)
            i = countNodes(root->left);
        if(root->right!=NULL)
            j = countNodes(root->right);
        return i+j+1;
    }
}
 
int height(treeNode *root)
{
    if(root==NULL) return 0;
    else
    {
        int i = 0,j = 0;
        if(root->left!=NULL)
            i = height(root->left);
        if(root->right!=NULL)
            j = height(root->right);
        if(i>j) return i+1;
        else return j+1;
    }
}
 
treeNode *taocaynhiphandaydu(int k, int i)
{
    if(k<=0) return NULL;
    if(k==1)
    {
        treeNode *t = maketreenode(i);
        return t;
    }
    else
    {
        treeNode *t = maketreenode(i);
        treeNode *contrai = taocaynhiphandaydu(k-1,2*i);
        treeNode *conphai = taocaynhiphandaydu(k-1,2*i+1);
        t->left = contrai;
        t->right = conphai;
        return t;
    }
}
 
int kiemtracaynhiphandaydu(treeNode *root)
{
    if(root==NULL) return 0;
    else{
        int i=0,j=0,hi=0,hj=0;
        if(root->left!=NULL)
        {
            i = kiemtracaynhiphandaydu(root->left);
            hi = height(root->left);
        }
        if(root->right!=NULL)
        {
            j = kiemtracaynhiphandaydu(root->right);
            hj = height(root->right);
        }
        if(((i==1)&&(j==1)&&(hi==hj))||(root->left==NULL&&root->right==NULL))
            return 1;
        return 0;
    }
}
 
int main()
{
    treeNode *root = NULL;
    root = taocaynhiphandaydu(3,1);
    preOrder(root);
    if(kiemtracaynhiphandaydu(root))
    printf("\nDay la Cay nhi phan hoan chinh \n");
    else
    printf("\nDay khong phai cay nhi phan hoan chinh\n");
    return 1;
}