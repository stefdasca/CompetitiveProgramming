#include<bits/stdc++.h>
using namespace std;
ifstream f("fructe.in");
ofstream g("fructe.out");
int n;
int a,b;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>a>>b;
        g<<b%2<<'\n';
    }
}
