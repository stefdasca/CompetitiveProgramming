#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
int n;
int frq[1000002];
bool still[1000002];
int mx = 1;
int cc = 0;
map<int, int>m;
void ciur()
{
    int val = 0;
    for(int i = mx + 1; i <= n; ++i)
    {
        frq[i] = 0;
        if(still[i])
            continue;
        for(int j = i; j <= n; j+=i)
        {
            if(still[j])
                continue;
            frq[i]++;
        }
        if(frq[i] >= frq[val])
            val = i;
    }
    mx = val;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        m[i] = 1;
    int sol = 1;
    while(m.size() > 1)
    {
        ciur();
        map<int, int> ::iterator it;
        for(it = m.begin(); it != m.end();)
        {
            int aa = it->first;
            ++it;
            if(aa % mx != 0)
            {
                cout << sol << " ";
                still[aa] = 1;
                m.erase(aa);
                ++cc;
            }
        }
        sol = mx;
    }
    cout << sol << '\n';
    return 0;
}
