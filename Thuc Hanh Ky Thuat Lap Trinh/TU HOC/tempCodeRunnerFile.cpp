  nhapDanhSachNhanVien(ds);
  if (ghiDanhSachNhanVien(ds, "danhsachnhanvien.dat"))
    cout << "\nGhi file thanh cong" << endl;
  else
    cout << "\nGhi file khong duoc";
  xuatDanhSachNhanVien(ds);