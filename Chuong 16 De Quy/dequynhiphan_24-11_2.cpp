/* 
            DE QUY NHI PHAN
    De bai: Tinh day Fibonancy
    F(0) = F(1) = 1
    F(n) = F(n - 1) + F(n - 2) voi n > 1

    -> Dieu kien dung:  F(0) = F(1) = 1
    -> Cong thuc de quy: F(n) = F(n - 1) + F(n - 2) voi n > 1

    Cach chay tay
    VD: Lay n = 5
    fibo_DeQuy(4) + fibo_DeQuy(3) = 5 + 3 = 8
    
    fibo_DeQuy(4) = fibo_DeQuy(3) + fibo_DeQuy(2) = 2 + 3 = 5
    fibo_DeQuy(3) = fibo_DeQuy(2) + fibo_DeQuy(1) = 2 + 1 = 3
    fibo_DeQuy(2) = fibo_DeQuy(1) + fibo_DeQuy(0) = 1 + 1 = 2 
*/

#include <iostream>
using namespace std;

int fibo_DeQuy(int n) {
    // Dieu kien dung
    if( n == 0 || n == 1)
        return 1;
    return fibo_DeQuy(n -1) + fibo_DeQuy(n - 2);
}

int fibo_KhuDeQuy(int n) {
    int f0, f1;
    f0 = f1 = 1;
    if(n == 0 || n == 1)
        return 1;
    int fn;
    for(int i = 2; i <= n; i++) {
        fn = f0 + f1;
        f0 = f1;
        f1 = fn;
    }
    return fn;
}

int main() {
    int n = 5;
    cout << "\nfibo_DeQuy("<<n<<") = " << fibo_DeQuy(n); // Cong thuc de duy
    cout << "\nfibo_KhuDeQuy("<<n<<") = " << fibo_KhuDeQuy(n);

    cout << endl;
    return 0;
}
