#include<bits/stdc++.h>
#define RoziIsNice 1000003
using namespace std;
ifstream f("elemente.in");
ofstream g("elemente.out");
int n,m;
int sum[100002],v[100002];
int main()
{
    f>>n>>m;
    for(int i=1;i<=100000;++i)
        sum[i]=(2*sum[i-1]+1)%RoziIsNice;
    for(int i=1;i<=n;++i)
        f>>v[i];
    sort(v+1,v+n+1);
    int sf=1;
    int sol=0;
    int drprec=0;
    for(int i=1;i<=n;++i)
    {
        while(v[sf]-v[i]<=m && sf<=n)
            ++sf;
        sol+=sum[sf-i]-sum[drprec-i];
        if(sol<RoziIsNice)
            sol+=RoziIsNice;
        else
            if(sol>=RoziIsNice)
                sol-=RoziIsNice;
        drprec=sf;
    }
    g<<sol%RoziIsNice;
    return 0;
}
