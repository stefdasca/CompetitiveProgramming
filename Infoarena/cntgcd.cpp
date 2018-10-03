#include <bits/stdc++.h>
#define ll long long
using namespace std;
ifstream f("cntgcd.in");
ofstream g("cntgcd.out");
ll n, phi[1000005], sumphi[1000005];
map <ll, ll> m;
ll rec(ll x)
{
    if(x <= 1000000)
        return sumphi[x];
    if(m.find(x) != m.end())
        return m[x];
    ll ans=x*(x+1)/2;
    ll last = x/2, sq = sqrt(x);
    ans-=rec(x/2);
    ans-=(x+1)/2;
    for(ll i=3;i<=sq;++i)
    {
        ans-=rec(x/i);
        ans-=(last-(x/i))*rec(i-1);
        last = x/i;
    }
    for(ll i = (x/sq); i > sq; --i)
        ans-=rec(x/i);
    m[x]=ans;
    return ans;
}
int main()
{
    ll a, b;
    f>> a >> b;
    n = a/b;
    for (int i=1;i<=1000000;++i)
        phi[i] = i;
    for (int i = 2; i <= 1000000; ++i)
        if(phi[i] == i)
            for (int j = i; j <= 1000000; j += i)
            {
                phi[j] /= i;
                phi[j] *= (i-1);
            }
    sumphi[1] = 1;
    for (int i = 2; i <= 1000000; ++i)
        sumphi[i] = phi[i] + sumphi[i-1];
    g<<rec(n)<<'\n';
    return 0;
}
