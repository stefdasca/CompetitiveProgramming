/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("fabrica.in");
ofstream g("fabrica.out");
int n,a,b;
int qtime[100002];
struct proc
{
    int tfree,per;
};
proc v[50002];
struct cmp
{
    bool operator()(int a, int b)
    {
        return v[a].tfree+v[a].per>v[b].tfree+v[b].per;
    }
};
priority_queue<int,vector<int>,cmp>q;
int main()
{
    f>>n>>a>>b;
    for(int i=1;i<=a;++i)
    {
        f>>v[i].per;
        q.push(i);
    }
    for(int i=1;i<=n;++i)
    {
        int x=q.top();
        qtime[i]=v[x].tfree+v[x].per;
        v[x].tfree+=v[x].per;
        q.pop();
        q.push(x);
    }
    sort(qtime+1,qtime+n+1);
    g<<qtime[n]<<" ";
    while(!q.empty())
        q.pop();
    for(int i=1;i<=b;++i)
    {
        f>>v[i].per;
        v[i].tfree=0;
        q.push(i);
    }
    int tmax=0;
    for(int i=n;i>=1;--i)
    {
        int x=q.top();
        tmax=max(tmax,qtime[i]+v[x].tfree+v[x].per);
        v[x].tfree+=v[x].per;
        q.pop();
        q.push(x);
    }
    g<<tmax<<'\n';
    return 0;
}
