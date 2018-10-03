#include<bits/stdc++.h>
using namespace std;
ifstream f("suma2.in");
ofstream g("suma2.out");
int n;
int v[5];
int x;
int main()
{
    f>>n;
    f>>x;
    v[1]=max(0,x);
    f>>x;
    v[2]=max(0,x);
    for(int i=3;i<=n;++i)
    {
        f>>x;
        v[3]=max(v[2],max(v[1]+x,x));
        v[1]=v[2];
        v[2]=v[3];
    }
    g<<v[3]<<'\n';
    return 0;
}
