#include <stdio.h>
void xuly(int so);
void chan(int x){
	printf("%d, ",x/2);
	xuly(x/2);
}

void le(int x){
	printf("%d, ",x*3+1);
	xuly(x*3+1);
}

void xuly(int so){
	if(so%2==0)
		chan(so);
	else if (so>1) le(so);
}

int main(){
	xuly(12);
	return 0;
}