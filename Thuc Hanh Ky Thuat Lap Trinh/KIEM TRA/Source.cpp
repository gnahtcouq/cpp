#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
using namespace std;
struct maTran
{
	int list[10][10];
	int dong;
	int cot;
};
void docMaTran(maTran &a)
{
	FILE *f;
	f = fopen("a.txt", "r");
	if (f == NULL)
	{
		cout << "Loi mo file";
		exit(1);
	}
	fscanf(f, "%d", &a.dong);
	fscanf(f, "%d", &a.cot);
	for (int i = 0; i < a.dong; i++)
		for (int j = 0; j < a.cot; j++)
			fscanf(f, "%d", &a.list[i][j]);
	fclose(f);
}
void xuatMaTran(maTran a)
{
	for (int i = 0; i < a.dong; i++)
	{
		for (int j = 0; j < a.cot; j++)
			cout << a.list[i][j] << "\t";
		cout << endl;
	}
}

int main()
{
	maTran a;
	docMaTran(a);
	xuatMaTran(a);

	system("pause");
	return 0;
}