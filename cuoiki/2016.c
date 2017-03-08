#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 typedef  struct quanly_{
     char name[30];
     char phone[30];
     int a, b, c;
     struct quanly_ *next;
 }quanly;
 quanly *root= NULL;

 void insert(char *name, char *phone){
    quanly *x= (quanly*)malloc(sizeof(quanly));
    strcpy(x->name, name);
    strcpy(x->phone, phone);
    x->next = root;
    root = x;
     return;
 }
  void inserthang(int a, int b, int c){
      quanly *tmp;
    quanly *x= (quanly*)malloc(sizeof(quanly));
    x->a = a;
    x->b = b;
    x->c = c;
    x->next = root;
    root = x;

 }
 void docfile(){
 FILE *f;
 f = fopen("danhsach.txt", "r");
 char name[30];
 char phone[30];
 	if(f==NULL)
	{
		printf("Khong the mo FileB\n");
		exit(1);
	}
	while(!feof(f)){
	fscanf(f, "%s %s\n", name, phone );
	insert(name, phone);
	}
	fclose(f);
}
void them(){
    char name[30];
    char phone[30];
    printf("Nhap thong tin khach hang:\n");
    printf("name: ");
    scanf("%s", name);
    printf("SDT: ");
    scanf("%s", phone);
    insert(name, phone);
}
void banhang(){
    int a,b,c;
    quanly *tmp;
    for(tmp = root; tmp != NULL; tmp = tmp->next)
    {
        printf("khach hang %s mua bao nhieu san pham A B C\n", tmp->name);
        scanf("%d %d %d", &a, &b, &c);
        if(a<=0){
             printf("nhap lai so san pham A:");
             scanf("%d", &a);
        }
        if(b<=0){
             printf("nhap lai so san pham B:");
             scanf("%d", &b);
        }
        if(c<=0){
             printf("nhap lai so san pham C:");
             scanf("%d", &c);
        }
        inserthang(a, b, c);
    }
}
void inds(){
     quanly *tmp;
     FILE *out;
     out = fopen("banhang.txt", "w");
     for(tmp = root; tmp != NULL; tmp = tmp->next){
         fprintf(out, "%d %d %d\n", tmp->a, tmp->b, tmp->c);
     }
     fclose(out);
} 
void action_list()
{
    quanly *tmp;
    printf("%-20s %-18s\n", "Name",  "SDT");
    for(tmp=root; tmp != NULL; tmp = tmp->next)
    {
        printf("%-20s %-18s\n", tmp->name, tmp->phone);
    }
}
void main(){
    int i;
	while(1)
	{
		printf("\t\t---Menu Chuong Trinh---\n");
		printf("\n1-Doc File Dansach.txt");
		printf("\n2-Them nguoi mua vao hang doi");
		printf("\n3-Ban hang");
		printf("\n4-Ghi thong tin sau 1 ngay");
		printf("\n5-Thong Ke thong tin ban hang");
		printf("\n6-Yeu cau dac biet");
		printf("\nChon chuc nang: ");
		scanf("%d",&i);
		switch(i)
		{
			case(1):  docfile(); action_list(); break;
			case(2):  them();  break;
			case(3):  banhang();inds(); break;
			case(4):  break;
			case(5): break;
			case(6): return; 
		}
	}
}
