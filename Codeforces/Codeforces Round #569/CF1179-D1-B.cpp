#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m;
vector<pair<int, int> >distante;
map<pair<int, int>, int>mp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int st = 1;
    int dr = n;
    while(st < dr)
    {
        int La = st, Ca = 1;
        int Lb = dr, Cb = m;
        bool oki = 0;
        while(Ca <= m || Cb >= 1)
        {
            if(oki == 0)
            {
                distante.push_back({La, Ca});
                ++Ca;
                oki = 1;
            }
            else
            {
                distante.push_back({Lb, Cb});
                --Cb;
                oki = 0;
            }
        }
        ++st;
        --dr;
    }
    if(st == dr)
    {
        int x = m;
        int y = 1;
        bool oki = 1;
        while(x >= y)
        {
            if(oki == 0)
                distante.push_back({st, x}), --x, oki = 1;
            else
                distante.push_back({st, y}), ++y, oki = 0;
        }
    }
    for(int i = 1; i < distante.size(); ++i)
    {
        int oxx = distante[i].first - distante[i-1].first;
        int oyy = distante[i].second - distante[i-1].second;
        if(mp[{oxx, oyy}])
        {
            cout << -1;
            return 0;
        }
        mp[{oxx, oyy}] = 1;
    }
    for(int i = 0; i < distante.size(); ++i)
        cout << distante[i].first << " " << distante[i].second << '\n';
    return 0;
}

