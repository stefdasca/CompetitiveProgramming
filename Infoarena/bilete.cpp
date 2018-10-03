#include<bits/stdc++.h>
using namespace std;
ifstream f("bilete.in");
ofstream g("bilete.out");
int n,k;
int v[1000002];
int ar[5];
struct og
{
    int L,C;
};
og vv[4];
bool test(og a, og b)
{
    if(a.L==b.L)
        return a.C<b.C;
    return a.L<b.L;
}
int main()
{
    f>>n>>k;
    for(int i=1;i<=k;++i)
        ar[i]=i;
    while(ar[1]<=n*n-k+1)
    {
        int nr1=0;
        int nr2=0;
        for(int i=1;i<=k;++i)
        {
            int L,C;
            if(ar[i]%n==0)
                L=ar[i]/n,C=n;
            else
                L=ar[i]/n+1,C=ar[i]%n;
            nr1=nr1*10+L;
            nr1=nr1*10+C;
            vv[i].L=L;
            vv[i].C=n-C+1;
        }
        sort(vv+1,vv+k+1,test);
        for(int i=1;i<=k;++i)
        {
            nr2=nr2*10+vv[i].L;
            nr2=nr2*10+vv[i].C;
        }
        if(v[nr2]==0)
            v[nr1]=1;
        int z=k;
        ar[z]++;
        if(k==2 && ar[2]>n*n)
        {
            ++ar[1];
            ar[2]=ar[1]+1;
        }
        if(k==3 && ar[3]>n*n)
        {
            ++ar[2];
            if(ar[2]>n*n-1)
                ++ar[1],ar[2]=ar[1]+1,ar[3]=ar[2]+1;
            else
                ar[3]=ar[2]+1;
        }
    }
    for(int i=1;i<=1000000;++i)
        if(v[i]==1)
            g<<i<<'\n';
    return 0;
}
