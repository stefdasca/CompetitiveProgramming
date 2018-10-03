#include<bits/stdc++.h>
using namespace std;
ifstream in("hapsan.in");
ofstream out("hapsan.out");
int n, m;
long long b[200002];
long long sum[200002];
long long mx;
struct ing
{
    int st, dr, pi;
};
ing v[200002], v2[200002];
bool cmp1(ing a, ing b)
{
    return a.st < b.st;
}
bool cmp2(ing a, ing b)
{
    return a.dr < b.dr;
}
map<int, int>valmax;
long long Fenwick[200002];
void add(long long nr, long long vl)
{
    for(; nr <= 200000; nr += nr & (-nr))
        Fenwick[nr] = max(Fenwick[nr], vl);
}
long long compute(long long nr)
{
    long long sol = 0;
    for(; nr; nr -= nr & -(nr))
        sol = max(sol, Fenwick[nr]);
    return sol;
}
vector<pair<int, int> >ans[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    in >> n;
    for(int i = 1; i <= n; ++i)
        in >> b[i];
    in >> m;
    for(int i = 1; i <= m; ++i)
        in >> v[i].st >> v[i].dr, v2[i] = v[i];
    sort(v+1, v+m+1, cmp1);
    sort(v2+1, v2+m+1, cmp2);
    int p1 = 1;
    int p2 = 1;
    long long sol = 0;
    for(int i = 1; i <= n; ++i)
    {
        while(v[p1].st == i)
        {
            valmax[v[p1].dr]++;
            ++p1;
        }
        while(v2[p2].dr == i-1)
        {
            valmax[v2[p2].dr]--;
            ++p2;
        }
        for(int j = 0; j < ans[i].size(); ++j)
            add(ans[i][j].first, ans[i][j].second);
        sum[i] = compute(b[i] - 1) + b[i];
        sol = max(sol, sum[i]);
        map<int, int> ::reverse_iterator it;
        it = valmax.rbegin();
        ans[it->first+1].push_back({b[i], sum[i]});
    }
    out << sol << '\n';
    return 0;
}
