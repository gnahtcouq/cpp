#include <iostream>
using namespace std;
const int MAX = 50;
//Cau truc DS DAC
struct DaySo{
    int ds[MAX];
    int n; //So Phan tu ds dac
};
void khoiTao(DaySo &x);
int isEmpty(DaySo x);
int isFull(DaySo x);
int listSize(DaySo x);
void doc_DanhSach(DaySo &x);
void xuat_DanhSach(DaySo x);
//Cau 2
void chen_ViTri(DaySo &x, int pos, int a);
//Cau 3
void xoa_ViTri(DaySo &x, int pos);
//Cau 4
void xoa_GiaTri_K(DaySo &x, int k);
//Cau 5
int timKiem_TuanTu(DaySo x, int a);
//Cau 6
void sapXep(DaySo &x);
int timKiem_NhiPhan(DaySo x, int a);
//Cau 7


int main(){
    //Cau 1
    DaySo x;
    khoiTao(x); //Ham nay de khoi tao danh sach dac
    doc_DanhSach(x); //Ham nay de nhap day so vao danh sach dac
    xuat_DanhSach(x); //Ham nay de xuat danh sach dac
    if(isEmpty(x)==0) //Ham nay de Kiem tra danh sach co rong hay khong, neu khong tra ve 1
        cout << "\nCau1. Danh sach rong";
    else
        cout << "\nCau1. Danh sach day";
    if(isFull(x)==0) //Ham nay de Kiem tra danh sach co day hay khong, neu = MAX tra ve 1
        cout << "\nCau1. Danh sach khong day";
    else
        cout << "\nCau1. Danh sach day";
    cout << "\nCau1. Xac dinh so phan tu cua danh sach " << listSize(x); //Ham nay de Xac dinh so phan tu cua danh sach
    
    //Cau 2
    int pos, a, k;
    cout << "\nCau2. Nhap phan tu can chen: ";
    cin >> k;
    cout << "\nCau2. Nhap vi tri can chen: ";
    cin >> pos;
    chen_ViTri(x, pos, k);
    xuat_DanhSach(x);

    //Cau 3
    cout << "\nCau3. Nhap vi tri can xoa: ";
    cin >> pos;
    xoa_ViTri(x, pos);
    xuat_DanhSach(x);

    //Cau 4
    xoa_GiaTri_K(x, k);
    //Cau 5
    cout << "\nCau5. Nhap phan tu k can tim: ";
    cin >> k;
    pos = timKiem_TuanTu(x, k);
    if (pos == -1)
        cout << "\nCau5. Khong tim thay";
    else
        cout << "\nCau5. Tim thay " << k << " o vi tri " << pos;
    //Cau 6
    sapXep(x);
    cout << "\nCau6. Danh sach sau khi sap xep ";
    xuat_DanhSach(x);

    //Cau 7

    return 0;
}

//Cau 1
void khoiTao(DaySo &x){
    x.n = 0;
}
//Ham kiem tra rong
int isEmpty(DaySo x){
    return (x.n == 0 ? 1 : 0);
}
//Ham kiem tra day
int isFull(DaySo x){
    return (x.n == MAX ? 1 : 0);
}
//Ham tra ve so nut cua DS dac
int listSize(DaySo x){
    return x.n;
}
/********Ham nhap day so vao ds DAC***********/
void doc_DanhSach(DaySo &x){
    cout << "\n Nhap vao so phan tu cua DS: ";
    cin >> x.n;
    for (int i = 0; i < x.n; i++)
    {
        cout << "\n Nhap vao phan tu thu " << i + 1 << ": ";
        cin >> x.ds[i];
    }
}
/********Ham xuat ra DS DAC***************/
void xuat_DanhSach(DaySo x){
    cout << "\n Phan tu trong DS: ";
    for (int i = 0; i < x.n; i++)
        cout << x.ds[i] << " ";
}
//Cau 2
void chen_ViTri(DaySo &x, int pos, int a){
    if (pos < 0 || pos > listSize(x))
        cout << "\n Vi tri " << pos << " khong hop le";
    else if (isEmpty(x) == 1){
        if (pos == 0){
            x.ds[0] = a;
            x.n++;
        }
        else
            cout << "\n Vi tri khong hop le";
    }
    else if (isFull(x) == 1)
        cout << "\n Danh sach day";
    else{
        for (int i = listSize(x) - 1; i >= pos; i--)
            x.ds[i + 1] = x.ds[i];
        x.ds[pos] = a;
        x.n++;
    }
}

//Cau 3
void xoa_ViTri(DaySo &x, int pos){
    int i;
    if (pos < 0 || pos > listSize(x) - 1)
        cout << "Vi tri" << pos << "khong hop le !";
    else if (isEmpty(x))
        cout << "DS bi rong";
    else{
        for (i = pos + 1; i <= listSize(x); i++)
            x.ds[i - 1] = x.ds[i];
        x.n--;
    }
}

//Cau 4
void xoa_GiaTri_K(DaySo& x, int k) {
	for (int i = 0; i < x.n; i++) {
		if (x.ds[i] == k) {
			for (int j = i; j < x.n - 1; j++)
				x.ds[j] = x.ds[j + 1];
			x.n--;
		}
	}
}
//Cau 5
int timKiem_TuanTu(DaySo x, int a){
    int i = 0;
    while (i < x.n && x.ds[i] != a)
        i++;
    if (i == x.n)
        return -1; //Khong tim thay
    return i;
}
//Cau 6
void sapXep(DaySo &x){
    for (int i = 0; i < x.n - 1; i++)
        for (int j = i + 1; j < x.n; j++)
            if (x.ds[j] < x.ds[i]){
                int tam = x.ds[i];
                x.ds[i] = x.ds[j];
                x.ds[j] = tam;
            }
}
int timKiem_NhiPhan(DaySo x, int a){
    int bottom = 0, top = x.n - 1;
    int mid;
    do{
        mid = (bottom + top) / 2;
        if (a == x.ds[mid])
            return mid;
        else if (a < x.ds[mid])
            top = mid - 1;
        else
            bottom = mid + 1;
    } while (bottom <= top);
    return -1;
}

//Cau 7