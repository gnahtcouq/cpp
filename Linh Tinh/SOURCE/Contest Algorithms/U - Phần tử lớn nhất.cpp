// Created by Nguyễn Mạnh Quân

#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
#define F(i, a, b) for(int i = a; i < b; ++i)
#define FD(i, a, b) for(int i = a; i > b; --i)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define endl '\n'

int main()
{
    faster();
    map<int, int> m;
    int n, x;
    cin >> n;
    while(n--)
    {
        cin >> x;
        ++m[x];
    }
    auto it = m.end();
    --it;
    cout << (*it).se << endl;
    it = m.begin();
    while(it != m.end()) cout << (*it++).fi << ' ';
    return 0;
}
