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
    ll N = 1e6;
    bool check[1000005] = {};
    check[0] = check[1] = 1;
    for(int i = 2; i * i <= N; ++i) if(!check[i]) for(int j = i * i; j <= N; j += i) check[j] = 1;
    vll v;
    for(ll i = 17; i <= N; ++i) if(!check[i]) v.pb(i);
    int x[] = {2, 4, 6, 10, 12, 16, 18, 22, 28, 30, 36};
    vll num;
    for(ll i : x) num.pb(pow(2, i));
    for(int i = 0; i < 8; ++i) num.pb(pow(3, x[i]));
    for(int i = 0; i < 6; ++i) num.pb(pow(5, x[i]));
    for(int i = 0; i < 5; ++i) num.pb(pow(7, x[i]));
    for(int i = 0; i < 4; ++i)
    {
        num.pb(pow(11, x[i]));
        num.pb(pow(13, x[i]));
    }
    int a[] = {2, 4, 6};
    for(ll i : v)
    {
        if(i >= 1000) num.pb(i * i);
        else
        {
            for(ll j : a)
            {
                ll tmp = pow(i, j);
                if(tmp <= 1e12) num.pb(tmp);
                else break;
            }
        }
    }
    sort(num.begin(), num.end());
    int t;
    cin >> t;
    ll A, B;
    while(t--)
    {
        cin >> A >> B;
        ll l, r;
        l = lower_bound(num.begin(), num.end(), A) - num.begin();
        r = upper_bound(num.begin(), num.end(), B) - num.begin();
        cout << r - l << endl;
    }
    return 0;
}
