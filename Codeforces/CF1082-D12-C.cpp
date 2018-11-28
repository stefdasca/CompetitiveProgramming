#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m;
long long mxans[100002];
struct nivele
{
    int materie, suma;
};
nivele v[100002];
bool cmp(nivele a, nivele b)
{
    if(a.materie != b.materie)
        return a.materie < b.materie;
    return a.suma > b.suma;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> v[i].materie >> v[i].suma;
    sort(v+1, v+n+1, cmp);
    int sum = 0;
    int cc = 0;
    long long sol = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(v[i].materie != v[i-1].materie)
            sum = 0, cc = 0;
        sum += v[i].suma;
        ++cc;
        if(sum > 0)
        {
            mxans[cc] += sum;
            sol = max(sol, mxans[cc]);
        }
    }
    cout << sol;
    return 0;
}
