#include<bits/stdc++.h>
using namespace std;
ifstream f("arborest.in");
ofstream g("arborest.out");
int dp[100002], n, k, mv, sol, mx[100002], mxx;
vector<int>v[100002];
void dfs(int nod, int mx)
{
    int maxx=-1;
    for(int i=0;i<v[nod].size();++i)
    {
        int vecin=v[nod][i];
        dfs(vecin, mx);
        if(dp[vecin] == mx-1 && nod != 1)
            dp[vecin] = 0, ++mv;
        else
            maxx=max(maxx, dp[vecin]);
    }
    dp[nod]=maxx+1;
}
int gg(int mx)
{
    mv=0;
    memset(dp, 0, sizeof(dp));
    dfs(1, mx);
    if(mv<=k)
        return 1;
    return 0;
}
int main()
{
    f >> n >> k;
    for(int i=2;i<=n;++i)
    {
        int nr;
        f>>nr;
        v[nr].push_back(i);
        mx[i]=mx[nr]+1;
        mxx=max(mxx, mx[i]);
    }
    int b=1;
    int e=mxx;
    while(b<=e)
    {
        int mid=(b+e)/2;
        if(gg(mid))
            sol=mid, e=mid-1;
        else
            b=mid+1;
    }
    g<<sol;
    return 0;
}
