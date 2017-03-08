#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student_t
{
    char id[10];
    char name[20];
    int  grade;
    struct Student_t *next;
} Student;

Student *root = NULL;

void addStudent(char *id, char *name, int grade)
{
    // Tạo học sinh mới và điền thông tin
    Student *ns = (Student *)malloc(sizeof(Student));
    strcpy(ns->id, id);
    strcpy(ns->name, name);
    ns->grade = grade;
    
    // Thêm vào danh sách theo thứ tự
    
    // Nếu chưa có gì
    if(root == NULL)
    {
        root = ns;
        root->next = NULL;
        return;
    };
    
    // Nếu mà lớn hơn root
    if(ns->grade > root->grade)
    {
        ns->next = root;
        root = ns;
        return;
    };
    
    // Trường hợp nằm trong trung gian
    Student *tmp;
    for(tmp = root; tmp != NULL ; tmp=tmp->next)
    {
        // Nếu chạy đến cuối rồi thì chèn vào cuối
        if(tmp->next == NULL)
        {
            tmp->next = ns;
            ns->next = NULL;
            return;
        };
        
        // Nếu học sinh có điểm nằm ở giữa danh sách
        if(tmp->grade >= ns->grade && ns->grade >= tmp->next->grade)
        {
            ns->next = tmp->next;
            tmp->next = ns;
            return;
        }
    }
};

Student *search(char *id)
{
    Student *tmp;
    for(tmp=root; tmp!=NULL; tmp=tmp->next)
    {
        if(strcmp(tmp->id, id)==0){ return tmp; };
    };
    return NULL;
}


void action_list()
{
    Student *tmp;
    printf("%2s %-18s : %5s\n", "ID", "Name", "Grade");
    for(tmp=root; tmp!= NULL; tmp = tmp->next)
    {
        printf("%2s %-18s : %5d\n", tmp->id, tmp->name, tmp->grade);
    }
}

void del(char *id)
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
}



void action_addStudent()
{
    int i, n, grade;
    char id[10], name[20];
   printf("Ban muon nhap bao nhieu sinh vien? ");
   scanf("%d", &n);
   for(i=1; i<=n; i++)
   {
       printf("Sinh Vien %d\n", i);
       printf("ID : ");
       scanf("%s", id);
       printf("Name : ");
       scanf("\n%[a-zA-Z ]", name);
       printf("Grade : ");
       scanf("\n%d", &grade);
       addStudent(id, name, grade);
   }
};

void action_searchId()
{
  char id[10];
  Student *hs;
  printf("Nhap ID:");
  scanf("%s", id );
  hs = search(id);
  printf("Sinh vien can tim:\n");
  printf("%2s %-18s : %5d\n", hs->id, hs->name, hs->grade);
  return;  
};
void action_del(){
  char id[10];
  Student *hs;
  printf("Nhap ID:");
  scanf("%s", id );
  del(id);
  return;
}

void main()
{
  int c;
    do{
    printf("____________MENU_________________\n");
    printf("1. Chen Sinh Vien\n");
    printf("2. Tim Sinh Vien\n");
    printf("3. Xoa Sinh Vien\n");
    printf("4. Danh Sach\n");
    printf("5. Thoat\n");
    printf("chon:");
    scanf("%d", &c);
    switch(c)
    {
        case 1: action_addStudent();  break;
        case 2: action_searchId();    break;
        case 3: action_del()   ;      break;
        case 4: action_list();        break;
        
        
    }
      
    }while(c!=5);
    
}