#include "mang2.h"

int main() {
	int arr[10][10];
	int row, col;
	//cout << "\nNhap so dong: ";
	//cin >> row;
	//cout << "\nNhap so cot: ";
	//cin >> col;
	//nhapMang(arr, row, col);
	//xuatMang(arr, row, col);
	//cout << "\nTong cac so duong le co trong ma tran: " << tong_SoLe(arr,row,col);
	//in_DuongCheoChinh(arr, row, col);
	//xuat_ChiaHet3Va7(arr, row, col);

	//Bai 3
	//cout << "\nNhap kich thuoc ma tran: ";
	//cin >> row;
	//nhap_MaTranVuong(arr, row);
	//xuat_MaTranVuong(arr, row);
	//xuat_Le(arr,row);
	//cout << "\nTong nguyen duong vua boi so cua 3 va 5: " << tongNguyen(arr, row) << endl;
	//cout << "\nTrung binh cong cac so nguyen duong: " <<trungBinhCong(arr, row);
	//
	
	//Bai 4
	//cout << "\nNhap kich thuoc ma tran: ";
	//cin >> row;
	//nhap_MaTranVuong(arr, row);
	//xuat_MaTranVuong(arr, row);
	//xuat_NguyenTo(arr, row);
	//cout << "\nTong cac so nguyen to co trong ma tran: " << tong_NguyenTo(arr, row);

	//int k;
	//cout << "\nNhap so dong muon tinh: ";
	//cin >> k;
	//cout << "\nTong dong " << k << " = "<<tong_Dong(arr, row, k);
	//
	
	//LAM THEM
	int a, b;
	cout << "\nNhap so dong: ";
	cin >> row;
	cout << "\nNhap so cot: ";
	cin >> col;
	nhapMang(arr, row, col);
	xuatMang(arr, row, col);
	//dem(arr, row, col, a ,b);
	//cout << "So phan tu am la: " << a << " So phan tu duong la: " << b;
	demChanLe(arr, row, col, a, b);
	cout << "So phan tu chan la: " << a << " So phan tu le la: " << b;
	//int x;
	//cout << "\nNhap x = ";
	//cin >> x;
	//cout << "\nSo lan xuat hien cua x: " << demX(arr, row, col, x);
	//cout << "\nSo phan tu la so nguyen to: " << dem_NguyenTo(arr, row, col);
	cout << "\nDem so hoan thien: " << demHoanThien(arr, row, col);
	cout << "\nDem boi so 3 va 5: " << demBoi(arr, row, col);
	cout << "\nTong cac phan tu o dong chan: " << tongDongChan(arr, row, col);
	return 0;
}
