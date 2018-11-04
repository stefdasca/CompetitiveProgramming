#include<bits/stdc++.h>
using namespace std;
ifstream f("heavymetal.in");
ofstream g("heavymetal.out");
int aib[200002];
unordered_map<int, int>sorted;
int n;
struct intervale
{
    int a, b;
};
intervale v[100002];
bool cmp(intervale a, intervale b)
{
    return a.a < b.a;
}
void update(int pos, int val)
{
    for(int i = pos; i <= sorted.size(); i += (i & (-i)))
        aib[i] = max(aib[i], val);
}
int compute(int pos)
{
    int sol = 0;
    for(int i = pos; i; i -= (i & (-i)))
        sol = max(sol, aib[i]);
    return sol;
}
int arr[200002];
int main()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
        f >> v[i].a >> v[i].b, arr[2*i-1] = v[i].a, arr[2*i] = v[i].b;
    sort(arr + 1, arr + 2*n + 1);
    int ax = 0;
    for(int i = 1; i <= 2*n; ++i)
        if(arr[i] > arr[i-1])
        {
            ++ax;
            sorted[arr[i]] = ax;
        }
    int ans = 0;
    sort(v+1, v+n+1, cmp);
    for(int i = 1; i <= n; ++i)
    {
        int val = compute(sorted[v[i].a]) + (v[i].b - v[i].a);
        ans = max(ans, val);
        update(sorted[v[i].b], val);
    }
    g << ans << '\n';
    return 0;
}
