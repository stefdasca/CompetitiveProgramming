#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int q, n;
int v[200002];
int frq[200002], frq0[200002], frq2[200002];
vector<int>wh[200002];
struct cmp
{
    bool operator()(int a, int b)
    {
        return (frq[a] - frq0[a]) < (frq[b] - frq0[b]);
    }
};
priority_queue<int, vector<int>, cmp>qq;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> q;
    for(; q; --q)
    {
        cin >> n;
        for(int i = 1; i <= n; ++i)
        {
            int nr, tip;
            cin >> nr >> tip;
            frq[nr]++;
            if(tip == 0)
                frq0[nr]++;
        }
        for(int i = 1; i <= n; ++i)
            if(frq[i] != 0)
                frq2[frq[i]]++, wh[frq[i]].push_back(i);
        int p2 = n;
        long long ans = 0, ans1 = 0;
        for(int i = n; i >= 1; --i)
        {
            while(p2 >= i)
            {
                for(int j = 0; j < wh[p2].size(); ++j)
                    qq.push(wh[p2][j]);
                --p2;
            }
            if(!qq.empty())
            {
                int nod = qq.top();
                qq.pop();
                ans += i;
                ans1 += min(i, frq[nod] - frq0[nod]);
            }
        }
        while(!qq.empty())
            qq.pop();
        cout << ans << " " << ans1 << '\n';
        for(int i = 1; i <= n; ++i)
            frq[i] = 0, frq2[i] = 0, frq0[i] = 0, wh[i].clear();
    }
    return 0;
}

