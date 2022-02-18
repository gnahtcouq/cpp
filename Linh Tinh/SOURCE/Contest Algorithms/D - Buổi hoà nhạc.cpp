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

int dd[1000005] = {};
 
int main()
{
    faster();
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = 0, ans = 0, tmp = 0;
    while(r < n)
    {
        if(dd[a[r]] == 0)
        {
            dd[a[r]]++;
            tmp++;
            r++;
        }
        else
        {
            ans = max(tmp, ans);
            tmp--;
            dd[a[l]]--;
            l++;
        }
    }
    ans = max(tmp, ans);
    cout << ans << endl;
    return 0;
}
