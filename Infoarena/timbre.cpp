#include<bits/stdc++.h>
using namespace std;
ifstream f("timbre.in");
ofstream g("timbre.out");
int n,m,k;
struct intt
{
    int maxxi,cost;
};
intt v[100002];
bool cmp(intt a, intt b)
{
    if(a.maxxi==b.maxxi)
        return a.cost>b.cost;
    return a.maxxi<b.maxxi;
}
struct c
{
    bool operator()(int a, int b)
    {
        return a>b;
    }
};
priority_queue<int,vector<int>,c>q;
int main()
{
    f>>n>>m>>k;
    for(int i=1;i<=m;++i)
    {
        f>>v[i].maxxi>>v[i].cost;
        if(v[i].maxxi>n)
            v[i].maxxi=n;
    }
    sort(v+1,v+m+1,cmp);
    int x=n;
    int sol=0;
    while(x>0)
    {
        while(v[m].maxxi>=x)
            q.push(v[m].cost),--m;
        sol+=q.top();
        q.pop();
        x-=k;
    }
    g<<sol;
    return 0;
}
