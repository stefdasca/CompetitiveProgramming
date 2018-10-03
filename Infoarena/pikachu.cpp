#include<bits/stdc++.h>
using namespace std;
ifstream f("pikachu.in");
ofstream g("pikachu.out");
int n,k;
int v[100002];
long long check(int val)
{
    long long mins=(1LL<<60);
    long long s=0;
    for(int i=1;i<=k;++i)
        s+=abs(v[i]-val);
    for(int i=k;i<=n;++i)
    {
        if(i>k)
            s-=abs(v[i-k]-val);
        mins=min(mins,s);
        if(i<n)
            s+=abs(v[i+1]-val);
    }
    return mins;
}
int main()
{
    f>>n>>k;
    int b=1;
    int e=0;
    for(int i=1;i<=n;++i)
        f>>v[i],e=max(e,v[i]);
    long long minsol=(1LL<<60);
    while(b<=e)
    {
        int mid=b+(e-b)/2;
        if(check(mid-1)>=check(mid) && check(mid)<=check(mid+1))
        {
            minsol=check(mid);
            break;
        }
        if(check(mid-1)>=check(mid))
            b=mid+1;
        else
            e=mid-1;
    }
    g<<minsol<<'\n';
    return 0;
}
