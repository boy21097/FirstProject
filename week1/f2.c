#include<stdio.h>

int main(){
  FILE *in, *out;
  char c;
  in = fopen("in.txt", "r");
  out = fopen("out.txt", "w");
  if( in == NULL || out == NULL){
    puts("File access Error!");
    return -1;
  }
  while( (c = fgetc(in)) != EOF)
      if( c >= 'a' && c <= 'z')
	fputc(c -'a' +'A', out);
      else if (c >= 'A' && c <= 'Z')
	fputc(c - 'A' + 'a', out);
      else
	fputc(c,out);   
    fclose(in);
    fclose(out);
  return 0;
}
