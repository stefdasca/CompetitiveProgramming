#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, T;
int city[402];
struct camioane
{
    int st, sf, consum, refill;
};
camioane v[250002];
int mxx[402][402];
long long mx = 0;
bool check(int a, int b, long long c, long long ct)
{
    if(c >= city[b] - city[a])
        return 1;
    if(mxx[a][b] > c)
        return 0;
    long long nkm = c;
    for(int i = a; i < b; ++i)
    {
        if(i - b >= 200 && nkm >= (city[i + 200] - city[i]))
        {
            nkm -= (city[i + 200] - city[i]);
            i += 199;
            continue;
        }
        if(i - b >= 100 && nkm >= (city[i + 100] - city[i]))
        {
            nkm -= (city[i + 100] - city[i]);
            i += 99;
            continue;
        }
        if(i - b >= 50 && nkm >= (city[i + 50] - city[i]))
        {
            nkm -= (city[i + 50] - city[i]);
            i += 49;
            continue;
        }
        if(i - b >= 25 && nkm >= (city[i + 25] - city[i]))
        {
            nkm -= (city[i + 25] - city[i]);
            i += 24;
            continue;
        }
        if(i - b >= 10 && nkm >= (city[i + 10] - city[i]))
        {
            nkm -= (city[i + 10] - city[i]);
            i += 9;
            continue;
        }
        if(nkm < city[i+1] - city[i])
        {
            --ct;
            if(ct == -1)
                return 0;
            nkm = c;
        }
        nkm -= (city[i+1] - city[i]);
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
    cin >> n >> T;
    for(int i = 1; i <= n; ++i)
        cin >> city[i];
    for(int i = 1; i <= n; ++i)
        for(int j = i + 1; j <= n; ++j)
            mxx[i][j] = max(mxx[i][j-1], city[j] - city[j-1]);
    for(int i = 1; i <= T; ++i)
        cin >> v[i].st >> v[i].sf >> v[i].consum >> v[i].refill;
    shuffle(v + 1, v + T + 1, rng);
    for(int i = 1; i <= T; ++i)
    {
        long long b = mx / v[i].consum - 1;
        long long e = (1LL<<60) / v[i].consum;
        long long ans = (1LL<<60) / v[i].consum;
        if(check(v[i].st, v[i].sf, mx / v[i].consum, v[i].refill) == 1)
            continue;
        while(b <= e)
        {
            long long mid = (b + e) / 2;
            if(check(v[i].st, v[i].sf, mid, v[i].refill) == 1)
                ans = mid, e = mid - 1;
            else
                b = mid + 1;
        }
        mx = max(mx, ans * v[i].consum);
    }
    cout << mx << '\n';
    return 0;
}
