#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define swap(a,b,c){c=a;a=b;b=c;}
void insert_sort(int a[],int dau,int la)
{
  int i,j,cuoi;
  for(i=dau+1;i<=la;i++)
    {
        j=i;
        cuoi=a[i];
        while(j>=dau&&a[j-1]>cuoi){
	        a[j]=a[j-1];
	        j=j-1;
	    }
        a[j]=cuoi;
    }
}

void quick_sort(int a[],int dau,int cuoi,int x)
{
    int i=dau,j=cuoi,pivot=a[dau];
    int tmp;
    if(cuoi-dau+1<=x)
    {
        insert_sort(a,dau,cuoi);
    }
    else{
        while(i<j){
        	while(a[i]<pivot) i++;
        	while(a[j]>pivot) j--;
        	if(i<=j){
        	    if(i<j)
        	      swap(a[i],a[j],tmp);
        	    i++;
        	    j--;
        	}
        }
    if(j>dau) quick_sort(a,dau,j,x);
    if(i<cuoi) quick_sort(a,i, cuoi,x); 
    }
}

void main()
{
    FILE *in,*out;
    in=fopen("hw11.txt","r");
    out=fopen("out.txt","w");
    if(in==NULL)
    {
      printf("FILE rong!\n");
      return;
    }
    int A[100];
    int i=0;
    while(!feof(in))
    {
      fscanf(in,"%d",&A[i]);
      i++;
    }
    printf("Nhap so x: ");
    int X;
    scanf("%d",&X);
    quick_sort(A,0,i-1,X);
    for(X=0;X<i;X++)
    {
      fprintf(out, "%d ",A[X] );
      printf("%d ",A[X]);
    }	
    printf("\n");
    fclose(in);
    fclose(out);
}
