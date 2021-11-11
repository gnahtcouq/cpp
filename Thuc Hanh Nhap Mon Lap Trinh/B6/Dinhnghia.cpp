#include "Khaibao.h"

void hoanvi(int &m, int &n) {
	int t = m;
	m = n;
	n = t;
}
void nhapNguyenDuong(int &n)
{
	do {
		cout << "Nhap so nguyen duong: ";
		cin >> n;
	} while (n <= 0 || n > 1000);
}

float tinhTong(int n) {
	float s = 0;
	for (int i = 1; i <= n; i++) {
		s += (float)1 / (i + 1);
	}
	return s;
}

void nhapNguyenDuong_3(int &n)
{
	do {
		cout << "Nhap so nguyen duong: ";
		cin >> n;
	} while (n <= 0);
}

float tinhBieuThuc(int n) {
	float s = 0;
	for (int i = 1; i <= n; i++) {
		s += (float) i / (i + 1);
	}
	return s;
}
// return 0: ko phai so nguyen to
// return 1: la so nguyen to
int ktraNguyenTo(int n) {
	if (n < 2) return 0;
	else {
		for (int i = 2; i <= sqrt(n); i++) {
			if (n%i == 0) {
				return 0;
			}
		}
		return 1;
	}
}

void nhapBanKinh(int &r) {
	do {
		cout << "Nhap ban kinh: ";
		cin >> r;
	} while (r <= 0);
}

float hTron(int r, float &dtich, float &cvi) {
	float pi = 3.14;
	cvi = (float) r * 2 * pi;
	dtich = (float) r * r * pi;
	return cvi;
}

int ktraChinhPhuong(int n) {
	if (sqrt(n) == (int)sqrt(n)) return 1;
	else return 0;
}