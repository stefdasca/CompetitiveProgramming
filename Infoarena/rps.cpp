#include<bits/stdc++.h>
using namespace std;
ifstream f("rps.in");
ofstream g("rps.out");
int n,k,w,d;
int tip[32];
int bt[]={1,2,0};
struct trie
{
    trie *nxt[3];
    int cnt,sol,who;
    trie()
    {
        memset(nxt,NULL,sizeof(nxt));
        cnt=0;
        sol=-2000000000;
        who=0;
    }
};
trie *r=new trie;
char c[1000002];
void ins(trie *t, int poz)
{
    t->cnt++;
    if(poz==k)
    {
        t->sol=d*t->cnt;
        return;
    }
    if(t->nxt[tip[c[poz]-'A']]==0)
        t->nxt[tip[c[poz]-'A']]=new trie;
    ins(t->nxt[tip[c[poz]-'A']], poz+1);
    t->sol=-2000000000;
    for(int i=0; i<3; i++)
    {
        int aux=0;
        if(t->nxt[i])
            aux=t->nxt[i]->sol;
        if(t->nxt[bt[i]])
            aux+=w*t->nxt[bt[i]]->cnt;
        if(aux>t->sol)
        {
            t->sol=aux;
            t->who=i;
        }
    }
}
char type(int nr)
{
    if(nr==0)
        return 'P';
    if(nr==1)
        return 'R';
    return 'S';
}
void query(trie *t, int poz)
{
    if(poz==k)
    {
        g<<'\n';
        return;
    }
    int nextPos=t->who;
    if(t->nxt[nextPos])
    {
        g<<type(nextPos);
        query(t->nxt[nextPos], poz+1);
    }
    else
    {
        g<<type(nextPos);
        for(int i=poz+1; i<k; i++)
            g<<'P';
        g<<'\n';
    }
}
int main()
{
    f>>n>>k>>w>>d;
    tip['P'-'A']=0;
    tip['R'-'A']=1;
    tip['S'-'A']=2;
    for(int i=1;i<=n;++i)
    {
        f>>c;
        ins(r,0);
        query(r,0);
    }
    return 0;
}
