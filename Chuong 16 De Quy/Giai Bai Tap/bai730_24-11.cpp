#include <iostream>
#include <time.h>
using namespace std;

// Bai 730
// Tinh s(n) = 1 + 2 + 3 + ... + n

// cong thuc de quy: s(n) = s(n - 1) + n

int deQuy(int n) {
    if (n == 1)
        return 1;
    return deQuy(n - 1) + n;
}

int khuDeQuy(int n) {
    int tong = 0;
    for (int i = 1; i <= n; i++)
        tong += i;
    return tong;
}

int deQuyDuoi(int n, int x = 1) {
    if(n == 1)
        return x;
    return deQuyDuoi(n - 1, x + n);
}


int main() {

    int n = 50;

    cout << "\nTong deQuy(" << n << ") = " << deQuy(n);
    cout << "\nTong khuDeQuy(" << n << ") = " << khuDeQuy(n);
    cout << "\nTong deQuyDuoi(" << n << ") = " << deQuyDuoi(n);

    clock_t start1 = clock(); // Bat dau tinh thoi gian. Tinh theo mili giay
    for(int i = 1; i <= 10000000; i++)
        deQuy(n);
    clock_t finish1 = clock(); // Ket thuc tinh thoi gian


    clock_t start2 = clock(); // Bat dau tinh thoi gian. Tinh theo mili giay
    for(int i = 1; i <= 10000000; i++)
        khuDeQuy(n);
    clock_t finish2 = clock(); // Ket thuc tinh thoi gian


    clock_t start3 = clock(); // Bat dau tinh thoi gian. Tinh theo mili giay
    for(int i = 1; i <= 10000000; i++)
        deQuyDuoi(n);
    clock_t finish3 = clock(); // Ket thuc tinh thoi gian

    double thoiGian1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
    double thoiGian2 = (double)(finish2 - start2) / CLOCKS_PER_SEC;
    double thoiGian3 = (double)(finish3 - start3) / CLOCKS_PER_SEC;

    cout << "\nDe quy chay het " << thoiGian1 << " s";
    cout << "\nKhu de quy chay het " << thoiGian2 << " s";
    cout << "\nDe quy duoi chay het " << thoiGian3 << " s";

    cout << endl;
    return 0;
}