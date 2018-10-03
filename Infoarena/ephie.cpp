/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("ephie.in");
ofstream g("ephie.out");
int n,a,b,s,smax,k;
map<int,int>m;
map<int,int> ::iterator it;
int main()
{
    f>>n>>k;
    for(int i=1;i<=n;++i)
    {
        f>>a>>b;
        s+=a;
        m[a+b]++;
        if(i>k)
        {
            it=m.begin();
            s-=it->first;
            if(m[it->first]==1)
                m.erase(it);
            else
                m[it->first]--;
        }
        smax=max(smax,s);
    }
    g<<smax;
    return 0;
}
