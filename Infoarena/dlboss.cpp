#include<bits/stdc++.h>
using namespace std;
ifstream f("dlboss.in");
ofstream g("dlboss.out");
long long n,t;
struct ladies
{
    long long beauty, time, initially, sol;
};
ladies v[100002];
bool cmp(ladies a, ladies b)
{
    if(a.beauty==b.beauty)
        return a.time<b.time;
    return a.beauty<b.beauty;
}
struct cmp2
{
    bool operator()(long long a, long long b)
    {
        return v[a].time<v[b].time;
    }
};
priority_queue<long long,vector<long long>,cmp2>q;
bool cmp3(ladies a, ladies b)
{
    return a.initially<b.initially;
}
int main()
{
    f>>n;
    f>>t;
    for(long long i=1;i<=n;++i)
    {
        f>>v[i].time>>v[i].beauty;
        v[i].initially=i;
    }
    sort(v+1,v+n+1,cmp);
    long long sum=0;
    for(long long i=n;i>=1;--i)
    {
        v[i].sol=q.size();
        if(v[i].beauty>v[i-1].beauty){
            q.push(i);
            sum+=v[i].time;
            while(sum>t)
                sum-=v[q.top()].time,q.pop();
        }
    }
    sort(v+1,v+n+1,cmp3);
    for(int i=1;i<=n;++i)
        g<<v[i].sol<<'\n';
    return 0;
}
