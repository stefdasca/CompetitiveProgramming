/*
            POI 06-Sophie

    editorial: https://github.com/thecodingwizard/competitive-programming/blob/master/POI/POI06-Sophie.cpp

    My implementation is based on those observations mentioned in the source code above.

*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

using namespace std;

typedef long long ll;

int n, k, m, sz;

bool scos[1000002];

vector<int> v[1000002];

int rms[1000002], cnt;

int ok[202], id[1000002];
bool scos2[202];

int bkt(int pos, int start, int nivel)
{
    if(nivel < 0)
        return -1;
    if(pos > sz)
        return 0;
    int real_pos = ok[pos];
    if(!scos2[pos])
    {
        for(int i = start; i < v[real_pos].size(); ++i)
        {
            int sf = v[real_pos][i];
            if(scos2[id[sf]])
                continue;

            bool orig_scos2[202];
            memcpy(orig_scos2, scos2, sizeof(orig_scos2));
            scos2[pos] = 1;
            int c1 = bkt(pos + 1, 0, nivel - 1);

            bool sol_1[202];
            memcpy(sol_1, scos2, sizeof(sol_1));
            memcpy(scos2, orig_scos2, sizeof(scos2));
            scos2[id[sf]] = 1;
            int c2 = bkt(pos, i + 1, nivel - 1);

            if(c1 > c2)
            {
                c2 = c1;
                memcpy(scos2, sol_1, sizeof(scos2));
            }
            return c2;
        }
    }
    int res = bkt(pos + 1, 0, nivel);
    if(res >= 0 && !scos2[pos])
        ++res;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    cin >> m;
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    for(int i = 1; i <= n; ++i)
    {
        sort(v[i].begin(), v[i].end());
        v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
    }
    int rem = n - k;
    int tot_scos = 0;
    for(int i = 1; i <= n; ++i)
        if(v[i].size() > rem)
            scos[i] = 1, tot_scos++;
    for(int i = 1; i <= n; ++i)
    {
        if(scos[i])
            continue;
        for(int j = 0; j < v[i].size(); ++j)
        {
            int vecin = v[i][j];
            if(scos[vecin])
            {
                swap(v[i][j], v[i].back());
                v[i].pop_back();
                --j;
            }
        }
        if(v[i].size() > 0)
        {
            ok[++sz] = i;
            id[i] = sz;
            if(sz > 1LL * rem * rem * 2)
            {
                cout << "NIE\n";
                return 0;
            }
        }
    }
    rem -= tot_scos;
    bkt(1, 0, rem);
    for(int i = 1; i <= sz; ++i)
        if(scos2[i])
            scos[ok[i]] = 1;
    int ramas = n;
    for(int i = 1; i <= n; ++i)
        if(scos[i])
            --ramas;
    if(ramas < k)
    {
        cout << "NIE\n";
        return 0;
    }
    cout << ramas << '\n';
    for(int i = 1; i <= n; ++i)
        if(!scos[i])
            cout << i << " ";
    return 0;
}
