#include <iostream>
using namespace std;
const int MAX = 100;
struct NhanVien {
  char ten[50];
  int tuoi;
  char chucVu[50];
  float heSoLuong;
};
struct DanhSachNhanVien {
  NhanVien ds[100];
  int soLuong;
};

void nhapNhanVien(NhanVien& nv) {
  cout << "Nhap ten nv: ";
  cin.getline(nv.ten, 50);
  cout << "Nhap tuoi: ";
  cin >> nv.tuoi;
  cin.ignore();
  cout << "Nhap chuc vu: ";
  cin.getline(nv.chucVu, 50);
  cout << "He so luong: ";
  cin >> nv.heSoLuong;
  cin.ignore();
}

void xuatNhanVien(NhanVien nv) {
  cout << nv.ten << "\t" << nv.tuoi << "\t" << nv.chucVu << "\t" << nv.heSoLuong << endl;
}

void nhapDanhSachNhanVien(DanhSachNhanVien& dsnv) {
  do {
    cout << "Nhap so NV: ";
    cin >> dsnv.soLuong;
  } while (dsnv.soLuong <= 0 || dsnv.soLuong > MAX);
  cin.ignore();
  for (int i = 0; i < dsnv.soLuong; i++) {
    nhapNhanVien(dsnv.ds[i]);
  }
}

void xuatDanhSachNhanVien(DanhSachNhanVien dsnv) {
  for (int i = 0; i < dsnv.soLuong; i++) {
    xuatNhanVien(dsnv.ds[i]);
  }
}

bool ghiDanhDachNhanVien(DanhSachNhanVien ds, char* tenFile) {
  FILE* f;
  fopen_s(&f, tenFile, "wb");
  if (f == NULL)
    return false;
  fwrite(&ds.soLuong, sizeof(int), 1, f);
  fwrite(&ds.ds, sizeof(NhanVien), ds.soLuong, f);
  fclose(f);
  return true;
}

bool docDanhDachNhanVien(DanhSachNhanVien& ds, char* tenFile) {
  FILE* f;
  fopen_s(&f, tenFile, "rb");
  if (f == NULL)
    return false;
  fread(&ds.soLuong, sizeof(int), 1, f);
  fread(&ds.ds, sizeof(NhanVien), ds.soLuong, f);
  fclose(f);
  return true;
}

int soNhanVienHeSoHon3(DanhSachNhanVien dsnv) {
  int dem = 0;
  for (int i = 0; i < dsnv.soLuong; i++) {
    if (dsnv.ds[i].heSoLuong > 3)
      dem++;
  }
  return dem;
}

DanhSachNhanVien dsNhanVienHeSoHon3(DanhSachNhanVien dsnv) {
  DanhSachNhanVien kq;
  kq.soLuong = 0;
  for (int i = 0; i < dsnv.soLuong; i++) {
    if (dsnv.ds[i].heSoLuong > 3)
      kq.ds[kq.soLuong++] = dsnv.ds[i];
  }
  return kq;
}

int soNhanVienXuatSac(DanhSachNhanVien dsnv, float luongCB) {
  int dem = 0;
  for (int i = 0; i < dsnv.soLuong; i++) {
    if (dsnv.ds[i].heSoLuong * luongCB / 24 >= 150000)
      dem++;
  }
  return dem;
}

bool ghiDanhSachNhanVienHeSoTren3(DanhSachNhanVien ds, char* tenFile) {
  FILE* f;
  fopen_s(&f, tenFile, "wb");
  if (f == NULL)
    return false;
  DanhSachNhanVien dshs3 = dsNhanVienHeSoHon3(ds);
  fwrite(&dshs3.soLuong, sizeof(int), 1, f);
  fwrite(&dshs3.ds, sizeof(NhanVien), dshs3.soLuong, f);
  fclose(f);
  return true;
}

bool docDanhSachNhanVien2(DanhSachNhanVien& ds, char* tenFile, int& soNVXS, int& soNV3) {
  FILE* f;
  fopen_s(&f, tenFile, "rb");
  if (f == NULL)
    return false;
  fread(&ds.soLuong, sizeof(int), 1, f);
  fread(&ds.ds, sizeof(NhanVien), ds.soLuong, f);
  fread(&soNVXS, sizeof(int), 1, f);
  fread(&soNV3, sizeof(int), 1, f);
  fclose(f);
  return true;
}

