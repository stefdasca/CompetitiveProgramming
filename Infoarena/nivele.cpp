#include<bits/stdc++.h>
using namespace std;
ifstream f("nivele.in");
ofstream g("nivele.out");
int t;
int n,v[50002],x;
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>n;
        int ok=0;
        for(int i=1;i<=n;++i){
            f>>x;
            while(ok && v[ok]==x)
                --ok,--x;
            v[++ok]=x;
        }
        if(ok==1 && v[1]==1)
            g<<"DA"<<'\n';
        else
            g<<"NU"<<'\n';
    }
    return 0;
}
