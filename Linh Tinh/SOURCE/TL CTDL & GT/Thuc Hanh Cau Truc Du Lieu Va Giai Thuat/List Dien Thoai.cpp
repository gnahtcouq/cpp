#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
//Quach Quang Minh
struct DT {
  int maDT;
  char tenDT[40];
  float gia;
};
struct Node {
  DT data;
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
void Nhap1DT(DT& x) {
  printf("Nhap maDT: ");
  scanf("%d", &x.maDT);
  printf("Nhap tenDT: ");
  fflush(stdin); gets(x.tenDT);
  printf("Nhap Gia: ");
  scanf(" %f", &x.gia);
}
void NhapN(int& n) {
  do {
    printf("Nhap so luong dien thoai: ");
    scanf("%d", &n);
    if (n < 1) printf("Ban nhap sai roi,xin nhap lai\n");
  } while (n < 1);
}
Node* CreateNode(DT x) {
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
  DT x;
  NhapN(n);
  for (int i = 0;i < n;i++) {
    printf("\nNhap thong tin dien thoai thu %d: \n", i + 1);
    Nhap1DT(x);
    Node* p = CreateNode(x);
    AddTail(l, p);
  }
}
void TieuDe() {
  printf("\n |========|=======================================|=========|");
  printf("\n |%-8s|%-39s|%9s|", "MA DT", "TEN DT", "GIA");
  printf("\n |========|=======================================|=========|");
}
void Xuat1DT(DT x) {
  printf("\n |%-8d|%-39s|%9.6f|", x.maDT, x.tenDT, x.gia);
}
void XuatDS(List l) {
  TieuDe();
  for (Node* p = l.pHead;p != NULL;p = p->pNext) {
    Xuat1DT(p->data);
  }
  printf("\n |========|=======================================|=========|");
}
void LietKeDT_Gia_LonHon5trieu(List l) {
  TieuDe();
  for (Node* p = l.pHead;p != NULL;p = p->pNext)
    if (p->data.gia > 5)
      Xuat1DT(p->data);
  printf("\n |========|=======================================|=========|");
}
void LietKeDT_Gia_NhoHon5trieu(List l) {
  TieuDe();
  for (Node* p = l.pHead;p != NULL;p = p->pNext)
    if (p->data.gia < 5)
      Xuat1DT(p->data);
  printf("\n |========|=======================================|=========|");
}
Node* TimDT_Ma_X(List l, int maX) {
  Node* p = l.pHead;
  while (p != NULL) {
    if (p->data.maDT == maX) return p;
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
  DT x;
  Node* p;
  int n;
  fscanf(f, "%d\n", &n);
  for (int i = 0;i < n;i++) {
    fscanf(f, "%d", &x.maDT);
    fscanf(f, "%f", &x.gia);
    fgets(x.tenDT, 40, f);
    x.tenDT[strlen(x.tenDT) - 1] = '\0';
    p = CreateNode(x);
    ////	AddHead(l,p);
    AddTail(l, p);
  }
  fclose(f);
}
void Swap(DT& x, DT& y) {
  DT t = x;
  x = y;
  y = t;
}
void SelectionSort_Tang_TenDT(List& l) {

  for (Node* i = l.pHead;i->pNext != NULL;i = i->pNext) {
    Node* vtmax = i;
    for (Node* j = i->pNext;j != NULL;j = j->pNext)
      if (stricmp(vtmax->data.tenDT, j->data.tenDT) > 0)
        vtmax = j;
    Swap(i->data, vtmax->data);
  }
}
void SelectionSort_Giam_TenDT(List& l) {

  for (Node* i = l.pHead;i->pNext != NULL;i = i->pNext) {
    Node* vtmax = i;
    for (Node* j = i->pNext;j != NULL;j = j->pNext)
      if (stricmp(vtmax->data.tenDT, j->data.tenDT) < 0)
        vtmax = j;
    Swap(i->data, vtmax->data);
  }
}
void SelectionSort_Tang_Ma(List& l) {
  for (Node* i = l.pHead;i->pNext != NULL;i = i->pNext) {
    Node* vtmax = i;
    for (Node* j = i->pNext;j != NULL;j = j->pNext)
      if (vtmax->data.maDT > j->data.maDT)
        vtmax = j;
    Swap(i->data, vtmax->data);
  }
}
void SelectionSort_Giam_Ma(List& l) {
  for (Node* i = l.pHead;i->pNext != NULL;i = i->pNext) {
    Node* vtmax = i;
    for (Node* j = i->pNext;j != NULL;j = j->pNext)
      if (vtmax->data.maDT < j->data.maDT)
        vtmax = j;
    Swap(i->data, vtmax->data);
  }
}
void InterchangeSort_Tang_Gia(List& l) {
  Node* i, * j;
  for (i = l.pHead;i != l.pTail;i = i->pNext) {
    for (Node* j = i->pNext;j != NULL;j = j->pNext)
      if (i->data.gia > j->data.gia)
        Swap(i->data, j->data);
  }
}
void InterchangeSort_Giam_Gia(List& l) {
  Node* i, * j;
  for (i = l.pHead;i != l.pTail;i = i->pNext) {
    for (Node* j = i->pNext;j != NULL;j = j->pNext)
      if (i->data.gia < j->data.gia)
        Swap(i->data, j->data);
  }
}

void InterchangeSort_Tang_TenDT(List& l) {
  Node* i, * j;
  for (i = l.pHead;i != l.pTail;i = i->pNext) {
    for (Node* j = i->pNext;j != NULL;j = j->pNext)
      if (stricmp(i->data.tenDT, j->data.tenDT) > 0)
        Swap(i->data, j->data);
  }
}
void InterchangeSort_Giam_TenDT(List& l) {
  Node* i, * j;
  for (i = l.pHead;i != l.pTail;i = i->pNext) {
    for (Node* j = i->pNext;j != NULL;j = j->pNext)
      if (stricmp(i->data.tenDT, j->data.tenDT) < 0)
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

  Node* pX = TimDT_Ma_X(l, maX);
  if (pX == NULL)
    return 0;
  DeleteNode(l, pX);
  return 1;
}
void Menu(int& chon) {
  printf("\n\n |========|======================MENU=======================|");
  printf("\n |  Phim  |\t\t\tCong viec        	    |");
  printf("\n |========|=================================================|");
  printf("\n |  \\1\\   |    \tLinearSearch Ma DT!                         |");
  printf("\n |========|=================================================|");
  printf("\n |  \\2\\   |    \tSelectionsort_tang theo Ma DT!              |");
  printf("\n |========|=================================================|");
  printf("\n |  \\3\\   |    \tSelectionsort_giam theo Ma DT!              |");
  printf("\n |========|=================================================|");
  printf("\n |  \\4\\   |    \tSelectionsort_tang theo Ten DT!             |");
  printf("\n |========|=================================================|");
  printf("\n |  \\5\\   |    \tInsertAfterP!                               |");
  printf("\n |========|=================================================|");
  printf("\n |  \\6\\   |    \tInsertBeforeP!                              |");
  printf("\n |========|=================================================|");
  printf("\n |  \\7\\   |    \tDelete Head!                                |");
  printf("\n |========|=================================================|");
  printf("\n |  \\8\\   |    \tDelete Tail!                                |");
  printf("\n |========|=================================================|");
  printf("\n |  \\9\\   |    \tInterchangeSort_tang_GIA!                   |");
  printf("\n |========|=================================================|");
  printf("\n |  \\10\\  |    \tSelectionsort_giam theo Ten DT!             |");
  printf("\n |========|=================================================|");
  printf("\n |  \\11\\  |    \tInterchangeSort_giam_GIA!                   |");
  printf("\n |========|=================================================|");
  printf("\n |  \\12\\  |    \tInterchangeSort_tang_TenDT!                 |");
  printf("\n |========|=================================================|");
  printf("\n |  \\13\\  |    \tInterchangeSort_giam_TenDT!                 |");
  printf("\n |========|=================================================|");
  printf("\n |  \\14\\  |    \tDelete List!                                |");
  printf("\n |========|=================================================|");
  printf("\n |  \\15\\  |    \tDelete X!                                   |");
  printf("\n |========|=================================================|");
  printf("\n |  \\16\\  |    \tDien thoai gia tren 5 trieu!                |");
  printf("\n |========|=================================================|");
  printf("\n |  \\17\\  |    \tDien thoai gia duoi 5 trieu!                |");
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
  DT y;
  InitList(l);
  ReadFile("D:/Thuc Hanh Cau Truc Du Lieu Va Giai Thuat/Dienthoai.txt", l);
  printf("\n\nDanh sach dien thoai vua nhap la:\n");
  XuatDS(l);
  do {
    Menu(chon);
    switch (chon) {
    case 5:
      printf("\n\nNhap maDT can tim: ");
      scanf("%d", &maX);
      t = TimDT_Ma_X(l, maX);
      if (t == NULL) printf("Khong tim thay dien thoai co maDT: %d\n", maX);
      else {
        printf("\n\nNhap thong tin dien thoai Y: \n");
        Nhap1DT(y);
        pNew = CreateNode(y);
        InsertAfterP(l, t, pNew);
        printf("\nDanh sach lien ket sau khi CHEN SAU: \n");
        XuatDS(l);
      }
      break;
    case 6:
      printf("\n\nNhap maDT can tim: ");
      scanf("%d", &maX);
      t = TimDT_Ma_X(l, maX);
      if (t == NULL) printf("Khong tim thay dien thoai co maDT: %d\n", maX);
      else {
        printf("\n\n Nhap thong tin dien thoai Y: \n");
        Nhap1DT(y);
        pNew = CreateNode(y);
        InsertBeforeP(l, t, pNew);
        printf("\nDanh sach lien ket sau khi CHEN TRUOC: \n");
        XuatDS(l);
      }
      break;
    case 1:
      printf("\n\nNhap maDT can tim: ");
      scanf("%d", &maX);
      t = TimDT_Ma_X(l, maX);
      if (t != NULL) {
        printf("Dien thoai duoc tim thay la: \n");
        printf("\n |========|=======================================|=========|");
        Xuat1DT(t->data);
        printf("\n |========|=======================================|=========|");
      }
      else printf("Khong tim thay dien thoai co maDT: %d\n", maX);
      break;
    case 2:
      SelectionSort_Tang_Ma(l);
      printf("\n\nDanh sach dien thoai Tang theo maDT la:\n");
      XuatDS(l);
      break;
    case 3:
      SelectionSort_Giam_Ma(l);
      printf("\n\nDanh sach dien thoai Giam theo maDT la:\n");
      XuatDS(l);
      break;
    case 7:
      DeleteHead(l);
      printf("\n\nXoa truoc:\n");
      XuatDS(l);
      break;
    case 4:
      SelectionSort_Tang_TenDT(l);
      printf("\n\nDanh sach dien thoai Tang theo tenDT la:\n");
      XuatDS(l);
      break;
    case 8:
      DeleteTail(l);
      printf("\n\nXoa sau:\n");
      XuatDS(l);
      break;
    case 9:
      InterchangeSort_Tang_Gia(l);
      printf("\n\nSap xep tang Gia:\n");
      XuatDS(l);
      break;
    case 10:
      SelectionSort_Giam_TenDT(l);
      printf("\n\nDanh sach dien thoai Tang theo tenDT la:\n");
      XuatDS(l);
      break;
    case 11:
      InterchangeSort_Giam_Gia(l);
      printf("\n\nSap xep giam Gia:\n");
      XuatDS(l);
      break;
    case 12:
      InterchangeSort_Tang_TenDT(l);
      printf("\n\nSap xep tang ten:\n");
      XuatDS(l);
      break;
    case 13:
      InterchangeSort_Giam_TenDT(l);
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
      printf("\n\nDien thoai Tren 5 trieu: \n");
      LietKeDT_Gia_LonHon5trieu(l);
      break;
    case 17:
      printf("\n\nDien thoai Duoi 5 trieu: \n");
      LietKeDT_Gia_NhoHon5trieu(l);
      break;
    default: chon = 0;
    }
  } while (chon != 0);
  return 0;
}

