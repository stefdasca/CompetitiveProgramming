#include<bits/stdc++.h>
using namespace std;
ifstream f("facebook.in");
ofstream g("facebook.out");
int n,k;
struct arr
{
    int nr;
    int pos;
};
arr v[(1<<18)];
bool test(arr a , arr b)
{
    if(a.nr==b.nr)
        return a.pos<b.pos;
    return a.nr < b.nr;
}
int main()
{
    f>>n>>k;
    for(int i=1;i<=n;++i)
        f>>v[i].nr,v[i].pos=i;
    sort(v+1,v+n+1, test);
    int nmin=(1<<30);
    for(int i=k;i<=n;++i)
        if(v[i].nr==v[i-k+1].nr)
        {
            int d=v[i].pos-1;
            nmin=min(nmin,d-k+1);
        }
    if(nmin==(1<<30))
        g<<-1;
    else
        g<<nmin;
    return 0;
}
