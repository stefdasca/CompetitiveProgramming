// https://www.infoarena.ro/problema/aib

#include<bits/stdc++.h>
using namespace std;
ifstream f("aib.in");
ofstream g("aib.out");
int n, m, v[100002], fenwick[100002];
void update(int node, int value)
{
    for(int i = node; i <= n; i += (i & (-i)))
        fenwick[i] += value;
}
int compute(int node)
{
    int ans = 0;
    for(int i = node; i > 0; i -= (i & (-i)))
        ans += fenwick[i];
    return ans;
}
int bin_search(int sum)
{
    int L = 1;
    int R = n;
    int ans = 0;
    while(L <= R)
    {
        int mid = (L + R) / 2;
        if(compute(mid) >= sum)
        {
            R = mid - 1;
            if(compute(mid) == sum)
                ans = mid;
        }
        else
            L = mid + 1;
    } 
    if(ans == 0)
        return -1;
    return ans;
}
int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        f >> v[i];
        update(i, v[i]);
    }
    for(int i = 1; i <= m; ++i)
    {
        int type;
        f >> type;
        if(type == 0)
        {
            int a, b;
            f >> a >> b;
            update(a, b);
        }
        if(type == 1)
        {
            int a, b;
            f >> a >> b;
            g << compute(b) - compute(a-1) << '\n';
        }
        if(type == 2)
        {
            int sum;
            f >> sum;
            g << bin_search(sum) << '\n';
        }
    }
    return 0;
}
