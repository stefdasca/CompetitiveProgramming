#include<bits/stdc++.h>
using namespace std;
ifstream f("perechi3.in");
ofstream g("perechi3.out");
long long T,n,x,ans;
int main()
{
    f>> T;
    while(T--)
    {
        f>> n;
        x = sqrt(n);
        ans = 0LL;
        for(long long i = 1; i<=x;++i)
            ans+=n/i;
        g << 2LL * (ans) - x*x << '\n';
    }

    return 0;
}
