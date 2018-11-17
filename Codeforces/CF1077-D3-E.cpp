/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
int v[200002];
map<int, int>mp;
multiset<int>s;
vector<int>er;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    map<int, int> ::iterator it;
    multiset<int, int> ::iterator R;
    vector<int>vv;
    for(it = mp.begin(); it != mp.end(); ++it)
        s.insert(it -> second), vv.push_back(it -> second);
    int maxans = 0;
    for(int i = 0; i < vv.size(); ++i)
    {
        for(int p = 1; p <= vv[i]; ++p)
        {
            int aa = 0;
            er.clear();
            er.push_back(vv[i]);
            R = s.lower_bound(vv[i]);
            s.erase(R);
            aa = p;
            int qx = p;
            while(s.lower_bound(qx + qx) != s.end())
            {
                aa += qx * 2;
                er.push_back(*s.lower_bound(qx + qx));
                s.erase(s.lower_bound(qx + qx));
                qx *= 2;
            }
            for(int Rose = 0; Rose < er.size(); ++Rose)
                s.insert(er[Rose]);
            maxans = max(maxans, aa);
        }
    }
    cout << maxans;
    return 0;
}
