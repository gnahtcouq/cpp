#include <stdio.h>
#include <conio.h>
//Quach Quang Minh
typedef struct TNode {
  int data;
  TNode* pLeft;
  TNode* pRight;
}*Tree;

//====================================================
void Init(Tree& t) //Ham khoi tao BST
{
  t = NULL;
}
//====================================================
int IsEmpty(Tree& t) {
  return (t == NULL);
}
//====================================================
Tree CreateNode(int x) //Ham tao nut moi
{
  TNode* p = new TNode;
  if (p != NULL) {
    p->data = x;
    p->pLeft = p->pRight = NULL;
  }
  return p;
}
//====================================================
void Insert(Tree& t, int x) {
  if (IsEmpty(t))t = CreateNode(x);
  else {
    if (x < t->data) Insert(t->pLeft, x);
    if (x > t->data) Insert(t->pRight, x);
  }
}
void CreateBinaryTree(Tree& t, int a[], int n) {
  for (int i = 0;i < n;i++)
    Insert(t, a[i]);

}
//====================================================
void NLR(Tree t) {
  if (t != NULL) {
    printf("%6d", t->data);
    NLR(t->pLeft);
    NLR(t->pRight);
  }
}
//====================================================
void LNR(Tree t) {
  if (t != NULL) {
    LNR(t->pLeft);
    printf("%6d", t->data);
    LNR(t->pRight);
  }
}
//====================================================
void LRN(Tree t) {
  if (t != NULL) {
    LRN(t->pLeft);
    LRN(t->pRight);
    printf("%6d", t->data);
  }
}
//====================================================
int DemNodeLa(Tree t) {
  if (t == NULL) return 0;
  if ((t->pLeft == NULL) && (t->pRight == NULL)) return 1;
  return DemNodeLa(t->pLeft) + DemNodeLa(t->pRight);
}
int main() {
  int a[] = { 99,5,8,1,5,6,2,9,7,4 };
  int n = 10;
  Tree t;
  Init(t);
  CreateBinaryTree(t, a, n);
  printf("\n\n\t Duyet NLR: "); NLR(t);
  printf("\n\n\t Duyet LNR: "); LNR(t);
  printf("\n\n\t Duyet LRN: "); LRN(t);
  printf("\n\n So Node La = %d", DemNodeLa(t));
  printf("\n\n\n\n\n\n\n\n\n\n");
  return 0;
}
