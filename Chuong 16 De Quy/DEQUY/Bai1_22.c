#include <stdio.h>
#include <math.h>
// bai 1
long Sum1(int n){
	if(n==1)	return 1;
	return n+Sum1(n-1);
}

// bai 2
long Sum2(int n){
	if(n==1)	return 1;
	return  n*n + Sum2(n-1);
}
// bai 3
float Sum3(int n){
	if (n==1)	return 1;
	return 1.0/n + Sum3(n-1);
}
// bai 4
float Sum4(int n){
	if (n==1)	return 0.5;
	return 1.0/(2*n) + Sum4(n-1);
}
// bai 5
float Sum5(int n){
	if (!n)	return 1;
	return 1.0/(2*n+1) + Sum5(n-1);
}
// bai 6
float Sum6(int n){
	if(n==1)	return 0.5;
	return 1.0/(n*(n+1)) + Sum6(n-1);
	/*float sum = 0;
	for(int i=1; i<=n; i++)
		sum += 1.0/(i*(i-1));
	return sum;*/
}
// bai 7
float Sum7(int n){
	if(n==1)	return 0.5;
	return n*1.0/(n+1) + Sum7(n-1);
}
// bai 8
float Sum8(int n){
	if(n==0)	return 0.5;
	return (2*n+1)*1.0/(2*n+2) + Sum8(n-1);
}
// bai 9
long GiaiThua(int n){
	if (n==0)	return 1;
	return n*GiaiThua(n-1);
}
// bai 10: T(x,n) = x^n = x * x^(n-1) n>0
//					  = 1/x * x^(n+1) n<0
//					  = 1 n=0
float T10(float x, int n){
	if(!n)	return 1;
	if(n<0)	return 1/x*T10(x,n+1);
	return x*T10(x,n-1);
}
// bai 11
long Sum11(int n){
	if(n==1)	return 1;
	/*long s=0;
	for(int i = 1; i<=n; i++)
		s += GiaiThua(i);
	return s;*/
	//return GiaiThua(n-1)*n + Sum11(n-1);
	return GiaiThua(n)+Sum11(n-1);
}
// bai 12
float Sum12(int x, int n){
	if(n==1)	return x;
	return T10(x,n) + Sum12(x,n-1);
}
// bai 13
float Sum13(int x, int n){
	if(n==1)	return x*x;
	return T10(x,2*n)+Sum13(x,n-1);
}
// bai 14
float Sum14(int x, int n){
	if(n==0)	return x;
	return T10(x,2*n+1)+Sum14(x,n-1);
}
// bai 15
float Sum15(int n){
	if(n==1)	return 1;
	return 1.0/Sum1(n) + Sum15(n-1);
}
// bai 16
float Sum16(float x, int n){
	if(n==1)	return x;
	return T10(x,n)/GiaiThua(n) + Sum16(x,n-1);
}
// bai 17
float Sum17(float x, int n){
	if(n==0)	return 1;
	return T10(x,2*n)/GiaiThua(2*n) + Sum17(x,n-1);
}
// bai 18
int ULMax(int n, int x){
	if(x%n==0 && n%2) return n;
	return ULMax(n-1,x);
}
/*int ULMax(int n){
	if(n%2) return n;
	return ULMax(n/2);
}*/
// bai 19
float Sum19(float n){
	if(n==1)	return sqrt(2);
	return sqrt(2 + Sum19(n-1));
}
// bai 20
float Sum20(float n){
	if(n==1)	return 1;
	return sqrt(n + Sum20(n-1));
}
// bai 21
float Sum21(float n, float i){
	if(n==i)	return sqrt(n);
	return sqrt(i + Sum21(n,i+1));
}
// bai 22
float Sum22(int n){
	if(n==1) 	return 1.0/2;
	return 1.0/(1+Sum22(n-1));
	
}
/*float FiBo(float n){
	if(!n || n==1)	return 1;
	return FiBo(n-1)+FiBo(n-2);
}
float Sum22(int n){
	return FiBo(n)/FiBo(n+1);
}*/

int main(){
	int n = 5, x = 5;
	printf("\n\nBai 2: Sum2(%d) = %d", n, Sum2(n));
	printf("\n\nBai 3: Sum3(%d) = %g", n, Sum3(n));
	printf("\n\nBai 4: Sum4(%d) = %g", n, Sum4(n));
	printf("\n\nBai 5: Sum5(%d) = %g", n, Sum5(n));
	printf("\n\nBai 6: Sum6(%d) = %g", n, Sum6(n));
	printf("\n\nBai 7: Sum7(%d) = %g", n, Sum7(n));
	printf("\n\nBai 8: Sum8(%d) = %g", n, Sum8(n));
	printf("\n\nBai 9: GiaiThua(%d) = %d", n, GiaiThua(n));
	printf("\n\nBai 10: T10(%d,%d) = %g", x, n, T10(x,-5));
	printf("\n\nBai 11: Sum11(%d) = %d", n, Sum11(n));
	printf("\n\nBai 12: Sum12(%d,%d) = %g", x, 3, Sum12(x,3));
	printf("\n\nBai 13: Sum13(%d,%d) = %g", x, 3, Sum13(x,3));
	printf("\n\nBai 14: Sum14(%d,%d) = %g", x, 3, Sum14(x,3));
	printf("\n\nBai 15: Sum15(%d) = %g", n, Sum15(n));
	printf("\n\nBai 16: Sum16(%d,%d) = %g", x, 3, Sum16(x,3));
	printf("\n\nBai 17: Sum17(%d,%d) = %g", x, 3, Sum17(x,3));
	printf("\n\nBai 18: Sum18(%d) = %d", n, ULMax(124,124));
	printf("\n\nBai 19: Sum19(%d) = %g", n, Sum19(n));
	printf("\n\nBai 20: Sum20(%d) = %g", n, Sum20(n));
	printf("\n\nBai 21: Sum21(%d) = %g", n, Sum21(n,1));
	printf("\n\nBai 22: Sum22(%d) = %g", n, Sum22(n));
	
	return 0;
}