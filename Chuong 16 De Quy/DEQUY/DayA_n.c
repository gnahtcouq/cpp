#include <stdio.h>

long A(int n){
	if(!n)	return 1;
	int tg = 0;
	for(int i=0; i<n; i++){
		tg += (n-1)*(n-1)*A(i);
		return tg;
	}
}
int main(){
	int n = 15;
	printf("Day A(%d): %d",n,A(n));
	return 0;
}