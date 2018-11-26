#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n;
vector<int>v[100002];
int sz[100002];
int coune[100002];
void dfs(int dad, int nod)
{
    bool isLeaf = 1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        isLeaf = 0;
        dfs(nod, vecin);
        sz[nod] += sz[vecin];
    }
    if(isLeaf)
        ++sz[nod];
    coune[sz[nod]]++;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 2; i <= n; ++i)
    {
        int q;
        cin >> q;
        v[q].push_back(i);
        v[i].push_back(q);
    }
    dfs(0, 1);
    int prev_ans = 0;
    int sum = 0;
    for(int i = 1; i <= n; ++i)
    {
        sum += coune[i];
        for(int j = prev_ans + 1; j <= sum; ++j)
            cout << i << " ";
        prev_ans = sum;
    }
    return 0;
}
