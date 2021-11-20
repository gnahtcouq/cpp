#include <iostream>
#include <stack>
using namespace std;

// "Nam Son" => noS maN


void inPut(stack<int> &s){
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
}

void outPut(stack<int> &s){
    while(!s.empty()){
        int x = s.top();
        s.pop();
        cout << " " << x;
    }
}

int main(){
    stack<int> s;
    inPut(s);



    cout << endl;
    system("pause");
    return 0;
}