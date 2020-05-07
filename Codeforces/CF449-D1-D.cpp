#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
 
// #define fisier 1
 
using namespace std;
 
typedef long long ll;
 
const int mod = 1000000007;
const double dancila = 3.14159265359; // PI 
const double eps = 1e-9;
 
ll n, v[1000002], frq[2000002];
ll p2[1000002], cnt[2000002];
int sos[1200002];
int main()
{
 
    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n;
    p2[0] = 1;
    for(int i = 1; i <= n; ++i)
        p2[i] = (p2[i-1] * 2) % mod;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        sos[v[i]]++;
    }
    for(int i = 0; i <= 19; ++i)
        for(int j = (1<<20) - 1; j >= 0; --j)
            if(!(j & (1<<i)))
                sos[j] += sos[j ^ (1<<i)];
    for(int i = 0; i <= 1000000; ++i)
        sos[i] = p2[sos[i]] - 1;
    for(int i = 0; i <= 19; ++i)
        for(int j = (1<<20) - 1; j >= 0; --j)
        {
            if(!(j & (1<<i)))
                sos[j] = (sos[j] - sos[j ^ (1<<i)]);
            if(sos[j] < 0)
                sos[j] += mod;
        }
    cout << sos[0] << '\n';
    return 0;
}
