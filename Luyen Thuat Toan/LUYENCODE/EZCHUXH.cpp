#include <iostream>
#include <string>
using namespace std;

int kiemTraBiTrung(string str, int vitridangxet) {
  for (int i = vitridangxet - 1; i >= 0; i--)
    if (str[i] == str[vitridangxet])
      return 1;
  return 0;
}

int demSoLanXuatHien(string str, int vitridangxet) {
  int dem = 1;
  for (int i = vitridangxet + 1; i < (int)str.length(); i++)
    if (str[i] == str[vitridangxet])
      dem++;
  return dem;
}

int main() {
  string str;
  getline(cin, str);

  int length = str.length();
  for (int i = 0; i < length - 1; ++i)
    for (int j = i + 1; j < length; ++j)
      if (str[i] > str[j])
        swap(str[i], str[j]);

  for (int i = 0; i < length; ++i) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      int kiemtratrung = kiemTraBiTrung(str, i);
      if (kiemtratrung == 1)
        continue;
      int dem = demSoLanXuatHien(str, i);
      cout << str[i] << ":" << dem << "\n";
    }
  }

  return 0;
}