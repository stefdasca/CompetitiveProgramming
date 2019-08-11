/*
        Infoarena arb3

    * Let's sort for each node its sons in order of their initial value. Because we know that the height of the tree is at most 20,
we can use at most 20 binary searches to find the answer for a given query.

    * We are going to simplify a bit the problem, by reducing it to finding the number of the road which passes through a node
for the kth time, while only considering the roads which pass through that node's father. Using some binary search and math,
you can find this out. With the answer we got, we are going to call recursively the same function, but for node's father, until we reach node 1.

    * Basically, in the binary search, we are going to find the leftmost node such that its value is smaller than (initial value of node we're searching
for - number of roads we're interested in) and using prefix sums, we are going to drop some roads which are not necessary for our problem.

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("arb3.in");
ofstream g("arb3.out");
int n, q, tt[100002], val[100002], poz[100002];
vector<int>arb[100002];
vector<long long>sp[100002];
bool cmp(int a, int b)
{
    return val[a] > val[b];
}
int get(int nod, int ct)
{
    if(nod == 1)
        return ct;
    int nx = tt[nod];
    int st = 0;
    int dr = arb[nx].size() - 1;
    int ans = arb[nx].size() - 1;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(val[arb[nx][mid]] <= (val[nod] - ct + 1))
            ans = mid, dr = mid - 1;
        else
            st = mid + 1;
    }
    int sol = 0;
    if(ans == arb[nx].size() - 1 && val[arb[nx].back()] - 1 > val[nod] - ct)
    {
        sol = sp[nx].back() - arb[nx].size() * (val[arb[nx].back()] - 1);
        sol = sol + (val[arb[nx].back()] - 1 - (val[nod] - ct) - 1) * arb[nx].size() + poz[nod] + 1;
    }
    else
    {
        sol = sp[nx][ans] - (ans + 1) * (val[arb[nx][ans]] - 1);
        sol = sol - ans * ((val[nod] - ct) - (val[arb[nx][ans]] - 1));
        sol = sol - (ans - poz[nod]);
    }
    return get(tt[nod], sol);
}
int main()
{
    f >> n >> q;
    for(int i = 2; i <= n; ++i)
    {
        f >> tt[i];
        arb[tt[i]].push_back(i);
        sp[tt[i]].push_back(0);
    }
    for(int i = 1; i <= n; ++i)
        f >> val[i];
    for(int i = 1; i <= n; ++i)
    {
        if(!arb[i].size())
            continue;
        sort(arb[i].begin(), arb[i].end(), cmp);
        for(int j = 0; j < arb[i].size(); ++j)
            poz[arb[i][j]] = j;
        sp[i][0] = val[arb[i][0]];
        for(int j = 1; j < arb[i].size(); ++j)
            sp[i][j] = sp[i][j-1] + val[arb[i][j]];
    }
    for(int i = 1; i <= q; ++i)
    {
        int nod, ct;
        f >> nod >> ct;
        g << get(nod, ct) << '\n';
    }
    return 0;
}
