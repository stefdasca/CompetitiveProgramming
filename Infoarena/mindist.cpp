/*
                infoarena mindist

    "Given N (<= 50000) points on a plane which are added one at a time, find for each new point added the closest point added so far.
in Manhattan metric"

    Let's define a new definition for distance: d(xa, ya, xb, yb) = xa - xb + ya - yb, where xa >= xb and ya >= yb.
Obviously, this is wrong if one of the conditions stated above doesn't hold, but here is the catch: We can solve the same problem
four times, for each 90 degrees rotation of the matrix, and this allows us to reduce the problem to a somewhat easier task:
    "Find the point with the biggest sum which is situated north-west of each point"

    We will use sqrt decomposition to answer to the queries more efficiently(BIT with max_sum for points which are farther away,
sets for points which have x in the same bucket with the asked square.

    In order to get 100, one has to optimize the solution a bit more, by avoiding useless queries, which won't change the answer

    Therefore, the total runtime is O(sides * n sqrt n log n), where sides = 4 because we solve the problem once for each side.

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("mindist.in");
ofstream g("mindist.out");
int n;
int buk = 224;
struct pct
{
    int x, y;
    int x2, y2;
};
pct v[50002];
int ans[50002];
int aib[230][50002];
int area[50002], mnn[230], mxx[230];
set<int>s[50002];
void add(int zona, int poz, int nr)
{
    for(; poz <= 50000; poz += (poz & (-poz)))
        aib[zona][poz] = max(aib[zona][poz], nr);
}
int compute(int zona, int poz)
{
    int mxx = -(1<<30);
    for(; poz; poz -= (poz & (-poz)))
        mxx = max(mxx, aib[zona][poz]);
    return mxx;
}
void solve()
{
    for(int i = 1; i <= n; ++i)
    {
        int sum = v[i].x2 + v[i].y2;
        for(int j = area[v[i].x2] - 1; j >= 0; --j)
        {
            if(v[i].x2 - mxx[j] >= ans[i])
                break;
            ans[i] = min(ans[i], sum - compute(j, v[i].y2));
        }
        for(int j = area[v[i].x2] * buk; j <= v[i].x2; ++j)
        {
            if(v[i].x2 - j >= ans[i] || s[j].empty() || *s[j].begin() > v[i].y2)
                continue;
            set<int> ::iterator it = s[j].lower_bound(v[i].y2);
            if(*it > v[i].y2 || it == s[j].end())
                --it;
            ans[i] = min(ans[i], sum - j - *it);
        }
        add(area[v[i].x2], v[i].y2, sum);
        s[v[i].x2].insert(v[i].y2);
    }
}
int main()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
    {
        f >> v[i].x >> v[i].y;
        if(i != 1)
            ans[i] = (1<<30);
    }
    for(int i = 1; i <= 50000; ++i)
    {
        int zonn = i / buk;
        area[i] = zonn;
        if(mnn[zonn] == 0)
            mnn[zonn] = i;
        mxx[zonn] = i;
    }
    for(int i = 1; i <= n; ++i)
        v[i].x2 = v[i].x, v[i].y2 = v[i].y;
    for(int j = 0; j <= 226; ++j)
        for(int k = 1; k <= 50000; ++k)
            aib[j][k] = -(1<<30);
    solve();
    for(int i = 1; i <= 50000; ++i)
        s[i].clear();
    for(int i = 1; i <= n; ++i)
        v[i].x2 = v[i].x, v[i].y2 = 50000 - v[i].y + 1;
    for(int j = 0; j <= 226; ++j)
        for(int k = 1; k <= 50000; ++k)
            aib[j][k] = -(1<<30);
    solve();
    for(int i = 1; i <= 50000; ++i)
        s[i].clear();
    for(int i = 1; i <= n; ++i)
        v[i].x2 = 50000 - v[i].x + 1, v[i].y2 = v[i].y;
    for(int j = 0; j <= 226; ++j)
        for(int k = 1; k <= 50000; ++k)
            aib[j][k] = -(1<<30);
    solve();
    for(int i = 1; i <= 50000; ++i)
        s[i].clear();
    for(int i = 1; i <= n; ++i)
        v[i].x2 = 50000 - v[i].x + 1, v[i].y2 = 50000 - v[i].y + 1;
    for(int j = 0; j <= 226; ++j)
        for(int k = 1; k <= 50000; ++k)
            aib[j][k] = -(1<<30);
    solve();
    for(int i = 1; i <= n; ++i)
        g << ans[i] << '\n';
    return 0;
}
