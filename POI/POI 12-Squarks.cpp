/*
        POI 12-Squarks

    If we fix the first three elements, all other elements are uniquely determined. Therefore, we are going to try all the possible tuples,
each tuple has v[1] - (sol_1 + sol_2), v[2] - (sol_1 + sol_3), v[i] - (sol_2 + sol_3).

    For each tuple, we will use the obvious O(n^2) algorithm to check whether all the elements from the multiset are matching with our sums.

*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("Ofast")
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

unordered_map<int, int> mp;
unordered_map<int, int> mp2;
int n, tot, v[302 * 302];

ll sum;
int k;
vector<int> possol;
set<vector<int> >sol;
void tri(int fi, int se, int tr)
{
    mp.clear();
    possol[0] = fi;
    possol[1] = se;
    possol[2] = tr;
    mp[fi+se]++;
    mp[fi+tr]++;
    mp[se+tr]++;
    int pz = 1;
    ll ac = fi + se + tr;
    bool bad = 0;
    for(int i = 3; i < n; ++i)
    {
        if(ac + 1LL * (n - i) * (possol[i-1] + 1) > sum)
            return;
        while(pz <= n * (n-1) / 2)
        {
            if(mp[v[pz]] > 0)
            {
                mp[v[pz]]--;
                if(mp[v[pz]] == 0)
                    mp.erase(v[pz]);
            }
            else
                break;
            ++pz;
        }
        possol[i] = v[pz] - possol[0];
        if(possol[i] <= possol[i-1])
            return;
        ac += possol[i];
        for(int j = 0; j < i; ++j)
        {
            mp[possol[i] + possol[j]]++;
            if(mp2.find(possol[i] + possol[j]) != mp2.end())
            {
                if(mp[possol[i] + possol[j]] > mp2[possol[i] + possol[j]])
                    return;
            }
            else
                return;
        }
        if(bad)
            break;
    }
    if(!bad && sum == ac)
    {
        while(pz <= n * (n-1) / 2)
        {
            if(mp[v[pz]] > 0)
            {
                mp[v[pz]]--;
                if(mp[v[pz]] == 0)
                    mp.erase(v[pz]);
            }
            else
                break;
            ++pz;
        }
        if(pz > n * (n-1) / 2)
            sol.insert(possol);
    }
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n * (n-1) / 2; ++i)
        cin >> v[i], sum += v[i], mp2[v[i]]++;
    sum /= (n-1);
    sort(v + 1, v + n * (n-1) / 2 + 1);
    possol.resize(n);
    for(int i = 3; i <= n; ++i)
        if((v[1] + v[2] + v[i]) % 2 == 0)
        {
            int ts = (v[1] + v[2] + v[i]) / 2;
            tri(ts - v[i], ts - v[2], ts - v[1]);
        }
    cout << sol.size() << '\n';
    for(set<vector<int> > :: iterator it = sol.begin(); it != sol.end(); cout << '\n', ++it)
        for(int j = 0; j < (*it).size(); ++j)
            cout << (*it)[j] << " ";
    return 0;
}
