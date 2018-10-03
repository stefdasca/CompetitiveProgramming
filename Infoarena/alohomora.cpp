#include <bits/stdc++.h>
using namespace std;
ifstream f("alohomora.in");
ofstream g("alohomora.out");
int t,n,m,k,i,ind,nr,a2,b2;
pair <int,int> a[1<<17],b[1<<17];
void intersect(int x,int y)
{
    n=m=0;
    int i=1,j=1;
    for(;i<=x&&j<=y;)
        if(a[i].first<b[j].first||(a[i].first==b[j].first&&a[i].second<b[j].second))
        {
            a[++n]=a[i];
            ++i;
        }
        else
            if(a[i].first>b[j].first||(a[i].first==b[j].first&&a[i].second>b[j].second))
            {
                b[++m]=b[j];
                ++j;
            }
        else
            i++,j++;
    for(;i<=x;++i)
        a[++n]=a[i];
    for(;j<=y;++j)
        b[++m]=b[j];
}
int main()
{
    f>>t;
    while(t--)
    {
        f>>n>>m>>k;
        for(i=1;i<=n;++i)
            f>>a[i].first>>a[i].second;
        for(i=1;i<=m;++i)
            f>>b[i].first>>b[i].second;
        if(k==1)
        {
            if(m<=n)
                g<<"1\n";
            else
                g<<"0\n";
            continue;
        }
        sort(a+1,a+n+1);
        sort(b+1,b+m+1);
        intersect(n,m);
        ind=1;
        nr=0;
        a2=0;
        b2=0;
        for(i=1;i<=n && ind<=m;++i)
        {
            if(a[i].first!=a[i-1].first)
            {
                while(nr>=k && a2<a[i].first && ind<=m)
                {
                    nr/=k;
                    a2++;
                    b2=1<<30;
                    while(ind<=m && nr && (b[ind].first<a2 || (b[ind].first==a2 && (b[ind].second==b2 || b2==(1<<30)))))
                        ++ind,--nr;
                }
                if(a2==a[i].first)
                    ++nr;
                else
                {
                    nr=1;
                    a2=a[i].first;
                    b2=a[i].second;
                }
            }
            else
            {
                nr++;
                b2=max(b2,a[i].second);
            }
            while(ind<=m && nr && (b[ind].first<a2 || (b[ind].first==a2&&b[ind].second==b2)))
                ++ind,--nr;
        }
        while(nr>=k && ind<=m)
        {
            nr/=k;
            a2++;
            b2=1<<30;
            while(ind<=m && nr && (b[ind].first<a2 || (b[ind].first==a2 && (b[ind].second==b2 || b2==(1<<30)))))
                ++ind,--nr;
        }
        if(ind>m)
            g<<"1\n";
        else
            g<<"0\n";
    }
    return 0;
}
