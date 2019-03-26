/*
                                        Baltic 12-Melody

    Firstly, create the graph where there is edge between i and j if one can get from note i to note j.
    Then, at step i, we will sort the notes based on dp[i-1][note], in order to reduce the number of states which have to be visited.
    When we find an unvisited state, we update it and we end the algorithm for that step when we visited all the notes(we will deal with
the favorite note separately)

    We will get O(n^2 * l + L * n log n)

*/
#include<bits/stdc++.h>
using namespace std;
int n, l, s;
int gg[102][102];
vector<int>gr[102];
struct str
{
    string s;
};
str v[102];
int q, fav[100002];
int dp[100002][102];
int wh[100002][102];
bool viz[100002][102];
int pz, vs[102];
bool cmp(int a, int b)
{
    return dp[pz][a] < dp[pz][b];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> l >> s;
    for(int i = 1; i <= n; ++i)
        cin >> v[i].s;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            int dd = 0;
            for(int z = 0; z < l; ++z)
                if(v[i].s[z] != v[j].s[z])
                    ++dd;
            if(dd <= s)
                gg[i][j] = 1, gr[i].push_back(j);
        }
    cin >> q;
    for(int i = 1; i <= q; ++i)
        cin >> fav[i];
    for(int i = 1; i <= n; ++i)
        dp[1][i] = (i != fav[1]);
    for(int i = 2; i <= q; ++i)
    {
        int lft = n;
        pz = i-1;
        for(int j = 1; j <= n; ++j)
            vs[j] = j;
        sort(vs + 1, vs + n + 1, cmp);
        for(int j = 1; j <= n; ++j)
            if(gg[j][fav[i]])
                if(!viz[i][fav[i]] || (dp[i-1][j] < dp[i][fav[i]]))
                {
                    dp[i][fav[i]] = dp[i-1][j];
                    wh[i][fav[i]] = j;
                    viz[i][fav[i]] = 1;
                }
        int po = 0;
        for(int j = 1; j <= n; ++j)
        {
            int nv = vs[j];
            for(int pos = 0; pos < gr[nv].size(); ++pos)
            {
                int z = gr[nv][pos];
                if(z == fav[i])
                    continue;
                if(!viz[i][z])
                {
                    dp[i][z] = dp[i-1][nv] + 1;
                    wh[i][z] = nv;
                    if(!viz[i][z])
                    {
                        viz[i][z] = 1;
                        ++po;
                        if(po >= n-1)
                        {
                            j = n+1;
                            break;
                        }
                    }
                }
            }
        }
    }
    int mn = (1<<30);
    int cn = -1;
    for(int j = 1; j <= n; ++j)
        if(viz[q][j] && dp[q][j] < mn)
            mn = dp[q][j], cn = j;
    cout << mn << '\n';
    vector<int>ans;
    int pp = q;
    while(pp)
    {
        ans.push_back(cn);
        cn = wh[pp][cn];
        --pp;
    }
    while(!ans.empty())
        cout << ans.back() << " ", ans.pop_back();
    return 0;
}
