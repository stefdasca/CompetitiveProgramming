#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n;
int v[200002], aint[800002];
int st[200002], dr[200002];
deque<int>d;
long long ans;
void build(int nod, int st, int dr)
{
    if(st == dr)
    {
        aint[nod] = v[st];
        return;
    }
    int mid = (st + dr) / 2;
    build(nod << 1, st, mid);
    build(nod << 1|1, mid+1, dr);
    aint[nod] = (aint[nod << 1] | aint[nod << 1|1]);
}
int query(int nod, int st, int dr, int L, int R)
{
    if(dr < L || st > R)
        return 0;
    if(L <= st && dr <= R)
        return aint[nod];
    int mid = (st + dr) / 2;
    int a = query(nod << 1, st, mid, L, R);
    int b = query(nod << 1|1, mid+1, dr, L, R);
    return (a | b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    build(1, 1, n);
    for(int i = 1; i <= n; ++i)
    {
        while(!d.empty() && v[i] > v[d.back()])
            d.pop_back();
        if(!d.empty())
            st[i] = d.back();
        d.push_back(i);
    }
    d.clear();
    for(int i = n; i >= 1; --i)
    {
        while(!d.empty() && v[i] >= v[d.back()])
            d.pop_back();
        if(!d.empty())
            dr[i] = d.back();
        else
            dr[i] = n+1;
        d.push_back(i);
    }
    ans = (1LL * n * (n-1)) / 2;
    for(int i = 1; i <= n; ++i)
    {
        int L = st[i] + 1;
        int R = i;
        int aa = 0;
        while(L <= R)
        {
            int mid = (L + R) / 2;
            int brz = query(1, 1, n, mid, i);
            if((brz | v[i]) == v[i])
                aa = mid, R = mid - 1;
            else
                L = mid + 1;
        }
        L = i;
        R = dr[i] - 1;
        int bb = 0;
        while(L <= R)
        {
            int mid = (L + R) / 2;
            int brz = query(1, 1, n, i, mid);
            if((brz | v[i]) == v[i])
                bb = mid, L = mid + 1;
            else
                R = mid - 1;
        }
        ans = ans - 1LL * (i - aa + 1) * (bb - i + 1) + 1;
    }
    cout << ans << '\n';
    return 0;
}

