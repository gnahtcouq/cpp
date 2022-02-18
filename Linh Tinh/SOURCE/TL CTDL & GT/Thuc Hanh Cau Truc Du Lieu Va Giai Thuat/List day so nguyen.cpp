#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
//------------------------------
typedef struct node {
  int data;
  struct node* pNext;
}NODE;

//------------------------------

void init(NODE*& phead) {
  phead = NULL;
}
//------------------------------

int IsEmpty(NODE* phead) {
  return(phead == NULL);
}
//------------------------------

NODE* createNode(int x) {
  NODE* p = new NODE;
  p->data = x;
  p->pNext = NULL;
  return p;
}
//------------------------------

NODE* createnode(int y) {
  NODE* p = new NODE;
  p->data = y;
  p->pNext = NULL;
  return p;
}
//------------------------------

void InsertFirst(NODE*& phead, int x) {
  NODE* p = createNode(x);
  NODE* ptam = phead;
  p->pNext = ptam;
  phead = p;
}

//------------------------------

void InsertLast(NODE*& phead, int x) {
  NODE* p = createNode(x);
  NODE* ptam = phead;
  while (ptam->pNext != NULL) {
    ptam = ptam->pNext;

  }
  ptam->pNext = p;
}

//------------------------------

void Output(NODE* phead) {
  NODE* p = phead;
  if (p == NULL) {
    printf("Danh sach rong ");
  }
  while (p != NULL) {
    printf("%d -> ", p->data);
    p = p->pNext;
  }

}

//------------------------------
NODE* Search(NODE* phead, int x) {
  NODE* p = phead;
  while (p->data != x && p != NULL)
    p = p->pNext;
  return p;
}

//------------------------------
void InsertAfter(NODE* p, int y) {
  NODE* tam;
  if (p != NULL) {
    tam = createnode(y);
    tam->pNext = p->pNext;
    p->pNext = tam;
  }
}

//------------------------------

int DemNode(NODE* phead, NODE* i) {
  int d = 0;
  for (i = phead; i != NULL; i = i->pNext)
    d++;
  return d;
}

//------------------------------
int Position(NODE* phead, int k) {
  for (int i = 0; i <= k; i++) {
    phead = phead->pNext;
  }
  return phead->data;
}
//------------------------------
int TimMAX(NODE* phead) {
  NODE* p = phead;
  int Max;
  Max = phead->data;
  for (p = phead->pNext; p != NULL; p = p->pNext) {
    if (p->data > Max)
      Max = p->data;
  }
  return Max;
}

//------------------------------
int TimMIN(NODE* phead) {
  NODE* p = phead;
  int Min;
  Min = phead->data;
  for (p = phead->pNext; p != NULL; p = p->pNext) {
    if (p->data < Min)
      Min = p->data;
  }
  return Min;
}
//------------------------------

void XoaX(NODE*& phead, int x) {

  NODE* tam = phead;
  printf("\nNhap vao gia tri x can xoa:");
  scanf("%d", &x);
  while (tam->pNext->data != x && tam != NULL)
    tam = tam->pNext;
  if (tam == NULL)
    printf("\nKhong co data x can xoa");
  else {
    NODE* tam2 = tam->pNext;
    tam->pNext = tam2->pNext;
    tam2->pNext = NULL;
    free(tam2);
  }
}
//------------------------------

void HoanVi(int& a, int& b) {
  int tam = a;
  a = b;
  b = tam;
}

//------------------------------

void InterchangeSort(NODE* phead, NODE* ptail)

{

  NODE* i, * j;

  for (i = phead; i != NULL && i != ptail; i = i->pNext)
    for (j = i->pNext; j != NULL; j = j->pNext)
      if (j->data < i->data)
        HoanVi(j->data, i->data);
}

//------------------------------
int main() {
  int chon, x, y, Max, Min, k;
  NODE* pNew;
  NODE* phead, * ptail, * i, * j, * p, * pDel;
  init(phead);
  //	Input(phead);
  //	Output(phead);

  do {
    system("cls");

    printf("\n1: Them 1 phan tu vao dau\n");
    printf("2: Them 1 phan tu vao cuoi\n");
    printf("3: Tim kiem\n");
    printf("4: Dem so nut\n");
    printf("5: Gia tri cua node (xac dinh)\n");
    printf("6: Tim max\n");
    printf("7: Tim min\n");
    printf("8: Xoa node\n");
    printf("9: InterchangeSort\n");
    printf("10: Xuat danh sach\n");
    printf("0: Thoat\n");

    printf("Hay chon cong viec: ");
    scanf("%d", &chon);

    switch (chon) {
    case 1:
      printf("Nhap gia tri phan tu can them: ");
      scanf("%d", &x);
      InsertFirst(phead, x);
      break;

    case 2:
      printf("Nhap gia tri phan tu can them: ");
      scanf("%d", &x);
      InsertLast(phead, x);

      break;

    case 3:
      printf("Nhap gia tri x can tim : ");
      scanf("%d", &x);
      Search(phead, x);
      printf("Nhap gia tri y can them: ");
      scanf("%d", &y);
      InsertAfter(phead, y);
      break;

    case 4:
      DemNode(phead, i);
      printf("So nut tren danh sach: %d", DemNode(phead, i));

      break;

    case 5:
      printf("Nhap k: ");
      scanf("%d", &k);
      Position(phead, k);
      printf("Gia tri tren danh sach: %d", Position(phead, k));

      break;

    case 6:
      Search(phead, x);
      TimMAX(phead);
      printf("Phan tu lon nhat trong danh sach: %d", TimMAX(phead));

      break;

    case 7:
      Search(phead, x);
      TimMIN(phead);
      printf("Phan tu nho nhat trong danh sach: %d", TimMIN(phead));

      break;

    case 8:
      Search(phead, x);
      XoaX(phead, x);
      break;

    case 9:
      InterchangeSort(phead, ptail);

      break;

    case 10:
      Output(phead);
      break;

    default: chon = 0;
    }
    getch();

  } while (chon != 0);

  return 0;
}

