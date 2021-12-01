
#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node *link;//Con trỏ trỏ đến phần tử kế tiếp
};

void khoiTao(Node& list) {
	list = NULL;
}
int isEmpty(Nodeptr list) {
	return (list == NULL ? 1 : 0);
}
Nodeptr tao_Node(TYPEINFO x) {
	Nodeptr p;
	p = new Node;
	p->data = x;
	p->link = NULL;
	return p;
}

void them_Dau(Node *&list, int x) {
  Node p;
  p = tao_Node(x);
  p->link = list;
  return p;
}
void nhap_DanhSach(Nodeptr& list)
{
	khoiTao(list);
	int x;
	do {
		cout << "\n Nhap vao x = (thoat -99) ";
		cin >> x;
		if (x == -99)
			break;
		them_Dau(list, x);
	} while (1);
}
void xuat_DanhSach(Nodeptr list) {
	Nodeptr p = list;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->link;
	}
}
void giaiPhong(Nodeptr& list) {
	Nodeptr p = list;
	while (p != NULL) {
		list = list->link;
		delete p;
		p = list;
	}
}