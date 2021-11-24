#include <iostream>
#include <time.h>
using namespace std;

// Bai 731
// 1^2 + 2^2 + 3^2 + ... + n^2

int deQuy(int n) {
    if (n == 1)
        return 1;
    return deQuy(n - 1) + n * n;
}

int khuDeQuy(int n) {
    int tong = 0;
    for (int i = 1; i <= n; i++)
        tong += i * i;
    return tong;
}

int deQuyDuoi(int n, int x = 1) {
    if(n == 1)
        return x;
    return deQuyDuoi(n - 1, x + n * n);
}


int main() {

    int n = 5;

    cout << "\nTong deQuy(" << n << ") = " << deQuy(n);
    cout << "\nTong khuDeQuy(" << n << ") = " << khuDeQuy(n);
    cout << "\nTong deQuyDuoi(" << n << ") = " << deQuyDuoi(n);

    cout << endl;
    return 0;
}