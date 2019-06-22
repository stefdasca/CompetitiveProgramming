#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, k, m, lft;
vector<pair<long long, long long> >v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> m;
    int z;
    cin >> z;
    v.push_back({z, 1});
    for(int i = 2; i <= n; ++i)
    {
        int nr;
        cin >> nr;
        if(v.size() && nr == v.back().first)
            v.back().second++;
        else
            v.push_back({nr, 1});
        if(v.back().second == k)
            v.pop_back();
    }
    for(int i = 0; i < v.size(); ++i)
        lft += v[i].second;
    lft *= m;
    int st = 0;
    int dr = v.size() - 1;
    while(st < dr)
    {
        if(v[st].first != v[dr].first)
        {
            cout << lft;
            return 0;
        }
        long long zz = (v[st].second + v[dr].second) / k;
        lft -= 1LL * (m-1) * zz * k;
        if((v[st].second + v[dr].second) % k == 0)
            ++st, --dr;
        else
        {
            cout << lft;
            return 0;
        }
    }
    if(st == dr)
    {
        long long zz = v[st].second * m;
        lft -= (zz/k) * k;
        if(zz % k != 0)
        {
            cout << lft;
            return 0;
        }
        --st;
        ++dr;
        while(st >= 0)
        {
            if(v[st].first != v[dr].first)
            {
                cout << lft;
                return 0;
            }
            long long zz = (v[st].second + v[dr].second) / k;
            lft -= 1LL * zz * k;
            if((v[st].second + v[dr].second) % k == 0)
                --st, ++dr;
            else
            {
                cout << lft;
                return 0;
            }
        }
        cout << lft;
        return 0;
    }
    else
    {
        cout << lft;
        return 0;
    }
    return 0;
}

