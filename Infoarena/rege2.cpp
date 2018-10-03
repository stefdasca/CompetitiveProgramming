#include<bits/stdc++.h>
using namespace std;
ifstream f("rege2.in");
ofstream g("rege2.out");
int t,n,s,mini;
vector<pair<int,int> >v[100002];
void dfs1(int dad, int nod, int rm)
{
    for(int i=0;i<v[nod].size();++i)
    {
        int vecin=v[nod][i].first;
        if(vecin==dad)
            continue;
        if(!rm)
            ++mini;
        else
            --rm;
        dfs1(nod, vecin, 1);
    }
}
int nec=0;
int sum[100002];
void dfs2(int dad, int nod, int maxx)
{
    int mini=maxx+1;
    int ns=0;
    for(int i=0;i<v[nod].size();++i)
    {
        int vecin=v[nod][i].first;
        int rr=v[nod][i].second;
        if(vecin==dad)
            continue;
        dfs2(nod, vecin, maxx);
        if(sum[vecin]+rr>maxx)
        {
            ++nec;
            sum[vecin]=rr;
        }
        else
            sum[vecin]+=rr;
        mini=min(mini,sum[vecin]);
        ++ns;
    }
    if(ns)
        nec+=(ns-1),sum[nod]=mini;
    else
        sum[nod]=0;
}
bool check(int val)
{
    nec=0;
    dfs2(0,1,val);
    if(nec<s)
        return 1;
    return 0;
}
int main()
{
    f>>t;
    for(;t;--t)
    {
        for(int j=1;j<=n;++j)
            v[j].clear();
        f>>n>>s;
        mini=0;
        int mxx=0;
        for(int j=1;j<n;++j)
        {
            int a,b,c;
            f>>a>>b>>c;
            v[a].push_back({b,c});
            v[b].push_back({a,c});
            mxx=max(mxx,c);
        }
        dfs1(0,1,0);
        if(mini>s)
        {
            g<<-1<<'\n';
            continue;
        }
        else
        {
            if(n==1)
            {
                cout<<0<<'\n';
                continue;
            }
            if(n==2)
            {
                cout<<v[1][0].second<<'\n';
                continue;
            }
            int b=mxx;
            int e=1000000000;
            int sol=e;
            while(b<=e)
            {
                int mid=(b+e)/2;
                if(check(mid))
                    sol=mid,e=mid-1;
                else
                    b=mid+1;
            }
            g<<sol<<'\n';
        }
    }
    return 0;
}
