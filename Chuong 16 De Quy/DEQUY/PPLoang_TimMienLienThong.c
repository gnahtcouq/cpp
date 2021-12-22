#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int A[MAX][MAX], n;
int Check[MAX][MAX];
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
		for(int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				fscanf(file,"%d ",&A[i][j]);
	}
	fclose(file);
	printf("\n\n Doc file thanh cong!\n\n");

	for(int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
			printf("%d ",A[i][j]);
		printf("\n");
	}
}

void Loang(int i, int j)
{
	Check[i][j]=1;
	if(A[i-1][j]==A[i][j] && !Check[i-1][j] && i>0)
		Loang(i-1,j);
	if(A[i+1][j]==A[i][j] && !Check[i+1][j] && i<n)
		Loang(i+1,j);
	if(A[i][j-1]==A[i][j] && !Check[i][j-1] && j>0)
		Loang(i,j-1);
	if(A[i][j+1]==A[i][j] && !Check[i][j+1] && j<n)
		Loang(i,j+1);
}

int main()
{
	ReadFile();
	for(int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			Check[i][j]=0;

	int dem=0;
	for(int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if(!Check[i][j])
			{
				dem++;
				Loang(i,j);
			}

	printf("\n\n\n\t Ket qua: %d",dem);
	return 0;
}