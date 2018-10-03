#include<bits/stdc++.h>
using namespace std;
ifstream f("retele.in");
ofstream g("retele.out");
int n, m, i, j, x, y, nrc, k;
int pls[50002], mns[50002];
vector<int>G[50002], GT[50002], ctc[50002];
stack<int>st;
bool mrkd[50002];
int pz[50002],nr2;
void dfs1 (int x)
{
    pls[x]=1;
    for (int i=0; i<G[x].size(); i++)
        if (pls[G[x][i]]==0)
            dfs1(G[x][i]);
    st.push(x);
}
void dfs2 (int x)
{
    mns[x]=nrc;
    for (int i=0; i<GT[x].size(); i++)
        if (mns[GT[x][i]]==0)
            dfs2(GT[x][i]);
}
struct nod
{
    int nr;
    int alc;
};
nod v[50002];
bool test(nod a, nod b)
{
    if(pz[a.alc]==pz[b.alc])
        return a.nr<b.nr;
    return pz[a.alc]<pz[b.alc];
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; i++){
        f>>x>>y;
        G[x].push_back(y);
        GT[y].push_back(x);
    }
    for (i=1; i<=n; i++)
        if (pls[i]==0)
            dfs1(i);
    while (!st.empty()){
        k=st.top();
        st.pop();
        if (mns[k]==0){
            nrc++;
            dfs2(k);
        }
    }
    for(int i=1;i<=n;++i){
        if(!ctc[mns[i]].size())
            pz[mns[i]]=++nr2;
        ctc[mns[i]].push_back(i);
        v[i].nr=i;
        v[i].alc=mns[i];
    }
    sort(v+1,v+n+1,test);
    g<<nrc<<'\n';
    for(int i=1;i<=n;++i)
        if(v[i].alc!=v[i-1].alc)
        {
            if(i!=1)
                g<<'\n';
            g<<ctc[v[i].alc].size()<<" ";
            g<<v[i].nr<<" ";
        }
        else
            g<<v[i].nr<<" ";
    return 0;
}

