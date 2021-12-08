#include <iostream>
#include <string>
using namespace std;

int STRLEN(string s) {
  int dem = 0;
  while (s[dem] != '\0') {
    dem++;
  }
  return dem;
}

int demSoTu(string s) {
  int dem;
  if (s[0] == ' ')
    dem = 0;
  else
    dem = 1;
  // int length = STRLEN((char*)s.c_str());
  int length = s.length();
  for (int i = 0; i < length - 1; i++) {
    if (s[i] == ' ' && s[i + 1] != ' ')
      dem++;
  }
  return dem;
}

int main() {
  string s4 = "Quoc Thang";
  cout << "\ns4 = " << s4;
  cout << "\nSo tu cua s4 = " << demSoTu(s4);

  system("pause");
  return 0;
}