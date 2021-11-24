/* 
        DE QUY PHI TUYEN

    Tinh so hang thu n cua day:
    x(0) = 1
    x(n) = n^2 * x(0) + (n-1)^2 * x(1) + ... + 2^2 * x(n-2) + 1^2 * x(n-1)

    x(2) = 2^2 * x(0) + 1^2 * x(1)
         =  4  * 1    +  1  *  1
         =  5
*/

#include <iostream>
#include <math.h>
using namespace std;

int tinh_DeQuy(int n) {
    // Dieu kien dung
    if(n == 0)
        return 1;
    int tong = 0;
    for(int i = 1; i <= n; i++)
        tong += i*i * tinh_DeQuy(n - i);
    return tong;
}

// int tinh_KhuDeQuy(int n) {
//     // Tu lam (cho phep dung mang de luu tru hoac co the khong dung)

// }

int main() {
    int n = 2;
    cout << "\ntinh_DeQuy(" << n << ") = " << tinh_DeQuy(n);

    cout << endl;
    return 0;
}