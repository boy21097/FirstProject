#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Queue_Node
{
    char name[100], number[100], email[100];
    struct Queue_Node *prev, *next;    
} QueeNode;

QueeNode *root = NULL;
QueeNode *tail = NULL;

void push(char *name, char *number, char *email)
{
    
    QueeNode *n = (QueeNode *)malloc(sizeof(QueeNode));
    strcpy(n->name,   name);
    strcpy(n->number, number);
    strcpy(n->email,  email);
    n->next = NULL;
    n->prev = NULL;
    
    // Nếu chưa có gì
    if(root == NULL)
    {
        root = n; tail=n; return;
    };
    
    n->next = root; root->prev = n; root=n; 
};

QueeNode *pop()
{
   if(tail == NULL) { return NULL; };
   QueeNode *x = tail;
   if(tail->prev != NULL) // Trước đuôi có 1 node
   {
       tail->prev->next = NULL; // Cắt đuôi
       tail  = tail->prev; // Đổi đuôi về trước
   }else{
       // Nếu còn 1 node thì cắt đi chẳng còn gì cả
       root = NULL;
       tail = NULL;
   }
   
   
   return x; // Trả lại cái vừa cắt được
};


void list()
{
    QueeNode *tmp;
    for(tmp=root; tmp != NULL; tmp=tmp->next)
    {
        printf("%10s %20s %20s\n", tmp->name, tmp->number, tmp->email);
    };
}

void fileRead()
{
    QueeNode *x;
    
    // Khai báo file
    FILE *in;
    in = fopen("in.txt", "rb");
    FILE *out;
    out = fopen("out.txt", "w");
    
    if(in == NULL){ printf("Error when open file!\n"); exit(1); };
    char name[100], number[100], address[100];
    while(!feof(in))
    {
        fscanf(in, "%s %s %s", name, number, address);
        push(name, number, address);
    }
    
    while(x = pop())
    
    {
        fprintf(out, "%-20s %-10s %-20s\n", x->name, x->number, x->email);
    };
    fclose(in);
    fclose(out);
    return;
}
void main()
{
    fileRead();
    printf("----\n");
}