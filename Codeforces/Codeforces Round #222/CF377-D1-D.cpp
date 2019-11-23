#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

struct nr
{
    int st, val, dr;
};
nr v[100002];

vector<int> ad[300002], drp[300002];

int aint[1200002], le[1200002], tba[1200002];
void update(int nod, int st, int dr, int L, int R, int tip)
{
    if(dr < L || st > R)
        return;
    if(L <= st && dr <= R)
    {
        aint[nod] += tip;
        tba[nod] += tip;
        if(le[nod] == 0)
            le[nod] = st;
        return;
    }
    int mid = (st + dr) / 2;
    update(nod << 1, st, mid, L, R, tip);
    update(nod << 1|1, mid+1, dr, L, R, tip);
    if(aint[nod << 1] > aint[nod << 1|1])
    {
        aint[nod] = aint[nod << 1];
        le[nod] = le[nod << 1];
    }
    else
    {
        aint[nod] = aint[nod << 1|1];
        le[nod] = le[nod << 1|1];
    }
    aint[nod] += tba[nod];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i].st >> v[i].val >> v[i].dr;
        ad[v[i].val].pb(i);
        drp[v[i].dr].pb(i);
    }
    int mx = 0;
    int L, R;
    for(int i = 1; i <= 300000; ++i)
    {
        for(int j = 0; j < ad[i].size(); ++j)
            update(1, 1, 300000, v[ad[i][j]].st, i, 1);
        if(aint[1] > mx)
        {
            mx = aint[1];
            L = le[1];
            R = i;
        }
        for(int j = 0; j < drp[i].size(); ++j)
            update(1, 1, 300000, v[drp[i][j]].st, v[drp[i][j]].val, -1);
    }
    cout << mx << '\n';
    for(int i = 1; i <= n; ++i)
        if(v[i].st <= L && v[i].val >= L && v[i].val <= R && v[i].dr >= R)
            cout << i << " ";
    return 0;
}
