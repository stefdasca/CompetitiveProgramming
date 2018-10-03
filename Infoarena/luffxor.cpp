/// I gonna let it burn burn burn
#include<bits/stdc++.h>
using namespace std;
ifstream f("luffxor.in");
ofstream g("luffxor.out");
int q,ins[200002],nri,qq;
struct trie
{
    trie *nod[2];
    int nr;
    trie()
    {
        memset(nod,0,sizeof(nod));
        nr=0;
    }
};
trie *r=new trie;
void add(int nr)
{
    trie *t=r;
    for(int i=30;i>=0;--i)
    {
        bool q;
        if(nr&(1<<i))
            q=1;
        else
            q=0;
        ++t->nr;
        if(!t->nod[q])
            t->nod[q]=new trie;
        t=t->nod[q];
    }
    ++t->nr;
}
void scoate(int nr)
{
    trie *t=r;
    for(int i=30;i>=0;--i)
    {
        bool q;
        if(nr&(1<<i))
            q=1;
        else
            q=0;
        --t->nr;
        if(!t->nod[q])
            t->nod[q]=new trie;
        t=t->nod[q];
    }
    --t->nr;
}
int query(trie *x, int niv, int xx, int k)
{
    if(k<0 || !x->nr)
        return 0;
    if(niv==-1)
        return x->nr;
    int q=-1;
    q+=(1<<niv);
    q+=(1<<niv);
    if(k>=q)
        return x->nr;
    int sol=0;
    if(x->nod[0])
    {
        if(!(xx&(1<<niv)))
            sol+=query(x->nod[0],niv-1,xx,k);
        else
            sol+=query(x->nod[0],niv-1,xx,k-(1<<niv));
    }
    if(x->nod[1])
    {
        if(!(xx&(1<<niv)))
            sol+=query(x->nod[1],niv-1,xx,k-(1<<niv));
        else
            sol+=query(x->nod[1],niv-1,xx,k);
    }
    return sol;
}
int main()
{
    f>>q;
    for(;q;--q)
    {
        int tip;
        f>>tip;
        if(tip==0)
        {
            ++nri;
            ++qq;
            int val;
            f>>val;
            ins[nri]=val;
            add(val);
            continue;
        }
        if(tip==1)
        {
            --qq;
            int val;
            f>>val;
            scoate(ins[val]);
            ins[val]=-1;
            continue;
        }
        if(tip==2)
        {
            int val, val2;
            f>>val>>val2;
            g<<query(r,30,val,val2)<<'\n';
            continue;
        }
    }
    return 0;
}
