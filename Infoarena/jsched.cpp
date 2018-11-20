#include<bits/stdc++.h>
using namespace std;
ifstream f("jsched.in");
ofstream g("jsched.out");
int n;
long long ans;
struct ala
{
    int t, w;
    double rap;
};
ala v[100002];
bool cmp(ala a, ala b)
{
    return a.rap < b.rap;
}
int main()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
        f >> v[i].t >> v[i].w, v[i].rap = (0.0000 + v[i].t) / (0.0000 + v[i].w);
    long long sum = 0;
    sort(v+1, v+n+1, cmp);
    for(int i = 1; i <= n; ++i)
    {
        sum += v[i].t;
        ans += sum * v[i].w;
    }
    g << ans << '\n';
    return 0;
}
