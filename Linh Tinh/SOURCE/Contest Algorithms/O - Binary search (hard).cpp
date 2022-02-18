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
#define PI 3.141592653589793238
#define endl '\n'

int binarySearch(const vll &v, ll x)
{
    int l = 0, r = v.sz - 1, mid, res = -2;
    while(l <= r)
    {
        mid = (l + r) / 2;
        if(v[mid] == x)
        {
            res = mid;
            r = mid - 1;
        }
        else if(v[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return res + 1;
}

int main()
{
    faster();
    int n;
    cin >> n;
    vll v(n);
    F(i, 0, n) cin >> v[i];
    sort(v.begin(), v.end());
    ll x;
    int idx;
    while(1)
    {
        cin >> x;
        if(x == -1) return 0;
        idx = binarySearch(v, x);
        if(idx != -1) cout << "Found x at " << idx << endl;
        else cout << "#Not found!\n";
    }
    return 0;
}
