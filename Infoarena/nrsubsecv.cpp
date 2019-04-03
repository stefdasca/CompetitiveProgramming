/*
         https://www.infoarena.ro/problema/nrsubsecv
         
    "Given an array of n numbers, find for m queries of type (x, y) the number of subarrays which have min value between x and y"
    
    We can use stacks to find for each number the first number in left/right smaller than the current number and then do prefix sums

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("nrsubsecv.in");
ofstream g("nrsubsecv.out");
int n, m, v[1000002], st[1000002], dr[1000002];
long long ans, cc[1000002];
int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
        f >> v[i];
    deque<int>d;
    for(int i = 1; i <= n; ++i)
    {
        while(!d.empty() && v[d.back()] >= v[i])
            d.pop_back();
        if(!d.empty())
            st[i] = d.back();
        d.push_back(i);
    }
    d.clear();
    for(int i = n; i >= 1; --i)
    {
        while(!d.empty() && v[d.back()] > v[i])
            d.pop_back();
        if(!d.empty())
            dr[i] = d.back();
        else
            dr[i] = n+1;
        d.push_back(i);
        cc[v[i]] += 1LL * (dr[i] - i) * (i - st[i]);
    }
    for(int i = 1000000; i >= 0; --i)
        cc[i] += cc[i+1];
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        f >> a >> b;
        long long ans = cc[a] - cc[b+1];
        g << ans << '\n';
    }
    return 0;
}
