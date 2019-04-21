#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n;
struct aa
{
    int x, y;
};
aa v[100002];
bool cmp(aa a, aa b)
{
    return abs(a.x - a.y) < abs(b.x - b.y);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i].x >> v[i].y;
    sort(v+1, v+n+1, cmp);
    long long sum = 0;
    int st = 1, dr = n;
    for(int i = n; i >= 1; --i)
    {
        long long xa = 1LL * v[i].x * (st - 1) + 1LL * v[i].y * (n - st);
        long long xb = 1LL * v[i].x * (dr - 1) + 1LL * v[i].y * (n - dr);
        if(xa <= xb)
            sum += xa, ++st;
        else
            sum += xb, --dr;
    }
    cout << sum;
    return 0;
}
