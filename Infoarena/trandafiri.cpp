#include<bits/stdc++.h>
using namespace std;
ifstream f("trandafiri.in");
ofstream g("trandafiri.out");
int n,v[100001];
long long sol;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i];
    sort(v+1,v+n+1);
    for(int i=n;i>1;--i)
        sol+=v[i]-v[i-1]+1;
    g<<sol<<'\n';
    return 0;
}
