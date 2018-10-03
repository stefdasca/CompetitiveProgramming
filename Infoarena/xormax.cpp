#include<bits/stdc++.h>
using namespace std;
ifstream f("xormax.in");
ofstream g("xormax.out");
int n,v[100002];
int XoR[100002];
struct trie
{
    int lpos;
    trie *f[2];
    trie()
    {
        lpos=0;
        memset(f, 0, sizeof(f));
    }
};
trie *rad=new trie;
trie *t;
int maxx=-1,st,dr;
void add(int nr, int i)
{
    t=rad;
    for(int j=20;j>=0;--j)
    {
        int q=((nr&(1<<j))>0);
        if(t->f[q]==NULL)
            t->f[q]=new trie;
        t=t->f[q];
        t->lpos=i;
    }
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>v[i];
        XoR[i]=XoR[i-1]^v[i];
    }
    add(0,0);
    for(int i=1;i<=n;++i)
    {
        t = rad;
        int nr=XoR[i];
        int vall=0;
        for(int j=20;j>=0;--j)
        {
            int q=((nr&(1<<j))>0);
            q^=1;
            vall^=(1<<j);
            if(t->f[q]==NULL)
                q^=1,vall^=(1<<j);
            t=t->f[q];
        }
        if(vall>maxx)
            maxx=vall,st=t->lpos+1,dr=i;
        add(XoR[i],i);
    }
    g<<maxx<<" "<<st<<" "<<dr<<'\n';
    return 0;
}
