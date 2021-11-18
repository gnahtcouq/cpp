#include <iostream>
#include <list>
using namespace std;

void inPut(list <int> &l);
void outPut(list <int> l);
int timMax(list <int> l);
void lietKeSoChan(list <int> l);

int main(){
    list<int> l; // khai bao dslk
    inPut(l);
    outPut(l);

    int max = timMax(l);
    cout << "\nMax = " << max << endl;

    lietKeSoChan(l);


    system("pause");
    return 0;
}

void inPut(list <int> &l){
    // Them phan tu vao dslk
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);

    // l.push_back <-> addTail
    // l.push_front <-> addHead
}

void outPut(list <int> l){
    // Vong lap duyet dslk
    for(list<int> ::iterator it = l.begin(); it != l.end(); it++){
        cout << *it << " ";
    }
}

int timMax(list <int> l){
    l.sort(); // sap tang dan
    return l.back(); // lay so cuoi cung
}

void lietKeSoChan(list <int> l){
    for(list<int>::iterator it = l.begin(); it != l.end(); it++){
        if(*it % 2 == 0)
            cout << *it << " ";
    }
}