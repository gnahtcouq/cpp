#include <iostream>
#include <conio.h> // de dung getch();
using namespace std;

/* Khai bao cau truc du lieu Stack */
struct Node {
    int data; // Du lieu no chua
    struct Node *pNext; // Con tro de lien ket voi cac Node khac
};
typedef struct Node NODE;

struct Stack {
    NODE *top;
};
typedef struct Stack STACK;

/* Khoi tao Stack */
void khoiTao(STACK &s) {
    s.top = NULL;
}

/* Tao Node trong Stack */
NODE *taoNode(int x) { // Do du lieu trong Stack dang la so nguyen
    NODE *p = new NODE;

    if(p == NULL) {
        cout << "\nKhong du bo nho de cap phat !";
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}

/* Kiem tra Stack rong hay khong? return false neu Stack rong. nguoc lai tra ve true */
bool kiemTraRong(STACK s) {
    if(s.top == NULL)
        return false;
    return true;
}

/* Them phan tu vao Stack. return true neu them thanh cong. nguoc lai return false */
bool push(STACK &s, NODE *p) { // p la Node can them vao trong Stack
    // Kiem tra xem Node p co bi rong hay khong
    if(p == NULL) {
        return false;
    }
    // Kiem tra xem Stack co rong hay khong?
    // Neu rong -> Node p them vao chinh la top
    if(kiemTraRong(s) == false) {
        s.top = p;
    }
    else {
        p->pNext = s.top;
        s.top = p;
    }
    return true; // Them thanh cong
}

/* Lay phan tu ra khoi Stack. return true neu lay thanh cong. nguoc lai return false */
bool pop(STACK &s, int &x) { // x la du lieu can lay ra
    // Neu Stack rong -> lay that bai
    if(kiemTraRong(s) == false)
        return false;
    // Neu Stack hien dang co phan tu ben trong
    NODE *p; // Tao con tro p de nam giu s.top
    p = s.top; // Cho con tro p tro toi s.top
    x = p->data; // Gan du lieu ben trong Node sang x
    s.top = s.top->pNext; // Cap nhat lai s.top la phan tu tiep theo
    delete p; // Xoa con tro p
    return true; // Lay thanh cong
}

/* Xem phan tu dau Stack. Luu y la: chi xem chu khong thay doi */
// return true neu xem thanh cong. nguoc lai return false
bool top(STACK s, int &x) {
    // Neu Stack rong -> that bai
    if(kiemTraRong(s) == false)
        return false;
    // Neu Stack hien dang co phan tu ben trong
    x = s.top ->data;
    return true; // Xem thanh cong
}

/* Ham nhap du lieu cho Stack */
void nhap(STACK &s) {
    khoiTao(s); // Khoi tao Stack
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
            push(s, p); // Dua Node p vao trong Stack
        }
    } while (luaChon == '1');
}

/* Ham xuat du lieu cua Stack */
void xuat(STACK s) {
    while(kiemTraRong(s) == true){ // Se lien tuc lap khi Stack chua rong
        int x; // Du lieu lay ra
        pop(s, x); // Lay ra x
        cout << "\nDu lieu lay ra: " << x;
    }
}



int main(){

    STACK s;
    nhap(s);
    // xuat(s);

    // Thu xuat ra s.top
    int x;
    top(s, x);
    cout << "\nTop = " << x;

    cout << endl;
    system("pause");
    return 0;
}