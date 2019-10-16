#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

vector<int>upd[100002];

int n, v[100002];

int aint[400002];
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
    aint[nod] = max(aint[nod << 1], aint[nod << 1|1]);
}

void update(int nod, int st, int dr, int poz, int val)
{
    if(st == dr)
    {
        aint[nod] = val;
        return;
    }
    int mid = (st + dr) / 2;
    if(poz <= mid)
        update(nod << 1, st, mid, poz, val);
    else
        update(nod << 1|1, mid+1, dr, poz, val);
    aint[nod] = max(aint[nod << 1], aint[nod << 1|1]);
}

int query(int nod, int st, int dr, int L, int R)
{
    if(dr < L || st > R)
        return -1;
    if(L <= st && dr <= R)
        return aint[nod];
    int mid = (st + dr) / 2;
    return max(query(nod << 1, st, mid, L, R), query(nod << 1|1, mid+1, dr, L, R));
}

int dif(int a, int b)
{
    if(a <= b)
        return b - a;
    return b + (n - a);
}

int ans[100002], bst[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i], ans[i] = -1;
    build(1, 1, n);

    bool rau = 1;
    for(int i = 1; i <= n; ++i)
    {
        int pozworst = -1;
        int st = 1;
        int dr = i-1;
        int anss = -1;
        while(st <= dr)
        {
            int mid = (st + dr) / 2;
            if(query(1, 1, n, mid, i) >= v[i] * 2 + 1)
                anss = mid, st = mid + 1;
            else
                dr = mid - 1;
        }
        pozworst = anss;
        if(pozworst == -1)
        {
            int st = i;
            int dr = n;
            int anss = -1;
            while(st <= dr)
            {
                int mid = (st + dr) / 2;
                if(query(1, 1, n, mid, n) >= v[i] * 2 + 1)
                    anss = mid, st = mid + 1;
                else
                    dr = mid - 1;
            }
            pozworst = anss;
        }
        if(pozworst != -1)
        {
            rau = 0;
            upd[pozworst].push_back(dif(pozworst, i));
            int aa = dif(pozworst, i) + pozworst;
            upd[n].push_back(aa);
        }
    }
    if(rau)
    {
        for(int i = 1; i <= n; ++i)
            cout << -1 << " ";
        return 0;
    }
    for(int i = 1; i <= n; ++i)
    {
        sort(upd[i].begin(), upd[i].end());
        if(!upd[i].empty())
            bst[i] = upd[i][0];
        else
            bst[i] = (1<<30);
    }
    for(int i = n - 1; i >= 1; --i)
        bst[i] = min(bst[i], bst[i+1] + 1);
    for(int i = 1; i <= n; ++i)
        cout << bst[i] << " ";
    return 0;
}
