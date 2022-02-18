#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
struct SV {
  int maSV;
  char holot[30];
  char ten[10];
  float dtb;
};
struct Node {
  SV data;
  Node* pNext;
};
struct List {
  Node* pHead, * pTail;
};
void InitList(List& l) {
  l.pHead = l.pTail = NULL;

}
int IsEmpty(List l) {
  return(l.pHead == NULL);
}
void Nhap1SV(SV& x) {
  printf("Nhap maSV sinh vien: ");
  scanf("%d", &x.maSV);
  printf("Nhap ho lot: ");
  fflush(stdin);gets(x.holot);
  printf("Nhap ten: ");
  fflush(stdin);gets(x.ten);
  printf("Nhap DTB: ");
  scanf("%f", &x.dtb);
}
void NhapN(int& n) {
  do {
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    if (n < 1) printf("Ban nhap sai roi,xin nhap lai\n");
  } while (n < 1);
}
Node* CreateNode(SV x) {
  Node* p = new Node;
  if (p != NULL) {
    p->data = x;
    p->pNext = NULL;
  }
  return p;
}
void AddHead(List& l, Node* pNew) {
  if (IsEmpty(l)) {
    l.pHead = l.pTail = pNew;
  }
  else {
    pNew->pNext = l.pHead;
    l.pHead = pNew;
  }
}
void AddTail(List& l, Node* pNew) {
  if (IsEmpty(l)) {
    l.pHead = l.pTail = pNew;
  }
  else {
    l.pTail->pNext = pNew;
    l.pTail = pNew;
  }
}
void NhapDS(List& l) {
  int n;
  SV x;
  NhapN(n);
  for (int i = 0;i < n;i++) {
    printf("\nNhap thong tin sinh vien thu %d: \n", i + 1);
    Nhap1SV(x);
    Node* p = CreateNode(x);
    AddTail(l, p);
  }
}
void TieuDe() {
  printf("\n |===============|=======================================|===========|");
  printf("\n |%-15s|%-39s|%11s|", "MA SV", "HO TEN SV", "DTB");
  printf("\n |===============|=======================================|===========|");
}
void Xuat1SV(SV x) {
  printf("\n |%-15d|%-39s|%11.2f|", x.maSV, x.holot, x.ten, x.dtb);
}
void XuatDS(List l) {
  TieuDe();
  for (Node* p = 1.pHead;p != NULL;p = p->pNext) {
    Xuat1SV(p->data);
  }
  printf("\n |===============|=======================================|===========|");
}
void LietKeSV_DTB_LonHon5(List l) {
  TieuDe();
  for (Node* p = 1.pHead;p != NULL;p = p->pNext) {
    Xuat1SV(p->data);
  }
  printf("\n |===============|=======================================|===========|");
}
Node* TimSV_Ma_X(List l, int maX) {
  Node* p = 1.pHead;
  while (p != NULL) {
    if (p->data.maSV == maX) return p;
    p = p->pNext;
  }
  return p;
}
void ReadFile(const char* filename, List& l) {
  FILE* f = fopen(filename, "rt");
  if (f == NULL) {
    printf("\nKhong doc duoc file");
    getch(); exit(1);
  }
  SV x;

  int n;
  fscanf(f, "%d\n", &n);
  for (int i = 0;i < n;i++) {
    fscanf(f, "%d %f %s", &x.maSV, &x.dtb, &x.ten);

    fgets(x.holot, 30, f);
    x.holot[strlen(x.holot) - 1] = '\0';
    Node* p = CreateNode(x);
    ////	AddHead(l,p);
    AddTail(l, p);
  }
  fclose(f);
}
void Swap(SV& x, SV& y) {
  SV t = x;
  x = y;
  y = t;
}
void SelectionSort_Tang_Ten(SACH a[], int n) {

  for (Node* i = 1.pHead;i->pNext != NULL;i = i->pNext) {
    Node* vtmax = i
      for (Node* j = i->pNext;j != NULL;j = i->pNext)
        if (strcmp(vtmax->data.ten, j->data.ten) > 0)
          vtmax = j;
    Swap(i->data, vtmax->data);
  }
}
void SelectionSort_Tang_Ma(List& l) {
  for (Node* i = 1.pHead;i->pNext != NULL;i = i->pNext) {
    Node* vtmax = i
      for (Node* j = i->pNext;j != NULL;j = i->pNext)
        if (vtmax->data.maSV > j->data.maSV)
          vtmax = j;
    Swap(i->data, vtmax->data);
  }
}
void SelectionSort_


