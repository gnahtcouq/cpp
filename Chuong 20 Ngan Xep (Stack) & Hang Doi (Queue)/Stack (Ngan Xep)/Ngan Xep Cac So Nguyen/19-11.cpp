/* 
B1: Khai bao cau truc du lieu
B2: Khoi tao
B3: Tao Node
B4: Them Node vao cau truc
B5: InPut/OutPut
B6: Xu li
B7: Giai phong
*/

#include <iostream>
using namespace std;

// B1: Khai bao cau truc du lieu
struct Node {
    int data;
    struct Node *pNext;
};
typedef struct Node NODE;

struct Stack {
    NODE *top;
};
typedef struct Stack STACK;

// B2: Khoi tao
void khoiTao(STACK &s){
    s.top = NULL;
}

// B3: Tao Node
NODE *taoNode(int DATA){
    NODE *p = new NODE();
    if(p == NULL){
        cout << "\nKhong du bo nho de cap phat";
        return NULL;
    }
    p->data = DATA; // bo DATA vao trong Node p
    p->pNext = NULL; // thiet lap moi lien ket
    return p; // tra Node p ve
}

/* 
    Can tao ra 3 ham sau day:
    1/ Kiem tra Stack co rong hay khong?
    2/ Push -> them 1 Node vao (themDau/themCuoi)
    3/ Pop -> xoa Node dau tien (giaiPhong)
    4/ Top -> xem Node dau tien
*/

// Neu Stack rong return true, nguoc lai return false
bool kiemTraStackRong(STACK s){
    if(s.top == NULL){
        return true; // rong
    }
    return false; // khong rong
}

// Them Node p vao Stack. Thanh cong return true, that bai return false
bool push(STACK &s, NODE *p){
    if(p == NULL){
        return false;
    }
    // Truong hop danh sach khong co gi -> p la Node duy nhat
    if(s.top == NULL){
        s.top = p;
    }
    else{
        p->pNext = s.top;
        s.top = p;
    }
    return true; // thanh cong
}

// Pop (xoa dau Stack) thanh cong -> return true
bool pop(STACK &s){
    NODE *p = s.top; // Cho 1 con tro p tro toi s.top
    s.top = s.top->pNext; // Cap nhat lai s.top la Node ke tiep
    delete p;
    return true;
}

int top(STACK s){
    return s.top->data;
}

void nhap(STACK &s){
    khoiTao(s); // Khoi tao Stack

    int n; // So luong Node can nhap
    cout << "\nNhap vao so luong Node: ";
    cin >> n;

    for(int i = 1; i <= n; i++){
        int DATA;
        cout << "\nNhap vao Node thu " << i << ": ";
        cin >> DATA;

        NODE *p = taoNode(DATA); // Bo DATA vao trong Node
        push(s, p); // Bo Node p vao trong Stack
    }
}

// outPut cung dong thoi giai phong khi lay ra tung Node
void xuat(STACK &s){
    // Vong lap se lap lien tuc khi ma Stack khong bi rong
    while(!kiemTraStackRong(s)){
        int x = top(s); // gan data cua top sang x
        pop(s); // delete top di
        cout << x << " ";
    }
}

int main(){
    STACK s;
    nhap(s);
    xuat(s);

    cout << endl;
    system("pause");
    return 0;
}
