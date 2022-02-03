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
    ll n, x;
    cin >> n;
    ll sum = 0, sum2 = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> x;
        sum += x;
        sum2 += x * x;
    }
    ll sumAll = n * (n + 1) / 2, sum2All = n * (n + 1) * (2 * n + 1) / 6;
    ll hieu = abs(sumAll - sum), tong = abs(sum2All - sum2) / hieu;
    cout << (tong - hieu) / 2 << ' ' << (tong + hieu) / 2;
    return 0;
}
