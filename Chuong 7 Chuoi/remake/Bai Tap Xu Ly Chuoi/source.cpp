#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <windows.h>
using namespace std;

// Ham to mau
void textcolor(int x) {
  HANDLE mau;
  mau = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(mau, x);
}

void xuatVector(vector<string> a) {
  cout << endl;
  for (int i = 0; i < a.size() - 1; ++i) {
    cout << a[i] << " ";
  }
  cout << a[a.size() - 1];
}

string tinhKetQuaBieuThucKhongNgoac(string s) {
  vector<string> a;
  // Tach chuoi neu dung substr ben C++
  /* int start = 0;
  int end;
  for (int i = start + 1; i < s.length(); ++i) {
    if (s[i] == ' ') {
      end = i;
      cout << s.substr(start, end - start) << endl;
      start = end + 1;
    }
  }
  cout << s.substr(start, s.length() - start) << endl; */
  // cout << s.substr(0, 1); // lay 1 phan tu

  // Buoc 1: Tach chuoi luu vao mang vector
  char* p = strtok((char*)s.c_str(), " ");

  while (p != NULL) {
    a.push_back(p);
    p = strtok(NULL, " ");
  }

  // Buoc 2: Xu ly tinh toan tren mang

  int dem = 1;
  // Thuc hien nhan chia truoc
  for (int i = 1; i < a.size(); i += 2) {
    if (a[i] == "*" || a[i] == "/") {
      cout << "\n\n";
      system("pause");
      textcolor(12);
      cout << "\nBuoc " << dem++ << endl;
      textcolor(7);
      for (int j = 0; j < a.size(); ++j) {
        if (j >= i - 1 && j <= i + 1)
          textcolor(14);
        cout << a[j] << " ";
        textcolor(7);
      }
      float x = stof(a[i - 1]);
      float y = stof(a[i + 1]);
      float ketqua;
      if (a[i] == "*")
        ketqua = x * y;
      else if (a[i] == "/")
        ketqua = x / y;
      a[i - 1] = to_string(ketqua);
      // xoa a[i] va a[i + 1] di
      a.erase(a.begin() + i, a.begin() + i + 2);
      // a.erase(a.begin() + i);
      // a.erase(a.begin() + i);

      cout << endl;
      for (int j = 0; j < a.size(); ++j) {
        if (j == i - 1)
          textcolor(14);
        cout << a[j] << " ";
        textcolor(7);
      }

      i -= 2; // Phai lui ve 2 cho bien i boi sau khi xoa thi index da bi thay doi cho nen neu khong lui thi se bi bo qua 1 so phep toan

      // system("pause");
      // xuatVector(a);

    }
  }

  // Thuc hien cong tru sau
  for (int i = 1; i < a.size(); i += 2) {
    if (a[i] == "+" || a[i] == "-") {
      cout << "\n\n";
      system("pause");
      textcolor(12);
      cout << "\nBuoc " << dem++ << endl;
      textcolor(7);
      for (int j = 0; j < a.size(); ++j) {
        if (j >= i - 1 && j <= i + 1)
          textcolor(14);
        cout << a[j] << " ";
        textcolor(7);
      }
      float x = stof(a[i - 1]);
      float y = stof(a[i + 1]);
      float ketqua;
      if (a[i] == "+")
        ketqua = x + y;
      else if (a[i] == "-")
        ketqua = x - y;
      a[i - 1] = to_string(ketqua);

      // xoa a[i] va a[i + 1] di
      a.erase(a.begin() + i, a.begin() + i + 2);
      // a.erase(a.begin() + i);
      // a.erase(a.begin() + i);

      cout << endl;
      for (int j = 0; j < a.size(); ++j) {
        if (j == i - 1)
          textcolor(14);
        cout << a[j] << " ";
        textcolor(7);
      }

      i -= 2; // Phai lui ve 2 cho bien i boi sau khi xoa thi index da bi thay doi cho nen neu khong lui thi se bi bo qua 1 so phep toan

      // system("pause");
      // xuatVector(a);
    }
  }
  return a[0];
}

int main() {
  string s = "1 + 2 * 3 - 4 / 5";

  // cout << s << " = " << tinhKetQuaBieuThucKhongNgoac(s);

  cout << "\nBieu thuc can tinh s = " << s;

  string ketqua = tinhKetQuaBieuThucKhongNgoac(s);

  cout << "\nKet qua cuoi cung cua bieu thuc la: " << ketqua;

  system("pause");
  return 0;
}
