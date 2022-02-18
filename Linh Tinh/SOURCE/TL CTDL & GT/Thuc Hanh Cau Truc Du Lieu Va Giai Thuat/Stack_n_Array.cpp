#include <stdio.h>
#include <conio.h>

#define MAXSTACK 100
//====================================================
struct Stack {
  int top;
  int node[MAXSTACK];
};
//====================================================
void NhapN(int& n) {
  do {
    printf("\n\n\tNhap so nguyen duong DECIMAL: ");
    scanf("%d", &n);
    if (n < 0) printf("\nBan nhap sai, xin nhap lai\n\n");
  } while (n < 0);
}
//====================================================
void Init(Stack& s) {
  s.top = -1;
}
//====================================================
int IsEmpty(Stack s) {
  return (s.top == -1);
}
//====================================================
int IsFull(Stack s) {
  return (s.top == MAXSTACK - 1);
}
//====================================================
int Push(Stack& s, int x) {
  if (IsFull(s)) return 0;
  else {
    s.node[++s.top] = x;
    return 1;
  }
}
//====================================================
int Pop(Stack& s, int& x) {
  if (IsEmpty(s)) return 0;
  else {
    x = s.node[s.top--];
    return 1;
  }
}
//====================================================
void Convert(Stack& s, int n, int coso) {
  while (n) {
    int du = n % coso;
    Push(s, du);
    n = n / coso;
  }
}
//====================================================
void Output(Stack& s, int coso) {
  int x;
  while (!IsEmpty(s)) {
    Pop(s, x);
    if (x < 10) printf("%d", x);
    else printf("%c", 'A' + x - 10);
  }
  switch (coso) {
  case 2: printf(" Bin"); break;
  case 8: printf(" Oct"); break;
  case 16: printf(" Hex"); break;
  }
}
//====================================================
int main() {
  Stack s;
  int n;

  Init(s);
  do {
    NhapN(n);
    if (n == 0) break;
    Convert(s, n, 2);		printf("\n\n\t He nhi phan: "); Output(s, 2);
    Convert(s, n, 8);		printf("\n\n\t He bat phan: "); Output(s, 8);
    Convert(s, n, 16);		printf("\n\n\t He thap luc phan: "); Output(s, 16);

  } while (1);

  return 0;
}
//====================================================
