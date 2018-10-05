#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
long long n,l,s;
long long cost[100002], lvl[100002];
long long sumpar[100002],len[100002];
long long sol,sum[100002][20];
long long mx[100002],tt[100002][20];
vector<int>v[100002];
bool rau = 0;
void dfss(int dd, int nod)
{
    int q = 0;
    int tata = dd;
    while(dd != 0)
    {
        if(q && tt[dd][q-1] == 0)
            break;
        if(q == 0)
        {
            sum[nod][q] = cost[dd];
            tt[nod][q] = dd;
        }
        else
        {
            sum[nod][q] = sum[nod][q-1] + sum[dd][q-1];
            tt[nod][q] = tt[dd][q-1];
        }
        dd = tt[nod][q];
        ++q;
    }
    for(int i = 0; i < v[nod].size(); ++i)
        lvl[v[nod][i]] = lvl[nod] + 1, dfss(nod, v[nod][i]);
}
int verif(long long st, long long cost, long long path)
{
    bool gg = 1;
    long long ac = 0;
    for(int i = 19; i >= 0; --i)
        if(path & (1<<i))
        {
            ac += sum[st][i];
            st = tt[st][i];
        }
    if(ac > cost)
        return 0;
    return 1;
}
int cb(long long st, long long cost, long long ram)
{
    int b = 0;
    int e = min(lvl[st] , ram);
    int sol = 0;
    while(b <= e)
    {
        int mid = (b+e)/2;
        if(verif(st, cost, mid))
            sol = mid, b = mid + 1;
        else
            e = mid - 1;
    }
    return sol;
}
void dfs(int nod)
{
    if(v[nod].size() == 0)
    {
        sumpar[nod] = cost[nod];
        len[nod] = 1;
        return;
    }
    for(int i = 0; i < v[nod].size(); ++i)
        dfs(v[nod][i]);
    long long mini = -1;
    long long val = -1;
    sol += v[nod].size()-1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        if(len[v[nod][i]] == l || sumpar[v[nod][i]] + cost[nod] > s)
            continue;
        int exp = cb(nod, s - (sumpar[v[nod][i]] + cost[nod]), l - (len[v[nod][i]] + 1));
        if(mini == -1 || exp > val)
            val = exp, mini = i;
    }
    if(mini == -1)
    {
        ++sol;
        sumpar[nod] = cost[nod];
        len[nod] = 1;
        return;
    }
    sumpar[nod] = sumpar[v[nod][mini]] + cost[nod];
    len[nod] = len[v[nod][mini]] + 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin>>n>>l>>s;
    for(int i = 1; i <= n; ++i)
    {
        cin >> cost[i];
        if(cost[i] > s)
            rau = 1;
    }
    if(rau)
    {
        cout << -1;
        return 0;
    }
    for(int i = 2; i <= n; ++i)
    {
        int a;
        cin >> a;
        v[a].push_back(i);
    }
    dfss(0, 1);
    dfs(1);
    cout << sol + 1;
    return 0;
}
