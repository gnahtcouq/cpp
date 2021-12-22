#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

int A[MAX][MAX];
int n;
int tham[MAX], Queue[MAX];


void ReadFile();
void BFS(int i);
int demLT()
{
	int t = 1;
	for(int i = 1; i <= n; i++)
		if(tham[i])
		{
			BFS(i);
			t++;
		}
	return t;
}
void Out()
{
	for(int i=1; i<=n; i++)
		printf("%d -> ",Queue[i]);
}
int main()
{
	ReadFile();
	printf("\n\n Ket qua tim kiem theo chieu rong: \n\t");
	for(int i = 1; i <= n; i++)
		if(tham[i])
			BFS(i);
	Out();
	printf("\n\n So thanh phan: %d",demLT());
	return 0;
}
void ReadFile()
{
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

	for(int i=1; i<=n; i++) tham[i]=1;
}
void BFS(int i)
{
	int start = 1, end=1;
	tham[i]=0;
	Queue[end]=i;
	while(start<=end)
	{
		int x = Queue[start];

//		printf("%d -> ",x);
		start++;
		for(int v=1; v<=n; v++)
			if(A[x][v] && tham[v])
			{
				end++;
				Queue[end] = v;
				tham[v]=0;
			}
	}
}
