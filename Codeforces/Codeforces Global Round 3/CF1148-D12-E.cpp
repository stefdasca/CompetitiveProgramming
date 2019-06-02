#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
pair<int, int> v1[300002];
int v2[300002];
struct mutari
{
    int a, b, c;
};
mutari v[2000002];
int xo;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v1[i].first, v1[i].second = i;
    sort(v1 + 1, v1 + n + 1);
    for(int i = 1; i <= n; ++i)
        cin >> v2[i];
    sort(v2 + 1, v2 + n + 1);
    deque<pair<int, int> >dif;
    for(int i = 1; i <= n; ++i)
    {
        if(v1[i].first < v2[i])
            dif.push_back({v2[i] - v1[i].first, v1[i].second});
        else
        {
            while(!dif.empty() && v1[i].first != v2[i])
            {
                int pa = min(dif.back().first, v1[i].first - v2[i]);
                v[++xo] = {dif.back().second, v1[i].second, pa};
                dif.back().first -= pa;
                v1[i].first -= pa;
                if(dif.back().first == 0)
                    dif.pop_back();
            }
            if(v1[i].first != v2[i])
            {
                cout << "NO";
                return 0;
            }
        }
    }
    if(!dif.empty())
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    cout << xo << '\n';
    for(int i = 1; i <= xo; ++i)
        cout << v[i].a << " " << v[i].b << " " << v[i].c << '\n';
    return 0;
}
