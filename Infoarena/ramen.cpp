#include<bits/stdc++.h>
using namespace std;
ifstream in("ramen.in");
ofstream out("ramen.out");
int n,d;
set<int>s;
set<int> ::iterator it;
int ans[100002];
struct aa
{
    int care, timp, pi;
};
aa v[100002];
bool cmp(aa a, aa b)
{
    if(a.care == b.care)
        return a.timp < b.timp;
    return a.care < b.care;
}
int main()
{
    in >> n >> d;
    for(int i = 1; i <= n; ++i)
    {
        in >> v[i].timp >> v[i].care;
        v[i].pi = i;
        s.insert(v[i].timp + d);
    }
    sort(v+1, v+n+1, cmp);
    for(int i = 1; i <= n; ++i)
    {
        it = s.lower_bound(v[i].timp - v[i].care);
        ans[v[i].pi] = *it + v[i].care;
        s.erase(it);
    }
    for(int i = 1; i <= n; ++i)
        out << ans[i] << '\n';
    return 0;
}
