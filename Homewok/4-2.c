#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Khai báo Stack
char stack[1000];
int length = 0;

void push(char x){    stack[length++] = x;     };
char pop()       { return  stack[--length];      };
char top()       { return stack[length];       };
int  isEmpty()   { return length == 0; };
int compare(char x, char y)
{
    if((x == '/' || x == '*') && (y == '+' && y=='-'))
    { return 1; }else{ return 0; };
    
 
    
};

void convert(char infix[]) // Trung tố sang hậu tố
{
    int i; char x;
    for(i=0; i<strlen(infix); i++)
    {
        if(infix[i] >= '0' && infix[i] <= '9')
        {
            printf("%c", infix[i] ); 
            continue; 
        };
        if(isEmpty()){ push(infix[i]); continue; };
        while(!isEmpty()&& compare(infix[i], top()))
        {
           printf("%c", pop()); 
        };
        push(infix[i]);
    };
    while(!isEmpty()){  printf("%c", pop());     };
};

void main()
{
    char x[100];
    printf("Nhap bieu thuc:");
    scanf("%s", x);
    printf("bieu thuc sau khi doi la:");
    convert(x);
    printf("\n");
}