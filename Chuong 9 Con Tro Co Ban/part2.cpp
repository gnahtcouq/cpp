#include <iostream>
using namespace std;
int main(){
    int a = 10; // a la 1 bien binh thuong
    int *b; // b la con tro
    // Viet gop int *b = &a;
    b = &a;
    //gia tri = gia tri
    //dia chi = dia chi

    cout << "Gia tri cua a la: " << a << endl;
    cout << "Dia chi cua a la: " << &a << endl;

    cout << "Gia tri cua con tro b la: " << *b << endl;
    cout << "Mien gia tri cua con tro b la: " << b << endl; // Mien gia tri la noi ma con tro tro toi
    cout << "Dia chi thuc su cua con tro b la: " << &b << endl;

    (*b) = 5; // lay gia tri con tro b tang len 5 lan
    cout << "a = " << a << endl;

    int *c; // Khai bao con tro c
    c = b; // con tro tro toi 1 con tro khac

    (*c) = 69;

    cout << "Gia tri cua con tro c la: " << *c << endl;
    cout << "Mien gia tri cua con tro c la: " << c << endl; // Mien gia tri la noi ma con tro tro toi
    cout << "Dia chi thuc su cua con tro c la: " << &c << endl;

    cout << "a = " << a << endl;
    cout << "*b= " << *b << endl;

    // int *d; // nam bo vo giua nga 4
    // *d = 5; // se bi sai do d chua co bo nho cap phat

    return 0;
}