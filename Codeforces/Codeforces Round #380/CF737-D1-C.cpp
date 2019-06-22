#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, s;
int frq[200002], boss[200002], sp[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for(int i = 1; i <= n; ++i)
    {
        int nr;
        cin >> nr;
        frq[nr]++;
        boss[i] = nr;
    }
    int mxx = (boss[s] == 0);
    int cok = (boss[s] == 0);
    --frq[boss[s]];
    sp[0] = frq[0];
    for(int level = 1; level < n; ++level)
    {
        if(frq[level])
            ++cok, --frq[level];
        sp[level] = sp[level-1] + frq[level];
        int copii = sp[level] - sp[0];
        int oki = cok + min(copii, n - level - 1);
        mxx = max(mxx, oki);
    }
    cout << n - mxx << '\n';
    return 0;
}
