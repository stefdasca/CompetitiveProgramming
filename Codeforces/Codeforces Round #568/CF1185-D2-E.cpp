#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int t, n, m;
char a[2002][2002];
bool ok;
int lgn;
struct ans
{
    int La, Ca;
    int Lb, Cb;
};
ans v[32];
vector<pair<int, int> >orz[28];
int frq[2002], frq2[2002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(; t; --t)
    {
        cin >> n >> m;
        for(int i = 1; i <= n; ++i)
            cin >> (a[i] + 1);
        for(int i = 0; i <= 26; ++i)
            orz[i].clear();
        int Lmax = -1, Cmax = -1;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                if(a[i][j] >= 'a' && a[i][j] <= 'z')
                {
                    if(Lmax == -1)
                        Lmax = i, Cmax = j;
                    else
                        if(a[i][j] >= a[Lmax][Cmax])
                            Lmax = i, Cmax = j;
                    orz[a[i][j] - 'a'].push_back({i, j});
                }
        if(Lmax == -1)
        {
            cout << "YES\n";
            cout << 0 << '\n';
            continue;
        }
        int lstok = (a[Lmax][Cmax] - 'a');
        bool rau = 0;
        for(int i = 0; i <= (a[Lmax][Cmax] - 'a'); ++i)
        {
            memset(frq, 0, sizeof(frq));
            memset(frq2, 0, sizeof(frq2));
            for(int j = 0; j < orz[i].size(); ++j)
            {
                frq[orz[i][j].first]++;
                frq2[orz[i][j].second]++;
            }
            int nrx = 0, nry = 0;
            for(int L = 1; L <= n; ++L)
                if(frq[L])
                    ++nrx;
            for(int C = 1; C <= m; ++C)
                if(frq2[C])
                    ++nry;
            if(!orz[i].size())
            {
                v[i] = {Lmax, Cmax, Lmax, Cmax};
                continue;
            }
            if(nrx > 1 && nry > 1)
            {
                rau = 1;
                break;
            }
            int mn = 10355;
            int mx = -41526;
            int fr = 0;
            if(nrx > 1)
            {
                for(int j = 0; j < orz[i].size(); ++j)
                {
                    mn = min(mn, orz[i][j].first);
                    mx = max(mx, orz[i][j].first);
                    fr = orz[i][j].second;
                }
                for(int j = mn; j <= mx; ++j)
                {
                    if(a[j][fr] == '.' || a[j][fr] < a[mn][fr])
                        rau = 1;
                }
                v[i].La = mn;
                v[i].Lb = mx;
                v[i].Ca = fr;
                v[i].Cb = fr;
            }
            else
            {
                for(int j = 0; j < orz[i].size(); ++j)
                {
                    mn = min(mn, orz[i][j].second);
                    mx = max(mx, orz[i][j].second);
                    fr = orz[i][j].first;
                }
                for(int j = mn; j <= mx; ++j)
                {
                    if(a[fr][j] == '.' || a[fr][j] < a[fr][mn])
                        rau = 1;
                }
                v[i].Ca = mn;
                v[i].Cb = mx;
                v[i].La = fr;
                v[i].Lb = fr;
            }
        }
        if(rau)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        cout << lstok + 1 << '\n';
        for(int i = 0; i <= lstok; ++i)
            cout << v[i].La << " " << v[i].Ca << " " << v[i].Lb << " " << v[i].Cb << '\n';
    }
    return 0;
}

