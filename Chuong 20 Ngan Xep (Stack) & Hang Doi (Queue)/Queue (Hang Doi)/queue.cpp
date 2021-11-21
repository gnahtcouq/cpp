#include <iostream>
#include <conio.h> // de dung getch();
using namespace std;

/* Khai bao cau truc du lieu Queue */
struct Node {
    int data; // Du lieu no chua
    struct Node *pNext; // Con tro de lien ket voi cac Node khac
};
typedef struct Node NODE;

struct Queue {
    NODE *pHead;
    NODE *pTail;
};
typedef struct Queue QUEUE;

/* Khoi tao Queue */
void khoiTao(QUEUE &q) {
   q.pHead = q.pTail = NULL;
}

/* Tao Node trong Queue */
NODE *taoNode(int x) { // Do du lieu trong Queue dang la so nguyen
    NODE *p = new NODE;

    if(p == NULL) {
        cout << "\nKhong du bo nho de cap phat !";
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}

/* Kiem tra Stack rong hay khong? return false neu Queue rong. nguoc lai tra ve true */
bool kiemTraRong(QUEUE q) {
    if(q.pHead == NULL)
        return false;
    return true;
}

/* Them phan tu vao Queue. return true neu them thanh cong. nguoc lai return false */
bool push(QUEUE &q, NODE *p) { // p la Node can them vao trong Queue
    // Kiem tra xem Node p co bi rong hay khong
    if(p == NULL) {
        return false;
    }
    // Kiem tra xem Queue co rong hay khong?
    // Neu rong -> Node p them vao chinh la pHead va pTail
    if(kiemTraRong(q) == false) {
        q.pHead = q.pTail = p;
    }
    else { // Them vao cuoi
        q.pTail->pNext = p;
        q.pTail = p;
    }
    return true; // Them thanh cong
}

/* Lay phan tu ra khoi Queue. return true neu lay thanh cong. nguoc lai return false */
bool pop(QUEUE &q, int &x) { // x la du lieu can lay ra
    // Neu Queue rong -> lay that bai
    if(kiemTraRong(q) == false)
        return false;
    // Neu Queue hien dang co phan tu ben trong
    NODE *p; // Tao con tro p de nam giu q.pHead
    p = q.pHead; // Cho con tro p tro toi q.pHead
    x = p->data; // Gan du lieu ben trong Node sang x
    q.pHead = q.pHead->pNext; // Cap nhat lai q.pHead la phan tu tiep theo
    delete p; // Xoa con tro p
    return true; // Lay thanh cong
}

/* Xem phan tu dau Queue. Luu y la: chi xem chu khong thay doi */
// return true neu xem thanh cong. nguoc lai return false
bool top(QUEUE q, int &x) {
    // Neu Queue rong -> that bai
    if(kiemTraRong(q) == false)
        return false;
    // Neu Queue hien dang co phan tu ben trong
    x = q.pHead->data;
    return true; // Xem thanh cong
}

/* Ham nhap du lieu cho Queue */
void nhap(QUEUE &q) {
    khoiTao(q); // Khoi tao Queue
    char luaChon;
        do {
        cout << "\n---------- MENU ----------";
        cout << "\n1. Nhap so nguyen";
        cout << "\n2. Ket thuc";
        cout << "\n--------------------------";

        do {
            cout << "\nNhap vao lua chon cua ban: ";
            luaChon = getch();
            if(luaChon != '1' && luaChon != '2') {
                cout << "\nLua chon khong hop le. Xin kiem tra lai";
            }
        } while (luaChon != '1' && luaChon != '2');

        // Lua chon 1
        if(luaChon == '1') {
            int x; // Du lieu can them vao Node
            cout << "\nNhap du lieu can them vao Node: ";
            cin >> x;
            NODE *p = taoNode(x); // Tao Node p chua x ben trong
            push(q, p); // Dua Node p vao trong Stack
        }
    } while (luaChon == '1');
}

/* Ham xuat du lieu cua Stack */
void xuat(QUEUE q) {
    while(kiemTraRong(q) == true){ // Se lien tuc lap khi Stack chua rong
        int x; // Du lieu lay ra
        pop(q, x); // Lay ra x
        cout << "\nDu lieu lay ra: " << x;
    }
}



int main(){

    QUEUE q;
    nhap(q);
    xuat(q);

    // // Thu xuat ra s.top
    // int x;
    // top(q, x);
    // cout << "\nTop = " << x;

    cout << endl;
    system("pause");
    return 0;
}