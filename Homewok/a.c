#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 50

// Cấu trúc chứa thông tin danh bạ
typedef struct{
  char name[30], phone[15], mail[30];
}Address;

// Cấu trúc của một node trong danh sách
typedef struct Node_{
  Address data; //Dữ liệu
  struct Node_* next; // Liên kết đến node tiếp theo
}Node;

// Mỗi con trỏ trỏ đến 1 node là 1 vị trí
typedef Node* Position;

// Khai báo 2 vị trí đầu và cuối cho danh sách
typedef struct{
  Position Rear, Front;
}Queue;


// Hàm tạo dữ liệu
Address cr(char * nam, char * phone, char * mail){
  Address * x = (Address *) malloc(sizeof(Address));
  strcpy(x->name, nam);
  strcpy(x->phone, phone);
  strcpy(x->mail, mail);
  return *x;
}

//
int createData(){
  FILE * f = fopen("in.dat", "w+b");
  Address arr[10];
  arr[0] = cr("Le Cong Hau","0456789","asd1@mail.com");
  arr[1] = cr("Chu van tin","0456789","asd2@mail.com");
  arr[2] = cr("Le Van Bien","0456789","asd3@mail.com");
  arr[3] = cr("Le Cong Cuto","0456789","asd4@mail.com");
  arr[4] = cr("Le Cong KO","0456789","asd5@mail.com");
  arr[5] = cr("Le Cong Hu","0456789","asd6@mail.com");
  arr[6] = cr("Le Cong Liu","0456789","asd7@mail.com");
  arr[7] = cr("Le Kik Lo","0456789","8@mail.com");
  arr[8] = cr("Le Cong Hau","0456789","acc9@mail.com");
  arr[9] = cr("Le Cong Hau","0456789","cc10@mail.com");

  fwrite(arr, sizeof(Address), 10, f);
  fclose(f);
  return 0;
}

//****************************************************************
// Kiểm tra node có rỗng hay không
int isEmpty(Queue * Qu){
  return Qu->Front == NULL;
}
// Tạo một danh sách trống
void makeNullQueue(Queue *q ){
  q ->Rear = q->Front = NULL;
}

// Thêm một phần tử vào
void enQueue(Queue* q, Address *x){
  Node * tmp = (Position) malloc(sizeof(Address));
  tmp->data = *x;
  tmp->next = NULL;
  if(isEmpty(q)){
    q->Front = q->Rear = tmp;
  }
  else{
    q->Rear->next = tmp;
    q->Rear = tmp;
  }
}

// Lấy một phần tử ra
Address deQueue(Queue * q){
  Address x;
  if(isEmpty(q))
    puts("Stack Empty");
  else{
    Position tmp = q->Front;
    q->Front = q->Front->next;
    Address x = tmp->data;
    free(tmp);
  }
  return x;
}

// Main
int main(){
  Queue* Qu = (Queue*)malloc (sizeof(Queue));
  makeNullQueue(Qu);
  Address da[1];
  FILE *in, *out;
  in = fopen("in.dat", "rb");
  out = fopen("outnew.dat", "wb");
  if(in == NULL){
    puts("Chua co file, Nhap Enter de tao file in.dat.");
    getchar();
    createData();
    in = fopen("in.dat", "rb");
  }
  while(!feof(in)){
    if( fread(da, sizeof(Address), 1, in)){
      printf("%-16s%-16s%-16s\n", da->name, da->phone, da->mail);
      enQueue(Qu, da);
    }
  }
  while(!isEmpty(Qu)){
    *da = deQueue(Qu);
    fwrite(da, sizeof(Address), 1, out);
  }
  fclose(in);
  fclose(out);
  return 0;
}
