#include <stdio.h>
#include <string.h>

void SelectionSort(char str[10][100], int length)
{
    int i; // Con chạy
    
    // Hàm đổi chỗ 2 phần tử
    void swap(int a, int b)
    {
        char c[100];
        strcpy(c,str[a]);
        strcpy(str[a] , str[b]);
        strcpy(str[b] ,c);
    };
    
    /*
    Coi như từ vị trí 0 đến vị trí i-1 đã được sắp xếp
    Hàm này sẽ chèn phần tử ở vị trí thứ i vào đằng trước
    tại vị trí thích hợp để từ mảng từ 0 đến i là dãy có thứ tự
    */
    void insert(int i)
    {
        // Liên tục so sánh từ về 0
        for(; i>0; i--)
        {
            // Nếu thấy phần tử đằng trước lớn hơn thì đổi chỗ
            if(strcmp(str[i-1], str[i]) > 0){ swap(i, i-1); };
        };
    };
    
    // Chèn lần lượt kí tự từ vị trí 1 vào xâu đã được sắp xếp trước nó
    for(i=1; i<length; i++){ insert(i); };
};

void main()
{
    int i;
    // Khai báo số phần tử tối đa
    int n = 10;
    // Khai báo mảng gồm n phần tử, mỗi phần tử là 1 xâu (max 100 kí tự)
    char str[n][100];
    char x[100], y[100], z[100];
    // Nhập vào từ bàn phím
    printf("Enter 10 words, sparate by space\n");
    for(i=1; i<=n; i++)
    {
      scanf("%s", str[i-1]);   
    };
    
    
    // Sắp xếp
    SelectionSort(str, n);
    
    // In ra
    printf("Sorted array\n");
    for(i=1; i<=n; i++)
    {
        printf("%s\n", str[i-1]);    
    }
    
}