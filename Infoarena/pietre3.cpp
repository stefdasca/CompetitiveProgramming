#include<bits/stdc++.h>
using namespace std;
ifstream f("pietre3.in");
ofstream g("pietre3.out");
int n,v[100002],k;
deque<pair<int,int> >d;
int pm[1000002];
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i];
    sort(v+1,v+n+1);
    int left=v[1];
    int right=v[1];
    int lenmax=0;
    for(int i=2;i<=n;++i)
        if(v[i]-v[i-1]==1)
            ++right;
        else
        {
            d.push_back({left,right});
            lenmax=max(lenmax,right-left+1);
            left=right=v[i];
        }
    d.push_back({left,right});
    lenmax=max(lenmax,right-left+1);
    g<<d.size()<<'\n';
    f>>k;
    for(int i=1;i<=k;++i)
    {
        int nr;
        f>>nr;
        pm[nr]++;
    }
    int nrs=1;
    for(int i=0;i<d.size()-1;++i)
        if(pm[d[i+1].first-d[i].second-1])
            lenmax=max(lenmax,d[i+1].second-d[i].first+1);
    for(int i=0;i<d.size()-1;++i)
        if(!pm[d[i+1].first-d[i].second-1])
            ++nrs;
        else
            pm[d[i+1].first-d[i].second-1]--;
    g<<nrs<<'\n';
    g<<lenmax;
    return 0;
}
