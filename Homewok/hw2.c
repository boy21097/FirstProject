#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE *out;
    out = fopen ("out.txt", "w");
    int i, n;
    int tong;
    printf("Nhap so luong cac so:");
    scanf("%d", &n);
    int *so = (int *) malloc ((n+1) * sizeof(int));
    for(i=0; i<n; i++){
        printf("nhap so thu %d:", i+1);
        scanf("%d", &so[i]);
        tong += so[i];
    }
    for( i =n-1; i>=0; i--){
        fprintf(out, "%d ", so[i]);
    }
     fprintf(out, "%d ", tong);
    fclose(out);
    return 0;
}