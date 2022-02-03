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

int main() {
  faster();
  int n, t, x, idx = 0;
  vi v;
  priority_queue<int> ans;
  cin >> n >> t;
  FOR(i, 1, n) {
    cin >> x;
    v.pb(x);
  }
  int st = n - 1, cnt = 0;
  int sum = 0, tmp = 0;
  while (idx <= st) {
    if (sum + v[idx] <= t) {
      sum += v[idx];
      cnt++;
    }
    else {
      ans.push(cnt);
      sum -= v[tmp];
      tmp++;
      cnt--;
      continue;
    }
    idx++;
  }
  ans.push(cnt);
  cout << ans.top();
  return 0;
}
