/* 
        DE QUY HO TUONG
    Tinh so hang thu n cua day
    x(0) = 1, y(0) = 0
    x(n) = x(n-1) + y(n-1)
    y(n) = 3*x(n-1) + 2*y(n-1)


    Tu de quy ho tuong ta chuyen no ve de quy nhi phan
    
    x(n) = x(n-1) + y(n-1)      (1)
    y(n) = 3*x(n-1) + 2*y(n-1)  (2)

    (1)  => y(n-1) = x(n) - x(n-1)
        <=> y(n)   = x(n+1) - x(n)    // +1 moi ve
    The vao (2)
         => x(n+1) - x(n)   = 3*x(n-1) + 2*(x(n) - x(n-1))
        <=> x(n+1) - x(n)   = 3*x(n-1) + 2*x(n)  - 2*x(n-1)
        <=> x(n+1) - x(n)   = x(n-1)   + 2*x(n)
        <=> x(n+1) - x(n-1) = 3*x(n)

         => x(n+1) = 3*x(n)   + x(n-1)
         => x(n)   = 3*x(n-1) + x(n-2) voi n > 1 (chuyen biet cua x)


    x(n) = x(n-1) + y(n-1)      (1)
    y(n) = 3*x(n-1) + 2*y(n-1)  (2)

    (1) => x(n-1) = x(n-2) + y(n-2)
    Dem thay the vao (2)
     => y(n) = 3*(x(n-2) + y(n-2))   + 2*y(n-1)
    <=> y(n) = 3*x(n-2)  + 3*y(n-2)) + 2*y(n-1)     (*)
    Ma ta lai co tu (2)
     => 3*x(n-1) = y(n)   - 2*y(n-1)
    <=> 3*x(n-2) = y(n-1) - 2*y(n-2)
    Dem the vao (*)
     => y(n) = y(n-1) - 2*y(n-2) + 3*y(n-2)) + 2*y(n-1)
    <=> y(n) = 3*y(n-1) + y(n-2)    (chuyen biet cua y)


    x(n)   = 3*x(n-1) + x(n-2)      (chuyen biet cua x)
    y(n)   = 3*y(n-1) + y(n-2)      (chuyen biet cua y)

*/

#include <iostream>
using namespace std;

// Khai bao nguyen mau ham
int x_n(int);
int y_n(int);

int x_n(int n) {
    if(n == 0)
        return 1;
    return x_n(n - 1) + y_n(n - 1);
}

int y_n(int n) {
    if(n == 0)
        return 0;
    return 3 * x_n(n - 1) + 2 * y_n(n - 1);
}

int xn_NhiPhan(int n) {
    if(n == 0 || n == 1)
        return 1;
    return 3 * xn_NhiPhan(n-1) + xn_NhiPhan(n-2);
}

int yn_NhiPhan(int n) {
    if(n == 0)
        return 0;
    if(n == 1)
        return 3;
    return 3 * yn_NhiPhan(n-1) + yn_NhiPhan(n-2);
}

int main() {
    int n = 5;
    cout << "\nx_n(" << n << ") = " << x_n(n);
    cout << "\ny_n(" << n << ") = " << y_n(n);

    cout << "\nxn_NhiPhan(" << n << ") = " << xn_NhiPhan(n);
    cout << "\nyn_NhiPhan(" << n << ") = " << yn_NhiPhan(n);


    cout << endl;
    return 0;
}
