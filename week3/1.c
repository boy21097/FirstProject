#include<stdio.h>
#include<stdlib.h>

typedef struct {
  char name[30];
  char phone[15];
  char email[30];
}Address;

typedef struct AddressList_{
  Address addr;
  struct AddressList_ * next;
} AddressList;
AddressList *root, *cur;

void insert (Address *addr){
  AddressList *new = ( AddressList*)malloc(sizeof(AddressList));
  new->addr = *addr;
  if(root == NULL){
    cur = root = new;
    new->next =NULL;
  }
  else{
    new->next = cur->next;
    cur->next = new;
    cur = new;
  }
}
void delNode(int index){
  AddressList * p = root, *tmp;
  int i = 0;
  if (index == 0){
    root = p->next;
    free(p);
  }
  else{
    for(; i < index - 1; i++)
      p = p->next;
    tmp = p->next;
    p->next = tmp->next;
    free(tmp);
  }
}
void showList(){
  AddressList *p = root;
  while(p != NULL){
    printf("%-20s%-15s%-20s\n", p->addr.name, p->addr.phone, p->addr.email);
    p = p->next;
  }
}
int main(){
  Address tmp;
  int n,i;
  printf("So luong ptu: ");
  scanf("%d", &n);
  for( i = 0; i< n; i++){
    printf("Data %d:", i + 1);
    scanf("%s%s%s", tmp.name, tmp.phone, tmp.email);
    insert(&tmp);
  }
  puts("Danh sach lien he:");
  showList();
  printf("Xoa phan tu thu: ");
  scanf("%d", &n);
  delNode(n);
  puts("\nDanh sach lien he moi:");
  showList();
  return 0;
}
  
