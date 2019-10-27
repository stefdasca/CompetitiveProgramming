/// the ginger empire has risen

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
long long n, a[12][12];
long long dp[12][12][4];
long long rep[12][12][4];
bool viz[12][12][4];
struct v
{
    int L, C;
};
v pp[102];
struct plm
{
    int L, C, tip, stp, rep;
};
bool verif(int a, int b, int c, int d, int tip)
{
    if(tip == 1)
    {
        if(a == c || b == d)
            return 1;
        return 0;
    }
    if(tip == 2)
    {
        if(abs(a-c) == abs(b-d))
            return 1;
        return 0;
    }
    int aa = abs(a-c);
    int bb = abs(b-d);
    if(aa == 2 && bb == 1)
        return 1;
    if(aa == 1 && bb == 2)
        return 1;
    return 0;
}
void Lee()
{
    deque<plm>d;
    for(int i = 1; i < n * n; ++i)
    {
        d.push_back({pp[i].L, pp[i].C, 1, dp[pp[i].L][pp[i].C][1] , rep[pp[i].L][pp[i].C][1]});
        d.push_back({pp[i].L, pp[i].C, 2, dp[pp[i].L][pp[i].C][2] , rep[pp[i].L][pp[i].C][2]});
        d.push_back({pp[i].L, pp[i].C, 3, dp[pp[i].L][pp[i].C][3] , rep[pp[i].L][pp[i].C][3]});
        for(int R = 1; R <= n; ++R)
            for(int O = 1; O <= n; ++O)
            {
                if(R != pp[i].L || O != pp[i].C)
                    for(int S = 1; S <= 3; ++S)
                        viz[R][O][S] = 0, dp[R][O][S] = 0, rep[R][O][S] = 0;
            }
        viz[pp[i].L][pp[i].C][1] = 1;
        viz[pp[i].L][pp[i].C][2] = 1;
        viz[pp[i].L][pp[i].C][3] = 1;
        while(!d.empty())
        {
            plm q = d[0];
            d.pop_front();
            for(int i = 1; i <= 3; ++i)
            {
                if(i == q.tip)
                    continue;
                if((!viz[q.L][q.C][i] || (dp[q.L][q.C][i] > dp[q.L][q.C][q.tip] + 1) || (dp[q.L][q.C][i] == dp[q.L][q.C][q.tip] + 1 && rep[q.L][q.C][q.tip] + 1 < rep[q.L][q.C][i])))
                {
                    viz[q.L][q.C][i] = 1;
                    dp[q.L][q.C][i] = dp[q.L][q.C][q.tip] + 1;
                    rep[q.L][q.C][i] = rep[q.L][q.C][q.tip] + 1;
                    d.push_back({q.L, q.C, i, dp[q.L][q.C][i], rep[q.L][q.C][i]});
                }
            }
            for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= n; ++j)
                {
                    if(verif(i, j, q.L, q.C, q.tip))
                    {
                        if(!viz[i][j][q.tip] || dp[i][j][q.tip] > dp[q.L][q.C][q.tip] + 1 || (dp[i][j][q.tip] == dp[q.L][q.C][q.tip] + 1 && rep[q.L][q.C][q.tip] < rep[i][j][q.tip]))
                        {
                            viz[i][j][q.tip] = 1;
                            dp[i][j][q.tip] = dp[q.L][q.C][q.tip] + 1;
                            rep[i][j][q.tip] = rep[q.L][q.C][q.tip];
                            d.push_back({i, j, q.tip, dp[i][j][q.tip], rep[i][j][q.tip]});
                        }
                    }
                }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
            pp[a[i][j]] = {i, j};
        }
    Lee();
    long long sol = (1<<30);
    long long repp = (1<<30);
    for(int i = 1; i <= 3; ++i)
    {
        if(dp[pp[n*n].L][pp[n*n].C][i] < sol)
            sol = dp[pp[n*n].L][pp[n*n].C][i], repp = rep[pp[n*n].L][pp[n*n].C][i];
        else
            if(dp[pp[n*n].L][pp[n*n].C][i] == sol && rep[pp[n*n].L][pp[n*n].C][i] < repp)
                repp = rep[pp[n*n].L][pp[n*n].C][i];
    }
    cout << sol << " " << repp << '\n';
    return 0;
}
