#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100
//Quach Quang Minh
//==========================================
typedef struct NhanVien {
  int maNV;
  char tenNV[40];
  float Luong;
}NV;
//==========================================
void NhapN(int& n) {
  do {
    printf("Nhap so luong NV (0<N): ");
    scanf("%d", &n);
    if (n < 1) printf("Nhap sai\n");
  } while (n < 1);
}
//==========================================
void Nhap1NV(NV& x) {
  printf("Nhap ma NV: ");
  scanf("%d", &x.maNV);

  printf("Nhap ten NV: ");
  fflush(stdin); gets(x.tenNV);

  printf("Nhap Luong: ");
  scanf("%f", &x.Luong);
}
//==========================================
void TieuDe() {
  printf("\n |===============|=======================================|===========|");
  printf("\n |%-15s|%-39s|%11s|", "MA NV", "TEN NV", "Luong");
  printf("\n |===============|=======================================|===========|");
}
//==========================================   
void Xuat1NV(NV x) {
  printf("\n |%-15d|%-39s|%11.2f|", x.maNV, x.tenNV, x.Luong);
}
struct Node {
  NV data;
  Node* pNext;
};
struct List {
  Node* pHead, * pTail;
};
void Init(List& l) {
  l.pHead = l.pTail = NULL;
}
int IsEmty(List l) {
  if (l.pHead == NULL) return 1;
  return 0;
}
Node* CreateNode(NV x) {
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
void AddHead(List& l, Node* p) {
  if (l.pHead == NULL)
    l.pHead = l.pTail = p;
  else {
    p->pNext = l.pHead;
    l.pHead = p;
  }
}
void AddTail(List& l, Node* p) {
  if (l.pTail == NULL)
    l.pHead = l.pTail = p;
  else {
    l.pTail->pNext = p;
    l.pTail = p;
  }
}
void Input(List& l) {
  NV x;
  Node* p;
  int n;
  NhapN(n);
  for (int i = 0;i < n;i++) {
    printf("Nhap thong tin NV thu:%d \n", i + 1);
    Nhap1NV(x);
    p = CreateNode(x);
    AddHead(l, p);
    //		AddTail(l,p);
  }
}
void Output(List l) {
  TieuDe();
  for (Node* p = l.pHead; p != NULL;p = p->pNext) {
    Xuat1NV(p->data);
  }
  printf("\n |===============|=======================================|===========|");
}
int main() {
  Node p;
  List l;
  Init(l);
  Input(l);
  printf("\nDanh sach SV vua nhap: \n");
  Output(l);
  return 0;
}
