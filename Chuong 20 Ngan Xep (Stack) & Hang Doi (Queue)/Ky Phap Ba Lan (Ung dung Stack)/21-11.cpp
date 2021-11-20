#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Khai bao cau truc du lieu ngan xep Stack
struct Node
{
    string data; // Du lieu chua ben trong Stack
    struct Node *pNext; // Con tro pNext de tao moi lien ket giua cac Node
};
typedef struct Node NODE;

struct Stack
{
    NODE *top; // Top quan ly dau Stack
};
typedef struct Stack STACK;

// Khoi tao ngan xep
void khoiTao(STACK &s){
    s.top = NULL;
}

// Tao Node trong ngan xep Stack
NODE *taoNode(string x) // Du lieu ben trong Node dang co kieu string
{
    NODE *p = new NODE;
    if(p == NULL){
        cout << "\nKhong du bo nho de cap phat";
        return NULL;
    }
    p->data = x; // Luu du lieu data vao ben trong Node
    p->pNext = NULL; // Cap nhat lai moi lien ket
    return p; // Tra ve Node p
}

// Kiem tra Stack rong. return true neu Stack co phan tu/return false neu Stack rong
bool kiemTraRong(STACK s){
    if(s.top == NULL)
        return false;
    return true;
}

// Them 1 Node vao Stack. return true neu thanh cong/return false neu that bai
bool push(STACK &s, NODE *p){
    if(kiemTraRong(s) == false){
        s.top = p; // Cap nhat dau Stack chinh la Node p
        return true;
    }
    p->pNext = s.top;
    s.top = p;
    return true;
}

// Lay phan tu trong Stack dem ra ngoai. return true neu thanh cong/return false neu that bai
bool pop(STACK &s, string &x){
    if(kiemTraRong(s) == false)
        return false;
    NODE *p = s.top; // con tro p tro toi con tro top
    x = p->data;
    s.top = s.top->pNext;
    delete p;
    return true;
}

// Xem phan tu dau Stack. return true neu thanh cong/return false chac that bai
bool top(STACK s, string &x){
    if(kiemTraRong(s) == false)
        return false;
    x = s.top->data;
    return true;
}

void xuLy(STACK &s){
    ifstream FileIn; // Khai bao file de doc du lieu
    FileIn.open("input.txt", ios_base::in); // Mo file de doc

    // Kiem tra file co ton tai
    if(!FileIn){
        cout << "\nKhong tim thay tep tin input.txt";
    }

    string str; // Bien luu gia tri doc tu file vao
    getline(FileIn, str); // Doc du lieu tu file luu vao bien str

    FileIn.close(); // Dong file lai


    khoiTao(s); // Khoi tao Stack

    string p1, p2, p3;
    int ketqua;

    for(int i = 0; i < str.length(); i++){
        NODE *p = new NODE;
        if(str[i] == '(')
            continue; // Bo lan lap hien tai
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%'){
            char *temp = new char;
            temp[0] = str[i];
            temp[1] = '\0';
            string a = temp;
            p = taoNode(a);
            push(s, p);
        }
        string temp;
        int start, end;

        if(str[i] >= '0' && str[i] <= '9'){
            start = i;
            for(int j = i + 1; j < str.length(); j++){
                if(str[j] < '0' || str[i] > '9'){
                    end = j;
                    i = j;
                    break;
                }
            }
            end - 1;
            temp = str.substr(start, end - start);
            p = taoNode(temp);
            push(s, p);
        }
        if(str[i] == ')'){
            pop(s, p1);
            pop(s, p2);
            pop(s, p3);

            int num3, num1;
            num3 = atoi(p3.c_str());
            num1 = atoi(p1.c_str());

            if(p2 == "+"){
                ketqua = num3 + num1;
            }
            if(p2 == "-"){
                ketqua = num3 - num1;
            }
            if(p2 == "*"){
                ketqua = num3 * num1;
            }
            if(p2 == "/"){
                ketqua = num3 / num1;
            }
            if(p2 == "%"){
                ketqua = num3 % num1;
            }
            
            // Dua lai no vao trong Stack
            char chr[20];
            itoa(ketqua, chr, 10);
            NODE *q = taoNode((string)chr);
            push(s, q);
        }
    }
    cout << ketqua;
}


int main(){
    STACK s;
    xuLy(s);
    // xuat(s);

    cout << endl;
    system("pause");
    return 0;
}