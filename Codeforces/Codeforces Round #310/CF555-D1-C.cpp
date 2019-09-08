#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int n, q;
struct intre
{
    int x, y;
    char tip;
};
intre v[200002];

int pc[2][200002];
map<int, int> poz[2];
map<int, int> scos;

int aint[2][800002];
int lazy[2][800002];
void propagate(int tip, int nod, int st, int dr)
{
    aint[tip][nod] = max(aint[tip][nod], lazy[tip][nod]);
    if(st != dr)
    {
        lazy[tip][nod << 1] = max(lazy[tip][nod << 1], lazy[tip][nod]);
        lazy[tip][nod << 1|1] = max(lazy[tip][nod << 1|1], lazy[tip][nod]);
    }
    lazy[tip][nod] = 0;
}
void update(int tip, int nod, int st, int dr, int L, int R, int val)
{
    if(lazy[tip][nod])
        propagate(tip, nod, st, dr);
    if(L <= st && dr <= R)
    {
        lazy[tip][nod] = val;
        return;
    }
    if(dr < L || st > R)
        return;
    int mid = (st + dr) / 2;
    update(tip, nod << 1, st, mid, L, R, val);
    update(tip, nod << 1|1, mid+1, dr, L, R, val);
    aint[tip][nod] = max(aint[tip][nod << 1], aint[tip][nod << 1|1]);
}
int query(int tip, int nod, int st, int dr, int val)
{
    if(lazy[tip][nod])
        propagate(tip, nod, st, dr);
    if(st == dr)
        return aint[tip][nod];
    int mid = (st + dr) / 2;
    int ans;
    if(val <= mid)
        ans = query(tip, nod << 1, st, mid, val);
    else
        ans = query(tip, nod << 1|1, mid+1, dr, val);
    aint[tip][nod] = max(aint[tip][nod << 1], aint[tip][nod << 1|1]);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i <= q; ++i)
    {
        cin >> v[i].x >> v[i].y >> v[i].tip;
        swap(v[i].x, v[i].y);
        if(v[i].tip == 'U')
            pc[0][++pc[0][0]] = v[i].y;
        else
            pc[1][++pc[1][0]] = v[i].x;
    }
    sort(pc[0]+1, pc[0]+pc[0][0]+1);
    sort(pc[1]+1, pc[1]+pc[1][0]+1);
    for(int i = 0; i <= 1; ++i)
    {
        for(int j = 1; j <= pc[i][0]; ++j)
            poz[i][pc[i][j]] = j;
    }
    for(int i = 1; i <= q; ++i)
    {
        if(scos.find(v[i].x) != scos.end())
        {
            cout << 0 << '\n';
            continue;
        }
        if(v[i].tip == 'U')
        {
            int ans = query(0, 1, 1, pc[0][0], poz[0][v[i].y]);
            cout << v[i].x - ans << '\n';
            int min_line = max(1, v[i].x - (v[i].x - ans));
            int max_line = v[i].x;
            int st = 1;
            int dr = pc[1][0];
            ans = 0;
            while(st <= dr)
            {
                int mid = (st + dr) / 2;
                if(pc[1][mid] >= min_line)
                    ans = mid, dr = mid - 1;
                else
                    st = mid + 1;
            }
            st = 1;
            dr = pc[1][0];
            int ans2 = 0;
            while(st <= dr)
            {
                int mid = (st + dr) / 2;
                if(pc[1][mid] <= max_line)
                    ans2 = mid, st = mid + 1;
                else
                    dr = mid - 1;
            }
            if(ans <= ans2)
                update(1, 1, 1, pc[1][0], ans, ans2, v[i].y);
        }
        else
        {
            int ans = query(1, 1, 1, pc[1][0], poz[1][v[i].x]);
            cout << v[i].y - ans << '\n';
            int min_column = max(1, v[i].y - (v[i].y - ans));
            int max_column = v[i].y;
            int st = 1;
            int dr = pc[0][0];
            ans = 0;
            while(st <= dr)
            {
                int mid = (st + dr) / 2;
                if(pc[0][mid] >= min_column)
                    ans = mid, dr = mid - 1;
                else
                    st = mid + 1;
            }
            st = 1;
            dr = pc[0][0];
            int ans2 = 0;
            while(st <= dr)
            {
                int mid = (st + dr) / 2;
                if(pc[0][mid] <= max_column)
                    ans2 = mid, st = mid + 1;
                else
                    dr = mid - 1;
            }
            if(ans <= ans2)
                update(0, 1, 1, pc[0][0], ans, ans2, v[i].x);
        }
        scos[v[i].x] = 1;
    }
    return 0;
}

