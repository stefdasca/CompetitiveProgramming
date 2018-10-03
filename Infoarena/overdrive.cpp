#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("overdrive.in");
ofstream g("overdrive.out");
long long n,a[35],s,min1,v[500],p1[100002],p2[100002],l1,l2,op=0,nr=1;
int main()
{
    f>>n;
    for(long long i=1;i<=n/2+n%2;++i)
        f>>a[i],s+=a[i],nr*=2;
    while(op<nr)
    {
        v[1]++;
        long long r=1;
        while(v[r]==2)
        {
            v[r]=0;
            v[r+1]++;
            ++r;
        }
        long long s1=0;
        for(long long i=1;i<=n;++i)
            if(v[i]==1)
                s1+=a[i];
        ++op;
        p1[op]=s1;
    }
    sort(p1+1,p1+op+1);
    for(long long i=1;i<=n;++i)
        v[i]=0;
    l1=op;
    op=0;
    nr=1;
    for(long long i=n/2+n%2+1;i<=n;++i)
        f>>a[i-(n/2+n%2)],s+=a[i-(n/2+n%2)],nr*=2;
    if(n%2==1)
        a[n/2+n%2]=0;
    while(op<nr)
    {
        v[1]++;
        long long r=1;
        while(v[r]==2)
        {
            v[r]=0;
            v[r+1]++;
            ++r;
        }
        long long s1=0;
        for(long long i=1;i<=n;++i)
            if(v[i]==1)
                s1+=a[i];
        ++op;
        p2[op]=s1;
    }
    l2=op;
    sort(p2+1,p2+l2+1);
    min1=s;
    for(long long i=1;i<=l1;++i)
    {
        long long b=1;
        long long e=l2;
        while(b<e)
        {
            long long m=(b+e)/2;
            if(p1[i]+p2[m]<s/2)
                b=m+1;
            else
                e=m-1;
        }
        min1=min(min1,(max(p1[i]+p2[e],s-(p1[i]+p2[e]))));
        min1=min(min1,(max(p1[i]+p2[b],s-(p1[i]+p2[b]))));
    }
    g<<max(min1,s-min1);
    return 0;
}
