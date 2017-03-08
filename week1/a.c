#include <stdio.h>
/*void replace_char(char *str, char c1, char c2)
{
    int i;
    if (str == NULL) return;
    for(i=0; str[i] != '\0'; i++)
        if(str[i]==c1)
            str[i]= c2;
    printf("%c", str[i]);
}*/
void replace_char(char *str, char c1, char c2)
{
    if(str == NULL)
    return;
    while(*str != '\0'){
        if(*str == c1)
            *str =c2;
            ++str;
	}
}

int main(){
    char str[1000];
    char c1, c2;
    printf("nhap xau:");
    scanf("%s", str);
    printf("nhap xau c1 c2:");
    scanf("\n%c %c", &c1, &c2);
    replace_char((char *)&str , c1, c2);
    printf(" xau sau khi thay doi la: %s", str);
    return 0;
    
}