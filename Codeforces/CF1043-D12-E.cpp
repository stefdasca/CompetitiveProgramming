#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
int n, m;
struct oameni
{
    int xa, xb;
};
oameni v[300002];
oameni v2[300002];
long long scor[300002];
long long match(int a, int b)
{
    return min(v[a].xa + v[b].xb, v[a].xb + v[b].xa);
}
bool cmp(oameni a, oameni b)
{
    return (a.xb - a.xa) < (b.xb - b.xa);
}
long long prefx[300002];
long long prefy[300002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n>>m;
    for(int i = 1; i <= n; ++i)
        cin >> v[i].xa >> v[i].xb, v2[i] = v[i];
    sort(v2 + 1, v2 + n + 1, cmp);
    for(int i = 1; i <= n; ++i)
    {
        prefx[i] = prefx[i-1] + v2[i].xa;
        prefy[i] = prefy[i-1] + v2[i].xb;
    }
    for(int i = 1; i <= n; ++i)
    {
        long long b = 1;
        long long e = n;
        long long sol = 0;
        long long dif = v[i].xa - v[i].xb;
        while(b <= e)
        {
            int mid = (b+e)/2;
            if(v2[mid].xb - v2[mid].xa <= -dif)
                sol = mid, b = mid + 1;
            else
                e = mid - 1;
        }
        scor[i] = scor[i] + sol * v[i].xa + prefy[sol];
        scor[i] = scor[i] + (n - sol) * v[i].xb + (prefx[n] - prefx[sol]);
    }
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        scor[a] -= match(a, b);
        scor[b] -= match(b, a);
    }
    for(int i = 1; i <= n; ++i)
        scor[i] -= (v[i].xa + v[i].xb);
    for(int i = 1; i <= n; ++i)
        cout << scor[i] << " ";
    return 0;
}
