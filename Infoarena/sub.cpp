#include<bits/stdc++.h>
using namespace std;
ifstream f("sub.in");
ofstream g("sub.out");
int a,b,sol,pzd;
string s;
string s2;
struct trie
{
    int apa, apb, lastap;
    trie *fii[26];
    trie()
    {
        apa=apb=lastap=0;
        memset(fii,0,sizeof(fii));
    }
};
trie *rad=new trie;
string p;
void introdu(int nr)
{
    trie *t=rad;
    for(int i=0;i<p.size();++i)
    {
        int x=p[i]-'a';
        if(nr==1 && t->fii[x]==NULL)
            t->fii[x]=new trie;
        if(nr==2 && t->fii[x]==NULL)
            break;
        t=t->fii[x];
        if(nr==2 && t->apa!=a)
            break;
        if(t->lastap!=pzd && nr==1)
        {
            t->apa++;
            t->lastap=pzd;
            if(t->apa<pzd)
                break;
            if(t->apa==a)
                ++sol;

        }
        if(nr==2)
        {
            if(!t->apb && t->apa==a)
                --sol,t->apb++;
        }
    }
}
int main()
{
    f>>a;
    for(int i=1;i<=a;++i)
    {
        pzd=i;
        f>>s;
        for(int j=0;j<s.size();++j)
        {
            p.clear();
            for(int k=j;k<s.size();++k)
                p+=s[k];
            introdu(1);
        }
    }
    f>>b;
    for(int i=1;i<=b;++i)
    {
        f>>s;
        for(int j=0;j<s.size();++j)
        {
            p.clear();
            for(int k=j;k<s.size();++k)
                p+=s[k];
            introdu(2);
        }
    }
    g<<sol<<'\n';
    return 0;
}
