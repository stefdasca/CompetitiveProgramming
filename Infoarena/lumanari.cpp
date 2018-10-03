#include<bits/stdc++.h>
using namespace std;
ifstream f("lumanari.in");
ofstream g("lumanari.out");
int n,sol,v[200002];
bool verif(int lung)
{
    long long rest=0;
    int st=n-lung;
    int i;
    for(i=1;i<=st;++i)
        rest+=v[i];
    for(;i<=n;++i)
    {
        if(v[i]+rest<i-st || rest<0)
            return 0;
        rest=rest+v[i]-i+st;
    }
    return 1;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i];
    sort(v+1,v+n+1);
    int b=1;
    int e=n;
    while(b<=e)
    {
        int m=(b+e)/2;
        if(verif(m))
        {
            sol=m;
            b=m+1;
        }
        else
            e=m-1;
    }
    g<<sol<<'\n';
    return 0;
}
