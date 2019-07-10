/*
     * we can find in O(n * m) in which range we are going to use each possible meal, using stacks
     * afterwards, we can create 2D prefix sums using the data computed in the previous step. 
*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

typedef long long ll;

ll n, m, cost[5002][202], v[5002], sc[5002], mat[5002][5002];

int st[5002], dr[5002];
ll mx[202];
void add(int xa, int ya, int xb, int yb, int val)
{
    mat[xa][ya] += val;
    mat[xb+1][ya] -= val;
    mat[xa][yb+1] -= val;
    mat[xb+1][yb+1] += val;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 2; i <= n; ++i)
        cin >> v[i];
    for(int i = 2; i <= n; ++i)
        sc[i] = sc[i-1] + v[i];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> cost[i][j];
    ll ans = 0;
    for(int i = 1; i <= m; ++i)
    {
        deque<int>d;
        for(int j = 1; j <= n; ++j)
        {
            while(!d.empty() && cost[j][i] > cost[d.back()][i])
                d.pop_back();
            if(d.empty())
                st[j] = 1;
            else
                st[j] = d.back() + 1;
            d.push_back(j);
        }
        d.clear();
        for(int j = n; j >= 1; --j)
        {
            while(!d.empty() && cost[j][i] > cost[d.back()][i])
                d.pop_back();
            if(d.empty())
                dr[j] = n;
            else
                dr[j] = d.back() - 1;
            d.push_back(j);
            add(st[j], j, j, dr[j], cost[j][i]);
        }
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            mat[i][j] = mat[i-1][j] + mat[i][j] + mat[i][j-1] - mat[i-1][j-1];
    for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			ans = max(ans, mat[i][j] - (sc[j] - sc[i]));
    cout << ans;
    return 0;
}

