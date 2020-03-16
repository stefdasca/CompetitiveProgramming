/*
        COCI 16-zoltan

    The LIS of the new array will be formed by two parts, a decreasing sequence of elements which ends at some value i,
followed by an increasing sequence of elements which starts at the same value i.

    In order to find the LIS and the reverse LIS, we're going to use two fenwick trees and normalize the input before
we apply any of the operations.

*/
#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n, v[200002], sortt[200002], valdis;
map<int, int> mp;

const int mod = 1000000007;
/// 0 - increasing
/// 1 - decreasing
int aib[2][200002];
int nr[2][200002];
int mx[2][200002];
int cnt[2][200002];
void add(int poz, int nod, int val, int x)
{
    for(; nod <= valdis; nod += (nod & (-nod)))
        if(aib[poz][nod] < val)
        {
            aib[poz][nod] = val;
            nr[poz][nod] = x;
        }
        else
            if(aib[poz][nod] == val)
            {
                nr[poz][nod] += x;
                if(nr[poz][nod] >= mod)
                    nr[poz][nod] -= mod;
            }
}
pair<int, int> compute(int poz, int nod)
{
    pair<int, int> ans = {0, 1};
    for(; nod; nod -= (nod & (-nod)))
    {
        if(aib[poz][nod] > ans.fi)
            ans = {aib[poz][nod], nr[poz][nod]};
        else
        {
            if(aib[poz][nod] == ans.fi)
            {
                ans.se += nr[poz][nod];
                if(ans.se >= mod)
                    ans.se -= mod;
            }
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        sortt[i] = v[i];
    }
    sort(sortt + 1, sortt + n + 1);
    for(int i = 1; i <= n; ++i)
        if(i == 1 || sortt[i] > sortt[i-1])
            mp[sortt[i]] = ++valdis;
    for(int i = 1; i <= n; ++i)
        v[i] = mp[v[i]];
    pair<int, int> opt = {0, 0};
    for(int i = n; i >= 1; --i)
    {
        pair<int, int> ansa = compute(0, v[i] - 1);
        int prod = ansa.se;
        if(mx[0][v[i]] < ansa.fi + 1)
        {
            mx[0][v[i]] = ansa.fi + 1;
            cnt[0][v[i]] = ansa.se;
            add(0, v[i], mx[0][v[i]], cnt[0][v[i]]);
        }
        else
            if(mx[0][v[i]] == ansa.fi + 1)
            {
                cnt[0][v[i]] += ansa.se;
                if(cnt[0][v[i]] >= mod)
                    cnt[0][v[i]] -= mod;
                add(0, v[i], mx[0][v[i]], ansa.se);
            }
        ansa = compute(1, valdis - v[i]);
        prod = (1LL * prod * ansa.se) % mod;
        if(mx[1][v[i]] < ansa.fi + 1)
        {
            mx[1][v[i]] = ansa.fi + 1;
            cnt[1][v[i]] = ansa.se;
            add(1, valdis - v[i] + 1, mx[1][v[i]], cnt[1][v[i]]);
        }
        else
            if(mx[1][v[i]] == ansa.fi + 1)
            {
                cnt[1][v[i]] += ansa.se;
                if(cnt[1][v[i]] >= mod)
                    cnt[1][v[i]] -= mod;
                add(1, valdis - v[i] + 1, mx[1][v[i]], ansa.se);
            }
        if(mx[0][v[i]] + mx[1][v[i]] - 1 > opt.fi)
        {
            opt.fi = mx[0][v[i]] + mx[1][v[i]] - 1;
            opt.se = prod;
        }
        else
            if(mx[0][v[i]] + mx[1][v[i]] - 1 == opt.fi)
            {
                opt.se = opt.se + prod;
                if(opt.se >= mod)
                    opt.se -= mod;
            }
    }
    cout << opt.fi << " ";
    while(opt.fi < n)
    {
        ++opt.fi;
        opt.se = (opt.se * 2) % mod;
    }
    cout << opt.se << '\n';
    return 0;
}
