#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
int *a,n;
int *check, dem=0;
void Out(){
	printf("\n%d. ",++dem);
	for(int i=1; i<=n; i++)
		printf("%d ",a[i]);
}

void HoanVi(int i){
	for(int j=1; j<=n; j++){
		if(!check[j]){
			a[i]=j;
			if(i==n)
				Out();
			else {
				check[j]=1;
				HoanVi(i+1);
				check[j]=0;
			}
		}
	}
}
int main(){
	printf("\n Nhap n = ");
	scanf("%d",&n);
	a = malloc((n+1)*sizeof(int));
	check = calloc((n+1),sizeof(int));
//	memset(check,0,(n+1)*sizeof(int));
	HoanVi(1);
	free(a);
	free(check);
	return 0;
}