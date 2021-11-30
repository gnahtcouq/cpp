/* Bài 1: Viết chương trình đọc vào 2 số nguyên a, b từ tập tin INPUT.TXT rồi tính tổng 2 số nguyên này, kết quả ghi vào tập tin OUTPUT.TXT */

#include <iostream>
using namespace std;

int main() {

  FILE *FileIn = fopen("INPUT.txt", "r");

  if(!FileIn) {
    cout << "\nKhong tim thay tap tin";
    return 0;
  }

  int a, b;
  fscanf(FileIn, "%d%d", &a, &b);

  // fscanf(FileIn, "%d", &a);
  // fscanf(FileIn, "%d", &b);

  fclose(FileIn);

  // cout << "\n a = " << a;
  // cout << "\n b = " << b;

  // int tong = a + b;

  FILE *FileOut = fopen("OUTPUT.txt", "w");

  fprintf(FileOut, "%d + %d = %d\n", a, b, a + b);

  fclose(FileOut);
  
  cout << endl;
  system("pause");
  return 0;
}