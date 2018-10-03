#include<bits/stdc++.h>
using namespace std;
ifstream f("modulo.in");
ofstream g("modulo.out");
long long a,b,c,sol=1;
int main()
{
    f>>a>>b>>c;
    for(;b;b>>=1)
    {
        if(b&1)
            sol=(sol*a)%c;
        a=(a*a)%c;
    }
    g<<sol;
}
