#include<bits/stdc++.h>
using namespace std;
ifstream f("obj.in");
ofstream g("obj.out");
int t,n,k;
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>n>>k;
        if(k%2==0)
            if(n%(k+2)==1)
                g<<"I"<<'\n';
            else
                g<<"G"<<'\n';
        else
            if(n%(2*k+2)==1)
                g<<"I"<<'\n';
            else
                g<<"G"<<'\n';
    }
    return 0;
}
