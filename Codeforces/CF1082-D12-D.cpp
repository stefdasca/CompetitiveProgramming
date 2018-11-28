#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, gr[502], m;
bool pus[502];
bool cmp(int a, int b)
{
    return gr[a] < gr[b];
}
struct ans
{
    int a, b;
};
ans v[1000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> gr[i];
    vector<int>gg;
    for(int i = 1; i <= n; ++i)
        if(gr[i] >= 2)
            gg.push_back(i), pus[i] = 1;
    sort(gg.begin(), gg.end(), cmp);
    for(int i = 0; i + 1 < gg.size(); ++i)
    {
        ++m;
        v[m] = {gg[i], gg[i+1]};
        gr[gg[i]]--;
        gr[gg[i+1]]--;
    }
    if(!gg.size())
    {
        cout << "NO";
        return 0;
    }
    bool mga = 0;
    bool mgb = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(!pus[i])
        {
            if(!mga)
            {
                mga = 1;
                gr[gg[0]]--;
                ++m;
                v[m] = {gg[0], i};
            }
            else
                if(!mgb)
                {
                    mgb = 1;
                    gr[gg.back()]--;
                    ++m;
                    v[m] = {gg.back(), i};
                }
                else
                {
                    bool rau = 0;
                    for(int j = 0; j < gg.size(); ++j)
                        if(gr[gg[j]] > 0)
                        {
                            ++m;
                            --gr[gg[j]];
                            v[m] = {gg[j], i};
                            rau = 1;
                            break;
                        }
                    if(rau == 0)
                    {
                        cout << "NO";
                        return 0;
                    }
                }
        }
    }
    cout << "YES ";
    cout << gg.size() - 1 + mga + mgb << '\n';
    cout << m << '\n';
    for(int i = 1; i <= m; ++i)
        cout << v[i].a << " " << v[i].b << '\n';
    return 0;
}
