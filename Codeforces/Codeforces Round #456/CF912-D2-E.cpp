#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
    return rng();
}
int n;
int pr[17];
long long k;
set<long long>s1, s2;
long long v1[10000002], v2[10000002], aa, bb;
void gen(long long mx)
{
    s1.insert(1);
    s2.insert(1);
    aa = bb = 1;
    v1[aa] = 1, v2[aa] = 1;
    int p = 1;
    while(p <= aa)
    {
        long long nr = v1[p];
        for(int i = 1; i <= n; i += 2)
            if(mx / nr >= pr[i])
            {
                if(s1.find(pr[i] * nr) != s1.end());
                else
                    v1[++aa] = pr[i] * nr, s1.insert(pr[i] * nr);
            }
        ++p;
    }
    p = 1;
    while(p <= bb)
    {
        long long nr = v2[p];
        for(int i = 2; i <= n; i += 2)
            if(mx / nr >= pr[i])
            {
                if(s2.find(pr[i] * nr) != s2.end());
                else
                    v2[++bb] = pr[i] * nr, s2.insert(pr[i] * nr);
            }
        ++p;
    }
    aa = bb = 0;
    set<long long> ::iterator it;
    for(it = s1.begin(); it != s1.end(); ++it)
        v1[++aa] = *it;
    for(it = s2.begin(); it != s2.end(); ++it)
        v2[++bb] = *it;
}
long long nr(long long mx)
{
    long long counter = 0;
    int b = bb;
    for(int i = 1; i <= aa; ++i)
    {
        while(b >= 1)
        {
            if(mx / v1[i] < v2[b])
                --b;
            else
                break;
        }
        counter += b;
    }
    return counter;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> pr[i];
    cin >> k;
    gen(1LL<<60);
    long long L = 1;
    long long R = (1LL<<60);
    long long ans = 0;
    while(L <= R)
    {
        long long mid = (L + R) / 2;
        if(nr(mid) >= k)
            ans = mid, R = mid - 1;
        else
            L = mid + 1;
    }
    cout << ans;
    return 0;
}
