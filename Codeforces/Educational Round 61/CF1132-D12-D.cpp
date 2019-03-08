#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n, k;
struct el
{
    long long x, y;
};
el v[200002];
long long tru[200002];
int lst[200002];
struct cmp
{
    bool operator()(pair<double, int>a, pair<double, int>b)
    {
        if(abs(a.first - b.first) <= 1e-9)
            return v[a.second].y > v[b.second].y;
        return a.first - b.first > 1e-9;
    }
};
priority_queue<pair<double, int>, vector<pair<double, int> >, cmp>q;
bool check(long long m)
{
    while(!q.empty())
        q.pop();
    for(int i = 1; i <= n; ++i)
        tru[i] = v[i].x;
    long long intt = 0;
    for(int i = 1; i <= n; ++i)
    {
        long long ch = max(0LL, v[i].y * (k - 1) - v[i].x);
        if(m == 0)
        {
            if(ch)
                return 0;
        }
        else
            intt += (ch / m) + (ch % m > 0);
    }
    if(intt > k)
        return 0;
    memset(lst, 0, sizeof(lst));
    for(int i = 1; i <= n; ++i)
        if(1LL * v[i].y * (k - 1) <= tru[i]);
        else
            q.push({(0.000000 + tru[i]) / (0.00000 + v[i].y), i});
    for(int i = 1; i <= k; ++i)
    {
        if(q.empty())
            return 1;
        pair<double, int> z = q.top();
        q.pop();
        if(tru[z.second] - 1LL * (i - 1) * v[z.second].y < 0)
            return 0;
        long long aa = tru[z.second] + m;
        lst[z.second] = i - 1;
        tru[z.second] = aa;
        if((k - 1) * v[z.second].y > tru[z.second])
            q.push({(0.0000 + tru[z.second]) / (0.00000 + v[z.second].y), z.second});
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> v[i].x;
    for(int i = 1; i <= n; ++i)
        cin >> v[i].y;
    long long st = 0;
    long long dr = (1LL<<42);
    long long ans = -1;
    while(st <= dr)
    {
        long long mid = (st + dr) / 2;
        if(check(mid))
            ans = mid, dr = mid - 1;
        else
            st = mid + 1;
    }
    cout << ans;
    return 0;
}

