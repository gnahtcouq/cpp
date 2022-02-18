#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//====================================================
struct Node {
  int data;
  Node* pNext;
};
//====================================================
struct STACK {
  Node* pHead, * pTail;
};
//====================================================
void Init(STACK& S) {
  S.pHead = S.pTail = NULL;
}
//====================================================
int IsEmpty(STACK S) {
  if (S.pHead == NULL)  return 1;
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
void AddHead(STACK& S, Node* pNew) {
  if (IsEmpty(S)) {
    S.pHead = S.pTail = pNew;
  }
  else {
    pNew->pNext = S.pHead;
    S.pHead = pNew;
  }
}
//====================================================
int Push(STACK& S, int sodu) {
  Node* pNew = CreateNode(sodu);
  AddHead(S, pNew);
  return 1;
}
//====================================================
void Convert(STACK& S, int n, int coso) {
  while (n != 0) {
    int sodu = n % coso;
    Push(S, sodu);
    n = n / coso;
  }
}
//====================================================
int Pop(STACK& S, int& x) {
  if (IsEmpty(S)) return 0;
  Node* p = S.pHead;
  x = p->data;
  S.pHead = S.pHead->pNext;
  if (S.pHead == NULL) S.pTail = NULL;
  delete p;
  return 1;
}
//====================================================
void Output(STACK& S, int coso) {
  int x;
  while (S.pHead != NULL) {
    Pop(S, x);
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
void NhapN(int& n) {
  do {
    printf("\n\n\tNhap so nguyen duong DECIMAL: ");
    scanf("%d", &n);
    if (n < 0) printf("\nBan nhap sai, xin nhap lai\n\n");
  } while (n < 0);
}
//====================================================

int main() {
  STACK S;
  int n;

  Init(S);
  do {
    NhapN(n);
    if (n == 0) break;
    Convert(S, n, 2);		printf("\n\n\t He nhi phan: "); Output(S, 2);
    Convert(S, n, 8);		printf("\n\n\t He bat phan: "); Output(S, 8);
    Convert(S, n, 16);		printf("\n\n\t He thap luc phan: "); Output(S, 16);
  } while (1);

  return 0;
}
