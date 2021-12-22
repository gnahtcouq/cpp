#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dem=0, n;
void Out(int a[], int n){
	printf("\n%d. ",++dem);
	for(int i=0; i<n; i++)
		printf("%d ",a[i]);
}
void SinhChuoiNhiPhan(){
	int a[n], i;
	memset(a,0,n*sizeof*a);
	do{
		Out(a,n);
		i=n-1;
		while(i>=0 && a[i]) i--;
		if(i>=0){
			a[i]=1;
			for(int j=i+1; j<n; j++)	a[j]=0;
		}
	}while(i>=0);
	
}
int *A;
void SinhChuoi_DeQuy(int i){
	for(int j=0; j<=1; j++){
		A[i] = j;
		if(i==n-1)	Out(A,n);
		else SinhChuoi_DeQuy(i+1);
	}
}
int main(){
	n = 3;
//	SinhChuoiNhiPhan();
	A = malloc(n*sizeof(int));
	SinhChuoi_DeQuy(0);
	free(A);
	return 0;
}