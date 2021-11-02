#include <iostream>
using namespace std;

void HoanVi(int &a, int &b){ // Tham chieu
    int temp = a;
    a = b;
    b = temp;
}

void HoanViCach2(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int a=1,b=2;
    int *c, *d;
    c = &a;
    d = &b;
    // HoanVi(a,b); // Ham hoan vi dung tham chieu
    // HoanVi(*c, *d);
    // HoanViCach2(&a, &b); // Ham hoan vi cach 2 dung con tro
    // HoanViCach2(c,d);

    cout << "\na = " << a;
    cout << "\nb = " << b;

    return 0;
}