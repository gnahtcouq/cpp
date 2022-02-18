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

const ll mod = 1e9 + 7;

ll MUL(ll a, ll b)
{
    ll res = 0;
    while(b > 0)
    {
        if(b & 1) res = (res + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return res;
}

ll POW(ll a, ll n)
{
    ll res = 1;
    while(n > 0)
    {
        if(n & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return res;
}

int main()
{
    faster();
    int t;
    ll a, n;
    cin >> t;
    while(t--)
    {
        cin >> a >> n;
        a %= mod;
        cout << MUL(a, n) << endl;
    }
    return 0;
}
