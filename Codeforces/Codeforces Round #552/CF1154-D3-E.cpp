#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;
int n, v[200002], k, ans[200002];
set<int> val, poz;
int pz[200002];
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        val.insert(v[i]);
        poz.insert(i);
        pz[v[i]] = i;
    }
    int te = 2;
    while(!val.empty())
    {
        te = 3 ^ te;
        int ss = *val.rbegin();
        set<int> ::iterator it = poz.lower_bound(pz[ss]);
        set<int> ::iterator it2 = poz.upper_bound(pz[ss]);
        val.erase(ss);
        for(int i = 1; i <= k+1; ++i)
        {
            ans[*it] = te;
            int prv = *it;
            bool stop = 0;
            if(it == poz.begin())
                stop = 1;
            else
                --it;
            val.erase(v[prv]);
            poz.erase(prv);
            if(stop)
                break;
        }
        for(int i = 1; i <= k; ++i)
        {
            if(it2 == poz.end())
                continue;
            ans[*it2] = te;
            int prv = *it2;
            bool stop = 0;
            if(*it2 == *poz.rbegin())
                stop = 1;
            else
                ++it2;
            val.erase(v[prv]);
            poz.erase(prv);
            if(stop)
                break;
        }
    }
    for(int i = 1; i <= n; ++i)
        cout << ans[i];
    return 0;
}
