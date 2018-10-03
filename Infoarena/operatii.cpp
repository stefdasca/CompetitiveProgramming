#include<bits/stdc++.h>
using namespace std;
ifstream f("operatii.in");
ofstream g("operatii.out");
int n;
int v[1000002];
long long sol;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i];
    for(int i=1;i<=n;++i)
        sol+=max(v[i]-v[i+1],0);
    g<<sol;
}
