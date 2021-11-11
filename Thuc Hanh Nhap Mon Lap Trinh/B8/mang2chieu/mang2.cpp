#include "mang2.h"

void nhapMang(int arr[][10], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << "arr[" << i << "][" << j << "] = ";
			cin >> arr[i][j];
		}
	}
}
void xuatMang(int arr[][10], int row, int col) {
	cout << "\nMang da nhap la: " << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int tong_SoLe(int arr[][10], int row, int col) {
	int sum = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] > 0 && arr[i][j] % 2 != 0)
				sum += arr[i][j];
		}
	}
	return sum;
}

void in_DuongCheoChinh(int arr[][10], int row, int col) {
	cout << "\nDuong cheo chinh: ";
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (i == j) cout << arr[i][j] << " ";
		}
	}
}

void xuat_ChiaHet3Va7(int arr[][10], int row, int col) {
	cout << "\nCac phan tu chia het cho 3 va 7: ";
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] % 3 == 0 && arr[i][j] % 7 == 0) cout << arr[i][j] << " ";
		}
	}
}

void nhap_MaTranVuong(int arr[][10], int row) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			cout << "arr[" << i << "][" << j << "] = ";
			cin >> arr[i][j];
		}
	}
}
void xuat_MaTranVuong(int arr[][10], int row) {
	cout << "\nMa Tran Vuong da nhap la: " << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void xuat_Le(int arr[][10], int row) {
	cout << "\nCac phan tu le: " << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			if (arr[i][j] % 2 != 0) cout << arr[i][j] << " ";
			if (arr[i][j] % 2 == 0) cout << " * ";
		}
	}
}

int tongNguyen(int arr[][10], int row) {
	int sum = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			if (arr[i][j] > 0 && arr[i][j] % 3 == 0 && arr[i][j] % 5 == 0) sum += arr[i][j];
		}
	}
	return sum;
}

float trungBinhCong(int arr[][10], int row) {
	int s = 0;
	float tbc = 0;
	int count = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			if (arr[i][j] > 0) {
				s += arr[i][j];
				count++;
				
			}
			tbc = (float)s / count;
		}
	}
	return tbc;
}

void xuat_NguyenTo(int arr[][10], int row) {
	cout << "\nSo nguyen to co trong ma tran: ";
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			if (arr[i][j] >= 2) {
				int dem = 0;
				for (int k = 2; k <= arr[i][j] / 2; k++)
					if (arr[i][j] % k == 0) dem++;
				if (dem == 0)cout << arr[i][j] << " ";
			}
		}
	}
}

int tong_NguyenTo(int arr[][10], int row) {
	int sum = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			if (arr[i][j] >= 2) {
				int dem = 0;
				for (int k = 2; k <= arr[i][j] / 2; k++)
					if (arr[i][j] % k == 0) dem++;
				if (dem == 0) sum += arr[i][j];
			}
		}
	}
	return sum;
}

int tong_Dong(int arr[][10], int row, int k) {
	int sum = 0;
	for (int i = 0; i < row; i++)
		sum = sum + arr[k][i];
	return sum;
}

void dem(int arr[][10], int row, int col,int &a,int &b) {
	int demAm = 0;
	int demDuong = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] < 0) demAm++;
			if (arr[i][j] > 0) demDuong++;
			a = demAm;
			b = demDuong;
		}
	}
}

void demChanLe(int arr[][10], int row, int col, int &a, int &b) {
	int demChan = 0;
	int demLe = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] %2 == 0) demChan++;
			if (arr[i][j] %2 != 0) demLe++;
			a = demChan;
			b = demLe;
		}
	}
}

int demX(int arr[][10], int row, int col, int x) {
	int dem = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] == x) dem++;
		}
	}
	return dem;
}

int dem_NguyenTo(int arr[][10], int row, int col) {
	int count = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] >= 2) {
				int dem = 0;
				for (int k = 2; k <= arr[i][j] / 2; k++)
					if (arr[i][j] % k == 0) dem++;
				if (dem == 0) count++;
			}
		}
	}
	return count;
}

bool kiemTraHoanThien(int &h){
	int tong = 0;
	for (int i = 1; i <= h / 2; i++){
		if (h%i == 0){
			tong += i;
		}
	}
	if (tong == h){
		return true;
	}
	return false;
}

int demHoanThien(int arr[][10], int row, int col){
	int dem = 0;
	for (int i = 0; i < row; ++i){
		for (int j = 0; j < col; ++j){
			if (kiemTraHoanThien(arr[i][j]) == true){
				dem++;
			}
		}
	}
	return dem;
}

int demBoi(int arr[][10], int row, int col) {
	int dem = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] > 0 && arr[i][j] % 3 == 0 && arr[i][j] % 5 == 0) dem++;
		}
	}
	return dem;
}

int tongDongChan(int arr[][10], int row, int col) {
	int s = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (i%2==0) s+=arr[i][j];
		}
	}
	return s;
}
