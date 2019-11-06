
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

int n;

int grad[1002];
void build(int st, int dr)
{
    grad[st] = n-1;
    for(int j = st+1; j <= dr; ++j)
        grad[j] = n;
    set<pair<int, int> >s;
    for(int j = st; j <= dr; ++j)
        s.insert({grad[j], j});
    while(!s.empty())
    {
        pair<int, int> mx = *s.rbegin();
        s.erase(mx);
        vector<pair<int, int> >v;
        for(int i = 1; i <= mx.fi; ++i)
        {
            v.pb(*s.rbegin());
            s.erase(*s.rbegin());
            cout << mx.se << " " << v.back().se << '\n';
            --v.back().fi;
        }
        for(int i = 0; i < mx.fi; ++i)
            s.insert(v[i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    if(n % 2 == 0)
    {
        cout << "NO\n";
        return 0;
    }
    if(n == 1)
    {
        cout << "YES\n";
        cout << "2 1\n";
        cout << "1 2\n";
        return 0;
    }
    cout << "YES\n";
    cout << 2 * n + 4 << " " << (2 * n + 4) * n / 2 << '\n';
    build(1, n + 2);
    cout << 1 << " " << n + 3 << '\n';
    build(n + 3, 2 * n + 4);
    return 0;
}
