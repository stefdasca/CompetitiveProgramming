#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m, k;
struct vs
{
    int val;
    int pos;
};
vs v[200002];
bool sp[200002];
bool cmp(vs a, vs b)
{
    return a.val < b.val;
}
bool be[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i)
        cin >> v[i].val, v[i].pos = i;
    sort(v+1, v+n+1, cmp);
    long long sum = 0;
    for(int i = n; i >= n - m * k + 1; --i)
        be[v[i].pos] = 1, sum += v[i].val;
    cout << sum << '\n';
    int nr = 0;
    int ct = 0;
    for(int i = 1; i <= n; ++i)
    {
        nr += be[i];
        if(nr == m && ct + 1 < k)
            cout << i << " ", nr = 0, ++ct;
    }
    return 0;
}

