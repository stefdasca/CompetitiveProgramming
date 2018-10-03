#include<bits/stdc++.h>
using namespace std;
ifstream f("cabana2.in");
ofstream g("cabana2.out");
int n;
int px[50002],nr;
vector<int>d[50002];
struct puncte
{
    int x,y;
};
puncte v[50002];
bool cmp(puncte a, puncte b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int cb(int unde, int who)
{
    int mar=d[unde].size()-1;
    int b=0;
    int e=mar;
    while(b<=e)
    {
        int m=(b+e)/2;
        if(d[unde][m]>=who && (m==0 || d[unde][m-1]<who))
            return m;
        if(d[unde][m]<who)
            b=m+1;
        else
            e=m-1;
    }
    return -1;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i].x>>v[i].y;
    sort(v+1,v+n+1,cmp);
    v[0].x=-2e9;
    for(int i=1;i<=n;++i)
        if(v[i].x!=v[i-1].x)
        {
            ++nr;
            px[nr]=v[i].x;
            d[nr].push_back(v[i].y);
        }
        else
            d[nr].push_back(v[i].y);
    long long smax=0;
    for(int i=1;i<nr;++i)
        for(int j=0;j<d[i].size()-1;++j)
        {
            int p1=d[i][j];
            int p2=d[i][j+1];
            for(int k=i+1;k<=nr;++k)
            {
                if(!d[k].size())
                    continue;
                int poz=cb(k,p1);
                if(poz==-1)
                    continue;
                if(d[k][poz]>p2)
                    continue;
                if(poz+1!=d[k].size())
                    if(d[k][poz]==p1 && d[k][poz+1]==p2)
                        smax=max(smax,abs(1LL*(p2-p1)*(px[k]-px[i])));
                break;
            }
        }
    g<<smax;
    return 0;
}
