#include <iostream>
#include <math.h>
using namespace std;
void ktSCP(int n);
int main() {
    int n;
    cout <<"\nNhap n: ";
    cin >> n;
    ktSCP(n);
    // if (sqrt(n)*sqrt(n)==n) cout << n << " la so chinh phuong";
    // else cout << n << " ko phai la so chinh phuong";

    //Ky thuat dat co hieu
    return 0;
}

void ktSCP(int n){
    int flag =0;
    for(int i=1;i<=n;i++)// i<n/2
        if(i*i==n){
            flag = 1;
            break;
        }
    if (flag==1)
        cout << n << "\nLa so chinh phuong";
    else
        cout << n << " ko phai la so chinh phuong";
}