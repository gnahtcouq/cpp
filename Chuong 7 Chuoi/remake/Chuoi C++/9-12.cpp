#include <iostream>
#include <string>
#include <string.h>
using namespace std;

void nhap(string &s) {
  cout << "\nNhap s: ";
  getline(cin, s);
}

int main() {
  // string s = "Tran Van Quoc Thang";
  // cout << s;

  // string s;
  // cout << "\nNhap ten: ";
  // // cin >> s; // <=> scanf
  // getline(cin, s); // <=> gets
  // cout << "\nTen: " << s;

  string s = "Quoc Thang";
  int dodai = s.length();
  cout << "\nDo dai = " << dodai;

  s.erase(s.begin() + 4); // xoa ky tu tai vi tri 4
  cout << "\ns = " << s;

  s.insert(s.begin() + 4, ' ');
  cout << "\ns = " << s;

  string a = "Thang";
  string b;
  b = a; // gan a sang b
  cout << "\nb = " << b;

  string c = " dep trai";
  a += c; // noi c vao sau a
  cout << "\na = " << a;

  string s1 = "Thang dep trai";
  strrev((char *)s1.c_str());
  cout << "\ns1 = " << s1;
  
  string s2 = "123";
  int number = atoi((char *)s2.c_str());
  cout << "\nnumber = " << number;

  int kichthuocthatsu = s2.capacity();
  cout << "\nKich thuoc that su = " << kichthuocthatsu;

  string s3;
  nhap(s3);
  cout << "\ns3 = " << s3;

  return 0;
}