#include<bits/stdc++.h>
using namespace std;
ifstream f("aladdin2.in");
ofstream g("aladdin2.out");
int main()
{
    int n,m,v1[10002],l1,v2[10002],l2;
    f>>n>>m;
    if(m>n)
        swap(n,m);
    v2[1]=1;
    v1[1]=-2;
    l1=1;
    l2=1;
    int r=n-m;
    int q=m%20;
    for(int j=1;j<=l2;++j)
        v2[j]*=(1<<q);
    for(int j=1;j<=l2;++j){
        if(v2[j]>9)
            v2[j+1]+=v2[j]/10,v2[j]%=10;
        if(j==l2 && v2[j+1])
            ++l2;
    }
    m=m/20;
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=l2;++j)
            v2[j]<<=20;
        for(int j=1;j<=l2;++j){
            if(v2[j]>9)
                v2[j+1]+=v2[j]/10,v2[j]%=10;
            if(j==l2 && v2[j+1])
                ++l2;
        }
    }
    for(int i=1;i<=l2;++i)
        v1[i]+=v2[i];
    l1=l2;
    int t=r%20;
    for(int j=1;j<=l2;++j)
        v2[j]*=(1<<t);
    for(int j=1;j<=l2;++j){
        if(v2[j]>9)
            v2[j+1]+=v2[j]/10,v2[j]%=10;
        if(j==l2 && v2[j+1])
            ++l2;
    }
    r/=20;
    for(int i=1;i<=r;++i)
    {
        for(int j=1;j<=l2;++j)
            v2[j]<<=20;
        for(int j=1;j<=l2;++j){
            if(v2[j]>9)
                v2[j+1]+=v2[j]/10,v2[j]%=10;
            if(j==l2 && v2[j+1])
                ++l2;
        }
    }
    for(int i=1;i<=l2;++i)
        v1[i]+=v2[i];
    l1=l2;
    for(int i=1;i<=l1;++i)
    {
        if(v1[i]>9)
            v1[i+1]+=v1[i]/10,v1[i]%=10;
        if(i==l1 && v1[i+1])
            ++l1;
    }
    for(int i=l1;i>=1;--i)
        g<<v1[i];
    return 0;
}
