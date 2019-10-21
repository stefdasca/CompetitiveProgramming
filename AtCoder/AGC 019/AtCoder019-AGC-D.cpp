#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

string a, b;

int st[2050];
int dr[2050];

int mx1[2050];
int mx2[2050];
int getans()
{
    int n = a.size(), i, j;

    for(i = 0; i < n; i++)
        if(b[i] == '1')
            break;

    if(i >= n)
    {
        for(i = 0; i < n; i++)
            if(a[i] == '1')
                return (1<<30);
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        for(j = i; ; j--)
            if(b[(j + n) % n] == '1')
                break;
        st[i] = j;
        for(j = i; ; j++)
            if(b[j%n] == '1')
                break;
        dr[i] = j;
    }

    int rv = (1<<30);
    for(i = 0; i < n; i++)
    {
        vector <pair<int, int> > v;
        int x = i;
        for (j = 0; j < n; j++)
        {
            if(a[j] == b[(j - i + n) % n])
                continue;
            x++;
            int s = -i + j, e = j;
            if(st[e] >= s)
                continue;
            v.pb({dr[e] - e, (s+n)%n - st[(s+n)%n]});
        }
        sort(v.begin(), v.end());

        mx1[0] = 0;
        for(j = 0; j < v.size(); j++)
            mx1[j + 1] = max(mx1[j], v[j].fi);
        mx2[v.size()] = 0;
        for(j = v.size() - 1; j >= 0; j--)
            mx2[j] = max(mx2[j + 1], v[j].se);

        for(j = 0; j <= v.size(); j++)
            rv = min(rv, x + 2 * (mx1[j] + mx2[j]));
    }
    return rv;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a;
    cin >> b;
    int n = a.size();
	int ans = getans();
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	ans = min(ans, getans());
	if(ans == (1<<30))
        cout << -1;
    else
        cout << ans;
    return 0;
}
