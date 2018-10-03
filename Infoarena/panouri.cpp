#include<bits/stdc++.h>
using namespace std;
ifstream f("panouri.in");
ofstream g("panouri.out");
int n,v[200002],t,nr;
int fr[20002];
bool ist[20002];
int main()
{
    f>>n>>t;
    for(int i=1;i<=n;++i)
        f>>v[i];
    for(int i=1;i<=t;ist[nr]=1,++i)
        f>>nr;
    int s=1;
    int e=1;
    int val=0;
    int lmin=n+1;
    while(s<=e && e<=n)
    {
        ++fr[v[e]];
        if(ist[v[e]]==1 && fr[v[e]]==1)
            ++val;
        while(val==t)
        {
            lmin=min(lmin,e-s);
            --fr[v[s]];
            if(ist[v[s]]==1 && fr[v[s]]==0)
                --val;
            ++s;
        }
        ++e;
    }
    g<<lmin<<'\n';
    return 0;
}
