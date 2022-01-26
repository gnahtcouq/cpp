#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
struct SV {
  int maSV;
  char tenSV[40];
  float DTB;
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
  printf("Nhap maSV: ");
  scanf("%d", &x.maSV);
  printf("Nhap tenSV: ");
  fflush(stdin); gets(x.tenSV);
  printf("Nhap DTB: ");
  scanf(" %f", &x.DTB);
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
  printf("\n |========|=======================================|=========|");
  printf("\n |%-8s|%-39s|%9s|", "MA SV", "TEN SV", "DTB");
  printf("\n |========|=======================================|=========|");
}
void Xuat1SV(SV x) {
  printf("\n |%-8d|%-39s|%9.1f|", x.maSV, x.tenSV, x.DTB);
}
void XuatDS(List l) {
  TieuDe();
  for (Node* p = l.pHead;p != NULL;p = p->pNext) {
    Xuat1SV(p->data);
  }
  printf("\n |========|=======================================|=========|");
}
void LietKeSV_DTB_LonHon5(List l) {
  TieuDe();
  for (Node* p = l.pHead;p != NULL;p = p->pNext)
    if (p->data.DTB > 5)
      Xuat1SV(p->data);
  printf("\n |========|=======================================|=========|");
}
void LietKeSV_DTB_NhoHon5(List l) {
  TieuDe();
  for (Node* p = l.pHead;p != NULL;p = p->pNext)
    if (p->data.DTB < 5)
      Xuat1SV(p->data);
  printf("\n |========|=======================================|=========|");
}
Node* TimSV_Ma_X(List l, int maX) {
  Node* p = l.pHead;
  while (p != NULL) {
    if (p->data.maSV == maX) return p;
    p = p->pNext;
  }
  return p;
}

