#include<bits/stdc++.h>
#define fading 1048575
using namespace std;
ifstream f("12perm.in");
ofstream g("12perm.out");
int n,v[15000002];
int main()
{
    f>>n;
    v[1]=1;
    v[2]=2;
    v[3]=6;
    v[4]=12;
    for(int i=5;i<=n;++i)
        v[i]=(v[i-1]+v[i-3]+2*(i-2))&fading;
    g<<v[n];
    return 0;
}
