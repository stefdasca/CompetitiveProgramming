/*
        APIO 10-Patrol

    detailed solution: http://apio-olympiad.org/2010/solutions.pdf

    Basically,

        * dp[1][i] - the best path in i's subtree, basically diameter of the tree(this solves the K = 1 testcases)
        * dphalf[i] - the best path + path which ends at node i
        * dp[2][i] - the two best paths in i's subtree

    These dp recurrences can be computed using DFS and casework, based on how many sons the current node has.

    Basically, we can create a path if we have at least one son(otherwise the path length will be 0)

    We can create a 1+half path if we have some son with a path or 3 sons.

    We can create two paths if we have 4 sons, 2 paths or 1 path and two sons.

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

int n, k, lvl[100002], maxlvl[100002];

vector<int> v[100002];

int dp[3][100002], dphalf[100002];
void dfs(int dad, int nod)
{
    maxlvl[nod] = lvl[nod];
    vector<pair<int, int> >cur, two;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        lvl[vecin] = 1 + lvl[nod];
        dfs(nod, vecin);

        maxlvl[nod] = max(maxlvl[nod], maxlvl[vecin]);
        dp[1][nod] = max(dp[1][nod], dp[1][vecin]);
        dphalf[nod] = max(dphalf[nod], dphalf[vecin]);
        dp[2][nod] = max(dp[2][nod], dp[2][vecin]);

        cur.pb({maxlvl[vecin], vecin});
		two.pb({dp[1][vecin], vecin});
    }
    sort(cur.begin(), cur.end(), greater<pair<int, int> >());
	sort(two.begin(), two.end(), greater<pair<int, int> >());
    if(cur.size() >= 2)
    {
        dp[1][nod] = max(dp[1][nod], cur[0].fi + cur[1].fi - 2 * lvl[nod]);
        dp[2][nod] = max(dp[2][nod], two[0].fi + two[1].fi);
        for(int i = 0; i < v[nod].size(); ++i)
        {
            int vecin = v[nod][i];
            if(vecin == dad)
                continue;
            int addhalf = (vecin == cur[0].se ? cur[1].fi : cur[0].fi);
            dphalf[nod] = max(dphalf[nod], dp[1][vecin] + addhalf);
            dp[2][nod] = max(dp[2][nod], dphalf[vecin] + addhalf - 2 * lvl[nod]);
            if(cur.size() >= 3)
            {
                int tba = cur[0].fi + cur[1].fi;
                if(vecin == cur[0].se)
                    tba += cur[2].fi - cur[0].fi;
                if(vecin == cur[1].se)
                    tba += cur[2].fi - cur[1].fi;
                dp[2][nod] = max(dp[2][nod], tba + dp[1][vecin] - 2 * lvl[nod]);
            }
        }
    }
	if(cur.size() >= 4)
        dp[2][nod] = max(dp[2][nod], cur[0].fi + cur[1].fi + cur[2].fi + cur[3].fi - 4 * lvl[nod]);
    if(cur.size() >= 3)
        dphalf[nod] = max(dphalf[nod], cur[0].fi + cur[1].fi + cur[2].fi - 2 * lvl[nod]);
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(0, 1);
    cout << 2 * (n - 1) + k - (k == 1 ? dp[1][1] : dp[2][1]);
    return 0;
}
