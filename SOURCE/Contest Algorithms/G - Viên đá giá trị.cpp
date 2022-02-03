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

ll mulmod(ll a, ll b, ll m)
{
    a %= m;
    b %= m;
    if (a == 0) return 0;
    ll res = 0;
    while (a != 0)
    {
        if (a & 1)
        {
            if (b >= m - res) res -= m;
            res += b;
        }
        a >>= 1;
        if (b >= m - b) b += b - m;
        else b += b;
    }
    return res;
}

ll POW(ll a, ll b, ll mod)
{
    ll c;
    if (b == 0) return 1;
    if (b == 1) return (a % mod);
    c = POW(a, b / 2, mod) % mod;
    c = mulmod(c, c, mod) % mod;
    if (b % 2) c = mulmod(c, a, mod);
    return (c % mod);
}

bool isPrime(ll p)
{
    if(p < 2) return 0;
    if (p == 2) return 1;
    if(p > 7 && (p % 2 == 0 || p % 3 == 0 || p % 5 == 0 || p % 7 == 0)) return 0;
    else
    {
        if (((POW(2, p, p) - (2 % p)) % p) == 0) return 1;
        else return 0;
    }
}

int main()
{
    faster();
    ll n;
    while(cin >> n) cout << isPrime(n) << endl;
    return 0;
}
