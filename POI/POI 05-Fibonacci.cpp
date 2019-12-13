/*

            POI 05-Fibonacci

    I don't know how legit my algorithm is, but here is how it works:

    Firstly, add the values of b to a.

    Then, run this sequence of operations for a finite amount of times:

        - run a for-loop and check at each step if we have 1 on the fibonacci base for positions i and i+1, once in descending order
and once in ascending order.
        - check if we have 1 on the position 0 and transfer it to position 1

    Finally, check the length of the number.

*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

using namespace std;

typedef long long ll;


int add(int a, int b)
{
    ll x = a+b;
    if(x >= mod)
        x -= mod;
    if(x < 0)
        x += mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a*b) % mod;
}

ll pw(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
    long long a = rng();
    return a;
}
int n, m, a[1000005], b[1000005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; ++i)
        cin >> b[i], a[i] += b[i];
    if(n < m)
        n = m;
    for(int xx = 1; xx <= 100; ++xx)
    {
        bool ch = 0;
        if(a[0] && !a[1])
            a[1] = 1, a[0] = 0, ch = 1;
        for(int pp = n+5; pp >= 0; --pp)
            if(a[pp] && a[pp+1])
                ch = 1, a[pp]--, a[pp+1]--, a[pp+2]++;
            else
                if(a[pp] >= 2)
                {
                    if(pp == 1)
                        a[pp+1]++, a[pp] -= 2;
                    else
                    {
                        a[pp+1]++;
                        a[pp]-=2;
                        a[pp-2]++;
                    }
                    ch = 1;
                }
        for(int pp = 1; pp <= n+5; ++pp)
            if(a[pp] && a[pp+1])
                ch = 1, a[pp]--, a[pp+1]--, a[pp+2]++;
            else
                if(a[pp] >= 2)
                {
                    if(pp == 1)
                        a[pp+1]++, a[pp] -= 2;
                    else
                    {
                        a[pp+1]++;
                        a[pp]-=2;
                        a[pp-2]++;
                    }
                    ch = 1;
                }
        if(a[1] >= 2)
            a[2]++, a[1] -= 2, ch = 1;
        if(!ch)
            break;
    }
    n = 1;
    for(int i = 1000004; i >= 1; --i)
        if(a[i] == 1)
        {
            n = i;
            break;
        }
    cout << n << " ";
    for(int i = 1; i <= n; ++i)
        cout << a[i] << " ";
    return 0;
}

