/* Bài 2: Đề cũng như bài 1 nhưng ta sẽ chia hàm con. */

#include <iostream>
using namespace std;

// Doc du lieu tu file va luu vao 2 bien a, b
void docFile(FILE *&FileIn, int &a, int &b) {
  FileIn = fopen("INPUT.txt", "r");
  if(!FileIn) {
    cout << "\nKhong tim thay tap tin";
    exit(0);
  }
  fscanf(FileIn, "%d%d", &a, &b);
  fclose(FileIn);
}

void ghiFile(FILE *&FileOut, int a, int b) {
  FileOut = fopen("OUTPUT.txt", "w");
  fprintf(FileOut, "%d + %d = %d\n", a, b, a + b);
  fclose(FileOut);
}

int main() {
  int a, b;
  FILE *FileIn, *FileOut;
  docFile(FileIn, a, b);
  ghiFile(FileOut, a, b);
  
  cout << endl;
  system("pause");
  return 0;
}