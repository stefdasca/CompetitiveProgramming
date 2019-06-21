/*
        CF101741-gym-J

    * solve the queries offline, using divide and conquer
    * basically, divide the queries based on their left and right point, solving the queries which have left and right point at different halves,
while keeping the other queries for the subsequent calls of the function

*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
int n, m, a[200002], q;
int L[200002], R[200002], ans[200002];
int f[200002][22], g[200002][22];
inline void up(int &a, int b)
{
    a+=b;
    if(a>=mod)
        a-=mod;
}
void solve(int l, int r, vector<int> v)
{
    if (l>r || !v.size())
        return;
    int i,j,mid=l+((r-l)>>1);
    for(i=l; i<=mid+1; ++i)
        for(j=0; j<m; ++j)
            f[i][j]=0;
    for (f[mid+1][0]=1,i=mid; i>=l; --i)
        for (j=0; j<m; ++j)
        {
            up(f[i][j],f[i+1][j]);
            up(f[i][(j+a[i])%m],f[i+1][j]);
        }
    for(i=mid; i<=r; ++i)
        for(j=0; j<m; ++j)
            g[i][j]=0;
    for (g[mid][0]=1,i=mid+1; i<=r; ++i)
        for (j=0; j<m; ++j)
        {
            up(g[i][j],g[i-1][j]);
            up(g[i][(j+a[i])%m],g[i-1][j]);
        }
    vector<int>vl,vr;
    for (i=0; i<(int)v.size(); ++i)
    {
        if (L[v[i]]>mid)
            vr.push_back(v[i]);
        else
            if (R[v[i]]<mid)
                vl.push_back(v[i]);
        else
            for (j=0; j<m; ++j)
                up(ans[v[i]],1LL*f[L[v[i]]][j]*g[R[v[i]]][(m-j)%m]%mod);
    }
    solve(l,mid-1,vl);
    solve(mid+1,r,vr);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> a[i], a[i] %= m;
    cin >> q;
    vector<int>v;
    for(int i = 1; i <= q; ++i)
    {
        cin >> L[i] >> R[i];
        v.push_back(i);
    }
    solve(1, n, v);
    for(int i = 1; i <= q; ++i)
        cout << ans[i] << '\n';
    return 0;
}

