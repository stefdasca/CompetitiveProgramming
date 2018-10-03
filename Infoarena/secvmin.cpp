#include<bits/stdc++.h>
using namespace std;
ifstream f("secvmin.in");
ofstream g("secvmin.out");
int n,m;
int v[100002],v2[100002];
int frq[1000002];
vector<int>lis[100002];
int sz[100002],solprec[100002];
int sol=1e9;
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        f>>v[i];
    for(int i=1;i<=m;++i)
        f>>v2[i],frq[v2[i]]=i;
    for(int i=1;i<=n;++i)
        if(frq[v[i]])
            lis[frq[v[i]]].push_back(i),++sz[frq[v[i]]];
    for(int i=0;i<sz[1] && lis[1][i]+m-1<=n;++i)
    {
        int cpst=lis[1][i];
        bool ok=1;
        if(i+1<sz[1] && (solprec[2]<sz[2] && lis[1][i+1]<lis[2][solprec[2]]))
            continue;
        for(int j=2;j<=m;++j)
        {
            int st=solprec[j];
            int e=sz[j]-1;
            ok=0;
            while(st<=e)
            {
                int mid=(st+e)/2;
                if(lis[j][mid]>cpst && (!mid || lis[j][mid-1]<cpst))
                {
                    ok=1;
                    cpst=lis[j][mid];
                    solprec[j]=mid;
                    break;
                }
                else
                    if(lis[j][mid]<cpst)
                        st=mid+1;
                    else
                        e=mid-1;
            }
            if(ok==0 || cpst-lis[1][i]+1>sol)
                break;
        }
        if(ok==1)
            sol=min(sol,cpst-lis[1][i]+1);
    }
    if(sol==1e9)
        g<<-1;
    else
        g<<sol;
    return 0;
}
