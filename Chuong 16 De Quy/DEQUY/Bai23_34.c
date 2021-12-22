#include <stdio.h>

// bai 23
int DemN23(int n){
	if(n<10 && n>-10)
		return 1;
	return DemN23(n/10)+1;
}
// bai 24
int Sum24(int n){
	if(n<10 && n>-10)
		return n;
	return n%10 + Sum24(n/10);
}
// bai 25
int Tich25(int n){
	if(n<10 && n>-10)
		return n;
	return n%10 * Tich25(n/10);
}
// bai 26
int DemLe26(int n){
	/*if(!n)	return 0;
	if(n%2)	return 1+ DemLe26(n/10);
	return DemLe26(n/10);*/
	if(n<10)	return (n%2)?1:0;
	return ((n%10%2)?1:0) + DemLe26(n/10);
}
// bai 27
int Sum27(int n){
	if(!n)	return 0;
	if(n%2)	return Sum27(n/10);
	return Sum27(n/10)+n%10;
}
// bai 28
int Tich28(int n){
	if(!n)	return 1;
	if(n%2==1)	return Tich28(n/10)*(n%10);
	return Tich28(n/10);
}
// bai 29
int Find29(int n){
	if(n<10)	return n;
	return Find29(n/10);
}
// bai 30
/*void DaoNguoc30(int n){
	if(n<10)	printf("%d",n);
	else{
		printf("%d",n%10);
		DaoNguoc30(n/10);
	}
}*/
int DoiSo(int a, int dem){
	if(dem>1)	return DoiSo(a*10, dem-1);
	return a;
}
int DaoNguoc30(int n){
	if(!n)	return 0;
	return DaoNguoc30(n/10) + DoiSo(n%10,DemN23(n));
}
// bai 31
int max31(int n, int max){
	if(n<10)	return n<max ? max:n;
	return max31(n/10, max>(n%10)?max:n%10);	
}
// bai 32
int min32(int n, int min){
	if(n<10)	return n>min ? min:n;
	return min32(n/10, min<(n%10)?min:n%10);	
}
// bai 33
int ODD33(int n){
	/*if(n%2==0 && n)	return 0;
	if (n%2)	return ODD33(n/10);
	return 1;*/
	if (n<10)	return (n%2) ? 1:0;
	return (n%2)? ODD33(n/10) : 0;
}
// bai 34
int Even34(int n){
	if (n<10)	return (n%2)? 0:1;
	/*{
		if(n%2)		return 0;
		return 1;
	}*/
	if(n%2)		return 0;
	return Even34(n/10);
}
int main(){
	int n=13335;
	printf("\n\nBai 23: So chu so cua (%d) la: %d", n, DemN23(n));
	printf("\n\nBai 24: Sum cac chu so cua (%d) la: %d", n, Sum24(n));
	printf("\n\nBai 25: Tich cac chu so cua (%d) la: %d", n, Tich25(n));
	printf("\n\nBai 26: So cac chu so le cua (%d) la: %d", n, DemLe26(n));
	printf("\n\nBai 27: Tong cac chu so chan cua (%d) la: %d", n, Sum27(n));
	printf("\n\nBai 28: Tich cac chu so le cua (%d) la: %d", n, Tich28(n));
	printf("\n\nBai 29: Tim chu so dau tien cua (%d) la: %d", n, Find29(n));
	printf("\n\nBai 30: Dao nguoc cua (%d) la: %d", n,DaoNguoc30(n)); //DaoNguoc30(n);
	printf("\n\nBai 31: Max chu so cua (%d) la: %d", n, max31(n,n%10));
	printf("\n\nBai 32: Min chu so cua (%d) la: %d", n, min32(n,n%10));
	printf("\n\nBai 33: (%d) co toan chu so le: %s", n, ODD33(n)?"True":"False");
	printf("\n\nBai 34: (%d) co toan chu so chan: %s", n, Even34(n)==1?"True":"False");
	return 0;
}