#include <iostream>
#include <stdlib.h> // thu vien ho tro cap phat bo nho con tro
using namespace std;

int main(){
    // Co 3 cach cap phat con tro ben C:
    // 1/ malloc
    // 2/ calloc
    // 3/ realloc

    int *b; // khai bao con tro

    // cap phat bo nho cho con tro
    b = (int *) malloc(sizeof(int)); // malloc tao ra vung nho, con tro b tro toi vung nho do

    *b = 69; // gan 69 cho con tro b
    cout << "\n*b = " << *b;

    free(b); // giai phong con tro
    // viec nay khong biet truoc gia tri la bao nhieu boi vi neu nhu co tien trinh nao khac lay no su dung thi gia tri cu moi mat, con neu khong co tien trinh nao lay thi gia tri van con do
    cout << "\n*b = " << *b;

    // int a = 5; // a thuoc STACK
    // int *c = &a; // cho con tro c tro toi bien a
    // free(c); // giai phong con tro c

    return 0;
}
