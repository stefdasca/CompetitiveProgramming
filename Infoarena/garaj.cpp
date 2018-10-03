#include<bits/stdc++.h>
using namespace std;
ifstream f("garaj.in");
ofstream g("garaj.out");
int n,qt;
int val[100002];
int coef[100002];
int mint=1e9;
struct vct
{
    int val,coef,z;
};
vct v[100002];
inline bool cmp(vct a, vct b)
{
    return a.z>b.z;
}
int main()
{
    f>>n>>qt;
    for(int i=1;i<=n;++i)
    {
        f>>v[i].val>>v[i].coef;
        v[i].coef*=2;
    }
    int b=1;
    int e=1e9;
    while(b<=e)
    {
        int m=(b+e)/2;
        int sum=0;
        for(int i=1;i<=n && sum<qt;++i)
            sum+=v[i].val*(m/v[i].coef);
        if(sum>=qt)
            mint=m,e=m-1;
        else
            b=m+1;
    }
    for(int i=1;i<=n;++i)
        v[i].z=v[i].val*(mint/v[i].coef);
    g<<mint<<" ";
    sort(v+1,v+n+1,cmp);
    int i=1;
    while(qt>0)
    {
        qt-=v[i].z;
        ++i;
    }
    g<<i-1;
    return 0;
}
