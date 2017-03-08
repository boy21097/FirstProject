#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	int maSo;
	char doChoi[31];
	struct Node *Left;
	struct Node *Right;
	struct Node *Parent;
}Node;

typedef struct CT
{
	int maSo;
	char doChoi[31];
}CT;

typedef struct soLg
{
	int soLg;
	char ten[31];
}soLg;

//CHEN NODE
Node *insert(Node *Ptr, Node *New, Node *PtrParent)
{
	if(Ptr == NULL)
	{
		return New;
	}
	else
	{
		if(Ptr->maSo < New->maSo)
		{
			Ptr->Right = insert(Ptr->Right, New, Ptr);
		}
		else if(Ptr->maSo > New->maSo)
		{
			Ptr->Left = insert(Ptr->Left, New, Ptr);
		}
		Ptr->Parent = PtrParent;
	}
	return Ptr;
}

Node *makeNode(int ma, char *sp)
{
	Node *New = (Node *)malloc(sizeof(Node));
	New->Left = NULL;
	New->Right = NULL;
	New->Parent = NULL;
	New->maSo = ma;
	strcpy(New->doChoi, sp);
	return New;
}


void readA(Node **RootA)
{
	FILE *taptin = fopen("A.txt", "r+");
	int ma;
	char tmp, sp[31];
	Node *New = NULL;
	if(taptin != NULL)
	{
		while((fscanf(taptin, "%d", &ma)) != EOF)
		{
			//printf("%d\n", ma);
			fscanf(taptin, "%c", &tmp);
			if(tmp == ' ')
			{	
				printf("%d bi lap, nhap them: ", ma);
				fgets(sp, 32, stdin);
				sp[strlen(sp) - 1] = '\0';
				New = makeNode(ma, sp);
				*RootA = insert(*RootA, New, NULL);
				//printf("%d, %s\n", New->maSo, New->doChoi);
		
				continue;

			}
			fgets(sp, 32, taptin);
			sp[strlen(sp) - 1] = '\0';
			//printf("%s\n", sp);
			New = makeNode(ma, sp);
			*RootA = insert(*RootA, New, NULL);
			//printf("%d, %s\n", New->maSo, New->doChoi);
		}
		fclose(taptin);
		
	}
	else
	{
		printf("Qua trinh mo file gap loi\n");
	}
}

int readB(CT listB[])
{
	FILE *taptin = fopen("B.txt", "r+");
	int i;
	int ma;
	char tmp, sp[31];
	if(taptin != NULL)
	{
		for(i=0; (fscanf(taptin, "%d", &ma)) != EOF; i++)
		{
			listB[i].maSo = ma;
			//printf("%d\n", ma);
			fscanf(taptin, "%c", &tmp);
			if(tmp == ' ')
			{	
				printf("%d bi lap, nhap them: ", ma);
				fgets(sp, 32, stdin);
				sp[strlen(sp) - 1] = '\0';
				strcpy(listB[i].doChoi, sp);
				printf("%d, %s\n", listB[i].maSo, listB[i].doChoi);
		
				continue;

			}
			fgets(sp, 32, taptin);
			sp[strlen(sp) - 1] = '\0';
			strcpy(listB[i].doChoi, sp);
		}
		fclose(taptin);
		return i;
	}
	else
	{
		printf("Qua trinh mo file gap loi\n");
	}
}
void inAGIAM(Node *Ptr)
{
	if(Ptr != NULL)
	{
		inAGIAM(Ptr->Right);
		printf("%d, %s\n", Ptr->maSo, Ptr->doChoi);
		inAGIAM(Ptr->Left);
	}

}
void inA(Node *Ptr)
{
	if(Ptr != NULL)
	{
		inA(Ptr->Left);
		printf("%d, %s\n", Ptr->maSo, Ptr->doChoi);
		inA(Ptr->Right);
	}

}

void inB(CT listB[], int soPTB)
{
	int i;
	for(i = 0; i < soPTB; i++)
	{	
		printf("%d, %s\n", listB[i].maSo, listB[i].doChoi);
	}
}

Node *search(Node *Ptr, int ma)
{
	if(Ptr != NULL)
	{
		if(Ptr->maSo < ma)
		{
			Ptr = search(Ptr->Right, ma);
		}
		else if(Ptr->maSo > ma)
		{
			Ptr = search(Ptr->Left, ma);
		}
	}
	return Ptr;


}

