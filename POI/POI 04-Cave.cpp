/*
                POI 04-Cave

    Let's find the answer using a dfs from node 1, which will be the root of the tree.

    For a certain node, we can find out the number of operations necessary to find the treasure node
if we consider only the subtree of node using the array S.

    S[i][j] = number of nodes in subtreee of i such that we can start from such that we can get answer equal to j.

    In order to find the answer, we will find the biggest value x such that S[i][x] is at least 2, and from that value,
we will add 1 as long as S[i][x] is positive(we can get answer x so Hansel will seek to improve his answer).

    After we found the required answer for our node, we will discard the lower possible answers.

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

#ifdef fisier
    ifstream f("input.in");
    ofstream g("output.out");
#endif

using namespace std;

typedef long long ll;

int n, sol[50002];
vector<int> v[50002], S[50002];

void dfs(int dad, int nod)
{
    for(int i = 0; i <= 25; ++i)
        S[nod].pb(0);
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        dfs(nod, vecin);
        for(int z = 0; z < S[vecin].size(); ++z)
            if(S[vecin][z] > 0)
                ++S[nod][z];
    }
    int m = S[nod].size() - 1;
    while(m >= 0 && S[nod][m] < 2)
        --m;
    sol[nod] = m + 1;
    while(S[nod][sol[nod]] > 0)
        ++sol[nod];
    for(int i = 0; i < sol[nod]; ++i)
        S[nod][i] = 0;
    S[nod][sol[nod]] = 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(0, 1);
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        if(sol[i] > ans)
            ans = sol[i];
    cout << ans;
    return 0;
}
