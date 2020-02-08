/*
        POI 14-Little_Bird

    One can observe that in a range [i, i + k], max_ans(i, i+k) - min_ans(i, i+k) is at most 1, so we can use two deques to keep the values
which return the smaller answer and the values to keep the bigger answer.

    For each i between 2 and n, we will check if the biggest value in the first deque is bigger than the current value, if this happens, then
ans[i] = the smaller answer, otherwise, ans[i] = the smaller answer + 1.

*/
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

// #define fisier 1

using namespace std;

typedef long long ll;

int n, v[1000002], mini, ans[1000002];

deque<int> d[2];
int tv[2];
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];

    int q;
    cin >> q;
    for(; q; --q)
    {
        int range;
        cin >> range;
        d[0].pb(1);
        tv[0] = 0;
        tv[1] = 1;
        for(int i = 2; i <= n; ++i)
        {
            if(i > range + 1)
            {
                if(ans[i - range - 1] == tv[0])
                {
                    if(!d[0].empty() && d[0][0] == i - range - 1)
                        d[0].pop_front();
                    if(d[0].empty())
                    {
                        tv[0]++;
                        tv[1]++;
                        swap(d[0], d[1]);
                    }
                }
                else
                {
                    if(!d[1].empty() && d[1][0] == i - range - 1)
                        d[1].pop_front();
                }
            }
            if(v[d[0][0]] > v[i])
            {
                while(!d[0].empty() && v[d[0].back()] <= v[i])
                    d[0].pop_back();
                d[0].pb(i);
                ans[i] = tv[0];
            }
            else
            {
                while(!d[1].empty() && v[d[1].back()] <= v[i])
                    d[1].pop_back();
                d[1].pb(i);
                ans[i] = tv[1];
            }
        }
        cout << ans[n] << '\n';
        for(int i = 0; i <= 1; ++i)
            d[i].clear();
        for(int i = 1; i <= n; ++i)
            ans[i] = 0;
    }
    return 0;
}
