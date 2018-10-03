#include<bits/stdc++.h>
using namespace std;
ifstream f("path.in");
ofstream g("path.out");
long long n,m,k;
struct noduri
{
    char a,b;
};
noduri errr[5000];
bool adj[60][60];
map<char,long long>mp;
bool frq[200];
vector<long long>v[56];
deque<long long>d;
long long lp[55],cat;
vector<long long>tps;
long long gr[60];
void input()
{
    f>>n>>m>>k;
    for(long long i=1;i<=m;++i)
    {
        f>>errr[i].a>>errr[i].b;
        frq[errr[i].a]=1;
        frq[errr[i].b]=1;
    }
    long long cod=1;
    for(char x='a';x<='z';++x)
        if(frq[x])
            d.push_back(cod),mp[x]=cod,++cod;
    for(char x='A';x<='Z';++x)
        if(frq[x])
            d.push_back(cod),mp[x]=cod,++cod;
    for(long long i=1;i<=m;++i)
    {
        v[mp[errr[i].a]].push_back(mp[errr[i].b]);
        adj[mp[errr[i].a]][mp[errr[i].b]]=1;
    }
}
void toposort()
{
    for(long long i=1;i<=m;++i)
        gr[mp[errr[i].b]]++;
    for(long long i=1;i<=n;++i)
        if(!gr[i])
            tps.push_back(i);
    long long pos=0;
    while(pos<n)
    {
        long long va=tps[pos];
        cat=max(cat,lp[va]);
        for(long long i=0;i<v[va].size();++i)
        {
            long long vecin=v[va][i];
            lp[vecin]=max(lp[vecin],lp[va]+1);
            --gr[vecin];
            if(!gr[vecin])
                tps.push_back(vecin);
        }
        ++pos;
    }
}
string sol;
bool is[200];
long long dp[55];
long long lelp[55];
bool viz[55];
void dfs(long long nod)
{
    viz[nod]=1;
    for(long long i=0;i<v[nod].size();++i)
    {
        long long vecin=v[nod][i];
        gr[vecin]++;
        if(viz[vecin])
            continue;
        dfs(vecin);
    }
}
void build()
{
    for(long long i=1;i<=cat+1;++i)
    {
        long long x='a';
        while(k)
        {
            sol+=(char)(x);
            long long sum=0;
            bool cg=(!is[x] && frq[x]!=0);
            if(cg && (i==1 || (i>1 && adj[mp[sol[i-2]]][mp[sol[i-1]]]!=0) ))
            {
                deque<long long>d;
                memset(dp,0,sizeof(dp));
                memset(lelp,0,sizeof(lelp));
                memset(viz,0,sizeof(viz));
                memset(gr,0,sizeof(gr));
                dfs(mp[sol.back()]);
                dp[mp[sol.back()]]=1;
                d.push_back(mp[sol.back()]);
                while(!d.empty())
                {
                    long long nod=d.front();
                    d.pop_front();
                    for(long long j=0;j<v[nod].size();++j)
                    {
                        long long vecin=v[nod][j];
                        if(lelp[nod]+1>lelp[vecin])
                        {
                            lelp[vecin]=lelp[nod]+1;
                            dp[vecin]=dp[nod];
                        }
                        else
                            if(lelp[nod]+1==lelp[vecin])
                                dp[vecin]+=dp[nod];
                        --gr[vecin];
                        if(!gr[vecin])
                            d.push_back(vecin);
                    }
                }
                for(long long j=1;j<=n;++j)
                    if(lelp[j]==cat-i+1)
                        sum+=dp[j];
            }
            if(k>sum)
                k-=sum;
            else
            {
                is[x]=1;
                break;
            }
            sol.pop_back();
            ++x;
            if(x>'z')
                x='A';
        }
    }
    g<<sol;
}
int main()
{
    input();
    toposort();
    build();
    return 0;
}
