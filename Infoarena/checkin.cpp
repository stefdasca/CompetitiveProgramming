#include<bits/stdc++.h>
using namespace std;
ifstream f("checkin.in");
ofstream g("checkin.out");
int n;
struct atm
{
    int tl,tt;
};
atm v[2002];
int v2[2002];
int o,b;
int main()
{
    int st=1e7;
    f>>n;
    for(int i=1;i<=n;++i){
        f>>v[i].tl>>v[i].tt;
        st=min(st,v[i].tt);
    }
    f>>o>>b;
    int dr=1e7;
    int sol=0;
    while(st<=dr)
    {
        int m=(st+dr)/2;
        for(int i=1;i<=n;++i)
            v2[i]=max(0,(m-v[i].tt)/v[i].tl);
        sort(v2+1,v2+n+1,greater<int>());
        int nr=0;
        for(int i=1;i<=min(n,o);++i)
            nr+=v2[i];
        if(nr>=b)
        {
            sol=m;
            dr=m-1;
        }
        else
            st=m+1;
    }
    g<<sol;
    return 0;
}
