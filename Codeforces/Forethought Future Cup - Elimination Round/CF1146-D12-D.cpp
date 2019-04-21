#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
long long ans, n, a, b;
bool viz[100002];
struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first;
    }
};
// pair<int, int> a; size, mod
priority_queue<pair<int, int>, vector<pair<int, int> >, cmp>d;
bool tk[100002];
long long sumpro(long long t1, long long r, long long termeni)
{
    long long rp = 0;
    rp = rp + t1 * termeni;
    rp = rp + 1LL * (termeni * (termeni-1)) / 2 * r;
    return rp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> a >> b;
    viz[0] = 1;
    d.push({0, 0});
    while(!d.empty())
    {
        pair<int, int> nod = d.top();
        if(nod.first > n)
            break;
        d.pop();
        if(tk[nod.second])
            continue;
        tk[nod.second] = 1;
        long long aa = nod.first / a + (nod.first % a >= nod.second);
        long long fst = a * (nod.first / a) + nod.second;
        if(nod.first >= fst)
            fst += a;
        ans = ans + aa * (n - nod.first + 1);
        long long dif = n / a + (n % a >= nod.second) - aa;
        if(dif > 0)
            ans = ans + dif * (n + 1) - sumpro(fst, a, dif);
        while(1)
        {
            long long pp = nod.second - b + (1LL<<30) * a;
            pp %= a;
            if(viz[pp])
                break;
            viz[pp] = 1;
            if(nod.second >= b)
                d.push({nod.first, pp});
            else
            {
                int rp = b/a;
                int nr = rp*a + nod.second;
                if(nr < b)
                    nr += a;
                d.push({max(nod.first, nr), pp});
            }
        }
    }
    cout << ans << '\n';
    return 0;
}

