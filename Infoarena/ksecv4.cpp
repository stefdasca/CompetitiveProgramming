#include<bits/stdc++.h>
#pragma GCC optimize("O2")
#define bucata 25
using namespace std;
ifstream f("ksecv4.in");
ofstream g("ksecv4.out");
int n,k,m;
long long va[3002],vb[3002],arr[1000002],bucM[1000002],bucm[1000002];
inline bool good(long long nr)
{
    int sol=1;
    long long maxx=-(1LL<<62),mini=(1LL<<62);
    for(int i=1;i<=n;++i)
    {
        if(i%25==1 && i+25<=n)
        {
            long long maxx2=max(maxx,bucM[i/25+1]);
            long long mini2=min(mini,bucm[i/25+1]);
            if((maxx2-mini2+1)/2<=nr)
            {
                maxx=maxx2;
                mini=mini2;
                i+=24;
            }
        }
        maxx=max(maxx,arr[i]);
        mini=min(mini,arr[i]);
        if((maxx-mini+1)/2>nr)
        {
            ++sol;
            if(sol>k)
                return 0;
            maxx=mini=arr[i];
        }
    }
    return 1;
}
int main()
{
    f>>n>>k>>m;
    for(int i=0;i<m;++i)
        f>>va[i];
    for(int i=0;i<m;++i)
        f>>vb[i];
    long long maxx=0,mini=(1LL<<62);
    for(int i=0;i<n;++i)
    {
        arr[i+1]=va[i%m]^vb[i/m];
        maxx=max(maxx,arr[i+1]);
        mini=min(mini,arr[i+1]);
    }
    for(int i=1;i<=n;i+=bucata)
    {
        bucm[i/25+1]=(1LL<<62);
        for(int j=i;j<=n && j<i+bucata;++j)
        {
            bucM[i/25+1]=max(bucM[i/25+1],arr[j]);
            bucm[i/25+1]=min(bucm[i/25+1],arr[j]);
        }
    }
    long long b=0;
    long long e=(maxx-mini+1)/2;
    long long sol=e;
    while(b<=e)
    {
        long long mid=(b+e)/2;
        if(good(mid))
            sol=mid,e=mid-1;
        else
            b=mid+1;
    }
    g<<sol<<'\n';
    return 0;
}
