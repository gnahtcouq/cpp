/* CON TRO BEN C++
Khai bao nhu ben C
vd:
int *a;

Cap phat: Dung toan tu new
Giai phong: Dung delete

Co su khac biet giua new va malloc, calloc, realloc

(malloc, calloc, realloc): la nhung cai ham tao ra 1 vung nho, cho con tro tro toi vung nho duoc tra ve
(malloc, calloc, realloc): Khong ho tro

(new): la toan tu, ho tro viec cap phat vung nho
(new): Ho tro DA HINH ben lap trinh huong doi tuong

LUU Y: Neu cap phat con tro theo kieu cua C thi phai giai phong cung theo kieu cua C
        Neu cap phat con tro theo kieu cua C++ thi phai giai phong cung theo kieu cua C++
Neu lay rau ong nay cam vao cam ba kia thi se bi loi trong 1 so truong hop

- realloc ben C ho tro cho ta tang hay giam bot so luong vung nho
nhung ben C++ thi khong co thang nao ho tro ca, ta cung khong the su dung
realloc o ben C++ ma bat buoc phai viet rieng 1 ham realloc
*/

#include <iostream>
using namespace std;

void nhap(int *n){
        cout << "\nNhap n = ";
        cin >> *n;
}
void xuat(int *n){
        cout << "\nn = " << *n;
}

int main(){
        int *n;
        n = new int; // cap phat bo nho
        nhap(n);
        xuat(n);

        delete n; // giai phong

        cout << endl;
        system("pause");
        return 0;
}