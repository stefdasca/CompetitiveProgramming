#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

typedef long long ll;

int n, m;
int v[100002];
int aint[400002];
int lazy[400002];
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
    aint[nod] = min(aint[nod << 1], aint[nod << 1|1]);
}
void propagate(int nod, int st, int dr)
{
    aint[nod] -= lazy[nod];
    if(st != dr)
    {
        lazy[nod << 1] += lazy[nod];
        lazy[nod << 1|1] += lazy[nod];
    }
    lazy[nod] = 0;
}
void update(int nod, int st, int dr, int L, int R)
{
    if(L <= st && dr <= R)
        lazy[nod]++;
    propagate(nod, st, dr);
    if(L <= st && dr <= R)
        return;
    if(dr < L || st > R)
        return;
    int mid = (st + dr) / 2;
    update(nod << 1, st, mid, L, R);
    update(nod << 1|1, mid+1, dr, L, R);
    aint[nod] = min(aint[nod << 1], aint[nod << 1|1]);
}
int query(int nod, int st, int dr, int poz)
{
    propagate(nod, st, dr);
    if(st == dr)
        return aint[nod];
    int mid = (st + dr) / 2;
    int ans = 0;
    if(poz <= mid)
        ans = query(nod << 1, st, mid, poz);
    else
        ans = query(nod << 1|1, mid+1, dr, poz);
    aint[nod] = min(aint[nod << 1], aint[nod << 1|1]);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    sort(v+1, v+n+1);
    build(1, 1, n);
    for(int i = 1; i <= m; ++i)
    {
        int x;
        cin >> x;
        int val = query(1, 1, n, n - x + 1);
        if(val == 0 || x > n)
        {
            cout << i-1;
            return 0;
        }
        int st = 1;
        int dr = n - x + 1;
        int ans1 = 0;
        while(st <= dr)
        {
            int mid = (st + dr) / 2;
            int y = query(1, 1, n, mid);
            if(y == val)
                ans1 = mid, dr = mid - 1;
            else
                st = mid+1;
        }
        st = 1;
        dr = n;
        int ans2 = 0;
        while(st <= dr)
        {
            int mid = (st + dr) / 2;
            int y = query(1, 1, n, mid);
            if(y > val)
                ans2 = mid, dr = mid - 1;
            else
                st = mid+1;
        }
        if(ans2 != 0)
        {
            update(1, 1, n, ans2, n);
            x -= (n - ans2 + 1);
        }
        if(x != 0)
            update(1, 1, n, ans1, ans1 + x - 1);
    }
    cout << m;
    return 0;
}

