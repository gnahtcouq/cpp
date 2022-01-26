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
struct QUEUE {
  Node* pHead, * pTail;
};
//==========================================   	
void Nhap1BN(BenhNhan& X) {
  printf("nhap ho va ten benh nhan: ");
  fflush(stdin);  gets(X.hoten);

  printf("nhap tuoi benh nhan: ");
  scanf("%d", &X.tuoi);
}
//==========================================
void TieuDe() {
  printf("\n |========|=======================================|=========|");
  printf("\n |%8s|%-39s|%9s|", "STT", "HO VA TEN", "TUOI");
  printf("\n |========|=======================================|=========|");
}
//==========================================   
void Xuat1BN(BenhNhan X) {
  printf("\n |%8d|%-39s|%9d|", X.stt, X.hoten, X.tuoi);
}
//====================================================
void Init(QUEUE& Q) {
  Q.pHead = Q.pTail = NULL;
}
//====================================================
int IsEmpty(QUEUE Q) {
  return (Q.pHead == NULL);
}
//====================================================
Node* CreateNode(BenhNhan X) {
  Node* p = new Node;
  if (p == NULL) {
    printf("Loi cap phat vung nho!");
    getch();
    exit(0);
  }
  p->data = X;
  p->pNext = NULL;
  return p;
}
//====================================================
void AddTail(QUEUE& Q, Node* pNew) {
  if (IsEmpty(Q)) {
    Q.pHead = Q.pTail = pNew;
  }
  else {
    Q.pTail->pNext = pNew;
    Q.pTail = pNew;
  }
}
//====================================================
void Output(QUEUE Q) {
  if (IsEmpty(Q)) printf("\n Danh sach RONG \n");
  else {
    TieuDe();
    for (Node* i = Q.pHead; i != NULL; i = i->pNext)
      Xuat1BN(i->data);
    printf("\n |========|=======================================|=========|");
  }
}
//====================================================
int Insert(QUEUE& Q, BenhNhan X) {
  Node* pNew = CreateNode(X);
  AddTail(Q, pNew);
  return 1;
}

//====================================================
int Remove(QUEUE& Q, BenhNhan& X) {
  if (IsEmpty(Q)) return 0;
  Node* p = Q.pHead;
  X = p->data;
  Q.pHead = Q.pHead->pNext;
  if (Q.pHead == NULL) Q.pTail = NULL;
  delete p;
  return 1;
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
  QUEUE Q;
  int chon;
  int soTT = 1;
  int sdk = 0;
  BenhNhan X;

  Init(Q);

  do {
    Menu(chon);

    switch (chon) {
    case 1:
      Nhap1BN(X); X.stt = soTT++;
      Insert(Q, X);
      break;
    case 2:
      Remove(Q, X);sdk++;
      TieuDe();
      Xuat1BN(X);
      printf("\n |========|=======================================|=========|");
      break;
    case 3:
      printf("\n So benh nhan chua kham = %d", soTT - sdk - 1);
      break;
    case 4:
      printf("\n So benh nhan chua kham = %d", sdk);
      break;
    case 5:
      Output(Q);
      break;

    default: chon = 0;
    }
  } while (chon);

  return 0;
}
