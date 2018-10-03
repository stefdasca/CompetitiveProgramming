/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("domino.in");
ofstream g("domino.out");
int n,x,y,sz;
bool viz[100002];
struct str
{
    int d,alc;
    bool tip;
};
vector<str>v[12];
str stk[100002],q,p;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>x>>y;
        v[x].push_back({y,i,0});
        v[y].push_back({x,i,1});
    }
    int cnt=0;
    for(int i=0;i<=9;++i)
        if(v[i].size()&1)
            ++cnt;
    if(cnt==1 || cnt>2)
    {
        g<<0;
        return 0;
    }
    g<<1<<'\n';
    for(int i=0;i<=9;++i)
        if(v[i].size()&1)
        {
            x=i;
            break;
        }
    stk[++sz]={x,0,0};
    cnt=0;
    while(sz){
        q=stk[sz];
        if(v[q.d].empty())
        {
            cnt++;
            if(cnt <= n)
                g<<q.alc<<" "<<!q.tip<<'\n';
            sz--;
            continue;
        }
        p=v[q.d].back();
        v[q.d].pop_back();
        if(!viz[p.alc]){
            viz[p.alc]=1;
            stk[++sz] = {p.d,p.alc,p.tip};
        }
    }
    return 0;
}
