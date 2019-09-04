#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

map<int, int> mp;
set<int>vl;

int n, q, R, v[500002], st[500002], dr[500002];

int aib[1000002];

int compute(int pz)
{
    int ans = 0;
    for(; pz; pz -= (pz & (-pz)))
        ans = max(ans, aib[pz]);
    return ans;
}
void upd(int pz, int val)
{
    for(; pz <= R; pz += (pz & (-pz)))
        aib[pz] = max(aib[pz], val);
}
struct plm
{
    int poz, val, pi, ans;
};
plm qu[400002];

bool cmp(plm a, plm b)
{
    return a.poz < b.poz;
}
bool cmp2(plm a, plm b)
{
    return a.pi < b.pi;
}

int ans[400002], unic[400002], mxx[400002], uq[400002];

void start()
{
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
        cin >> v[i], vl.insert(v[i]);
    for(int i = 1; i <= q; ++i)
        cin >> qu[i].poz >> qu[i].val, qu[i].pi = i, vl.insert(qu[i].val);
    for(set<int> ::iterator it = vl.begin(); it != vl.end(); ++it)
        mp[*it] = ++R;
    for(int i = 1; i <= n; ++i)
        v[i] = mp[v[i]];
    for(int i = 1; i <= q; ++i)
        qu[i].val = mp[qu[i].val];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    start();
    int max_answer = 0;
    for(int i = 1; i <= n; ++i)
    {
        st[i] = compute(v[i] - 1) + 1;
        upd(v[i], st[i]);
        max_answer = max(max_answer, st[i]);
    }
    memset(aib, 0, sizeof(aib));
    for(int i = n; i >= 1; --i)
    {
        dr[i] = compute(R - v[i]) + 1;
        upd(R - v[i] + 1, dr[i]);
        if(st[i] + dr[i] - 1 == max_answer)
        {
            if(uq[st[i]] == 0)
                uq[st[i]] = i;
            else
                uq[st[i]] = -1;
        }
    }
    for(int i = 1; i <= max_answer; ++i)
        if(uq[i] > 0)
            unic[uq[i]] = 1;
    sort(qu+1, qu+q+1, cmp);
    memset(aib, 0, sizeof(aib));
    int aa = 1;
    for(int i = 1; i <= q; ++i)
    {
        while(aa < qu[i].poz)
            upd(v[aa], st[aa]), ++aa;
        qu[i].ans += 1 + compute(qu[i].val - 1);
    }
    memset(aib, 0, sizeof(aib));
    aa = n;
    for(int i = q; i >= 1; --i)
    {
        while(aa > qu[i].poz)
            upd(R - v[aa] + 1, dr[aa]), --aa;
        qu[i].ans += compute(R - qu[i].val);
    }
    sort(qu+1, qu+q+1, cmp2);
    for(int i = 1; i <= q; ++i)
        cout << max(max_answer - unic[qu[i].poz], qu[i].ans) << '\n';
    return 0;
}
