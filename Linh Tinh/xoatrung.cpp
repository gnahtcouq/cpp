#include <iostream>
using namespace std;

void xoaTrung(int *a, int &n);

int main(){
    int a[] = {1, 2, 3, 1, 1, 1, 6, 8, 9};
    int n = 9;
    xoaTrung(a,n);
    for(int i=0;i<n;i++)
        cout << " " << a[i];
    cout << endl;
    return 0;
}

void xoaTrung(int *a, int &n){
    int i,j,k;
    for(i=0;i<n-1;i++){
        j=i+1;
        while(j<n)
            if(a[i]==a[j]){
                for(k=j;k<n-1;k++)
                    a[k]=a[k+1];
                n=n-1;
            }
            else
                j=j+1;
    }
}