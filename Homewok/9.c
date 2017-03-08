#include <stdio.h>
#include <string.h>

const char FIN[]  = "hw9.txt";
const char FOUT[] = "out.txt";
// Biến lưu số từ khác nhau
int count=0;
    
// Biến lưu tần số
struct sFreq
{
        char word[100];
        int freq;
} freq[100];

int length;
char s[100][100];

void WordCound()
{
   // Hàm check từ
    void check(char s[100])
    {
        
        int i;
        for(i=0; i<count; i++)
        {
            if(strcmp(s, freq[i].word) == 0){freq[i].freq++; return; };
        };
        strcpy(freq[count].word, s); freq[count].freq = 1; count++;
    }
    
    int i;
    for(i=0; i<length; i++){ check(s[i]);   };
    
    for(i=0; i<count; i++)
    {
        printf("chu '%s' xuat hien : %d lan\n", freq[i].word, freq[i].freq);
    }
};

void ScanWord()
{
    FILE *f = fopen(FIN, "r");
    for(length=0; !feof(f); length++)  {  fscanf(f, "%s", s[length]);  
    };
}

void main()
{
    ScanWord();
    WordCound();
}
