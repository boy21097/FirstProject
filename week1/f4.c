#include<stdio.h>
#include<string.h>
int main(){
  FILE *in, *out;
  char s[100];
  in = fopen("input.txt", "r");
  out= fopen("output.txt", "w");
  if(in == NULL || out == NULL){
    puts("Error!");
    return -1;
  }
  while( fgets(s, 100,in) != NULL)
    fprintf(out, "%d %s",s[strlen(s) -1] == '\n'?(int) strlen(s) - 1:(int)strlen(s), s);
  fclose(in);
  fclose(out);
  return 0;
}
