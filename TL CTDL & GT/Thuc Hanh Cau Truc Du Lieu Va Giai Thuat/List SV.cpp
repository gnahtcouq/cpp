#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100
//Quach Quang Minh
//==========================================
typedef struct SinhVien {
  int maSV;
  char tenSV[40];
  float DTB;
}SV;
//==========================================
void NhapN(int& n) {
  do {
    printf("Nhap so luong SV (0<N): ");
    scanf("%d", &n);
    if (n < 1) printf("Nhap sai\n");
  } while (n < 1);
}
//==========================================
void Nhap1SV(SV& x) {
  printf("Nhap ma SV: ");
  scanf("%d", &x.maSV);

  printf("Nhap ten SV: ");
  fflush(stdin); gets(x.tenSV);

  printf("Nhap DTB: ");
  scanf("%f", &x.DTB);
}
//==========================================
void TieuDe() {
  printf("\n |===============|=======================================|===========|");
  printf("\n |%-15s|%-39s|%11s|", "MA SV", "TEN SV", "DTB");
  printf("\n |===============|=======================================|===========|");
}
//==========================================   
void Xuat1SV(SV x) {
  printf("\n |%-15d|%-39s|%11.2f|", x.maSV, x.tenSV, x.DTB);
}
struct Node {
  SV data;
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
Node* CreateNode(SV x) {
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
  SV x;
  Node* p;
  int n;
  NhapN(n);
  for (int i = 0;i < n;i++) {
    printf("Nhap thong tin SV thu:%d \n", i + 1);
    Nhap1SV(x);
    p = CreateNode(x);
    AddHead(l, p);
    //		AddTail(l,p);
  }
}
void Output(List l) {
  TieuDe();
  for (Node* p = l.pHead; p != NULL;p = p->pNext) {
    Xuat1SV(p->data);
  }
  printf("\n |===============|=======================================|===========|");
}
int main() {
  Node p;
  List l;
  Init(l);
  Input(l);
  printf("\nDanh SV lien ket vua nhap: \n");
  Output(l);
  return 0;
}
