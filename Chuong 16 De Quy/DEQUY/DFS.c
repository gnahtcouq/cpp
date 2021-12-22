#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
int A[MAX][MAX];
int k=0;
int n;
int tham[MAX];


void ReadFile();
void DFS(int Stack[], int u);
void Output(int *a);
int main(){
	ReadFile();
	int Stack[n];
	memset(Stack,0,n*sizeof*Stack);
	
	int u=1;
	DFS(Stack,u);
	Output(Stack);
}
void ReadFile(){
	FILE *file = fopen("input.txt","r");
	if(!file)
	{
		perror("\n\n Loi mo file! ");
		exit(1);
	}
	fscanf(file,"%d\n",&n);
	while(!feof(file))
	{
		for(int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				fscanf(file,"%d ",&A[i][j]);
	}
	fclose(file);
	printf("\n\n Doc file thanh cong!\n\n");
	
	for(int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
			printf("%d ",A[i][j]);
		printf("\n");
	}
	
	memset(tham,1,n*sizeof*tham);
}
void DFS(int Stack[], int u){
	Stack[k]=u;
	tham[u]=0;
	k++;
	for(int v=1; v<=n; v++)
		if(A[u][v] && tham[v])
			DFS(Stack,v);
}
void Output(int *a){
	printf("\n\n Ket qua tim kiem theo chieu sau:\n\n\t");
	for(int i=0; i<n; i++)
		if(a[i])
			printf("%d -> ",a[i]);
}
