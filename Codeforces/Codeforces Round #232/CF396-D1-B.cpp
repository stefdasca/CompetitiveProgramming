#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
bool miillerTest(ll d, ll n)
{
    ll a = 2 + (1LL * rand() * rand() * rand()) % (n - 4);
    ll x = power(a, d, n);

    if (x == 1  || x == n-1)
       return true;
    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)      return false;
        if (x == n-1)    return true;
    }
    return false;
}
bool isPrime(ll n, ll k)
{
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
    ll d = n - 1;
    while (d % 2 == 0)
        d /= 2;
    for (ll i = 0; i < k; i++)
         if (!miillerTest(d, n))
              return false;

    return true;
}
ll cmmdc(ll a, ll b)
{
    ll c;
    while(b)
    {
        c = a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(; t; --t)
    {
        int n;
        cin >> n;
        ll numarator = 0, numitor = 1;
        if(n <= 50)
            for(int i = 2; i <= n; ++i)
            {
                int j = i;
                int k = i+1;
                while(!isPrime(j, 4))
                    --j;
                while(!isPrime(k, 4))
                    ++k;
                ll num = 1LL * j * k;
                ll new_num = num / cmmdc(num, numitor) * numitor;
                numarator = numarator * new_num / numitor + new_num / num;
                numitor = new_num;
                ll dc = cmmdc(numarator, numitor);
                numarator /= dc;
                numitor /= dc;
            }
        else
        {
            int n2 = n - 1;
            while(!isPrime(n2, 4))
                --n2;
            numarator = n2 - 2;
            numitor = (numarator + 2) * 2;
            int j = n2;
            int k = n2 + 1;
            for(int i = n2; i <= n; ++i)
            {
                if(i == n2)
                {
                    while(!isPrime(j, 4))
                        --j;
                    while(!isPrime(k, 4))
                        ++k;
                }
                else
                {
                    if(isPrime(i, 4))
                        j = i, k = j + 1;
                    while(!isPrime(k, 4))
                        ++k;
                }
                ll num = 1LL * j * k;
                ll new_num = num / cmmdc(num, numitor) * numitor;
                numarator = numarator * (new_num / numitor) + new_num / num;
                numitor = new_num;
                ll dc = cmmdc(numarator, numitor);
                numarator /= dc;
                numitor /= dc;
            }
        }
        cout << numarator << "/" << numitor << '\n';
    }
    return 0;
}
