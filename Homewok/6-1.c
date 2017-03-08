#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct address_{
    char name[20], number[15], email[20];
    
    
}address;
void search(char* ten){
FILE *in;
in = fopen("in.txt", "r");
FILE *out;
out = fopen("out.txt", "w");
int i, k=0;
    if(in == NULL){ printf("File khong co du lieu\n"); exit(1); };
    address x;
    for(i=1; i<=10;i++){
        fscanf(in, "%s %s %s\n", x.name, x.number, x.email);
        if(strcmp(x.name,  ten) == 0 ) {
            printf("%-20s%-20s%-20s", x.name, x.number, x.email);
            fprintf(out, "%-20s%-20s%-20s",x.name, x.number,x.email );
            k=1;
            break;
        }    
    } 
    if(k==0) printf("Ten khong co trong danh sach");
    fclose(in);
    fclose(out);
}
void main(){
    char ten[20];
    printf("nhap ten can tim:");
    scanf("%s", ten);
    search(ten);
    return;
}