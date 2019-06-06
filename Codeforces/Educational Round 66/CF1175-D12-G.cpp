#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll NMAX = 100002;
const ll INF = (1LLU << 62) - 1;
int n, k;
int v[NMAX];
int stk[NMAX];
pair < ll, ll > f[NMAX];
vector < pair < ll, ll > > inttree[4 * NMAX];
bool check(pair < ll, ll > a, pair < ll, ll > b, pair < ll, ll > c) {
  return (1. * (a.second - c.second) / (c.first - a.first) <= 1. * (a.second - b.second) / (b.first - a.first));
}
void add(int node, ll j, ll x) {
  while(inttree[node].size() >= 2 && check(inttree[node][inttree[node].size() - 2], inttree[node][inttree[node].size() - 1], {j, x}))
    inttree[node].pop_back();
  inttree[node].push_back({j, x});
}
void update(int node, int le, int ri, ll j, ll x)
{
  add(node, -j, x);
  if(le == ri)
    return;
  int mid = (le + ri) / 2;
  if(mid >= j)
    update(2 * node, le, mid, j, x);
  else
    update(2 * node + 1, mid + 1, ri, j, x);
}
void rev(int node, int le, int ri)
{
  reverse(inttree[node].begin(), inttree[node].end());
  if(le == ri)
    return ;
  int mid = (le + ri) / 2;
  rev(2 * node, le, mid);
  rev(2 * node + 1, mid + 1, ri);
}
ll eval(pair < ll, ll > d, ll x) {
  return d.first * x + d.second;
}
ll get_value(int node, ll x)
{
  while (inttree[node].size() >= 2 && eval(inttree[node][inttree[node].size() - 2], x) <= eval(inttree[node][inttree[node].size() - 1], x))
    inttree[node].pop_back();
  return eval(inttree[node].back(), x);
}
ll query(int node, int le, int ri, int x, int y, ll w)
{
  if(x <= le && ri <= y)
    return get_value(node, w);
  int mid = (le + ri) / 2;
  ll ans = INF;
  if(x <= mid)
    ans = min(ans, query(2 * node, le, mid, x, y, w));
  if(y > mid)
    ans = min(ans, query(2 * node + 1, mid + 1, ri, x, y, w));

  return ans;
}
void clean_data(int node, int le, int ri)
{
  inttree[node].clear();
  if(le == ri)
    return ;
  int mid = (le + ri) / 2;
  clean_data(2 * node, le, mid);
  clean_data(2 * node + 1, mid + 1, ri);
}
struct Lining
{
  int stk[NMAX];
  pair < int, int > upd[NMAX];
  int top, updc;
  Lining() {
    top = 0;
    updc = 0;
  }
  void add(int i)
  {
    int pos = top + 1;
    if(top == 0)
      pos = 1;
    else if(f[stk[1]].first >= f[i].first && f[stk[1]].second >= f[i].second)
      pos = 1;
    else {
      int le = 2;
      int ri = top;

      while(le <= ri) {
        int mid = (le + ri) / 2;
        if(check(f[stk[mid - 1]], f[stk[mid]], f[i])) {
          ri = mid - 1;
          pos = mid;
        } else {
          le = mid + 1;
        }
      }
    }

    upd[++updc] = {top, stk[pos]};
    stk[pos] = i;
    top = pos;
  }
  ll eval(ll x)
  {
    int le = 1;
    int ri = top;
    while (ri - le >= 3)
    {
      int m1 = le + (ri - le) / 3;
      int m2 = ri - (ri - le) / 3;
      if(f[stk[m1]].first * x + f[stk[m1]].second < f[stk[m2]].first * x + f[stk[m2]].second)
        ri = m2;
      else
        le = m1;
    }
    ll ans = INF;
    for (; le <= ri; le++)
      ans = min(ans, f[stk[le]].first * x + f[stk[le]].second);

    return ans;
  }
  void undo()
  {
    stk[top] = upd[updc].second;
    top = upd[updc].first;

    updc--;
  }
  void clean_data()
  {
    top = 0;
    updc = 0;
  }
};
int main()
{
  cin >> n >> k;
  ll **dp = new ll *[k + 5];
  for(int i = 0; i <= k; ++i)
    dp[i] = new ll [n + 5];
  for(int i = 1; i <= k; ++i)
    for(int j = 0; j <= n; ++j)
      dp[i][j] = INF;
  dp[1][0] = 0;
  int m = 0;
  for(int i = 1; i <= n; ++i)
   {
    cin >> v[i];
    m = max(m, v[i]);
    dp[1][i] = 1LL * i * m;
  }

  Lining b;
  for(int j = 2; j <= k; ++j) {
    for(int i = 1; i <= n; ++i)
      update(1, 1, n, i, dp[j - 1][i - 1]);

    rev(1, 1, n);

    int top = 0;
    for(int i = 1; i <= n; ++i) {
    while(top && v[stk[top]] <= v[i]) {
      top--;
      b.undo();
    }

      stk[++top] = i;
      f[i] = {v[i], query(1, 1, n, stk[top - 1] + 1, i, v[i])};
      b.add(i);
      dp[j][i] = b.eval(i + 1);
    }

    b.clean_data();
    clean_data(1, 1, n);
  }
  cout << dp[k][n] << '\n';
  return 0;
}
