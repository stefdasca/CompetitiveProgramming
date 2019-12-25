/*
        JOI 19-GrowingVegetable

    Let's define a dp recurrence: dp[x][i][j][k] = min cost if we filled the first x positions with i letters R, j letters G and k letters Y.
The transitions are quite easy, you check what happens when you add a new R, a new G or a new Y(in case you can still add such letter)

    This recurrence has O(n^4) states but O(n^3) time, which doesn't fit in memory limit. However, we can observe that we don't need the last state,
since we can compute the value of k based on the values of x, i and j, and this is enough to get 100.

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

int n;
string s;
vector<int> v[4];
int dp[402][402][402][3];
bool viz[402][402][402][3];
int sp[5][402];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; ++i)
    {
        if(s[i] == 'R')
            v[1].pb(i), sp[1][i]++;
        if(s[i] == 'G')
            v[2].pb(i), sp[2][i]++;
        if(s[i] == 'Y')
            v[3].pb(i), sp[3][i]++;
        if(i)
            for(int j = 1; j <= 3; ++j)
                sp[j][i] += sp[j][i-1];
    }
    viz[0][0][0][0] = viz[0][0][0][1] = viz[0][0][0][2] = 1;
    int mn = (1<<30);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j <= i; ++j)
            for(int k = 0; k <= i; ++k)
                for(int lst = 0; lst <= 2; ++lst)
                {
                    if(!viz[i][j][k][lst])
                        continue;
                    int chR = j;
                    int chG = k;
                    int chY = i - j - k;
                    // next = rosu
                    if(chR < v[1].size() && lst != 0)
                    {
                        int realpos = v[1][chR];
                        if(chG > 0 && v[2][chG-1] > realpos)
                            realpos += sp[2][v[2][chG-1]] - sp[2][realpos];
                        if(chY > 0 && v[3][chY-1] > realpos)
                            realpos += sp[3][v[3][chY-1]] - sp[3][realpos];
                        if(!viz[i+1][j+1][k][0] || dp[i+1][j+1][k][0] > dp[i][j][k][lst] + max(0, realpos - i))
                        {
                            dp[i+1][j+1][k][0] = dp[i][j][k][lst] + max(0, realpos - i);
                            viz[i+1][j+1][k][0] = 1;
                        }
                    }
                    if(chG < v[2].size() && lst != 1)
                    {
                        int realpos = v[2][chG];
                        if(chR > 0 && v[1][chR-1] > realpos)
                            realpos += sp[1][v[1][chR-1]] - sp[1][realpos];
                        if(chY > 0 && v[3][chY-1] > realpos)
                            realpos += sp[3][v[3][chY-1]] - sp[3][realpos];
                        if(!viz[i+1][j][k+1][1] || dp[i+1][j][k+1][1] > dp[i][j][k][lst] + max(0, realpos - i))
                        {
                            dp[i+1][j][k+1][1] = dp[i][j][k][lst] + max(0, realpos - i);
                            viz[i+1][j][k+1][1] = 1;
                        }
                    }
                    if(chY < v[3].size() && lst != 2)
                    {
                        int realpos = v[3][chY];
                        if(chR > 0 && v[1][chR-1] > realpos)
                            realpos += sp[1][v[1][chR-1]] - sp[1][realpos];
                        if(chG > 0 && v[2][chG-1] > realpos)
                            realpos += sp[2][v[2][chG-1]] - sp[2][realpos];
                        if(!viz[i+1][j][k][2] || dp[i+1][j][k][2] > dp[i][j][k][lst] + max(0, realpos - i))
                        {
                            dp[i+1][j][k][2] = dp[i][j][k][lst] + max(0, realpos - i);
                            viz[i+1][j][k][2] = 1;
                        }
                    }
                }
    }
    for(int i = 0; i <= 2; ++i)
        if(viz[n][(int)v[1].size()][(int)v[2].size()][i])
            mn = min(mn, dp[n][(int)v[1].size()][(int)v[2].size()][i]);
    if(mn == (1<<30))
        mn = -1;
    cout << mn;
    return 0;
}
