/*
        IOI 04-Empodia

    Find for each number in array the rightmost position j, j < i, such that v[j] is smaller than v[i] -> I noted that st[pos]
    Find for each number in array the leftmost position j, j > i, such that v[j] is bigger than v[i] -> I noted that dr[pos]

    In order for a framed interval [L, R] to work, the following conditions need to be accomplished

        1. min(v[L], v[L+1], ..., v[R]) = v[L];
        2. max(v[L], v[L+1], ..., v[R]) = v[R];
        3. v[R] - v[L] = R - L

    From (3) results that v[R] - R must be equal to v[L] - L, so we can group the elements by their difference.

    For each group we can keep a stack which keeps the elements in increasing order of their positions in array and
in decreasing order of dr[pos]. Handling the stack in a similar way to the previous stacks will lead us to finding the empodia.

    Getting rid of the ineligible empodia can be done by keeping a set with the empodias and for each new empodio, remove the empodios which end
in a position bigger than the end of the current empodia

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

int n, val[2000002], poz[2000002], sm_emp[2000002];

int st[2000002], dr[2000002];

vector<int> diff[4000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<int> d;
    for(int i = 0; i < n; ++i)
    {
        cin >> val[i];
        while(!d.empty() && val[i] > val[d.back()])
            d.pop_back();
        st[i] = (!d.empty() ? d.back() : 0);
        diff[i - val[i] + n - 1].pb(i);
        d.pb(i);
        sm_emp[i] = n;
    }
    d.clear();
    for(int i = n-1; i >= 0; --i)
    {
        while(!d.empty() && val[i] < val[d.back()])
            d.pop_back();
        dr[i] = (!d.empty() ? d.back() : n);
        d.pb(i);
    }
    for(int df = 0; df <= 2 * n - 1; ++df)
    {
        d.clear();
        for(int poz = 0; poz < diff[df].size(); ++poz)
        {
            int i = diff[df][poz];
            while(!d.empty() && dr[d.back()] < i)
                d.pop_back();
            if(!d.empty() && st[i] <= d.back())
                sm_emp[d.back()] = i;
            while(!d.empty() && dr[d.back()] < dr[i])
                d.pop_back();
            d.pb(i);
        }
    }
    vector<pair<int, int> >ans;
    set<pair<int, int> > sf;
    for(int i = 0; i < n; ++i)
    {
        if(sm_emp[i] == n)
            continue;
        while(!sf.empty() && (*sf.rbegin()).fi >= sm_emp[i])
            sf.erase(*sf.rbegin());
        sf.insert({sm_emp[i], i});
    }
    for(set<pair<int, int> > ::iterator it = sf.begin(); it != sf.end(); ++it)
    {
        pair<int, int> xx = *it;
        swap(xx.fi, xx.se);
        ans.pb(xx);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i].fi + 1 << " " << ans[i].se + 1 << '\n';
    return 0;
}
