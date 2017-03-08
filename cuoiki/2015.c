#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Add
{
	int ID;
	char toy[30];
	int count;
}Add;
typedef struct Treenode
{
	Add Data;
	struct Treenode *left,*right;
}Treenode;
typedef struct TK
{
	char S[30];
}TK;

Treenode *makenodetree(Add T)
{
	Treenode *tmp=(Treenode*)malloc(sizeof(Treenode));
	if(tmp==NULL)
	{
		printf("Stack full\n");
		//return;
	}
	tmp->Data=T;
	tmp->left=NULL;
	tmp->right=NULL;
	return tmp;
}
void Insert(Treenode **root,Add T)//chen nut co noi dung T vao cay
{
	if(*root==NULL) *root = makenodetree(T);
	else if((*root)->Data.ID>T.ID)
		Insert(&(*root)->left,T);
	else 
		Insert(&(*root)->right,T);
}
Treenode *Search(Treenode **root,int ID1)//tim kiem
{
	Treenode *tmp = *root;
	while(tmp!=NULL)
	{
		if(tmp->Data.ID==ID1)
			return tmp;
		else if((tmp->Data.ID)>ID1)
			tmp=tmp->left;
		else tmp=tmp->right;
	}
	return NULL;
}
void inorder(Treenode *root)//in theo thu tu tang dan
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d %s \n",root->Data.ID, root->Data.toy );
	inorder(root->right);
}
void reverst_inorder(Treenode *root)//in theo thu tu giam dan
{
	if(root==NULL)
		return;
	reverst_inorder(root->right);
	printf("%d %s\n",root->Data.ID,root->Data.toy);
	reverst_inorder(root->left);
}
/*void del(Treenode **root,int ID1) //xoa em nho
{
    Student *x, *tmp;
    // Nếu id chính là học sinh đầu tiên
    if(strcmp(root->id, id) == 0)
    {
        x = root;
        root = root->next;
        free(x);
        return;
    };
    
    // Nếu không phải học sinh đầu
    for(tmp = root; tmp->next != NULL; tmp=tmp->next)
    {
        if(strcmp(tmp->next->id, id) == 0)
        {
            x = tmp->next;
            tmp->next = tmp->next->next;
            free(x);
            return;
        }
    }
}*/
void read_fileA(Treenode **root)//Doc 2 lan
{
	FILE *f1;
	f1=fopen("A.txt","r");//Mo file A.txt va read
	if(f1==NULL)//Kiem tra xem co file chua
	{
		printf("Khong the mo file.\n");
		return;
	}
	Add tmp;//tao bien de luu tru tam thoi
	char c;//doc dau TAB
	char s[100];
	while(!feof(f1))
	{
		fscanf(f1,"%[a-zA-Z0-9 ]\n", s);
		char c = s[strlen(s)-1];
		if(c==' '|| (c >='0' && c<='9')){
			sscanf(s, "%d", &tmp.ID);
			printf("Nhap them do choi cho em be co id = %d :", tmp.ID);
			scanf("%s", tmp.toy);
		}
		else{
		    tmp.count=1;
			sscanf(s, "%d %s", &tmp.ID, tmp.toy);
		}
		Insert(root,tmp);
	}
	fclose(f1);
}
int read_fileB(Add tmp[])
{
	int i=0;
	char s[100];
	char c;
	FILE *f1;
	f1=fopen("B.txt","r");
	if(f1==NULL)
	{
		printf("Khong the mo FileB\n");
		exit(1);
	}
	while(!feof(f1))
    {
		fscanf(f1,"%[a-zA-Z0-9 ]\n", s);
		char c = s[strlen(s)-1];
		if(c==' '|| (c >='0' && c<='9')){
			sscanf(s, "%d", &tmp[i].ID);
			printf("Nhap them do choi cho em be co id = %d :", tmp[i].ID);
			scanf("%s", tmp[i].toy);
		}
		else{
		    tmp[i].count=1;
			sscanf(s, "%d %s", &tmp[i].ID, tmp[i].toy);
		}
		i++;
	}
	return i;
}
void inmang(Add tmp[],int N)
{
	int i;
	for(i=0;i<N;i++)
		printf("%d %s\n",tmp[i].ID,tmp[i].toy);
}
void inthongtin(Treenode *tmp)
{
	printf("%d %s\n",tmp->Data.ID,tmp->Data.toy);
}
void Ktra_trung(Treenode **root,Add tmp[],int N)
{
	int i;
	Treenode *cur;
	for(i=0;i<N;i++)//duyet mang
	{
		cur=Search(root,tmp[i].ID);// tim kiem phan tu trung tren cay
		if(cur!=NULL)//neu trung
		{
			inthongtin(cur);	
		}
	}
}
void tonghop(Treenode **root, Add tmp[], int N)//them phan tu trong mang vao cay
{
	int i;
	for(i=0;i<N;i++)
		Insert(root,tmp[i]);
}
void menu()
{
	Add tmp[10];
	int n;
	Treenode *root=NULL;
	int i;
	while(1)
	{
		printf("\t\t---Menu Chuong Trinh---\n");
		printf("\n1-Doc File A");
		printf("\n2-Doc File B");
		printf("\n3-Ktra trung");
		printf("\n4-Tong Hop");
		printf("\n5-Thong Ke");
		printf("\n6-Ket thuc chuong trinh");
		printf("\nChon chuc nang: ");
		scanf("%d",&i);
		switch(i)
		{
			case(1): read_fileA(&root); printf("In cay A:\n"); inorder(root); break;
			case(2): n=read_fileB(tmp); inmang(tmp,n); break;
			case(3): Ktra_trung(&root,tmp,n); printf("Cay sau khi xoa nut trung\n"); inorder(root); break;
			case(4): tonghop(&root,tmp,n); reverst_inorder(root); break;
			case(5): break;
			case(6): return; 
		}
	}
}
void main()
{
	menu();
}
