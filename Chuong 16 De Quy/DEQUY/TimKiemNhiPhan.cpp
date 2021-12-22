#include <iostream>
#include <stdlib.h>
#define MAX 20
using namespace std;
int *a, n;

int TimKiem(int c, int left, int right) {
	if(left <= right) {
		int middle = (right+left)/2;
		if(a[middle]==c)
			return middle;
		if(a[middle]>c)
			return TimKiem(c,left,middle-1);
		return TimKiem(c,middle+1,right);
	}
	return -1;
}
int TimKiem_KhuDeQuy(int c, int left, int right){
	int m;
	do{
		m = (left+right)/2;
		if(a[m]>c) right = m-1;
		if(a[m]<c) left = m+1;
		
	}while(a[m]!=c || left>right);
	if(a[m]==c)	return m;
	return -1;
}


int main() {
	n = 10;
	a = new int[n]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	int c;
	do {
		cout << "\n\t Nhap vao 1 so: ";
		cin >> c;
		cout << "\n\t Ket qua: " << TimKiem_KhuDeQuy(c,0,n-1);
	} while(1);
	
	delete [] a;
	return 0;
}