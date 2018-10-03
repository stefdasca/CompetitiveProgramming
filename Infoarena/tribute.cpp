#include<bits/stdc++.h>
using namespace std;
ifstream f("tribute.in");
ofstream g("tribute.out");
int n,x,y;
struct ox
{
    int val;
    long long sum;
};
ox v[50002];
ox v2[50002];
bool test(ox a, ox b)
{
    return a.val<b.val;
}
int main()
{
    f>>n>>x>>y;
    for(int i=1;i<=n;++i)
        f>>v[i].val>>v2[i].val;
    sort(v+1,v+n+1,test);
    sort(v2+1,v2+n+1,test);
    for(int i=1;i<=n;++i){
        v2[i].sum=v2[i].val+v2[i-1].sum;
        v[i].sum=v[i].val+v[i-1].sum;
    }
    long long ss=1e12;
    int lmin=0;
    v[n+1].val=1e9;
    v2[n+1].val=1e9;
    for(int i=x;i<=50000;++i)
    {
        int b=1;
        int e=n;
        long long prd=0;
        while(b<=e)
        {
            int m=(b+e)/2;
            if(v[m].val<=i-x && v[m+1].val>i-x)
            {
                prd+=1ll*m*(i-x)-v[m].sum;
                break;
            }
            else
                if(v[m].val>i-x)
                    e=m-1;
                else
                    b=m+1;
        }
        e=n;
        b=1;
        while(b<=e)
        {
            int m=(b+e)/2;
            if(v[m].val>i && v[m-1].val<=i)
            {
                prd+=(v[n].sum-v[m-1].sum)-1ll*(n-m+1)*i;
                break;
            }
            else
                if(v[m].val<=i)
                    b=m+1;
                else
                    e=m-1;
        }
        if(prd<ss)
            ss=prd,lmin=i;
    }
    long long ss2=1e12;
    int cmin=0;
    for(int i=y;i<=50000;++i)
    {
        int b=1;
        int e=n;
        long long prd=0;
        while(b<=e)
        {
            int m=(b+e)/2;
            if(v2[m].val<=i-y && v2[m+1].val>i-y)
            {
                prd+=1ll*m*(i-y)-v2[m].sum;
                break;
            }
            else
                if(v2[m].val>i-y)
                    e=m-1;
                else
                    b=m+1;
        }
        e=n;
        b=1;
        while(b<=e)
        {
            int m=(b+e)/2;
            if(v2[m].val>i && v2[m-1].val<=i)
            {
                prd+=(v2[n].sum-v2[m-1].sum)-1ll*(n-m+1)*i;
                break;
            }
            else
                if(v2[m].val<=i)
                    b=m+1;
                else
                    e=m-1;
        }
        if(prd<ss2)
            ss2=prd,cmin=i;
    }
    g<<ss+ss2;
    return 0;
}