bool them(DanhSachNhanVien& dsnv, NhanVien nvMoi) { //them nvMoi vao cuoi ds
  if (dsnv.soLuong == MAX)
    return false;
  dsnv.ds[dsnv.soLuong++] = nvMoi;
  //dsnv.soLuong = dsnv.soLuong + 1;
}
bool capNhat(DanhSachNhanVien& dsnv, char ten[]) {
  for (int i = 0; i < dsnv.soLuong; i++)
    if (strcmp(dsnv.ds[i].ten, ten) == 0) {
      int chon;
      do {
        cout << "1. Cap nhat ten: " << endl;
        cout << "2. Cap nhat tuoi: " << endl;
        cout << "3. Cap nhat chuc vu: " << endl;
        cout << "4. Cap nhat he so luong: " << endl;
        cout << "0. Thoat" << endl;
        cout << "Ban muon cap nhat gi? ";
        cin >> chon;
        if (chon == 0)
          break;
        if (chon == 1) {
          cin.ignore();
          cout << "Nhap ten moi: ";
          cin.getline(dsnv.ds[i].ten, 50);
        }
        else if (chon == 2) {
          cout << "Nhap tuoi: ";
          cin >> dsnv.ds[i].tuoi;
        }
        else if (chon == 3) {
          cin.ignore();
          cout << "Nhap chuc vu: ";
          cin.getline(dsnv.ds[i].chucVu, 50);
        }
        else if (chon == 4) {
          cout << "Nhap he so luong moi: ";
          cin >> dsnv.ds[i].heSoLuong;
        }
        else
          cout << "Chon sai roi";

      } while (1);
      return true;
    }
  return false;
}
DanhSachNhanVien dsCongNhanLuongCao1(DanhSachNhanVien dsnv) {
  float max = 0;
  for (int i = 0; i < dsnv.soLuong; i++) {
    if (strcmp(dsnv.ds[i].chucVu, "CN") == 0 && dsnv.ds[i].heSoLuong > max)
      max = dsnv.ds[i].heSoLuong;
  }

  DanhSachNhanVien kq;
  kq.soLuong = 0;
  if (max == 0)
    return kq;
  for (int i = 0; i < dsnv.soLuong; i++) {
    if (strcmp(dsnv.ds[i].chucVu, "CN") == 0 && dsnv.ds[i].heSoLuong == max)
      kq.ds[kq.soLuong++] = dsnv.ds[i];
  }
  return kq;
}
int main1() {
  DanhSachNhanVien ds1;
  NhanVien nv1;
  int soNVXS, soNV3;
  //nhapDanhSachNhanVien(ds1);
  if (docDanhDachNhanVien(ds1, "nvien_2.dat"))
    //if (docDanhSachNhanVien2(ds1, "nhanvien2.dat",soNVXS,soNV3))
  {
    //cout << "Doc thanh cong";
    cout << "\n Thong tin cua cac nv vua doc la: " << endl;
    xuatDanhSachNhanVien(ds1);
    /*char tenNv[50];
    cout << "Cho biet ten nv can cap nhat: ";
    cin.getline(tenNv, 50);
    capNhat(ds1,tenNv);
    if (ghiDanhDachNhanVien(ds1, "nhanvien.dat"))
      cout << "Da ghi thanh cong";
    else
      cout << "Ghi file khong duoc";*/
      /*cout << "Nhap thong nv can them: ";
      nhapNhanVien(nv1);
      if (them(ds1, nv1))
      {
        if (ghiDanhDachNhanVien(ds1, "nhanvien.dat"))
          cout << "Da ghi thanh cong";
        else
          cout << "Ghi file khong duoc";
      }
      else
        cout << "Danh sach da day";*/
        //DanhSachNhanVien dscnLuongCao = dsCongNhanLuongCao1(ds1);
        ////xuatDanhSachNhanVien(dscnLuongCao);
        //ghiDanhDachNhanVien(dscnLuongCao,"nvien_2.dat");
  }
  else {
    cout << "Doc khong duoc"; exit;
  }

  /*if (ghiDanhDachNhanVien2(ds1, "nhanvien2.dat"))
    cout << "Da luu thanh cong";
  else
    cout << "Luu khong duoc";*/

  cout << endl;
  system("pause");
  return 0;
}