#include<bits/stdc++.h>
using namespace std;
ifstream f("chatnoir.in");
ofstream g("chatnoir.out");
int t;
int n,m,c1,c2;
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>n>>m>>c1>>c2;
        if(c2<=5 || m-c2<=4 || c1<=5 || n-c1<=4)
            g<<"DA"<<'\n';
        else
            g<<"NU"<<'\n';
    }
    return 0;
}
