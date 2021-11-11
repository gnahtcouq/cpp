#include<iostream>

using namespace std;


void show(string s){
    for(int i=0;i<s.size();i++){
        if(s[i]>='a' && s[i]<='z') s[i] -=32;
    }
    cout << s << endl;
}

int main() {
    string s;
    cin >> s;
    show(s);
    return 0;
}
