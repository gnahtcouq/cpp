#include <iostream>
using namespace std;
struct Node {
  int data;
  Node* link;
};
void khoiTao(Node*& list) {
	list = NULL;
}
int isEmpty(Node* list) {
	return (list == NULL ? 1 : 0);
}
// Node* tao_Node(int x) {
// 	Node* p;
// 	p = new Node;
// 	p->data = x;
// 	p->link = NULL;
// 	return p;
// }
void them_Dau(Node*& list, int x) {
	Node* q;
	q = new Node;
	q->data = x;
	q->link = NULL;
	Node* p;
	p = q;
	p->link = list;
	list = p;
}

void nhap_DanhSach(Node*& list)
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
void xuat_DanhSach(Node* list) {
	Node* p = list;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->link;
	}
}
void giaiPhong(Node*& list) {
	Node* p = list;
	while (p != NULL) {
		list = list->link;
		delete p;
		p = list;
	}
}

int main() {
	Node* list;
	khoiTao(list);
	nhap_DanhSach(list);
	cout << "\nDSLK vua nhap: ";
	xuat_DanhSach(list);

	giaiPhong(list);
	cout << endl;

	system("pause");
	return 0;
}