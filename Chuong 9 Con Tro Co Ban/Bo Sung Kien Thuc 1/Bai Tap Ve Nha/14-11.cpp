/* 
Bài 16: Sử dụng con trỏ để làm lại các bài tập về mảng một chiều.
Nhập/Xuất mảng
Tìm phần tử thỏa yêu cầu (chẵn, nguyên tố, dương, hoàn thiện ...)
Tính tổng/đếm các phần tử thỏa yêu cầu
Sắp xếp tăng/giảm
 */
#include <iostream>
#include <math.h>
using namespace std;

void nhapMang(int *a, int n);
void xuatMang(int *a, int n);
void hoanVi(int &a, int &b);
void interChangeSort_Tang(int *a, int n);
void interChangeSort_Giam(int *a, int n);
void REALLOC(int *&a, int sizecu, int sizemoi);
void XoaPhanTu(int *&a, int &n, int x);

int main(){
    int n;
    do{
        cout << "\nNhap vao n = ";
        cin >> n;
        if(n<0)
            cout << "\nGia tri n khong hop le. Xin kiem tra lai";
    }while(n<0);

    int *a;
    a = new int[n];
    nhapMang(a,n);
    xuatMang(a,n);

    // cout << "\nMang sau khi sap xep tang la: ";
    // interChangeSort_Tang(a,n);
    // xuatMang(a,n);

    // cout << "\nMang sau khi sap xep giam la: ";
    // interChangeSort_Giam(a,n);
    // xuatMang(a,n);

    int x;
    cout << "\nNhap x = ";
    cin >> x;
    cout << "\nMang sau khi xoa phan tu chi so x la: ";
    XoaPhanTu(a,n,x);
    xuatMang(a,n);


    delete []a;

    system("pause");
    return 0;
}

void nhapMang(int *a, int n){
    for(int i=0; i<n; i++){
        cout << "\nNhap vao a[" << i << "]= ";
        cin >> a[i]; 
    }
}
void xuatMang(int *a, int n){
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
}
void hoanVi(int &a, int &b){
    a = a - b;
    b = a + b;// b = a
    a = b - a; // a = b
}
void interChangeSort_Tang(int *a, int n){
    for(int i = 0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] > a[j])
                hoanVi(a[i],a[j]);
        }
    }
}
void interChangeSort_Giam(int *a, int n){
    for(int i = 0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] < a[j])
                hoanVi(a[i],a[j]);
        }
    }
}
void REALLOC(int *&a, int sizecu, int sizemoi){
	int *b = new int[sizecu]; // Tạo ra mảng phụ b
	// Lưu từng phần tử của mảng a sang mảng b.
	for(int i = 0; i < sizecu; i++){
		b[i] = a[i];
	}
	delete[] a; // Xóa mảng a đi.
	a = new int[sizemoi]; // Cấp mới lại size cho mảng a.
	// Lưu từng phần tử của mảng b sang mảng a.
	for(int i = 0; i < sizecu; i++){
		a[i] = b[i];
	}
	delete[] b; // Xóa mảng phụ b đi.
}
void XoaPhanTu(int *&a, int &n, int x){
	for(int i = x; i < n - 1; i++){
		a[i] = a[i + 1];
	}
	n--;
	REALLOC(a, n, n);
}