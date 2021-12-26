#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>

using namespace std;

char map[50][50]; // mang 2 chieu cac ky tu

// Hàm thay đổi kích cỡ của khung cmd.
void resizeConsole(int width, int height) {
  HWND console = GetConsoleWindow();
  RECT r;
  GetWindowRect(console, &r);
  MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Hàm tô màu.
void textcolor(int x) {
  HANDLE mau;
  mau = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(mau, x);
}

// Hàm xóa màn hình.
void xoaManHinh() {
  HANDLE hOut;
  COORD Position;
  hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  Position.X = 0;
  Position.Y = 0;
  SetConsoleCursorPosition(hOut, Position);
}

void veDuongDua_1() {
  // Dai 30, rong 30
  for (int i = 0; i < 30; i++) {
    map[i][0] = ' ';
    map[i][29] = ' ';
    if (i % 2 == 0)
      map[i][14] = '|';
    for (int j = 1; j < 29 && j != 14; j++) {
      map[i][j] = ' ';
    }
  }
}

void veDuongDua_2() {
  // Dai 30, rong 30
  for (int i = 0; i < 30; i++) {
    map[i][0] = ' ';
    map[i][29] = ' ';
    if (i % 2 != 0)
      map[i][14] = '|';
    for (int j = 1; j < 29 && j != 14; j++) {
      map[i][j] = ' ';
    }
  }
}

void inDuongDua() {
  for (int i = 0; i < 30; i++) {
    cout << "\t\t\t";
    for (int j = 0; j < 30; j++) {
      // In duong dua
      if (j == 0 || j == 29) {
        textcolor(191);
        cout << map[i][j];
        textcolor(7);
      }
      else if (j == 14) {
        textcolor(15);
        cout << map[i][j];
        textcolor(7);
        map[i][j] = ' '; // Xoa lan di
      }


      // In xe player
      else if (map[i][j] == 'X' || map[i][j] == '@' || map[i][j] == '#') {
        textcolor(14);
        cout << map[i][j];
        textcolor(7);
      }

      // In xe computer
      else if (map[i][j] == '!') {
        // map[i][j] = ' '; // Bo di ky tu !
        textcolor(200);
        cout << map[i][j];
        textcolor(7);
      }

      // Nhung ky tu khong phai la xe
      else
        cout << map[i][j];
    }
    cout << endl;
  }
}

void veXePlayer(int x, int y) {
  map[x][y] = 'X'; // Than xe
  map[x][y - 1] = '#'; // Ben trai than xe
  map[x][y + 1] = '#'; // Ben phai than xe
  map[x - 1][y - 1] = '@'; // Banh xe tren ben trai
  map[x + 1][y - 1] = '@'; // Banh xe duoi ben trai
  map[x - 1][y + 1] = '@'; // Banh xe tren ben phai
  map[x + 1][y + 1] = '@'; // Banh xe duoi ben phai
}

void veXeChuongNgaiVat(int x, int y) {
  map[x][y] = '!'; // Than xe
  map[x][y - 1] = '!'; // Ben trai than xe
  map[x][y + 1] = '!'; // Ben phai than xe
  map[x - 1][y - 1] = '!'; // Banh xe tren ben trai
  map[x + 1][y - 1] = '!'; // Banh xe duoi ben trai
  map[x - 1][y + 1] = '!'; // Banh xe tren ben phai
  map[x + 1][y + 1] = '!'; // Banh xe duoi ben phai
}

void xoaXeChuongNgaiVat(int x, int y) {
  map[x][y] = ' '; // Than xe
  map[x][y - 1] = ' '; // Ben trai than xe
  map[x][y + 1] = ' '; // Ben phai than xe
  map[x - 1][y - 1] = ' '; // Banh xe tren ben trai
  map[x + 1][y - 1] = ' '; // Banh xe duoi ben trai
  map[x - 1][y + 1] = ' '; // Banh xe tren ben phai
  map[x + 1][y + 1] = ' '; // Banh xe duoi ben phai
}

void diChuyenXe(int& x, int& y) { // x,y la toa do hien tai cua xe

  // Trai tren cung (1, 2)
  // Trai duoi cung (28, 2)
  // Phai tren cung (1, 27)
  // Phai duoi cung (28, 27)

  // Qua trai
  if (GetAsyncKeyState(VK_LEFT)) {
    if (y > 2) {
      // Kiem tra su dung do giua xe player va xe tinh
      if (map[x][y] == '!' || map[x][y - 1] == '!' || map[x][y + 1] == '!' || map[x - 1][y - 1] == '!' || map[x + 1][y - 1] == '!' || map[x - 1][y + 1] == '!' || map[x + 1][y + 1] == '!') {
        cout << "\a"; // Tieng beep
      }

      // Xoa xe di
      map[x][y] = ' '; // Than xe
      map[x][y - 1] = ' '; // Ben trai than xe
      map[x][y + 1] = ' '; // Ben phai than xe
      map[x - 1][y - 1] = ' '; // Banh xe tren ben trai
      map[x + 1][y - 1] = ' '; // Banh xe duoi ben trai
      map[x - 1][y + 1] = ' '; // Banh xe tren ben phai
      map[x + 1][y + 1] = ' '; // Banh xe duoi ben phai

      y--; // Giam cot xuong
      veXePlayer(x, y); // Ve lai xe

    }
  }

  // Qua phai
  else if (GetAsyncKeyState(VK_RIGHT)) {
    if (y < 27) {
      // Kiem tra su dung do giua xe player va xe tinh
      if (map[x][y] == '!' || map[x][y - 1] == '!' || map[x][y + 1] == '!' || map[x - 1][y - 1] == '!' || map[x + 1][y - 1] == '!' || map[x - 1][y + 1] == '!' || map[x + 1][y + 1] == '!') {
        cout << "\a"; // Tieng beep
      }

      // Xoa xe di
      map[x][y] = ' '; // Than xe
      map[x][y - 1] = ' '; // Ben trai than xe
      map[x][y + 1] = ' '; // Ben phai than xe
      map[x - 1][y - 1] = ' '; // Banh xe tren ben trai
      map[x + 1][y - 1] = ' '; // Banh xe duoi ben trai
      map[x - 1][y + 1] = ' '; // Banh xe tren ben phai
      map[x + 1][y + 1] = ' '; // Banh xe duoi ben phai

      y++; // Tang cot len
      veXePlayer(x, y); // Ve lai xe

    }
  }

  // Di len
  else if (GetAsyncKeyState(VK_UP)) {
    // Kiem tra su dung do giua xe player va xe tinh
    if (map[x][y] == '!' || map[x][y - 1] == '!' || map[x][y + 1] == '!' || map[x - 1][y - 1] == '!' || map[x + 1][y - 1] == '!' || map[x - 1][y + 1] == '!' || map[x + 1][y + 1] == '!') {
      cout << "\a"; // Tieng beep
    }

    // Xoa xe di
    if (x > 1) {
      map[x][y] = ' '; // Than xe
      map[x][y - 1] = ' '; // Ben trai than xe
      map[x][y + 1] = ' '; // Ben phai than xe
      map[x - 1][y - 1] = ' '; // Banh xe tren ben trai
      map[x + 1][y - 1] = ' '; // Banh xe duoi ben trai
      map[x - 1][y + 1] = ' '; // Banh xe tren ben phai
      map[x + 1][y + 1] = ' '; // Banh xe duoi ben phai

      x--; // Giam so dong
      veXePlayer(x, y); // Ve lai xe
    }
  }

  // Di xuong
  else if (GetAsyncKeyState(VK_DOWN)) {
    // Kiem tra su dung do giua xe player va xe tinh
    if (map[x][y] == '!' || map[x][y - 1] == '!' || map[x][y + 1] == '!' || map[x - 1][y - 1] == '!' || map[x + 1][y - 1] == '!' || map[x - 1][y + 1] == '!' || map[x + 1][y + 1] == '!') {
      cout << "\a"; // Tieng beep
    }

    // Xoa xe di
    if (x < 28) {
      map[x][y] = ' '; // Than xe
      map[x][y - 1] = ' '; // Ben trai than xe
      map[x][y + 1] = ' '; // Ben phai than xe
      map[x - 1][y - 1] = ' '; // Banh xe tren ben trai
      map[x + 1][y - 1] = ' '; // Banh xe duoi ben trai
      map[x - 1][y + 1] = ' '; // Banh xe tren ben phai
      map[x + 1][y + 1] = ' '; // Banh xe duoi ben phai

      x++; // Tang so dong
      veXePlayer(x, y); // Ve lai xe
    }
  }

}

int main() {
  resizeConsole(600, 800);
  int x = 20, y = 15; // Toa do xe player
  int x1 = 5, y1; // Toa do xe chuong ngai vat dong
  int x2 = 5, y2 = 10; // Toa do xe chuong ngai vat tinh
  int quangduong = 0;
  int a = 0;
  while (true) {
    quangduong++;
    a++;
    if (a % 2 != 0)
      veDuongDua_1();
    else
      veDuongDua_2();

    // Ramdom tung do cho xe computer
    /*
    Muon random 1 so nguyen trong doan [a, b]
    srand(time(0)); // reset thoi gian
    int x = a + rand() % (b - a + 1); // cong thuc
    */

    srand(time(0)); // reset thoi gian
    y1 = 2 + rand() % 26; // [2, 27]


    veXePlayer(x, y);
    veXeChuongNgaiVat(x1, y1); // Xe dong
    veXeChuongNgaiVat(x2, y2); // Xe tinh

    xoaManHinh();


    inDuongDua();

    diChuyenXe(x, y);

    Sleep(0);


    if (a > 30)
      a = 0;

    cout << "\nQuang duong = " << quangduong << " m";

    // Dang so sanh xem co bi trung voi xe tinh & xe dong hay khong
    // Kiem tra su dung do giua xe player va xe tinh
    if (map[x][y] == '!' || map[x][y - 1] == '!' || map[x][y + 1] == '!' || map[x - 1][y - 1] == '!' || map[x + 1][y - 1] == '!' || map[x - 1][y + 1] == '!' || map[x + 1][y + 1] == '!') {
      cout << "\a"; // Tieng beep
      cout << "\nBan choi ngu vl, ban da bi dung o quang duong " << quangduong << " m";
    }

    xoaXeChuongNgaiVat(x1, y1);
    x1++; // Tang dong len tao hieu ung di chuyen
    if (x1 == 31)
      x1 = 2;

    xoaXeChuongNgaiVat(x2, y2);
    x2++;
    if (x2 == 31) {
      x2 = 5;
      y2 = 2 + rand() % 26;
    }


  }


  system("pause");
  return 0;
}