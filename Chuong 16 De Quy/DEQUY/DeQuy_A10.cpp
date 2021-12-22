//Day so: 4,3,-2,-6,-5,0,4,... Tim so thu 10
#include <bits/stdc++.h>
using namespace std;

int DeQuy(int n){
	if(!n)
		return 4;
	if(n==1)
		return 3;
	return DeQuy(n-1) - DeQuy(n-2) - 1;
}
int main(){
	int n;
	cout << "Nhap n: ";	cin >> n;
	cout << "DeQuy("<<n<<") = "<<DeQuy(n);
	return 0;
}