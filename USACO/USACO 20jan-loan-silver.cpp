#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
 
#define fisier 1
 
using namespace std;
 
typedef long long ll;
 
const int mod = 1000000007;
const double dancila = 3.14159265359; // PI 
const double eps = 1e-9;
 
ll n, k, m;
 
ll ok(ll x)
{
    ll day = 0;
    ll sum = 0;
    while(day < k)
    {
        ll rap = (n-sum) / x;
        ll remainder = (n-sum) % x;
        if(rap < m)
        {
            sum += (k-day) * m;
            break;
        }
        ll daysrap = 1 + remainder/rap;
        sum += min(k-day, daysrap) * rap;
        day += min(k-day, daysrap);
    }
    return (sum >= n);
}
int main()
{
    #ifdef fisier
        ifstream cin("loan.in");
        ofstream cout("loan.out");
    #endif
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k >> m;
    
    ll st = 1;
    ll dr = (1LL<<40);
    ll ans = 1;
    while(st <= dr)
    {
        ll mid = (st + dr) / 2;
        if(ok(mid))
            ans = mid, st = mid + 1;
        else
            dr = mid - 1;
    }
    cout << ans;
    return 0;
}
