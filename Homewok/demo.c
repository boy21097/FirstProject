#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    // Khai báo file
    FILE *in;
    in = fopen("in.txt", "rb");
    if(in == NULL){ printf("Error when open file!\n"); exit(1); };
    
    char name[100], number[100], address[100];
    int i;
    while(1)
    {
        if(!feof(in))
        {
            fscanf(in, "%s %s %s\n", name, number, address);
            printf("%10s %10s %10s\n", name, number, address);
        }
    }
}