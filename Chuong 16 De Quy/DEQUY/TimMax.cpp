#include <iostream>
using namespace std;
int a[7] = {1, 2, 3, 10, 5, 6, 7};
int FindMax(int left, int right) {
	int max = 0;
	if(left==right) max = a[left];
	else {
		int m = (left+right)/2;
		int t1 = FindMax(left, m);
		int t2= FindMax(m+1, right);
		m = t1>t2 ? t1:t2;
	}
	return max;
}
int main() {
	cout << "\n\t Ket qua: " << FindMax(0, 6);
	return 0;
}