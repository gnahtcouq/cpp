#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define MAX 20
int X[MAX];
int a[MAX], b[2*MAX], c[2*MAX];
int n;

void Out(int *X, int n){
	for(int i=1; i<=n; i++)
		cout << "(" << i << ", " << X[i] << "), ";
}

void TamHau(int i){
	for(int j=1; j<=n; j++){
		if(a[j] && b[i+j] && c[i-j+n]){
			X[i]=j;
			if(i==n)	Out(X,n);
			else{
				a[j] = 0; b[i+j]=0; c[i-j]=0;
				TamHau(i+1);
				a[j] = 1; b[i+j]=1; c[i-j]=1;
			}
		}
	}
}

int main(){
	n=8;
	memset(a,1,MAX*sizeof(int));
	memset(b,1,2*MAX*sizeof(int));
	memset(c,1,2*MAX*sizeof(int));
	
	TamHau(1);
	return 0;
}