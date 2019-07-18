/*
        COCI 16-uzastopni

    We can solve this task using dp on tree. Let's say we computed the possible sets of numbers for each of the sons of the current node.
Therefore, we can merge the intervals by iterating on the left end of a possible interval. This solution has complexity
O(N * K^3) but we can optimize it by using bitset.

*/
#include<bits/stdc++.h>
using namespace std;
int n, val[10002];
vector<int> v[10002], q[112];
bitset<112>s[10002][112];
vector<pair<int, int> >r[10002];
void dfs(int nod)
{
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        dfs(vecin);
    }
    for(int i = 0; i < 101; ++i)
        q[i].clear();
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int x = v[nod][i];
        for(int j = 0; j < r[x].size(); ++j)
        {
            pair<int, int> ox = r[x][j];
            q[ox.first].push_back(ox.second);
        }
    }
    for(int i = 102; i >= 1; --i)
    {
        if(i == val[nod])
        {
            s[nod][i] |= s[nod][i + 1];
            s[nod][i].set(i);
        }
        else
        {
            for(int orz = 0; orz < q[i].size(); orz++)
            {
                int mx = q[i][orz];
                if(mx < val[nod] || i > val[nod])
                {
                  s[nod][i] |= s[nod][mx + 1];
                  s[nod][i].set(mx);
                }
            }
        }
        if(val[nod] >= i)
            for (int hi = 102; hi >= i; --hi)
                if (s[nod][i].test(hi) && val[nod] <= hi)
                    r[nod].emplace_back(i, hi);
    }
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> val[i];
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    dfs(1);
    cout << r[1].size() << '\n';
    return 0;
}
