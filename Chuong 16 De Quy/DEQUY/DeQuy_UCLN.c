#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int UCLN (int a, int b) {
	if(a%b==0)
		return b;
	else
		return UCLN(b,a%b);
}
int main(int argc, char *argv[]) {
	int a, b;
	printf("Nhap 2 so a, b: ");
	scanf("%d %d", &a,&b);
	printf("UCLN(%d,%d) = %d",a,b,UCLN(a,b));
	return 0;
}

