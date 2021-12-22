// Sai
#include <bits/stdc++.h>
using namespace std;

string str[] = {"tam","toan","trang","cong","trung","tu"};
int dem=0, n, k,*a;
void Out(int *a, int n){
	cout << endl << ++dem <<". ";
	for(int i=0; i<n; i++)
		cout << str[a[i]] << ", ";
}
void ToHop(int i){
	if(k==0)	return;
	if(a[i]==n-k+i){
		ToHop(i-1);
	}
	else{
		
		a[i]++;
		a[i+1]=a[i]+1;
//		for(int j=i+1; j<k; j++) a[j]=a[j-1]+1;
		Out(a,k);
		ToHop(i);
	}
}
int main(){
	n=6, k=4;
	a=new int[k];
	for(int i =0; i<k; i++) a[i]=i;
	Out(a,k);
	ToHop(k-1);
	delete []a;
	return 0; 
}