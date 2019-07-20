#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;

int n, v[102], ss;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; ++i)
        cin >> v[i], sum += v[i];
    ss = v[1];
    vector<int>vv;
    vv.pb(1);
    for(int i = 2; i <= n; ++i)
        if(v[i] * 2 <= v[1])
            ss += v[i], vv.pb(i);
    int px = sum/2 + 1;
    if(ss < px)
    {
        cout << 0;
    }
    else
    {
        cout << vv.size() << '\n';
        for(int i = 0; i < vv.size(); ++i)
            cout << vv[i] << " ";
    }
    return 0;

}
