#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

typedef long long ll;
unordered_set<int> lin[100010], col[100010];
unordered_set<int> ::iterator it;
int n, x[100010], y[100010], sol;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int xx, yy;
        cin >> xx >> yy;
        lin[xx].insert(yy);
        col[yy].insert(xx);
        x[i] = xx;
        y[i] = yy;
    }
    for(int i = 1; i <= n; ++i)
        if(lin[x[i]].size() < col[y[i]].size())
        {
            for(it = lin[x[i]].begin(); it != lin[x[i]].end(); ++it)
            {
                int nr = *it;
                if(nr > y[i])
                    if(col[y[i]].find(x[i]+nr-y[i]) != col[y[i]].end() && col[nr].find(x[i]+nr-y[i]) != col[nr].end())
                        ++sol;
            }
        }
        else
        {
            for(it = col[y[i]].begin(); it != col[y[i]].end(); ++it)
            {
                int nr = *it;
                if(nr > x[i])
                    if(lin[x[i]].find(y[i]+nr-x[i]) != lin[x[i]].end() && lin[nr].find(y[i]+nr-x[i]) != lin[nr].end())
                        sol++;
            }
        }
    cout << sol;
    return 0;
}

