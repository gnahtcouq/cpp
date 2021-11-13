#include <iostream>
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

int main(){
    DaySo ds1, ds2;
    ds1.soLuong = 3;
    ds1.data[0] = 10;
    ds1.data[1] = -10;
    ds1.data[2] = 20;
    ds2 = demSoDuong2(ds1);

    // xuat ds2
    if(ds2.soLuong == 0)
        cout << "\nKhong co so duong";
    else
        cout << "\nCac so duong co trong day so la: ";
    for(int i = 0; i < ds2.soLuong; i++){
        cout << ds2.data[i] << " " << endl;
    }

    cout << endl;
    system("pause");
    return 0;
}