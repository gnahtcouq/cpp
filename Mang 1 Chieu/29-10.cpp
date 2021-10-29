#include <iostream>
using namespace std;
#define MAX 100

int main(){
    // const int n = 10;
    // int a[MAX];
    // double b[20];
    // char c[30];
    int a[4] = {1,2,3,4};

    // cout << "\nPhan tu thu 1 la: " << a[0] << endl;
    // cout << "\nPhan tu thu 2 la: " << a[1] << endl;
    // cout << "\nPhan tu thu 3 la: " << a[2] << endl;
    // cout << "\nPhan tu thu 4 la: " << a[3] << endl;
    // cout << "\nPhan tu thu 5 la: " << a[4] << endl;
    for(int i=0;i<4;i++)
        cout << a[i] << " ";

    return 0;
}