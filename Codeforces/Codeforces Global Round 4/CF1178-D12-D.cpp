#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;

int n;
vector<pair<int, int> >ans;
bool prim(int x)
{
    if(x < 2)
        return 0;
    for(int i = 2; i * i <= x; ++i)
        if(x%i == 0)
            return 0;
    return 1;
}
bool ch[5002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i < n; ++i)
        ans.pb({i, i+1});
    ans.pb({n, 1});
    int edg = n;
    int cr = 1;
    while(!prim(edg))
    {
        ans.pb({cr, cr+2});
        ++edg;
        ch[cr] = 1;
        ch[cr+2] = 1;
        while(ch[cr])
            ++cr;
    }
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i].fi << " " << ans[i].se << '\n';
    return 0;
}

