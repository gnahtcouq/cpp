
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct ttNode {
  int data;
  struct ttNode* pNext;
} Node;

typedef struct ttList {
  Node* pHead, * pTail;
} List;

void Init(List& l) {
  l.pHead = l.pTail = NULL;
}

int IsEmpty(List l) {
  if (l.pHead == NULL)
    return 1;
  return 0;
}

Node* CreateNode(int x) {
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

//ham them phan tu vao dau danh sach
void AddHead(List& l, Node* p) {
  if (IsEmpty(l)) {
    l.pHead = l.pTail = p;
  }
  else {
    p->pNext = l.pHead;
    l.pHead = p;
  }
}

void AddTail(List& l, Node* p) {
  if (IsEmpty(l)) {
    l.pHead = l.pTail = p;
  }
  else {
    l.pTail->pNext = p;
    l.pTail = p;
  }
}

void Input(List& l) {
  int x;
  Init(l);
  do {
    printf("Nhap so nguyen (nhap 0 de dung): ");
    scanf("%d", &x);
    if (x == 0)
      break;
    Node* p = CreateNode(x);
    //AddHead(l,p);
    AddTail(l, p);
  } while (1);
}

//ham doc thong tin tu file 
void ReadFile(const char* filename, List& l) {
  FILE* f = fopen(filename, "rw");
  if (f == NULL) {
    printf("\nkhong doc duoc file!!!");
    return;
  }
  int n, x;
  fscanf(f, "%d\n", &n);
  for (int i = 0; i < n; i++) {
    fscanf(f, "%d", &x);
    Node* p = CreateNode(x);
    AddTail(l, p);
  }
  fclose(f);
}

void Output(List l) {
  Node* p = l.pHead;
  while (p) {
    printf(" (%d) -> ", p->data);
    p = p->pNext;
  }
  printf("[NULL]");
}

//ham tim kiem x bang linearsearch
Node* LinearSearch(List l, int x) {
  for (Node* p = l.pHead; p; p = p->pNext) {
    if (p->data == x)
      return p;
  }
  return NULL;
}

void InsertAfterP(List& l, Node* p, Node* pNew) {
  if (p == l.pTail)
    AddTail(l, pNew);
  else {
    Node* pSau = p->pNext;
    pNew->pNext = pSau;
    p->pNext = pNew;
  }
}
void Swap(int& a, int& b)


{
  int t = a;
  a = b;
  b = t;
}
void InsertBeforeP(List& l, Node* p, Node* pNew) {
  InsertAfterP(l, p, pNew);
  Swap(p->data, pNew->data);
}


//void Deletehead(List &l)
//{
//	node* Del= l.pHead;
//	l.pHead = pDel -> pNext;
//	if (l.pHead == NULL)
//}
void XuatMenu(int& chon) {
  printf("\n===================== MENU =====================");
  printf("\n1: LinearSearch");
  printf("\n2: interchangesort tang");
  printf("\n3: interchangesort giam");
  printf("\n4: selectionsort tang");
  printf("\n5: selectionsort giam");
  printf("\n6: insertafterP");
  printf("\n7: insertbeforeP");

  //	printf("\n2: InsertAfterP");
  printf("\n\nMoi chon cong viec: ");
  scanf("%d", &chon);
}

int main() {
  List l;
  Init(l);
  int chon;
  int x, y;
  Node* p;
  Node* pNew;
  //Input(l);
  do {
    ReadFile("D:/List Int.txt", l);
    printf("\nGia tri danh sach:\n");
    Output(l);
    XuatMenu(chon);
    switch (chon) {
    case 1:
    case 6:
      printf("\nNhap x can tim trong mang: ");
      scanf("%d", &x);
      p = LinearSearch(l, x);
      if (LinearSearch(l, x) == NULL)
        printf("\nKhong the tim thay %d trong mang !!!", x);
      else {
        printf("\ntim thay %d trong mang !!!", x);
      }
      printf("\nNhap y can chen vao mang: ");
      scanf("%d", &y);
      pNew = CreateNode(y);
      InsertAfterP(l, p, pNew);
      printf("\ndanh sach sau khi chen sau x:\n");
      Output(l);
      break;

    case 7:
      printf("\nNhap x can tim trong mang: ");
      scanf("%d", &x);
      p = LinearSearch(l, x);
      if (LinearSearch(l, x) == NULL)
        printf("\nKhong the tim thay %d trong mang !!!", x);
      else {
        printf("\ntim thay %d trong mang !!!", x);
      }
      printf("\nNhap y can chen vao mang: ");
      scanf("%d", &y);
      pNew = CreateNode(y);
      InsertBeforeP(l, p, pNew);
      printf("\ndanh sach sau khi chen truoc x:\n");
      Output(l);
      break;
    default:
      chon = 0;

    }
  } while (chon != 0);
  return 0;
}
