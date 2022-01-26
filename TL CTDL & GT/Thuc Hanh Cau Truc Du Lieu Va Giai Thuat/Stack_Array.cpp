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
void Convert(Stack& s, int n) {
  while (n) {
    int du = n % 2;
    Push(s, du);
    n = n / 2;
  }
}
//====================================================
void Output(Stack& s) {
  int x;
  while (!IsEmpty(s)) {
    Pop(s, x);
    printf("%d", x);
  }
  printf(" Bin");
}
//====================================================
int main() {
  Stack s;
  int n;

  Init(s);
  do {
    NhapN(n);
    if (n == 0) break;
    Convert(s, n);		printf("\n\n\t He nhi phan: "); Output(s);

  } while (1);

  return 0;
}
//====================================================
