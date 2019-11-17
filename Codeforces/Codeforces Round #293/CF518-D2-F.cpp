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

int n, m;

char a[2002][2002], b[2002][2002];

bool oki[2002][2002], oki2[2002][2002];

int sumgg[2002][2002], sumgg2[2002][2002];

int prf[2002][2002];

vector<int> pzbd[2002];


ll solve2()
{
    ll sol2 = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            sumgg[i][j] = sumgg[i][j-1] + oki[i][j];
            sumgg2[i][j] = sumgg2[i][j-1] + oki2[i][j];
            prf[i][j] = prf[i][j-1] + (a[i][j] == '#');
            if(a[i][j] == '#')
                pzbd[i].pb(j);
        }
    for(int startcol = 2; startcol < m; ++startcol)
    {
        for(int j = 1; j < n; ++j)
        {
            if(a[j][startcol] == '#')
                break;
            if(j >= 2)
            {
                int va = prf[j][startcol];
                int st = startcol;
                int dr = m-1;
                int anss = startcol;
                if(va == prf[j][m-1])
                    anss = m-1;
                else
                    anss = pzbd[j][va];
                if(anss >= startcol + 2)
                    sol2 += sumgg2[j][anss] - sumgg2[j][startcol + 1];
                if(anss >= startcol + 1)
                    sol2 += sumgg[j][anss] - sumgg[j][startcol];
            }
            if(j >= 2)
            {
                int va = prf[j][startcol];
                int st = 2;
                int dr = startcol;
                int anss = startcol;
                if(va == prf[j][2])
                    anss = 2;
                else
                    anss = pzbd[j][va - 1];
                if(anss <= startcol - 2)
                    sol2 += sumgg2[j][startcol - 2] - sumgg2[j][anss - 1];
                if(anss <= startcol - 1)
                    sol2 += sumgg[j][startcol - 1] - sumgg[j][anss - 1];
            }
        }
        for(int j = n; j >= 2; --j)
        {
            if(a[j][startcol] == '#')
                break;
            if(j <= n-1)
            {
                int va = prf[j][startcol];
                int st = startcol;
                int dr = m-1;
                int anss = startcol;
                if(va == prf[j][m-1])
                    anss = m-1;
                else
                    anss = pzbd[j][va];
                if(anss >= startcol + 2)
                    sol2 += sumgg[j][anss] - sumgg[j][startcol + 1];
                if(anss >= startcol + 1)
                    sol2 += sumgg2[j][anss] - sumgg2[j][startcol];
            }
            if(j <= n-1)
            {
                int va = prf[j][startcol];
                int st = 2;
                int dr = startcol;
                int anss = startcol;
                if(va == prf[j][2])
                    anss = 2;
                else
                    anss = pzbd[j][va - 1];
                if(anss <= startcol - 2)
                    sol2 += sumgg[j][startcol - 2] - sumgg[j][anss - 1];
                if(anss <= startcol - 1)
                    sol2 += sumgg2[j][startcol - 1] - sumgg2[j][anss - 1];
            }
        }
    }
    return sol2;
}
ll solve()
{
    ll sol = 0;
    // 0 turns
    for(int i = 2; i < n; ++i)
    {
        bool ok = 1;
        for(int j = 1; j <= m; ++j)
            if(a[i][j] == '#')
                ok = 0;
        sol += ok;
    }
    for(int i = 2; i < m; ++i)
    {
        bool ok = 1;
        for(int j = 1; j <= n; ++j)
            if(a[j][i] == '#')
                ok = 0;
        sol += ok;
    }
    // 1 turn
    for(int i = n; i >= 1; --i)
        for(int j = m; j >= 1; --j)
            if(a[i][j] == '.')
            {
                if(i == n)
                    oki[i][j] = 1;
                else
                    oki[i][j] |= oki[i+1][j];
            }
            else
                oki[i][j] = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(a[i][j] == '.')
            {
                if(i == 1)
                    oki2[i][j] = 1;
                else
                    oki2[i][j] |= oki2[i-1][j];
            }
            else
                oki2[i][j] = 0;
    for(int i = 2; i < n; ++i)
    {
        for(int j = 1; j < m; ++j)
        {
            if(a[i][j] == '#')
                break;
            if(j >= 2)
                sol += oki[i][j], sol += oki2[i][j];
        }
        for(int j = m; j > 1; --j)
        {
            if(a[i][j] == '#')
                break;
            if(j <= m-1)
                sol += oki[i][j], sol += oki2[i][j];
        }
    }
    ll sol2 = solve2();
    // 2 turns
    for(int i = 1; i <= n; ++i)
        pzbd[i].clear();
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
            b[i][j] = a[j][i];
    swap(n, m);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            a[i][j] = b[i][j];
    memset(oki, 0, sizeof(oki));
    memset(oki2, 0, sizeof(oki2));
    memset(sumgg, 0, sizeof(sumgg));
    memset(sumgg2, 0, sizeof(sumgg2));
    memset(prf, 0, sizeof(prf));
    for(int i = n; i >= 1; --i)
        for(int j = m; j >= 1; --j)
            if(a[i][j] == '.')
            {
                if(i == n)
                    oki[i][j] = 1;
                else
                    oki[i][j] |= oki[i+1][j];
            }
            else
                oki[i][j] = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(a[i][j] == '.')
            {
                if(i == 1)
                    oki2[i][j] = 1;
                else
                    oki2[i][j] |= oki2[i-1][j];
            }
            else
                oki2[i][j] = 0;
    sol2 += solve2();
    sol += sol2 / 2;
    return sol;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> (a[i] + 1);
    cout << solve();
    return 0;
}
