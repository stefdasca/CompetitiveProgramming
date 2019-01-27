#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, d;
long long arr[300002];
struct aint
{
    long long ssmax, ssmaxl, ssmaxr, sum;
};
aint v[1200002];
void build(int nod, int st, int dr)
{
    if(st == dr)
    {
        v[nod].ssmax = arr[st];
        v[nod].ssmaxl = arr[st];
        v[nod].ssmaxr = arr[st];
        v[nod].sum = arr[st];
        return;
    }
    int mid = ((st + dr) >> 1);
    build(nod << 1, st, mid);
    build(nod << 1 | 1, mid+1, dr);
    v[nod].sum = v[nod << 1].sum + v[nod << 1 | 1].sum;
    v[nod].ssmaxl = max(v[nod].sum, max(v[nod << 1].ssmaxl, v[nod << 1].sum + v[nod << 1 | 1].ssmaxl));
    v[nod].ssmaxr = max(v[nod].sum, max(v[nod << 1 | 1].ssmaxr, v[nod << 1 | 1].sum + v[nod << 1].ssmaxr));
    v[nod].ssmax = max(v[nod << 1].ssmax, v[nod << 1 | 1].ssmax);
    v[nod].ssmax = max(v[nod].ssmax, max(v[nod].ssmaxl, v[nod].ssmaxr));
    v[nod].ssmax = max(v[nod].ssmax, v[nod << 1].ssmaxr + v[nod << 1 | 1].ssmaxl);
}
int L, R;
long long sol, ssm, ss, prv, prv2;
void qu(int nod, int st, int dr)
{
    if(st > R || dr < L)
        return;
    if(L <= st && dr <= R)
    {
        sol = max(sol, v[nod].ssmax);
        if(ssm == -(1LL<<60))
            ssm = max(v[nod].ssmaxr, v[nod].sum);
        else
        {
            sol = max(sol, ssm + v[nod].ssmaxl);
            ssm = max(ssm + v[nod].sum, max(v[nod].ssmaxr, v[nod].sum));
        }
        sol = max(sol, ssm);
        return;
    }
    int mid = (st + dr) >> 1;
    qu(nod << 1, st, mid);
    qu(nod << 1 | 1, mid+1, dr);
}
long long di[300002], dif[300002];
long long ans = 0;
long long st[300002], dr[300002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> d;
    for(int i = 1; i <= n; ++i)
    {
        cin >> di[i] >> arr[i];
        arr[i] = d - arr[i];
    }
    build(1, 1, n);
    for(int i = 1; i < n; ++i)
        dif[i] = di[i+1] - di[i];
    deque<int>de;
    for(int i = 1; i < n; ++i)
    {
        while(!de.empty() && dif[i] >= dif[de.back()])
            de.pop_back();
        if(de.empty())
            st[i] = 1;
        else
            st[i] = de.back() + 1;
        de.push_back(i);
    }
    de.clear();
    for(int i = n-1; i >= 1; --i)
    {
        while(!de.empty() && dif[i] >= dif[de.back()])
            de.pop_back();
        if(de.empty())
            dr[i] = n;
        else
            dr[i] = de.back();
        de.push_back(i);
    }
    for(int i = 1; i <= n; ++i)
        ans = max(ans, arr[i]);
    for(int i = 1; i < n; ++i)
    {
        long long prd = -1LL * dif[i] * dif[i];
        sol = -(1LL<<60);
        ssm = -(1LL<<60);
        ss = 0;
        L = st[i];
        R = dr[i];
        qu(1, 1, n);
        ans = max(ans, sol + prd);
    }
    cout << ans;
    return 0;
}

