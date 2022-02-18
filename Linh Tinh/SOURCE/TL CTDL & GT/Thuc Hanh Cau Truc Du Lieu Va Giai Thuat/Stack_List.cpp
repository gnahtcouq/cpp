#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//====================================================
struct Node {
  int data;
  Node* pNext;
};
//====================================================
struct List {
  Node* pHead, * pTail;
};
//====================================================
void Init(List& l) {
  l.pHead = l.pTail = NULL;
}
//====================================================
int IsEmpty(List l) {
  if (l.pHead == NULL)  return 1;
  return 0;
}
//====================================================
Node* CreateNode(int x) {
  Node* p;
  p = new Node;
  if (p == NULL) {
    printf("Loi cap phat vung nho!");
    getch();
    exit(0);
  }
  p->data = x;
  p->pNext = NULL;
  return p;
}
//====================================================
void AddHead(List& l, Node* pNew) {
  if (IsEmpty(l)) {
    l.pHead = l.pTail = pNew;
  }
  else {
    pNew->pNext = l.pHead;
    l.pHead = pNew;
  }
}
//====================================================
int Push(List& l, int sodu) {

}
//====================================================
void Convert(int n, List& l) {
  while (n != 0) {
    int sodu = n % 2;
    Push(l, sodu);
    n = n / 2;
  }
}
//====================================================
int Pop(List& l, int& x) {

}
//====================================================
void Output(List& l) {
  int x;
  while (l.pHead != NULL) {
    Pop(l, x);
    printf("%d", x);
  }
  printf(" Bin");
}
//====================================================
void NhapN(int& n) {
  do {
    printf("\n\n\tNhap so nguyen duong DECIMAL: ");
    scanf("%d", &n);
    if (n < 0) printf("\nBan nhap sai, xin nhap lai\n\n");
  } while (n < 0);
}
//====================================================

int main() {
  List l;
  int n;

  Init(l);
  do {
    NhapN(n);
    if (n == 0) break;
    Convert(n, l); printf("\n\n\t Chuyen sang nhi phan = "); Output(l);

  } while (1);

  return 0;
}