void ReadFile(const char* filename, List& l) {
  FILE* f = fopen(filename, "rt");
  if (f == NULL) {
    printf("\nKhong doc duoc file|");
    return;
  }
  SV x;
  Node* p;
  int n;
  fscanf(f, "%d\n", &n);
  for (int i = 0;i < n;i++) {
    fscanf(f, "%d", &x.maSV);
    fscanf(f, "%f", &x.DTB);
    fgets(x.tenSV, 40, f);
    x.tenSV[strlen(x.tenSV) - 1] = '\0';
    p = CreateNode(x);
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
void SelectionSort_Tang_TenSV(List& l) {

  for (Node* i = l.pHead;i->pNext != NULL;i = i->pNext) {
    Node* vtmax = i;
    for (Node* j = i->pNext;j != NULL;j = j->pNext)
      if (stricmp(vtmax->data.tenSV, j->data.tenSV) > 0)
        vtmax = j;
    Swap(i->data, vtmax->data);
  }
}
void SelectionSort_Giam_TenSV(List& l) {

  for (Node* i = l.pHead;i->pNext != NULL;i = i->pNext) {
    Node* vtmax = i;
    for (Node* j = i->pNext;j != NULL;j = j->pNext)
      if (stricmp(vtmax->data.tenSV, j->data.tenSV) < 0)
        vtmax = j;
    Swap(i->data, vtmax->data);
  }
}
void SelectionSort_Tang_Ma(List& l) {
  for (Node* i = l.pHead;i->pNext != NULL;i = i->pNext) {
    Node* vtmax = i;
    for (Node* j = i->pNext;j != NULL;j = j->pNext)
      if (vtmax->data.maSV > j->data.maSV)
        vtmax = j;
    Swap(i->data, vtmax->data);
  }
}
void SelectionSort_Giam_Ma(List& l) {
  for (Node* i = l.pHead;i->pNext != NULL;i = i->pNext) {
    Node* vtmax = i;
    for (Node* j = i->pNext;j != NULL;j = j->pNext)
      if (vtmax->data.maSV < j->data.maSV)
        vtmax = j;
    Swap(i->data, vtmax->data);
  }
}
void InterchangeSort_Tang_DTB(List& l) {
  Node* i, * j;
  for (i = l.pHead;i != l.pTail;i = i->pNext) {
    for (Node* j = i->pNext;j != NULL;j = j->pNext)
      if (i->data.DTB > j->data.DTB)
        Swap(i->data, j->data);
  }
}
void InterchangeSort_Giam_DTB(List& l) {
  Node* i, * j;
  for (i = l.pHead;i != l.pTail;i = i->pNext) {
    for (Node* j = i->pNext;j != NULL;j = j->pNext)
      if (i->data.DTB < j->data.DTB)
        Swap(i->data, j->data);
  }
}

void InterchangeSort_Tang_TenSV(List& l) {
  Node* i, * j;
  for (i = l.pHead;i != l.pTail;i = i->pNext) {
    for (Node* j = i->pNext;j != NULL;j = j->pNext)
      if (stricmp(i->data.tenSV, j->data.tenSV) > 0)
        Swap(i->data, j->data);
  }
}
void InterchangeSort_Giam_TenSV(List& l) {
  Node* i, * j;
  for (i = l.pHead;i != l.pTail;i = i->pNext) {
    for (Node* j = i->pNext;j != NULL;j = j->pNext)
      if (stricmp(i->data.tenSV, j->data.tenSV) < 0)
        Swap(i->data, j->data);
  }
}
void InsertAfterP(List& l, Node* p, Node* pNew) {
  if (p == l.pTail) AddTail(l, pNew);
  else {
    pNew->pNext = p->pNext;
    p->pNext = pNew;
  }
}
void InsertBeforeP(List& l, Node* p, Node* pNew) {
  InsertAfterP(l, p, pNew);
  Swap(p->data, pNew->data);
}
void DeleteHead(List& l) {
  Node* pDel = l.pHead;
  l.pHead = pDel->pNext;
  if (l.pHead == NULL)l.pTail = NULL;
  delete(pDel);
}
Node* PrevNodeP(List& l, Node* p) {
  if (p == l.pHead)
    return NULL;
  Node* pTruoc = l.pHead;
  while (pTruoc->pNext != p)
    pTruoc = pTruoc->pNext;
  return pTruoc;
}
void DeleteTail(List& l) {
  if (l.pHead == l.pTail)
    DeleteHead(l);
  else {
    Node* pDel = l.pTail;
    Node* pTruoc = PrevNodeP(l, pDel);
    pTruoc->pNext = NULL;
    l.pTail = pTruoc;
    delete(pDel);
  }
}
void Destroylist(List& l) {
  while (!IsEmpty(l)) {
    DeleteHead(l);
  }
}
void DeleteNode(List& l, Node* pDel) {
  if (pDel == l.pHead)
    DeleteHead(l);
  else if (pDel == l.pTail)
    DeleteTail(l);
  else {
    Node* pPrev = PrevNodeP(l, pDel);
    pPrev->pNext = pDel->pNext;
    free(pDel);
  }
}
int XoaX(List& l, int maX) {

  Node* pX = TimSV_Ma_X(l, maX);
  if (pX == NULL)
    return 0;
  DeleteNode(l, pX);
  return 1;
}
void Menu(int& chon) {
  printf("\n\n |========|======================MENU=======================|");
  printf("\n |  Phim  |\t\t\tCong viec        	    |");
  printf("\n |========|=================================================|");
  printf("\n |  \\1\\   |    \tLinearSearch Ma SV!                         |");
  printf("\n |========|=================================================|");
  printf("\n |  \\2\\   |    \tSelectionsort_tang theo Ma SV!              |");
  printf("\n |========|=================================================|");
  printf("\n |  \\3\\   |    \tSelectionsort_giam theo Ma SV!              |");
  printf("\n |========|=================================================|");
  printf("\n |  \\4\\   |    \tSelectionsort_tang theo HoTen SV!           |");
  printf("\n |========|=================================================|");
  printf("\n |  \\5\\   |    \tInsertAfterP!                               |");
  printf("\n |========|=================================================|");
  printf("\n |  \\6\\   |    \tInsertBeforeP!                              |");
  printf("\n |========|=================================================|");
  printf("\n |  \\7\\   |    \tDelete Head!                                |");
  printf("\n |========|=================================================|");
  printf("\n |  \\8\\   |    \tDelete Tail!                                |");
  printf("\n |========|=================================================|");
  printf("\n |  \\9\\   |    \tInterchangeSort_tang_DTB!                   |");
  printf("\n |========|=================================================|");
  printf("\n |  \\10\\  |    \tSelectionsort_giam theo HoTen SV!           |");
  printf("\n |========|=================================================|");
  printf("\n |  \\11\\  |    \tInterchangeSort_giam_DTB!                   |");
  printf("\n |========|=================================================|");
  printf("\n |  \\12\\  |    \tInterchangeSort_tang_HoTenSV!               |");
  printf("\n |========|=================================================|");
  printf("\n |  \\13\\  |    \tInterchangeSort_giam_HoTenSV!               |");
  printf("\n |========|=================================================|");
  printf("\n |  \\14\\  |    \tDelete List!                                |");
  printf("\n |========|=================================================|");
  printf("\n |  \\15\\  |    \tDelete X!                                   |");
  printf("\n |========|=================================================|");
  printf("\n |  \\16\\  |    \tSinh vien DTB lon hon 5!                    |");
  printf("\n |========|=================================================|");
  printf("\n |  \\17\\  |    \tSinh vien DTB nho hon 5!                    |");
  printf("\n |========|=================================================|");
  printf("\n |  \\0\\   |    \t\t\tThoat!                      |");
  printf("\n |========|=================================================|");
  printf("\n\nMoi ban chon chuc nang: ");	scanf("%d", &chon);
}
int main() {
  List l;
  int x, kq;
  int chon;
  int maX;
  Node* t, * pNew;
  SV y;
  InitList(l);
  ReadFile("D:/Thuc Hanh Cau Truc Du Lieu Va Giai Thuat/Sinhvien.txt", l);
  printf("\n\nDanh sach sinh vien vua nhap la:\n");
  XuatDS(l);
  do {
    Menu(chon);
    switch (chon) {
    case 5:
      printf("\n\nNhap maSV can tim: ");
      scanf("%d", &maX);
      t = TimSV_Ma_X(l, maX);
      if (t == NULL) printf("Khong tim thay sinh vien co maSV: %d\n", maX);
      else {
        printf("\n\nNhap thong tin sinh vien Y: \n");
        Nhap1SV(y);
        pNew = CreateNode(y);
        InsertAfterP(l, t, pNew);
        printf("\nDanh sach lien ket sau khi CHEN SAU: \n");
        XuatDS(l);
      }
      break;
    case 6:
      printf("\n\nNhap maSV can tim: ");
      scanf("%d", &maX);
      t = TimSV_Ma_X(l, maX);
      if (t == NULL) printf("Khong tim thay sinh vien co maSV: %d\n", maX);
      else {
        printf("\n\n Nhap thong tin sinh vien Y: \n");
        Nhap1SV(y);
        pNew = CreateNode(y);
        InsertBeforeP(l, t, pNew);
        printf("\nDanh sach lien ket sau khi CHEN TRUOC: \n");
        XuatDS(l);
      }
      break;
    case 1:
      printf("\n\nNhap maSV can tim: ");
      scanf("%d", &maX);
      t = TimSV_Ma_X(l, maX);
      if (t != NULL) {
        printf("Sinh vien duoc tim thay la: \n");
        printf("\n |========|=======================================|=========|");
        Xuat1SV(t->data);
        printf("\n |========|=======================================|=========|");
      }
      else printf("Khong tim thay sinh vien co maSV: %d\n", maX);
      break;
    case 2:
      SelectionSort_Tang_Ma(l);
      printf("\n\nDanh sach sinh vien Tang theo maSV la:\n");
      XuatDS(l);
      break;
    case 3:
      SelectionSort_Giam_Ma(l);
      printf("\n\nDanh sach sinh vien Giam theo maSV la:\n");
      XuatDS(l);
      break;
    case 7:
      DeleteHead(l);
      printf("\n\nXoa truoc:\n");
      XuatDS(l);
      break;
    case 4:
      SelectionSort_Tang_TenSV(l);
      printf("\n\nDanh sach sinh vien Tang theo tenSV la:\n");
      XuatDS(l);
      break;
    case 8:
      DeleteTail(l);
      printf("\n\nXoa sau:\n");
      XuatDS(l);
      break;
    case 9:
      InterchangeSort_Tang_DTB(l);
      printf("\n\nSap xep tang DTB:\n");
      XuatDS(l);
      break;
    case 10:
      SelectionSort_Giam_TenSV(l);
      printf("\n\nDanh sach sinh vien Tang theo tenSV la:\n");
      XuatDS(l);
      break;
    case 11:
      InterchangeSort_Giam_DTB(l);
      printf("\n\nSap xep giam DTB:\n");
      XuatDS(l);
      break;
    case 12:
      InterchangeSort_Tang_TenSV(l);
      printf("\n\nSap xep tang ten:\n");
      XuatDS(l);
      break;
    case 13:
      InterchangeSort_Giam_TenSV(l);
      printf("\n\nSap xep giam ten:\n");
      XuatDS(l);
      break;
    case 14:
      Destroylist(l);
      printf("\n\nXoa List:\n");
      XuatDS(l);
      break;
    case 15:
      XuatDS(l);
      printf("\n>>> Gia tri can xoa: ");
      scanf("%d", &x);
      kq = XoaX(l, x);
      if (kq == 1) {
        printf("*** Gia tri trong danh sach sau khi xoa %d:\n", x);
        XuatDS(l);
      }
      else
        printf("*** Danh sach khong ton tai %d\n", x);
      break;
    case 16:
      printf("\n\nSinh vien DTB tren 5: \n");
      LietKeSV_DTB_LonHon5(l);
      break;
    case 17:
      printf("\n\nSinh vien DTB duoi 5: \n");
      LietKeSV_DTB_NhoHon5(l);
      break;
    default: chon = 0;
    }
  } while (chon != 0);
  return 0;
}

