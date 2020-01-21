/*
            POI 13-Polarization

    It is obvious that the min answer is n-1(just direct edges from the nodes with even depth to nodes with odd depth)

    For the max answer, one can observe that it's optimal to fix the root at a node such that we can split it in two sets of subtrees which
have the smallest possible difference in size.

    This works because the answer is equal to the sum of the answers for each subtree, and we add the product of the size of the smaller subtree + 1,
multiplied with n - (size of the smaller subtree + 1), which is far bigger than the possible sum of the answers for each subtree.

    Knowing this observation, now we can run knapsack to find a subset with the desired sum. Normal knapsack will give us TLE, so we need
to use one optimization: if we have many items of same value, we compress them in log2 items with the same sum(1, 2, 4, ...
multiples of item) until we're left with some difference smaller than the current step.

    Also, if we know that one subtree is bigger than n/2, we don't have to run knapsack, since it's optimal to group all other subtrees in one set
and the big subtree in the other set.

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

int n;
ll maxans, qt[250002];

int sts[250002];

vector<int> v[250002];

void dfs(int dad, int nod)
{
    sts[nod] = 1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        dfs(nod, vecin);
        qt[nod] = qt[nod] + qt[vecin] + sts[vecin];
        sts[nod] += sts[vecin];
    }
}
bool ruk[250002];
void dfs2(int dad, int nod, ll val)
{
    maxans = max(maxans, qt[nod]);
    ll prd = val - (n - sts[nod]);
    int mxx = (n - sts[nod]);
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        mxx = max(mxx, sts[vecin]);
        prd += qt[vecin];
    }
    if(mxx > n/2)
        prd += 1LL * mxx * (n - mxx);
    else
    {
        vector<int> v2;
        for(int i = 0; i < v[nod].size(); ++i)
        {
            int vecin = v[nod][i];
            if(vecin == dad)
                continue;
            v2.pb(sts[vecin]);
        }
        if(n - sts[nod])
            v2.pb(n - sts[nod]);
        sort(v2.begin(), v2.end());
        memset(ruk, 0, sizeof(ruk));
        ruk[0] = 1;
        int mxs = 0;
        for(int i = 0; i < v2.size(); )
        {
            int j = i;
            while(j < v2.size() && v2[j] == v2[i])
                ++j;
            int dif = j - i;
            int val = v2[i];
            int put = 1;
            while(dif)
            {
                int obj = 0;
                if(dif >= put)
                    obj = val * put, dif -= put;
                else
                    obj = val * dif, dif = 0;
                for(int j = mxs; j >= 0; --j)
                    if(ruk[j])
                        ruk[j + obj] = 1;
                mxs += obj;
                mxs = min(mxs, (n-1) / 2);
                put <<= 1;
            }
            i = j;
        }
        ll mxi = 0;
        for(int i = 0; i <= (n-1)/2; ++i)
            if(ruk[i])
                mxi = i;
        prd += (mxi + 1) * (n - 1 - mxi);
        prd += mxi;
    }
    maxans = max(maxans, prd);
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        dfs2(nod, vecin, val + n - sts[vecin] + qt[nod] - qt[vecin] - sts[vecin]);
    }
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

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
    dfs2(0, 1, 0);
    cout << n-1 << " " << maxans << '\n';
    return 0;
}
