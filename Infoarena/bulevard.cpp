/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("bulevard.in");
ofstream g("bulevard.out");
int n,v[100002];
int hm[100002];
int maxdr[100002];
int who[100002];
int t;
int st=1;
int mxx,nr1,nr2;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i];
    f>>t;
    hm[1]=1;
    for(int i=2;i<=n;++i)
    {
        while(v[i]-v[st]>t)
            ++st;
        hm[i]=i-st+1;
    }
    maxdr[n]=hm[n];
    who[n]=n;
    for(int i=n-1;i>=1;--i)
        if(hm[i]>=maxdr[i+1])
            maxdr[i]=hm[i],who[i]=i;
        else
            maxdr[i]=maxdr[i+1],who[i]=who[i+1];
    for(int i=1;i<=n;++i)
    {
        int sum=hm[i];
        int b=i+1;
        int e=n;
        int md=0;
        while(b<=e)
        {
            int mid=(b+e)/2;
            if(v[mid]-v[i]>t && v[mid-1]-v[i]<=t)
            {
                sum+=maxdr[mid];
                md=who[mid];
                break;
            }
            if(v[mid]-v[i]>t)
                e=mid-1;
            else
                b=mid+1;
        }
        if(sum>mxx)
            mxx=sum,nr1=v[i]-t,nr2=v[md]-t;
    }
    g<<mxx<<'\n';
    g<<max(0,nr1)<<" "<<max(0,nr2)<<'\n';
    return 0;
}
