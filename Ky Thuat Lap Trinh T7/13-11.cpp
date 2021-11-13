#include <iostream>
#include <math.h>
using namespace std;
const int MAX = 50;

struct DaySo{
	int data[MAX];
	int soLuong;
};

void nhapDS(DaySo &ds){
    cout << "\nNhap so phan tu: ";
    cin >> ds.soLuong;
    for (int i = 0; i < ds.soLuong; i++){
        cout << "a[" << i << "] = ";
        cin >> ds.data[i];
    }
}
void xuatDS(DaySo ds){
    for (int i = 0; i < ds.soLuong; i++)
        cout << ds.data[i] << " ";
}

int demSoDuong(DaySo ds){
	int dem = 0;
	for (int i = 0; i < ds.soLuong; i++){
		if (ds.data[i] > 0)
			dem++;
	}
	return dem;
}
DaySo demSoDuong2(DaySo ds){
	DaySo tam;
	tam.soLuong = 0;
	for (int i = 0; i < ds.soLuong; i++){
		if (ds.data[i] > 0)
			tam.data[tam.soLuong++] = ds.data[i];
	}
	return tam;
}
bool duongLonNhat(DaySo ds, int &max){
    bool flag = false;
    for (int i = 0; i < ds.soLuong; i++){
        if(ds.data[i] > 0){
            if(!flag){ // flag == false
                max = ds.data[i];
                flag = true;
            }
            else{
                if(max < ds.data[i])
                    max = ds.data[i];
            }
        }
    }
    return flag;
}
int viTriDuongMaxDauTien(DaySo ds){
    int vitri = -1;
    for (int i = 0; i < ds.soLuong; i++){
        if(ds.data[i] > 0){
            if(vitri == -1){
                vitri = i;
            }
            else if (ds.data[i] > ds.data[vitri]){
                vitri = i;
            }
        }
    }
    return vitri;
}

bool kiemTraSHT(int x)
{
	int  tong = 1;
	for (int i = 2; i<=x/2; i++)
		if (x%i == 0)
			tong = tong + i;

	if (tong == x)
		return true;
	return false;
}
bool kiemTraCoSoHoanThien(DaySo ds){
    for(int i = 0; i < ds.soLuong; i++){
        if(kiemTraSHT(ds.data[i]))
            return true;
    }
    return false;
}

int timMin(DaySo ds){
    int min = ds.data[0];
    for (int i = 0; i < ds.soLuong; i++)
        if (ds.data[i] < min)
            min = ds.data[i];
    return min;
}
void kiemTraACoBeHonMinKhong(DaySo ds, int a){
    int min = timMin(ds);
    cout << "\nNhap a = ";
    cin >> a;
    if(a < min)
        cout << "\n" << a << " khong lon hon so be nhat trong day so";
    else
        cout << "\n" << a << " lon hon so be nhat trong day so";
}

bool kiemTraDoiXung(DaySo ds) {
	for (int i = 0; i < ds.soLuong / 2; i++)
		if (ds.data[i] != ds.data[ds.soLuong - 1 - i])
            return false;
	return true;
}
bool kiemTraAmLe(DaySo ds){
	for (int i = 0; i < ds.soLuong; i++){
		if (ds.data[i] < 0 && ds.data[i] % 2 != 0)
			return true;
	}
	return false;
}

int timMax(DaySo ds){
    int max = ds.data[0];
    for (int i = 0; i < ds.soLuong; i++)
        if (ds.data[i] > max)
            max = ds.data[i];
    return max;
}
void kiemTraACoLonHonMaxKhong(DaySo ds, int a){
    int max = timMax(ds);
    cout << "\nNhap a = ";
    cin >> a;
    if(a < max)
        cout << "\n" << a << " khong lon hon so lon nhat trong day so";
    else
        cout << "\n" << a << " lon hon so lon nhat trong day so";
}
bool kiemTraTang(DaySo ds)
{
	for (int i = 0; i < ds.soLuong-1; i++)
	{
		if (ds.data[i] >= ds.data[i+1])
			return false;
	}
	return true;
}
bool kiemTraTangSHT(DaySo ds)
{
	for (int i = 0; i < ds.soLuong; i++)
	{
		if (!kiemTraSHT(ds.data[i]))
			return false;
	}
	return true;
}

bool kiemTraNguyenTo(int n){
    if(n < 2)
        return false;
    for(int i = 2; i <= sqrt(n); i++)
        if(n % i == 0)
            return false;
    return true;
}

struct MATRANVUONG{
    int data[MAX][MAX];
    int bac; // so dong = so cot
};

bool kiemTraSNT(MATRANVUONG mt){
    for(int i = 0; i < mt.bac; i++){
        for(int j = 0; j < mt.bac; j++){
            if(kiemTraNguyenTo(mt.data[i][j]))
                return true;
        }
    }
    return false;
}

bool kiemTraDonVi(MATRANVUONG mt){
	for (int i = 0; i < mt.bac; i++){
		for (int j = 0; j < mt.bac; j++){
			if (i == j){
				if (mt.data[i][j] != 1)
					return false;
			}
			else if (mt.data[i][j] != 0)
				return false;
		}
	}
	return true;
}

// kiem tra ma tran vuong co phai doi xung hay khong
bool kiemTraDoiXung(MATRANVUONG mt){
	for (int i = 0; i < mt.bac; i++){
		for (int j = 0; j < i; j++){
			if (mt.data[i][j] != mt.data[j][i])
				return false;
		}
	}
	return true;
}

int main(){
    DaySo ds1, ds2;
    ds1.soLuong = 3;
    ds1.data[0] = 10;
    ds1.data[1] = -10;
    ds1.data[2] = 20;
    ds1.data[3] = 20;
    ds1.data[4] = 20;

    ds2 = demSoDuong2(ds1);

    // xuat ds2
    if(ds2.soLuong == 0)
        cout << "\nKhong co so duong";
    else
        cout << "\nCac so duong co trong day so la: ";
    for(int i = 0; i < ds2.soLuong; i++){
        cout << ds2.data[i] << " " << endl;
    }

    cout << "\nVi tri duong lon nhat dau tien la: " << viTriDuongMaxDauTien(ds1);

    int a;
    kiemTraACoBeHonMinKhong(ds1, a);

    cout << endl;
    system("pause");
    return 0;
}