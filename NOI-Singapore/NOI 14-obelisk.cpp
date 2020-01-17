/*
        NOI 14-Obelisk

    This problem is obviously solvable with Dijkstra's algorithm, the only annoying part being the math part behind the distance.

    One can find the distance between the adjacent points using some casework, similar to the one described in the official solution
        (https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/NOI/official)

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

// #define fisier 1

using namespace std;

typedef long long ll;

int k, m;
int sx, sy, ex, ey, sp[100002];
int dx[3] = {-1, 1, 0};
vector<pair<int, int> >gauri[100002], v[100002];
int calc(int x, int y)
{
    if(m == 1)
        return abs(x) + abs(y);
    int ans = (1<<30);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int g = 0; g < 2; g++)
            {
                for(int h = 0; h < 2; h++)
                {
                    int p = abs(x + dx[i] * (m + 1));
                    int q = abs(y + dx[j] * (m + 1));
                    int t1 = p / (m + 1) + (i < 2);
                    int t2 = q / (m + 1) + (j < 2);
                    int cur = t1 * 2 + t2 * 2 + g * 2 + h * 2;
                    p %= (m + 1);
                    q %= (m + 1);
                    if(p)
                    {
                        if(!t2)
                            cur += 2;
                        if(g)
                            cur += m + 1 - p;
                        else
                            cur += p;
                    }
                    if(q)
                    {
                        if(!t1)
                            cur += 2;
                        if(h)
                            cur += m + 1 - q;
                        else
                            cur += q;
                    }
                    ans = min(ans, cur);
                }
            }
        }
    }
    return ans;
}

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int di[100002];
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k >> m;
    cin >> sx >> sy >> ex >> ey;
    gauri[k].push_back({sx, sy});
    gauri[0].push_back({ex, ey});
    for(int i = k-1; i >= 1; --i)
    {
        int nr;
        cin >> nr;
        for(; nr; --nr)
        {
            int xa, ya;
            cin >> xa >> ya;
            gauri[i].pb({xa, ya});
        }
    }
    for(int i = 0; i < k; ++i)
        sp[i+1] = sp[i] + gauri[i].size();
    for(int i = 1; i <= k; i++)
        for(int x = 0; x < gauri[i].size(); x++)
            for(int y = 0; y < gauri[i - 1].size(); y++)
            {
                int dist = calc(gauri[i - 1][y].fi - gauri[i][x].fi, gauri[i - 1][y].se - gauri[i][x].se);
                v[x + sp[i]].push_back({y + sp[i - 1], dist});
            }
    for(int i = 0; i <= 100000; ++i)
        di[i] = (1<<30);
    di[sp[k]] = 0;
    pq.push({0, sp[k]});

    while(!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        if(p.fi > di[p.se])
            continue;
        int nod = p.se;
        for(auto e : v[nod])
            if(di[e.fi] > di[nod] + e.se)
            {
                di[e.fi] = di[nod] + e.se;
                pq.push({di[e.fi], e.fi});
            }
    }
    cout << di[0];
    return 0;
}
