/*

        SPOJ SUBSET(same as USACO open 2012 gold - subsets)

    editorial: http://usaco.org/current/data/sol_subsets.html

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

using namespace std;

typedef long long ll;

int n, nr[22];
vector<int> st, dr;
vector<pair<int, int> > half(vector<int> S)
{
    vector<pair<int, int>> ans;
    int N = S.size();
    for(int i = 0; i < (1 << N); i++)
        for(int j = i; ; j = (j - 1) & i)
        {
            int sum = 0;
            for(int k = 0; k < N; k++)
            {
                if(j & (1 << k))
                    sum -= S[k];
                else
                    if(i & (1 << k))
                        sum += S[k];
            }
            if(sum >= 0)
                ans.push_back({sum, i});
            if(j == 0)
                break;
        }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> nr[i];
        if(i & 1)
            st.pb(nr[i]);
        else
            dr.pb(nr[i]);
    }
    vector<pair<int, int> > L = half(st);
    vector<pair<int, int> > R = half(dr);
    int p = 0;
    int q = 0;
    int LS = L.size();
    int RS = R.size();
    vector<bool> good(1 << n);
    while(p < LS && q < RS)
    {
        if(L[p].fi < R[q].fi)
            p++;
        else
            if(L[p].fi > R[q].fi)
                q++;
            else
            {
                int p2 = p;
                int q2 = q;
                while(p2 < LS && L[p2].fi == L[p].fi)
                    p2++;
                while(q2 < RS && R[q2].fi == R[q].fi)
                    q2++;
                for(int i = p; i < p2; i++)
                    for(int j = q; j < q2; j++)
                        good[L[i].se | (R[j].se << st.size())] = 1;
                p = p2;
                q = q2;
            }
    }
    int ans = 0;
    for(int i = 0; i < (1<<n); ++i)
        ans += good[i];
    cout << ans << '\n';
    return 0;
}
