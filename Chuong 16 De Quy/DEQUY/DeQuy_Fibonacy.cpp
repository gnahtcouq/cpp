#include <iostream>
using namespace std;

// Tim so hang thu n trong day Fibonacy
long Fibo(int n){
	if(!n || n ==1)
		return 1;
	return Fibo(n-1) + Fibo(n-2);	
}

int main(){
	int n;
	cout << "Nhap so n = ";
	cin >> n;
	cout << "So hang thu "<<n<<" trong day Fibonacy la: "<< Fibo(n)<<endl;
	return 0;
}