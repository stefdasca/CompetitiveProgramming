#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int n, sf[402], sm[402];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if(c == 'M')
            sm[a]++, sm[b+1]--;
        else
            sf[a]++, sf[b+1]--;
    }
    int mx = 0;
    for(int i = 1; i <= 400; ++i)
    {
        sm[i] += sm[i-1];
        sf[i] += sf[i-1];
        mx = max(mx, 2 * min(sf[i], sm[i]));
    }
    cout << mx;
    return 0;
}
