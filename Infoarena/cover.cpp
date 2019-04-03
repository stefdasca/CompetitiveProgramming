#include<bits/stdc++.h>
using namespace std;
ifstream f("cover.in");
ofstream g("cover.out");
int n, q;
int val[1000002];
struct qu
{
    int L, R;
};
qu v[60002];
bool cmp(qu a, qu b)
{
    if(a.L == b.L)
        return a.R < b.R;
    return a.L < b.L;
}
int dp[4000002];
int mxs[1000002], mxd[1000002];
int main()
{
    f >> q >> n;
    for(int i = 1; i <= n; ++i)
        f >> val[i];
    for(int i = 1; i <= q; ++i)
    {
        f >> v[i].L >> v[i].R;
        mxs[v[i].R] = max(mxs[v[i].R], v[i].L);
        mxd[v[i].R] = v[i].R;
    }
    sort(v+1, v+q+1, cmp);
    for(int i = 1; i <= n; ++i)
    {
        if(!mxs[i])
            mxs[i] = mxs[i-1], mxd[i] = mxd[i-1];
        else
            if(mxs[i-1] > mxs[i])
                mxs[i] = mxs[i-1], mxd[i] = mxd[i-1];
    }
    deque<int>d;
    d.push_back(0);
    int mn = (1<<30);
    for(int i = 1; i <= n; ++i)
    {
        while(!d.empty() && d.front() < mxs[i-1])
            d.pop_front();
        int zz = val[i] + dp[d.front()];
        while(!d.empty() && zz < dp[d.back()])
            d.pop_back();
        d.push_back(i);
        if(i >= v[q].L && i <= v[q].R)
            mn = min(mn, zz);
        dp[i] = zz;
    }
    g << mn << '\n';
    return 0;
}
