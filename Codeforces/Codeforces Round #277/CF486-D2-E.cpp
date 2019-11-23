#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int aib[100002];
void add(int nod, int val)
{
    for(; nod <= 100000; nod += (nod & (-nod)))
        aib[nod] = max(aib[nod], val);
}
int compute(int nod)
{
    int ans = 0;
    for(; nod; nod -= (nod & (-nod)))
        ans = max(ans, aib[nod]);
    return ans;
}

int n, v[100002], len[100002], nr[100002];
vector<int> ps[100002], pmx[100002];

bool cmp(int a, int b)
{
    return v[a] < v[b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    int mx = 0;
    for(int i = 1; i <= n; ++i)
    {
        len[i] = 1 + compute(v[i] - 1);
        mx = max(mx, len[i]);
        ps[len[i]].pb(i);
        add(v[i], len[i]);
    }
    for(int i = mx; i >= 1; --i)
    {
        if(i == mx)
        {
            if(ps[i].size() == 1)
                nr[ps[i][0]] = 3;
            else
                for(int j = 0; j < ps[i].size(); ++j)
                    nr[ps[i][j]] = 2;
            continue;
        }
        pmx[i + 1].resize(ps[i + 1].size() + 2);
        vector<int> ok;
        for(int j = ps[i + 1].size() - 1; j >= 0; --j)
        {
            pmx[i + 1][j] = v[ps[i + 1][j]];
            if(j + 1 < ps[i + 1].size())
                pmx[i + 1][j] = max(pmx[i + 1][j], pmx[i + 1][j + 1]);
        }
        for(int j = 0; j < ps[i].size(); ++j)
        {
            int st = 0;
            int dr = ps[i + 1].size() - 1;
            if(ps[i][j] > ps[i + 1].back())
                continue;
            int ans;
            while(st <= dr)
            {
                int mid = (st + dr) / 2;
                if(ps[i][j] <= ps[i + 1][mid])
                    ans = mid, dr = mid - 1;
                else
                    st = mid + 1;
            }
            int mxx = pmx[i + 1][ans];
            if(v[ps[i][j]] < mxx)
                ok.pb(ps[i][j]);
        }
        ps[i] = ok;
        if(ps[i].size() == 1)
            nr[ps[i][0]] = 3;
        else
            for(int j = 0; j < ps[i].size(); ++j)
                nr[ps[i][j]] = 2;
    }
    for(int i = 1; i <= n; ++i)
    {
        if(nr[i] == 0)
            nr[i] = 1;
        cout << nr[i];
    }
    return 0;
}
