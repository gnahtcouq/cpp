#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
//Quach Quang Minh
struct Node {
  int data;
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
Node* CreateNode(int x) {
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
  int x;
  Node* p;
  do {
    printf("Nhap gia tri (Nhap 0 ket thuc): ");
    scanf("%d", &x);
    if (x == 0)
      break;
    p = CreateNode(x);
    AddHead(l, p);
    //		AddTail(l,p);
  } while (1);
}
void Output(List l) {
  for (Node* p = l.pHead; p != NULL;p = p->pNext) {
    printf("(%d)->", p->data);
  }
  printf("[NULL]");
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

