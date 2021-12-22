#include <stdio.h>

void ThapHaNoi(int n, char A, char B, char C, int *dem){
	if(n==1){
		*dem+=1;
		printf("\n%d. %c --> %c",*dem, A,C);
	}
		
	else{
		ThapHaNoi(n-1,A,C,B,dem);
		ThapHaNoi(1,A,B,C,dem);
		ThapHaNoi(n-1,B,A,C,dem);
	}
}
int main(){
	int dem=0;
	ThapHaNoi(4,'A','B','C',&dem);
	printf("\n%d",dem);
	return 0;
}