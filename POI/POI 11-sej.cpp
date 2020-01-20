/*
        POI 11-sej

    Let's find x = gcd(n, m_k);

    We can observe that the answer is n / the smallest divisor such that none of m_1, m_2, ..., m_(k-1) are multiples of that divisor.
However, this is not good enough, so we need to speed up the process(it takes only 70).

    In order to do this, we will keep a set of all the relevant divisors of all the numbers in the input, this can be done with DFS.
        (a relevant divisor of a number is one of the prime divisors of n)

    Finally, the answer will be the smallest visited divisor at step k

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

// #define fisier 1

using namespace std;

typedef long long ll;

ll n, k, m, ans = (1LL<<60);

ll cmmdc(ll a, ll b)
{
    ll c;
    while(b)
    {
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

vector<ll> primes;
set<ll> s;

void dfs(ll nod, bool chk)
{
    if(chk == 1)
        ans = min(ans, nod);
    s.insert(nod);
    for(int i = 0; i < primes.size(); ++i)
        if(nod % primes[i] == 0 && s.find(nod / primes[i]) == s.end())
            dfs(nod/primes[i], chk);
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    if(k == 1)
    {
        cout << n;
        return 0;
    }
    ll nn = n;
    for(ll i = 2; i * i <= n; ++i)
        if(n % i == 0)
        {
            primes.pb(i);
            while(n % i == 0)
                n /= i;
        }
    if(n > 1)
        primes.pb(n);
    for(int i = 1; i <= k; ++i)
    {
        ll p;
        cin >> p;
        dfs(cmmdc(p, nn), (i == k));
    }
    cout << nn/ans;
    return 0;
}
