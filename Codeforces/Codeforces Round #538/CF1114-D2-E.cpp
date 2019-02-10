#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
int ask(int val)
{
    cout << "> " << val << endl;
    int ans;
    cin >> ans;
    return ans;
}
int v[1000002];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int st = 0;
    int dr = 1000000000;
    int mx = 0;
    int pp = 60;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        --pp;
        if(ask(mid))
            mx = mid + 1, st = mid + 1;
        else
            dr = mid - 1;
    }
    vector<int>vv;
    for(int i = 1; i <= min(n, pp); ++i)
    {
        int pos = rand_seed() % n + 1;
        while(v[pos])
            pos = rand_seed() % n + 1;
        v[pos] = 1;
        cout << "? " << pos << endl;
        int val;
        cin >> val;
        vv.push_back(val);
    }
    vv.push_back(mx);
    sort(vv.begin(), vv.end());
    int ans = vv[1] - vv[0];
    for(int i = 1; i < vv.size(); ++i)
        ans = __gcd(ans, vv[i] - vv[i-1]);
    cout << "! " << mx - (n - 1) * ans << " " << ans << endl;
    return 0;
}
