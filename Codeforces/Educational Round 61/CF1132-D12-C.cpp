#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n, q;
struct p
{
    int x, y;
};
p v[5002];
int sum[5002];
int ct1[5002];
int ct2[5002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i <= q; ++i)
    {
        cin >> v[i].x >> v[i].y;
        sum[v[i].x]++;
        sum[v[i].y+1]--;
    }
    for(int i = 1; i <= n; ++i)
        sum[i] += sum[i-1];
    int ansmare = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(sum[i] > 0)
            ++ansmare;
        if(sum[i] == 1)
            ++ct1[i];
        if(sum[i] == 2)
            ++ct2[i];
        ct2[i] += ct2[i-1];
        ct1[i] += ct1[i-1];
    }
    int mx = 0;
    for(int i = 1; i <= q; ++i)
        for(int j = i+1; j <= q; ++j)
        {
            if(v[i].y < v[j].x || v[j].y < v[i].x)
                mx = max(mx, ansmare - (ct1[v[i].y] - ct1[v[i].x - 1]) - (ct1[v[j].y] - ct1[v[j].x - 1]));
            else
            {
                int st = max(v[i].x, v[j].x);
                int dr = min(v[i].y, v[j].y);
                int pred = ansmare;
                pred = pred - (ct2[dr] - ct2[st - 1]);
                pred = pred - (ct1[max(v[i].y, v[j].y)] - ct1[min(v[i].x, v[j].x) - 1]);
                mx = max(mx, pred);
            }
        }
    cout << mx;
    return 0;
}

