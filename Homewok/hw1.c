#include <stdio.h>
int main(int argc, char* argv[]){
    FILE *in, *out;
    char c[100];
    int i=1;
    if( argc != 3){
        puts("Loi tham so!");
        return -1;
    }
    in = fopen(argv[1],"r");
    out= fopen(argv[2], "w");

    if(in ==NULL || out == NULL){
    puts("file khong co noi dung");
    return -1;
    }
    while ( fgets(c, 100, in) != NULL ){
        fprintf(out, "%d %s", i, c);
        ++i;
    }
    fclose(in);
    fclose(out);
}