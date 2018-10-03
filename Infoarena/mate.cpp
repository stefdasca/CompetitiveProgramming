#include<bits/stdc++.h>
using namespace std;
ifstream f("mate.in");
ofstream g("mate.out");
int n,i,step,sol=2,v[1<<19],fr[1<<19];
bool check(int L)
{
    for(i=1;i<=n;++i)
        fr[i]=0;
    for(i=1;i<=n;++i)
    {
        fr[v[i]]++;
        if(i>L)
            fr[v[i-L]]--;
        if(fr[v[i]]==(L+1)/2)
            return 1;
    }
    return 0;
}
int main()
{
    f>>n;
    for(i=1;i<=n;++i)
        f>>v[i];
    for(step=1<<18;step;step>>=1)
        if(sol+step<=n && check(sol+step))
            sol+=step;
    g<<sol;
    return 0;
}
