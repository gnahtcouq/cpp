#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100
//Quach Quang Minh
//==========================================
typedef struct CuonSach {
  int masach;
  char tensach[40];
  float gia;
}SACH;
//==========================================
void NhapN(int& n) {
  do {
    printf("Nhap so luong cuon sach (0<N): ");
    scanf("%d", &n);
    if (n < 1) printf("Nhap sai\n");
  } while (n < 1);
}
//==========================================
void Nhap1SACH(SACH& x) {
  printf("Nhap ma cuon sach: ");
  scanf("%d", &x.masach);

  printf("Nhap ten cuon sach: ");
  fflush(stdin); gets(x.tensach);

  printf("Nhap gia cuon sach: ");
  scanf("%f", &x.gia);
}
//==========================================
void TieuDe() {
  printf("\n |===============|=======================================|===========|");
  printf("\n |%-15s|%-39s|%11s|", "MA SACH", "TEN CUON SACH", "GIA");
  printf("\n |===============|=======================================|===========|");
}
//==========================================   
void Xuat1SACH(SACH x) {
  printf("\n |%-15d|%-39s|%11.2f|", x.masach, x.tensach, x.gia);
}
struct Node {
  SACH data;
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
Node* CreateNode(SACH x) {
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
  SACH x;
  Node* p;
  int n;
  NhapN(n);
  for (int i = 0;i < n;i++) {
    printf("Nhap thong tin cuon sach thu:%d \n", i + 1);
    Nhap1SACH(x);
    p = CreateNode(x);
    AddHead(l, p);
    //		AddTail(l,p);
  }
}
void Output(List l) {
  for (Node* p = l.pHead; p != NULL;p = p->pNext) {
    Xuat1SACH(p->data);
  }
  printf("\n|=======|=====================================");
}
int main() {
  Node p;
  List l;
  Init(l);
  Input(l);
  printf("\nDanh sach lien ket vua nhap: \n");
  Output(l);
  return 0;
}
