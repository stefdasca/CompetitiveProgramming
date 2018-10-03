/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
#define mod 666013
using namespace std;
ifstream f("arbore4.in");
ofstream g("arbore4.out");
int n;
int hms[100002];
long long fact[100002];
long long f2[100002];
long long pw(long long b, int ex)
{
    long long sol=1;
    while(ex)
    {
        if(ex&1)
            sol=(sol*b)%mod;
        b=(b*b)%mod;
        ex>>=1;
    }
    return sol;
}
long long comb(int n, int k)
{
    long long sol=((fact[n]*f2[k])%mod*f2[n-k])%mod;
    sol%=mod;
    return sol;
}
vector<int>v[100002];
bool viz[100002];
long long sol[100002];
void dfs(int dad, int nod)
{
    viz[nod]=1;
    sol[nod]=1;
    hms[nod]=1;
    if(v[nod].size()==1 && nod!=1)
        return;
    for(int i=0;i<v[nod].size();++i)
        if(!viz[v[nod][i]])
        {
            dfs(nod, v[nod][i]);
            hms[nod]+=hms[v[nod][i]];
        }
    int nr=hms[nod]-1;
    for(int i=0;i<v[nod].size();++i)
        if(v[nod][i]!=dad)
        {
            sol[nod]=(sol[nod]*comb(nr,hms[v[nod][i]])*sol[v[nod][i]])%mod;
            nr-=hms[v[nod][i]];
        }
}
int main()
{
    f>>n;
    fact[0]=1;
    f2[0]=1;
    for(long long i=1;i<=n;++i){
        fact[i]=(fact[i-1]*i)%mod;
        f2[i]=pw(fact[i],mod-2);
    }
    for(int i=1;i<n;++i)
    {
        int a,b;
        f>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(0,1);
    g<<sol[1]<<'\n';
    return 0;
}
