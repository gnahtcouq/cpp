#pragma once
#include <iostream>
using namespace std;

void nhapMang(int arr[][10], int row, int col);
void xuatMang(int arr[][10], int row, int col);
int tong_SoLe(int arr[][10], int row, int col);
void in_DuongCheoChinh(int arr[][10], int row, int col);
void xuat_ChiaHet3Va7(int arr[][10], int row, int col);
void nhap_MaTranVuong(int arr[][10], int row);
void xuat_MaTranVuong(int arr[][10], int row);
void xuat_Le(int arr[][10], int row);
int tongNguyen(int arr[][10], int row);
float trungBinhCong(int arr[][10], int row);
void xuat_NguyenTo(int arr[][10], int row);
int tong_NguyenTo(int arr[][10], int row);
int tong_Dong(int arr[][10], int row, int k);
void dem(int arr[][10], int row, int col, int &a, int &b);
void demChanLe(int arr[][10], int row, int col, int &a, int &b);
int demX(int arr[][10], int row, int col, int x);
int dem_NguyenTo(int arr[][10], int row, int col);
bool kiemTraHoanThien(int &h);
int demHoanThien(int arr[][10], int row, int col);
int demBoi(int arr[][10], int row, int col);
int tongDongChan(int arr[][10], int row, int col);
