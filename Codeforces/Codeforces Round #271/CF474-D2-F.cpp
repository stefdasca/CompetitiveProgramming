#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n, v[100002], q;
struct aint
{
    int mini, cmmdc, ct;
};
aint v2[400002];
void build(int nod, int st, int dr)
{
    if(st == dr)
    {
        v2[nod] = {v[st], v[st], 1};
        return;
    }
    int mid = (st + dr) / 2;
    build(nod << 1, st, mid);
    build(nod << 1|1, mid + 1, dr);
    v2[nod].mini = min(v2[nod << 1].mini, v2[nod << 1|1].mini);
    if(v2[nod << 1].mini == v2[nod].mini)
        v2[nod].ct += v2[nod << 1].ct;
    if(v2[nod << 1 | 1].mini == v2[nod].mini)
        v2[nod].ct += v2[nod << 1 | 1].ct;
    v2[nod].cmmdc = __gcd(v2[nod << 1].cmmdc, v2[nod << 1|1].cmmdc);
}
int mn, cmm, cc;
void query(int nod, int L, int R, int st, int dr)
{
    if(R < st || L > dr)
        return;
    if(st <= L && R <= dr)
    {
        if(mn == -1 && cmm == -1)
            mn = v2[nod].mini, cmm = v2[nod].cmmdc, cc = v2[nod].ct;
        else
        {
            cmm = __gcd(cmm, v2[nod].cmmdc);
            if(mn == v2[nod].mini)
                cc += v2[nod].ct;
            else
                if(mn > v2[nod].mini)
                    cc = v2[nod].ct, mn = v2[nod].mini;
        }
        return;
    }
    int mid = (L + R) / 2;
    query(nod << 1, L, mid, st, dr);
    query(nod << 1|1, mid + 1, R, st, dr);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    build(1, 1, n);
    cin >> q;
    for(int i = 1; i <= q; ++i)
    {
        int st, dr;
        cin >> st >> dr;
        mn = -1, cmm = -1, cc = -1;
        query(1, 1, n, st, dr);
        if(cmm % mn == 0)
            cout << (dr - st + 1) - cc << '\n';
        else
            cout << dr - st + 1 << '\n';
    }
    return 0;
}

