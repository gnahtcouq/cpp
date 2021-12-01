#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {
  string m_Code;
  int m_Speed, m_Equiment;
  int n;
  string temp;
  ifstream FileIn;

  FileIn.open("input.txt");
  FileIn >> n;
  cout << "\nSo luong: " << n;
  for(int i = 0; i < n; i++) {
    FileIn >> m_Code;
    FileIn >> m_Speed;
    FileIn >> m_Equiment;

    cout << "\nm_Code = " << m_Code;
    cout << "\nm_Speed = " << m_Speed;
    cout << "\nm_Equiment = " << m_Equiment;
    cout << "\n------------------";
  }

  FileIn.close();

  system("pause");
  return 0;
}