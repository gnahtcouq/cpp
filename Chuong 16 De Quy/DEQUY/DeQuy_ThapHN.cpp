#include <iostream>
using namespace std;

void transfer(int n, char A, char B, char C);
int main()
{
	transfer(4,'A', 'B', 'C');
	return 0;
}
void transfer(int n, char A, char B, char C)
{
	if(n==1)
		cout << A << " --> " << C << endl;
	else
	{
		transfer(n-1, A, C, B);
		transfer(1,A, B, C);
		transfer(n-1,B, A, C);
	}
}