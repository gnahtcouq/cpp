#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// struct ThongTin {
//   string m_Code;
//   int m_speed, m_equiment;
// };
// typedef struct ThongTin THONGTIN;

int main() {
  int n;
  string m_Code;
  int m_Speed, m_Equiment;
  ifstream FileIn;
  FileIn.open("input.txt", ios::in);
  if (!FileIn) {
    printf("\nKhong tim thay tap tin");
    exit(0);
  }
  FileIn >> n;
  getline(FileIn, m_Code);
  m_Code.erase(m_Code.begin() + m_Code.length() - 1);

  FileIn.close();
  cout << "\nm_Code = " << m_Code;
  system("pause");
  return 0;
}