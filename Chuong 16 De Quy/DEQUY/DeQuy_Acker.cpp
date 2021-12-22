#include <bits/stdc++.h>
using namespace std;

int Acker(int m, int n){
	if(!m)
		return n+1;
	if(!n)
		return Acker(m-1,1);
	return Acker(m-1,Acker(m,n-1));
}
int main(){
	int m, n;
	cout << "Nhap m, n: ";	cin >> m >> n;
	cout << "Acker("<<m<<','<<n<<") = "<< Acker(m,n);
	return 0;
}