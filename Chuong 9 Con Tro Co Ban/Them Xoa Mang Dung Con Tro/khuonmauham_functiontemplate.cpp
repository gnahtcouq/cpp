#include <iostream>
using namespace std;


template <typename thangdeptrai>
void hoanVi(thangdeptrai &a, thangdeptrai &b){
    thangdeptrai temp = a;
    a = b;
    b = temp;
}

int main(){
    float a = 1, b = 2;

    hoanVi(a,b);

    cout << "\na = " << a << " & b = " << b;

    cout << endl;
    system("pause");
    return 0;
}