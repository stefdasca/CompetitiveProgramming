/*

     editorial: https://community.topcoder.com/tc?module=Static&d1=match_editorials&d2=srm281

*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

class Equidistance
{
    public:
        ll effort(vector<int> initial, int fixed, ll D)
        {
            if(D < 1)
                D = 1;
            ll ans = 0;
            for(int k = 0; k < initial.size(); ++k)
                ans += abs(initial[fixed] + (k-fixed) * D - initial[k]);
            return ans;
        }
        long long minimumEffort(vector <int> initial)
        {
            sort(initial.begin(), initial.end());
            ll sol = (1LL<<60);
            int n = initial.size();
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                {
                    if(i == j)
                        continue;
                    double D = (double)((ll)initial[j] - initial[i]) / (j-i);
                    sol = min(sol, effort(initial, i, floor(D)));
                    sol = min(sol, effort(initial, i, ceil(D)));
                }
            return sol;
        }
};

