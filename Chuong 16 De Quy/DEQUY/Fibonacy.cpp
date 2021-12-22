#include<iostream>
using namespace std;

// Dung de quy
int fibo1(int n)
{
    if(n<=2)    return 1;
    return fibo1(n-1) + fibo1(n-2);
}
// Dung mang 1 chieu
int fibo2(int n){
    int f[n+1];
    f[1]=f[2]=1;
    for (int i=3; i<=n; i++)
        f[i] = f[i-1]+f[i-2];
    return f[n];
}
//Dùng 3 biến đuổi nhau
int fibo3(int n){
    if(n<=2)    return 1;
    int f, f1, f2;
    f2 = f1 = 1;
    for (int i=3; i<=n; i++)
    {
        f = f1+f2;
        f2 = f1;
        f1 = f;
    }
    return f;
}
int main(){
    int n = 6;
    cout << "\n\t Ket qua: " << fibo3(n);
    return 0;
}
