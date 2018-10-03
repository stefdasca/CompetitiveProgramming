#include<bits/stdc++.h>
using namespace std;
ifstream f("mere.in");
ofstream g("mere.out");
int n,k,t;
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>n>>k;
        if(n<k)
            g<<"Remiza"<<'\n';
        else
            if((n/k)%2==1 || (n/k)%2==0 && n%k)
                g<<"Santa Klaus"<<'\n';
            else
                g<<"Remiza"<<'\n';
    }
    return 0;
}
