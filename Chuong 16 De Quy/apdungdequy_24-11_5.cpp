#include <iostream>
using namespace std;

int tinhTongChuSo(int n) {
    if(n == 0)
        return 0;
    return n%10 + tinhTongChuSo(n/10);
}

int main() {

    int n = 12345;

    cout << "\nTong cac chu so cua " << n << " la " << tinhTongChuSo(n);    

    cout << endl;
    return 0;
}