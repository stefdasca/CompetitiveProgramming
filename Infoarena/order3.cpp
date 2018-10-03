#include<bits/stdc++.h>
using namespace std;
ifstream f("order3.in");
ofstream g("order3.out");
int q;
long long nr;
int n,v[53];
long long hm[53][53];
void prec()
{
    for(int i=1;i<=51;++i)
    {
        hm[i][i]=1;
        hm[i][i-1]=1;
        for(int j=i-2;j>=1;--j)
            hm[i][j]=hm[i][j+1]*2;
    }
}
void solve2(long long nr)
{
    vector<int>v;
    int sum=1;
    long long p2=1;
    while(p2*2<=nr)
        p2<<=1,++sum;
    nr-=p2;
    while(sum>1)
    {
        for(int i=1;i<=sum;++i)
            if(nr>=hm[sum][i])
                nr-=hm[sum][i];
            else
            {
                v.push_back(i);
                sum-=i;
                break;
            }
    }
    if(sum==1)
        v.push_back(1);
    g<<v.size()<<" ";
    for(int i=0;i<v.size();++i)
        g<<v[i]<<" ";
    g<<'\n';
}
void solve1()
{
    int sum=0;
    for(int i=1;i<=n;++i)
        sum+=v[i];
    long long nr=(1LL<<(sum-1));
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<v[i];++j)
            nr+=hm[sum][j];
        sum-=v[i];
    }
    g<<nr<<'\n';
}
int main()
{
    prec();
    f>>q;
    for(;q;--q)
    {
        int tip;
        f>>tip;
        if(tip==2)
        {
            f>>nr;
            solve2(nr);
        }
        else
        {
            f>>n;
            for(int i=1;i<=n;++i)
                f>>v[i];
            solve1();
        }
    }
    return 0;
}
