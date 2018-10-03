#include<bits/stdc++.h>
using namespace std;
ifstream f("fbsearch.in");
ofstream g("fbsearch.out");
int T;
int n,m;
struct siruri
{
    string s2;
};
siruri v[100002];
unordered_map<string,int>S;
int v2[100002];
string u;
int r;
char tip;
struct trie
{
    trie *f[28];
    int who;
    trie()
    {
        who=0;
        memset(f,0,sizeof(f));
    }
};
trie *rad=new trie;
trie *t;
bool cmp(int a, int b)
{
    for(int j=0;j<min(v[a].s2.size(),v[b].s2.size());++j)
    {
        if(v[a].s2[j]<v[b].s2[j])
            return 1;
        if(v[a].s2[j]>v[b].s2[j])
            return 0;
    }
    if(v[a].s2.size()<v[b].s2.size())
        return 1;
    return 0;
}
int main()
{
    f>>T;
    for(int i=1;i<=T;++i)
    {
        f>>n>>m;
        S.clear();
        rad = new trie;
        rad->who=1;
        memset(v2,0,sizeof(v2));
        for(int j=1;j<=n;++j)
        {
            f>>v[j].s2;
            S[v[j].s2]=j;
            t=rad;
            int L=v[j].s2.size();
            if(cmp(j,t->who)==1)
                rad->who=j;
            for(int q=0;q<L;++q)
            {
                int val=(v[j].s2[q]-'A')%32;
                if(v[j].s2[q]=='_')
                    val=26;
                if(t->f[val]==NULL)
                {
                    t->f[val]=new trie;
                    (t->f[val])->who=j;
                }
                else
                    if(cmp(j,(t->f[val])->who)==1)
                        (t->f[val])->who=j;
                t=t->f[val];
            }
        }
        for(int j=1;j<=m;++j)
        {
            f>>tip>>u;
            if(tip=='U')
            {
                f>>r;
                v2[S[u]]+=r;
                t=rad;
                if(v2[S[u]]>v2[rad->who])
                    rad->who=S[u];
                else
                    if(v2[S[u]]==v2[rad->who])
                        if(cmp(S[u],rad->who)==1)
                            rad->who=S[u];
                int L=u.size();
                for(int j=0;j<L;++j)
                {
                    int val=(u[j]-'A')%32;
                    if(u[j]=='_')
                        val=26;
                    if(v2[S[u]]>v2[t->who])
                        t->who=S[u];
                    else
                        if(v2[S[u]]==v2[t->who])
                            if(cmp(S[u],t->who)==1)
                                t->who=S[u];
                    t=t->f[val];
                }
            }
            else
            {
                int L=u.size();
                bool ok=0;
                t=rad;
                for(int j=0;j<L;++j)
                {
                    int val=(u[j]-'A')%32;
                    if(u[j]=='_')
                        val=26;
                    if(t->f[val]==NULL)
                    {
                        ok=1;
                        break;
                    }
                    t=t->f[val];
                }
                if(ok)
                    g<<"Search Bing for "<<u<<'\n';
                else
                    g<<v[t->who].s2<<'\n';
            }
        }
        delete rad;
    }
    return 0;
}
