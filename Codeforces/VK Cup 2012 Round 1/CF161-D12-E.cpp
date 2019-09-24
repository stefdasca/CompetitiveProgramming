#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int dg(int nr)
{
    if(nr <= 9)
        return 1;
    if(nr <= 99)
        return 2;
    if(nr <= 999)
        return 3;
    if(nr <= 9999)
        return 4;
    return 5;
}
int n;
int nxt[110002];
vector<int>pr;
bool prim(int nr)
{
    if(nr < 2)
        return 0;
    for(int i = 2; i * i <= nr; ++i)
        if(nr % i == 0)
            return 0;
    return 1;
}
int mat[6][6];
int ans = 0;
int pp;
void bkt(int pz, int nr)
{
    if(pz == pp)
    {
        ++ans;
        return;
    }
    int x = nr;
    int d = pp;
    while(d >= pz)
    {
        mat[pz][d] = mat[d][pz] = x%10;
        x /= 10;
        --d;
    }
    int diff = 1;
    for(int i = pz + 1; i <= pp; ++i)
        diff *= 10;
    int nrform = 0;
    for(int i = 1; i <= pp; ++i)
        nrform = nrform * 10 + mat[pz+1][i];
    int number = nrform;
    while(nxt[number] - nrform < diff)
    {
        bkt(pz+1, nxt[number]);
        number = nxt[number];
    }
    x = nr;
    d = pp;
    while(d >= pz)
    {
        mat[pz][d] = mat[d][pz] = 0;
        x /= 10;
        --d;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 109999; i >= 0; --i)
        if(prim(i+1))
            nxt[i] = i+1;
        else
            nxt[i] = nxt[i+1];
    for(; t; --t)
    {
        int nr;
        cin >> nr;
        pp = dg(nr);
        ans = 0;
        memset(mat, 0, sizeof(mat));
        bkt(1, nr);
        cout << ans << '\n';
    }
    return 0;
}
