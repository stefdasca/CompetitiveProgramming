#include<bits/stdc++.h>
using namespace std;
ifstream fi("sequencequery.in");
ofstream fo("sequencequery.out");
int n, m;
long long arr[100002];
struct aint
{
    long long ssmax, ssmaxl, ssmaxr, sum;
};
aint v[400002];
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
int main()
{
    fi >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        fi >> arr[i];
    }
    build(1, 1, n);
    for(int i = 1; i <= m; ++i)
    {
        fi >> L >> R;
        sol = -(1LL<<60);
        ssm = -(1LL<<60);
        ss = 0;
        qu(1, 1, n);
        fo << sol << '\n';
    }
    return 0;
}
