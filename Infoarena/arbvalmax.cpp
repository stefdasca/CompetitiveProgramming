#include<bits/stdc++.h>
#define maxx 300002
using namespace std;
ifstream f("arbvalmax.in");
ofstream g("arbvalmax.out");
int n,val[maxx],m;
vector<int>v[maxx];
int dp1[maxx],dp2[maxx],bestson[maxx][3],who[maxx];
void dfs1(int nod)
{
    for (int i=0;i<v[nod].size();++i)
    {
        int vecin=v[nod][i];
        dfs1(vecin);
        int valuetoupdate = max(bestson[vecin][1] , val[vecin]);
        if (valuetoupdate > bestson[nod][1])
        {
            bestson[nod][2] = bestson[nod][1];
            bestson[nod][1] = valuetoupdate;
            if(valuetoupdate == bestson[vecin][1])
                who[nod]=who[vecin];
            else
                who[nod]=vecin;
            continue;
        }
        bestson[nod][2] = max(bestson[nod][2] , valuetoupdate);
    }
}
inline void dfs2(int nod)
{
    for (int i=0;i<v[nod].size();++i)
    {
        int vecin=v[nod][i];
        dp1[vecin] = max(dp1[nod] , (who[nod] == vecin || who[nod] == who[vecin] ? bestson[nod][2] : bestson[nod][1]));
        dp2[vecin] = max(dp2[nod] , max(val[nod] , (who[nod] == vecin || who[nod] == who[vecin] ? bestson[nod][2] : bestson[nod][1])));
        dfs2(vecin);
    }
}
int main()
{
    f>>n>>m;
    for(int i=2;i<=n;++i)
    {
        int nr;
        f>>nr;
        v[nr].push_back(i);
    }
    for(int i=1;i<=n;++i)
        f>>val[i];
    dfs1(1);
    dfs2(1);
    for(int i=1;i<=m;++i)
    {
        int x,y;
        f>>x>>y;
        int maxi=max(bestson[y][1],max(dp2[x],dp1[y]));
        g<<maxi<<'\n';
    }
    return 0;
}
