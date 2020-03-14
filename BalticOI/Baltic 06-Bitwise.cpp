/*
        Baltic 06-Bitwise

    We can use greedy to solve this problem. Since 2^i > sum of all 2^x with x < i, it's optimal to try to
check if we can create bit i from the biggest i to the smallest i.

    Since we have bitwise AND between sequences, we need to check whether we can get bit i in each of the sequences.
    Also, if we can get bit i from one of the sequences, we should change at most one element to do it, because
we have bitwise OR between the elements from the same sequence.

    Within one sequence, it's optimal to check if we have bit i already in some element, and if that's not the case,
we should try to change some element to get it.

    Last but not least, one should be careful to update the upper bound for the element changed or fixed,
so that we don't lose bit i along the way.

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

ll n, p, sz[102];
pair<ll, ll> seg[102];

int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> p;
    for(int i = 1; i <= p; ++i)
        cin >> sz[i];
    for(int i = 1; i <= n; ++i)
        cin >> seg[i].fi >> seg[i].se;
    ll sum = 0;
    ll mini = 2e9+1e8;
    for(int i = 1; i <= p; ++i)
    {
        ll mxx = 0;
        for(int j = sum+1; j <= sum + sz[i]; ++j)
            mxx = max(mxx, seg[j].se);
        mini = min(mini, mxx);
        sum += sz[i];
    }
    int maxpw = 0;
    while((1LL<<(maxpw+1)) <= mini)
        ++maxpw;
    ll ans = 0;
    for(int j = maxpw; j >= 0; --j)
    {
        bool ok = 1;
        sum = 0;
        for(int i = 1; i <= p; ++i)
        {
            if(!ok)
                break;
            ok = 0;
            for(int poz = sum + 1; poz <= sum + sz[i]; ++poz)
            {
                if(seg[poz].fi & (1<<j))
                {
                    ok = 1;
                    break;
                }
                else
                {
                    int rest = (1LL<<j) - seg[poz].fi % (1LL<<(j+1));
                    if(seg[poz].fi + rest <= seg[poz].se)
                    {
                        ok = 1;
                        break;
                    }
                }
            }
            sum += sz[i];
        }
        if(ok)
        {
            ans += (1<<j);
            sum = 0;
            for(int i = 1; i <= p; ++i)
            {
                bool oki = 0;
                for(int poz = sum + 1; poz <= sum + sz[i]; ++poz)
                {
                    if(seg[poz].fi & (1<<j))
                    {
                        seg[poz].se = min(seg[poz].se, seg[poz].fi + (1<<j) - seg[poz].fi % (1<<j) - 1);
                        oki = 1;
                        break;
                    }
                }
                if(!oki)
                    for(int poz = sum + 1; poz <= sum + sz[i]; ++poz)
                    {
                        if(!(seg[poz].fi & (1<<j)))
                        {
                            int rest = (1LL<<j) - seg[poz].fi % (1LL<<(j+1));
                            if(seg[poz].fi + rest <= seg[poz].se)
                            {
                                seg[poz].fi += rest;
                                seg[poz].se = min(seg[poz].se, seg[poz].fi + (1<<j) - seg[poz].fi % (1<<j) - 1);
                                break;
                            }
                        }
                    }
                sum += sz[i];
            }
        }
    }
    cout << ans;
    return 0;
}
