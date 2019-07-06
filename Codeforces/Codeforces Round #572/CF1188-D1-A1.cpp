#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

typedef long long ll;
int n, ok = 1, gr[100002];
vector<int>v[100002];
struct muchii
{
    int a, b;
};
bool rau;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        ++gr[a];
        ++gr[b];
    }
    for(int i = 1; i <= n; ++i)
        if(gr[i] == 2)
            ok = 0;
    if(ok == 1)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}