Node *find_min(Node *Ptr)
{
	if(Ptr != NULL)
	{
		while(Ptr->Left != NULL)
		{
			Ptr = Ptr->Left;
		}
	}
	return Ptr;
}
//XOA NODE
Node *delNode(Node **Root, Node *Del)  
{
	Node *Now = NULL;
	Node *Luu = (Node *)malloc(sizeof(Node));
	if(Del != NULL)
	{
//		printf("------Xoa: %s; L = %p; R = %p\n", Del->ma, Del->Left, Del->Right);
		if(Del->Left != NULL && Del->Right != NULL)
		{
			memcpy(Luu, Del, sizeof(Node));
			Now = find_min(Del->Right);
			memcpy(Del, Now, sizeof(Node));
			Del->Left = Luu->Left;
			Del->Right = Luu->Right;
			Del->Parent = Luu->Parent;
			Now = delNode(Root, Now);
			free(Now);
		}
		else if(Del->Left == NULL)
		{
			Now = Del;
			if(Del->Parent != NULL)
			{
				if(Del->Parent->Left == Del)
				{
					Del->Parent->Left = Del->Right;
			
				}
				else
				{
					Del->Parent->Right = Del->Right;
				}
			}
			else
			{
				*Root = Del->Right;
				if(	Del->Right != NULL)
				{
					Del->Right->Parent = NULL;//quan trong
				}
			}
			return Now;
		}
		else
		{
			Now = Del;
			if(Del->Parent != NULL)
			{
				if(Del->Parent->Left == Del)
				{
					Del->Parent->Left = Del->Left;
				}
				else
				{
					Del->Parent->Right = Del->Left;
				
				}
			}
			else
			{
				*Root = Del->Left;
				if(	Del->Right != NULL)
				{
					Del->Left->Parent = NULL;//quan trong
				}
			}
			return Now;
		}
	}
}

void thong_ke(Node *Ptr, soLg loaiDoChoi[])
{
	if(Ptr != NULL)
	{
		int j;
		thong_ke(Ptr->Right, loaiDoChoi);
		for(j = 0; j < 100; j++)
		{	
			if(strcmp(loaiDoChoi[j].ten, Ptr->doChoi) == 0)
			{
				loaiDoChoi[j].soLg++;
				break;
			}
			if(loaiDoChoi[j].soLg == 0)
			{
				strcpy(loaiDoChoi[j].ten, Ptr->doChoi);
				loaiDoChoi[j].soLg++;
				break;
			}
		}	
		thong_ke(Ptr->Left, loaiDoChoi);
	}







}

void menu()
{
	int luaChon, i = 0, soPTB;;
	int j;
	CT listB[50];
	Node *Now = NULL;
	Node *RootA = NULL;
	soLg loaiDoChoi[100];
	do
	{
		printf("\nNhap 1 de: Doc file A\n");
		printf("Nhap 2 de: Doc file B\n");
		printf("Nhap 3 de: Tim kiem\n");
		printf("Nhap 4 de: Tong hop\n");
		printf("Nhap 5 de: Thong ke\n");
		printf("Nhap 6 de: thoat chuong trinh\n");
		printf("Nhap de: ");
		do
		{
			scanf("%d", &luaChon);
			while(getchar() != '\n');
		}while(luaChon < 1 || luaChon > 6);
		if(luaChon == 6) break;
		switch(luaChon)
		{
			case 1:
				readA(&RootA);
				printf("\n----------------------\n");
				inA(RootA);
				break;
			case 2:
				soPTB = readB(listB);
				printf("\n----------------------\n");
				inB(listB, soPTB);
				break;
			case 3:
				printf("\nMa bi trung:");
				for(j = 0; j < soPTB; j++)
				{	
				
					Now = search(RootA, listB[j].maSo);
					if(Now != NULL)
					{
						printf("\n%d, %s\n", Now->maSo, Now->doChoi);
						delNode(&RootA, Now);
					}


				}
				printf("\n----------------------\n");
				inA(RootA);
				break;

			case 4:
				for(j = 0; j < soPTB; j++)
				{	
				
					Now = makeNode(listB[j].maSo, listB[j].doChoi);
					RootA = insert(RootA, Now, NULL);

				}	

				printf("\n----------------------\n");
				inA(RootA);
				break;

			case 5:
				for(j = 0; j < 100; j++)
				{	
					loaiDoChoi[j].soLg = 0;
					strcpy(loaiDoChoi[j].ten, "");
				}	
				thong_ke(RootA, loaiDoChoi);	
				printf("\n----------------------\n");
				for(j = 0; j < 100; j++)
				{	
					if(loaiDoChoi[j].soLg != 0)
					{
						printf("'%s' (%d)\n", loaiDoChoi[j].ten, loaiDoChoi[j].soLg);
					}
				}	
				break;
		}
	}while(luaChon);
	

}

main()
{
	menu();
}
