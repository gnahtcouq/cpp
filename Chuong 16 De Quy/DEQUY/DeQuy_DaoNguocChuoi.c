#include <stdio.h>
#include <string.h>

void DaoNguoc(char *s, int start, int end)
{
	if(start >= end)
		return;
	char c;
	c = *(s+start);
	*(s+start) = *(s+end);
	*(s+end) = c;
	return DaoNguoc(s,++start, --end);
}
void DaoNguoc2(int n, char c[]){
	if(!n)
		printf("%c",c[0]);
	else{
		printf("%c",c[n]);
		DaoNguoc2(n-1,c);
	}
}
int main(int argc, char *argv[])
{
	char s[100];
	printf("Nhap chuoi: s = ");
	gets(s);
	DaoNguoc(s,0,strlen(s)-1);
	printf("Chuoi dao nguoc la: ");
	puts(s);
	
	DaoNguoc2(strlen(s)-1,s);
	return 0;
}

