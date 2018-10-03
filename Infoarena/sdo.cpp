#include<bits/stdc++.h>
using namespace std;
ifstream f("sdo.in");
ofstream g("sdo.out");
int n,k;
int v[3000002];
int main()
{
    f>>n>>k;
    for(int i=1;i<=n;++i)
        f>>v[i];
    nth_element(v+1,v+k,v+n+1);
    g<<v[k];
    return 0;
}
