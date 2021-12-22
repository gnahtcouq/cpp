#include<stdio.h>

int DemChuSo(int n,int dem){
	if(n<10 && n>-10)
		return dem;
	dem++;
	return DemChuSo(n/10,dem);
	
}
int DemChuSo2(int n){
	if(n<10&&n>-10)
		return 1;
	return DemChuSo2(n/10)+1;
}

int main(int argc, char *argv[]) {
	long a;
	printf("Nhap so a: ");
	scanf("%d", &a);
	printf("\nSo chu so cua %d = %d",a,DemChuSo(a,1));
	printf("\nSo chu so cua %d = %d",a,DemChuSo2(a));
	return 0;
}
