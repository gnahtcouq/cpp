#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>
using namespace std;

void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

int main() {
  ifstream FileIn;
  FileIn.open("gioithieu.txt", ios::in);

  while (!FileIn.eof()) {
    char c;
    FileIn.get(c);
    Sleep(5);
    textcolor(14);
    cout << c;
    textcolor(7);

    // Neu ma co su tuong tac tu 1 phim bat ki thi se ket thuc loi gioi thieu
    if (kbhit()) {
      return 0;
    }
  }

  FileIn.close();

  system("pause");
  return 0;
}