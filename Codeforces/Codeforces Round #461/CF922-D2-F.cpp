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

using namespace std;

typedef long long ll;

ll n, k, ct, total;
bool oki[300002];
int divi[300002];
int ps[300002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = i + i; j <= n; j += i)
            divi[j]++, ps[j]++;
        ps[i] += ps[i-1];
    }
    if(ps[n] < k)
    {
        cout << "No\n";
        return 0;
    }
    int n = 0;
    while(ps[n] < k)
        ++n;
    int dif = ps[n] - k;
    vector<pair<int, int> >vp;
    for(int i = n; 2 * i > n; --i)
        vp.pb({divi[i], i});
    sort(vp.begin(), vp.end());
    for(int i = vp.size() - 1; i >= 0; --i)
        if(dif >= vp[i].fi)
            oki[vp[i].se] = 1, dif -= vp[i].fi;
    cout << "Yes\n";
    for(int i = 1; i <= n; ++i)
        total += (!oki[i]);
    cout << total << '\n';
    for(int i = 1; i <= n; ++i)
        if(!oki[i])
            cout << i << " ";
    return 0;
}
