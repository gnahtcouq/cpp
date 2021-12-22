#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int A[MAX][MAX];
int count=0;
int F[MAX]= {0};

void WriteFile(int A[][MAX], int count)
{
	char filename[100];
	printf("\nNhap ten file: ");
	fflush(stdin);
	gets(filename);

	FILE *file = fopen(filename,"w");
	if(!file)
	{
		perror("\n\n Khong the tao file!");
		exit(1);
	}
	int n;
	fprintf(file,"%d\n",count);
	for(int i=0; i<count; i++)
	{
		for(int j=0; j<count; j++)
			fprintf(file,"%d ",A[i][j]);
		fputc('\n',file);
	}
	fclose(file);
}
void ReadFile(int A[][MAX], int *count)
{
	char filename[100];
	//printf("\nNhap ten file: "); fflush(stdin);	gets(filename);

	FILE *file = fopen("Matrix.txt","r");
	if(!file)
	{
		perror("\n\n Khong the tao file!");
		exit(1);
	}
	fscanf(file,"%d",count);
	int j=0;
	while(!feof(file))
	{
		for(int i=0; i<*count; i++)
			for(int j=0; j<*count; j++)
				fscanf(file,"%d ",&A[i][j]);
	}
}
void Output()
{
	for(int i=0; i<count; i++)
	{
		for(int j=0; j<count; j++)
			printf("\t%d",A[i][j]);
		printf("\n");
	}
}
void BFS(int Q[],int u)
{
	for(int i=0; i<count; i++)	F[i]=1;
	F[u]=0;
	int head=0, tail=0;
	Q[tail]=u;
//	printf("%d -> ",u);
	while(tail<=head)
	{
		int x = Q[tail];
		for(int v=0; v<count; v++)
		{
			if(A[x][v] && F[v])
			{
				head++;
				Q[head]=v;
				F[v]=0;
//				printf("%d -> ",v);
			}
		}
		tail++;
	}

}
int k=0;

void DFS(int S[], int u)
{
	for(int i=0; i<count; i++)	F[i]=1;
	F[u]=0;
	S[k]=u;
	k++;
	for(int v=0; v<count; v++)
		if(A[u][v] && F[v])
			DFS(S,v);
}
void Travel(int A[])
{
	for(int i=0; i<count; i++)
	{
		if(!A[i])
			continue;
		printf("%d %s ",A[i],(i<count-2 ? "->" : ""));
	}
	printf("\n");
}
int Num[MAX]= {0};
//int c=0, a=0;
void Comp(int Num[],int u, int *c, int a)
{
	Num[a] = *c;
	a++;
	for(int i=0; i<count; i++)	F[i]=1;
	for(int v=0; v<count; v++)
	{
		if(A[u][v] && F[v])
			Comp(Num,v,c,a);
	}
}

void Comp_Search(int Num[])
{
	int a=0,c=0;
	for(int u = 1; u<=count; u++){
		c++;
		Comp(Num,u,&c,a);
	}
	int j=0;
	printf("\n\n\n\n");
	for(int i=1; i<=c; i++){
		printf("\nMien %d: ",i);
		while(Num[j] && Num[j]==i){
			printf("%d\t",j);
			j++;
		}
	}
	/*int num=0;
	for(int u=0; u<count; u++)
	{
		if(F[u]){
			num++;
			printf("\n\n\nMien lien thong %d: ",num);
			DFS(u);
		}
	}*/
	/*int C[count];
	for(int i=0; i<count; i++)	C[i]=0;
	k=0;
	for(int u=0; u<count; u++){
		if(!C[u]){
			k++;
			Comp(C,u);
		}
	}
	printf("\n\n___________________\n\n");
	for(int i=0; i<count; i++)
		printf("%d\t",C[i]);*/

}
int main()
{
	ReadFile(A,&count);
	int S[count];
	for(int i=0; i<count; i++) S[i]=0;
	int Q[count];
	for(int i=0; i<count; i++) Q[i]=0;
	Output();
	int u=2;
	printf("\nTim kiem theo chieu rong xuat phat tu dinh %d:\n\t",u);
	BFS(Q,u);
	Travel(Q);
	printf("\n\nTim kiem theo chieu sau xuat phat tu dinh %d:\n\t",u);
	DFS(S,u);
	Travel(S);
	//Comp_Search(Num);
	return 0;
}


int G[MAX][MAX], n, chuaxet[MAX], doi[MAX], i, j;

void DocFile(){
	freopen("input.txt","r",stdio);
	scanf("%d", &n);
	printf("\nSo dinh cua do thi: %d",n);
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			scanf("%d",G[i][j]);
		}
	}
	for(i=1; i<=n; i++){
		chuaxet[i]=TRUE;
	}
}

void BFS(int i){
	int u, dau, cuoi;
	dau=1;
	cuoi=1;
	doi[cuoi]=1;
	chuaxet[i]=FALSE;
	while(dau<=cuoi){
		u=doi[dau]; //lay dinh n ra khoi hang doi
		printf("%d\t",u);
		dau=dau+1; //duyet dinh dau hang doi
		for(j=1; j<=n; j++){
			if(G[u][j]==1 && chuaxet[j]){
				cuoi = cuoi+1;
				doi[cuoi]=j;
				chuaxet[j]=FALSE;
			}
		}
	}
}
int main()
{
	DocFile();
	for(i=1; i<=n; i++){
		if(chuaxet[i])
			BFS(i);
	}
	return 0;
}