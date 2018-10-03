#include<bits/stdc++.h>
using namespace std;
ifstream f("slidingwindow.in");
ofstream g("slidingwindow.out");
int n,d;
struct s
{
    int nr,poz;
};
s v[1000002];
bool test(s a, s b)
{
    return a.nr<b.nr;
}
int main()
{
    f>>n>>d;
    for(int i=1;i<=n;++i)
        f>>v[i].nr,v[i].poz=i;
    int dmin=2e9+1;
    stable_sort(v+1,v+n+1,test);
    for(int i=n;i>=1;--i)
        for(int j=i-1;v[i].nr-v[j].nr<=dmin && j>=1;--j)
            if(abs(v[i].poz-v[j].poz)<=d){
                dmin=min(dmin,v[i].nr-v[j].nr);
                break;
            }
    g<<dmin;
}
