#include <iostream>
using namespace std;

// Tim Giai Thua n!
long GiaiThua(int n){
	if(!n)
		return 1;
	return n*GiaiThua(n-1);
}
int main(){
	cout << GiaiThua(10);
	return 0;
}