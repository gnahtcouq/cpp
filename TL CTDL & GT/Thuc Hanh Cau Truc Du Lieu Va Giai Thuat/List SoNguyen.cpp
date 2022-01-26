#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<conio.h> 
typedef struct node {
  int info;
  struct node* next;

}Node;
Node* phead;//pHead quan ly danh sach
//====================================de thuc hien cau a,b
void init(Node*& pHead) {
  pHead = NULL;
}
//===============
int isEmpty(Node* pHead) {
  return(pHead == NULL);
}
//===============
Node* createNode(int x) {
  Node* p = new Node;
  p->info = x;
  p->next = NULL;
  return p;
}
//===============
void insertFirst(Node*& pHead, int x) {
  Node* p = createNode(x);
  Node* tam = pHead;
  p->next = tam;
  pHead = p;
}
//===============
void inserLast(Node*& pHead, int x) {
  Node* p = createNode(x);
  Node* tam = pHead;
  while (tam->next != NULL) {
    tam = tam->next;
  }
  tam->next = p;
}
////===============
void showlist(Node* pHead) {
  Node* p = pHead;
  if (p == NULL)
    printf("\nDanh sach bi rong");
  while (p != NULL) {
    printf("%d\t", p->info);
    p = p->next;
  }
}
int demsonut(Node* pHead) {
  int dem = 0;
  for (Node* p = pHead;p != NULL;p = p->next) {
    dem++;
  }
  return dem;
}
Node* searchX(Node* pHead, int x) {
  while (pHead != NULL) {
    if (pHead->info == x) {
      return pHead;
    }
    pHead = pHead->next;
  }
  return NULL;
}
void chenysaux(Node*& pHead, int y, int x) {
  Node* p = pHead;
  Node* newnode;
  newnode = createNode(y);
  if (p == NULL) {
    printf("chua co gi het");
    p = newnode;
  }
  else {
    Node* find = searchX(pHead, x);
    if (find == NULL) {
      printf("khong tim thay %d\n", x);
    }
    else {
      newnode->next = find->next;
      find->next = newnode;
    }
  }
}
int GiaTriThuK(Node* pHead, int x) {
  for (int i = 1; i < x; i++) {
    pHead = pHead->next;
  }
  return pHead->info;
}
void  XoaX(Node*& pHead, int x) {
  Node* xoa = new Node;
  xoa->next = pHead;
  pHead = xoa;
  Node* q;
  for (Node* p = pHead; p->next != NULL; p = p->next)
    if (p->next->info == x) {
      q = p->next;
      p->next = q->next;
      delete q;
    }
  pHead = pHead->next;
  delete xoa;
}
void HoanVi(int& a, int& b)


{
  int t = a;
  a = b;
  b = t;
}
void SapXep(Node* pHead, Node* pTail) {
  Node* i, * j;
  for (i = pHead; i != NULL && i != pTail; i = i->next) {

    for (j = i->next; j != NULL; j = j->next) {
      if (i->info > j->info) {
        HoanVi(j->info, i->info);
      }
    }
  }
}
////========================================
int main() {
  Node* pHead;//bien tro den nut dau tien trong danh sach
  Node* pTail;
  init(pHead);//khoi tao danh sach lien ket ban  dau chua co nut nao
  int chon, x, y;
  do {
    //		system(cls);
        //nhap chon lua nguoi dung
    printf("\n1: Them 1 phan tu vao dau");
    printf("\n2: Them 1 phan tu vao cuoi");
    printf("\n3: Xuat danh sach");
    printf("\n4: tim x va chen y sau x");
    printf("\n5: Dem so nut");
    printf("\n6: Gia tri k");
    printf("\n7: Xoa x");
    printf("\n8: Sap xep Insertion Sort x");
    printf("\n0: Thoat\n");
    printf("Hay chon cong viec: "); scanf("%d", &chon);
    printf("\n");
    //thuc hien cong viec cho lua chon tuong ung	
    switch (chon) {
    case 1://them dau
      printf("nhap gia tri phan tu can them vao dau:\n");
      scanf("%d", &x);
      insertFirst(pHead, x);
      break;
    case 2://them cuoi
      printf("nhap gia tri phan tu can them vao cuoi:\n");
      scanf("%d", &x);
      inserLast(pHead, x);
      break;
      break;
    case 3://xuat danh sach
      printf("\n");
      showlist(pHead);
      printf("\n");
      break;
    case 4:
      printf("nhap x:");
      scanf("%d", &x);
      printf("nhap y:");
      scanf("%d", &y);
      chenysaux(pHead, y, x);
      printf("Danh sach sau khi chen y sau x: ");
      printf("\n");
      showlist(pHead);
      break;
    case 5:
      printf("So nut dem duoc: %d\n", demsonut(pHead));
      break;
    case 6:
      printf("\nNhap vi tri thu x cua danh sach: ");
      scanf("%d", &x);
      showlist(pHead);
      printf("\nGia tri cua node x trong danh sach la: %d\n", GiaTriThuK(pHead, x));
      break;
    case 7:
      printf("\nNhap gia tri phan tu muon xoa: ");
      scanf("%d", &x);
      XoaX(pHead, x);
      break;
    case 8:
      SapXep(pHead, pTail);
      printf("\nDanh sach sau khi sap xep: ");
      showlist(pHead);
      break;
    default: chon = 0;
    }
  } while (chon != 0);
  return 0;
}
