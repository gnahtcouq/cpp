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
void CreateBinaryTree(Tree& t, int a[], int begin, int end) {
  if (begin > end) return;
  int i = (begin + end) / 2;
  t = CreateNode(a[i]);

  CreateBinaryTree(t->pLeft, a, begin, i - 1);
  CreateBinaryTree(t->pRight, a, i + 1, end);
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
int main() {
  int a[] = { 5,8,1,6,2,9,7,4 };
  int begin = 0, end = 7;

  Tree t;
  Init(t);

  CreateBinaryTree(t, a, begin, end);
  printf("\n\n\t Duyet NLR: "); NLR(t);
  printf("\n\n\t Duyet LNR: "); LNR(t);
  printf("\n\n\t Duyet LRN: "); LRN(t);
  printf("\n\n\n\n\n\n\n\n\n\n");
  return 0;
}
