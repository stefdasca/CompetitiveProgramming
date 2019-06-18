#include<bits/stdc++.h>
#pragma gcc optimize("O3")
#define mati ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
string s;
deque<int>d[5];
int st[300002];
long long ans;
int main()
{
    mati
    cin >> s;
    int mn = s.size();
    d[0].push_back(1454333), d[1].push_back(1485433);
    for(int i = s.size() - 1; i >= 0; --i)
    {
        bool ok = (s[i] == '1');
        for(int j = 0; d[ok][j] + (d[ok][j] - i) < mn; ++j)
            if(s[d[ok][j]] == s[d[ok][j] + (d[ok][j] - i)])
            {
                mn = d[ok][j] + (d[ok][j] - i);
                break;
            }
        ans += (s.size() - mn);
        d[s[i] - '0'].push_front(i);
    }
    cout << ans;
    return 0;
}
