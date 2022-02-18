#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//==========================================
struct BenhNhan {
  int stt;
  char hoten[41];
  int tuoi;
};
//====================================================
struct Node {
  BenhNhan data;
  Node* pNext;
};
//====================================================
struct List {
  Node* pHead, * pTail;
};
//==========================================   	
void Nhap1BN(BenhNhan& x) {
  printf("nhap ho va ten benh nhan: ");
  fflush(stdin);  gets(x.hoten);

  printf("nhap tuoi benh nhan: ");
  scanf("%d", &x.tuoi);
}
//==========================================
void TieuDe() {
  printf("\n |========|=======================================|=========|");
  printf("\n |%8s|%-39s|%9s|", "STT", "HO VA TEN", "TUOI");
  printf("\n |========|=======================================|=========|");
}
//==========================================   
void Xuat1BN(BenhNhan x) {
  printf("\n |%8d|%-39s|%9d|", x.stt, x.hoten, x.tuoi);
}
//====================================================
void Init(List& l) {
  l.pHead = l.pTail = NULL;
}
//====================================================
int IsEmpty(List l) {
  return (l.pHead == NULL);
}
//====================================================
Node* CreateNode(BenhNhan x) {
  Node* p = new Node;
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
void AddTail(List& l, Node* pNew) {
  if (IsEmpty(l)) {
    l.pHead = l.pTail = pNew;
  }
  else {
    l.pTail->pNext = pNew;
    l.pTail = pNew;
  }
}
//====================================================
void Output(List l) {
  if (IsEmpty(l)) printf("\n Danh sach RONG \n");
  else {
    TieuDe();
    for (Node* i = l.pHead; i != NULL; i = i->pNext)
      Xuat1BN(i->data);
    printf("\n |========|=======================================|=========|");
  }
}
//====================================================
int Insert(List& l, BenhNhan X) {

}
//====================================================
int Remove(List& l, BenhNhan& X) {

}
//====================================================
void Menu(int& chon) {
  printf("\n\n===============MENU===================");
  printf("\n1_Them benh nhan");
  printf("\n2_Benh nhan tiep theo se duoc kham");
  printf("\n3_So benh nhan chua kham");
  printf("\n4_So benh nhan da duoc kham");
  printf("\n5_Danh sach benh nhan cho doi kham");

  printf("\n\n0_Exit");
  printf("\n======================================");
  printf("\n\nBan chon chuc nang: ");
  scanf("%d", &chon);
}
//====================================================
int main() {
  List l;
  int chon;
  BenhNhan x;

  Init(l);

  do {
    Menu(chon);

    switch (chon) {
    case 1:
      Nhap1BN(x);
      break;
    case 2:

      break;
    case 3:

      break;
    case 4:

      break;
    case 5:
      Output(l);
      break;

    default: chon = 0;
    }
  } while (chon);

  return 0;
}
