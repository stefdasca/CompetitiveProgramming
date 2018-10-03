#include<bits/stdc++.h>
#define Maxx (1<<16)
#define LG 16
using namespace std;
ifstream f("concurs.in");
ofstream g("concurs.out");
int n,scor[Maxx/2],t;
int maxs=-2e9,m1,m2;
vector<int>m[Maxx/2];
int pe,nod[Maxx],niv[Maxx],lap[Maxx/2];
int RMQ[LG][Maxx],Log2[Maxx];
int nrboss[Maxx/2];
void dfs(int varf, int lvl)
{
    ++pe;
    nod[pe]=varf;
    niv[pe]=lvl;
    for(int i=0;i<m[varf].size();++i)
    {
        dfs(m[varf][i],lvl+1);
        ++pe;
        nod[pe]=varf;
        niv[pe]=lvl;
    }
    lap[varf]=pe;
}
void rmq()
{
    for(int i=2;i<=pe;++i)
        Log2[i]=Log2[i/2]+1;
    for(int i=1;i<=pe;++i)
        RMQ[0][i]=i;
    for(int i=1;(1<<i)<=pe;++i)
        for(int j=(1<<i);j<=pe;++j)
        {
            int k=(1<<(i-1));
            RMQ[i][j]=RMQ[i-1][j];
            int x=niv[RMQ[i-1][j]];
            int y=niv[RMQ[i-1][j-k]];
            if(x>y)
                RMQ[i][j]=RMQ[i-1][j-k];
        }
}
void solve()
{
    for(int i=1;i<=t;++i)
    {
        int a,b;
        f>>a>>b;
        int x=min(lap[a],lap[b]);
        int y=max(lap[a],lap[b]);
        int lug=(y-x+1);
        int k=Log2[lug];
        int sol=RMQ[k][y];
        if(niv[sol]>niv[RMQ[k][x+(1<<k)-1]])
            sol=RMQ[k][x+(1<<k)-1];
        if(scor[nod[sol]]>maxs)
            maxs=scor[nod[sol]],m1=a,m2=b;
        else
            if(scor[nod[sol]]==maxs)
                if(a<m1)
                    m1=a,m2=b;
                else
                    if(a==m1)
                        m2=min(m2,b);
    }
    g<<maxs<<" "<<m1<<" "<<m2;
}
void read()
{
    f>>n>>t;
    for(int i=1;i<=n;++i)
        f>>scor[i];
    for(int i=1;i<n;++i)
    {
        int a,b;
        f>>a>>b;
        nrboss[b]++;
        m[a].push_back(b);
    }
}
int main()
{
    read();
    int rad=0;
    for(int i=1;i<=n;++i)
        if(nrboss[i]==0)
            rad=i;
    dfs(rad,0);
    rmq();
    solve();
    return 0;
}
