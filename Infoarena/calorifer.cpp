/*
                Infoarena calorifer(https://www.infoarena.ro/problema/calorifer)

        Statement is basically https://codeforces.com/contest/977/problem/D but instead of divide by 3 and multiply by 2,
you multiply by 3 and divide by 2. Also, some of the numbers may miss here and you have to check whether given array can
be arranged or not.

        The idea is similar with the idea from this div3 problem, sort the elements by number of 2 in their prime exponentiation
and check if you can go from the current element to the next one by using the given operations


*/
#include <bits/stdc++.h>
using namespace std;
ifstream f("calorifer.in");
ofstream g("calorifer.out");
long long count2(long long x)
{
    long long ans = 0;
    while(x % 2 == 0)
    {
        ans++;
        x /= 2;
    }
    return ans;
}
long long n;
vector<pair<long long,long long> >v;
bool check()
{
    long long stn = v[0].second;
    for(long long i = 1; i < n; ++i)
    {
        long long p2 = stn;
        long long dv = -v[i-1].first - (-v[i].first);
        for(int j = 1; j <= dv; ++j)
            p2 /= 2;
        while(p2 < v[i].second)
            p2 *= 3;
        if(p2 != v[i].second)
            return 0;
        stn = v[i].second;
    }
    return 1;
}
int main()
{
    f >> n;
    for(long long i = 1; i <= n; i++)
    {
        int nr;
        f >> nr;
        int val = -count2(nr);
        v.push_back({val, nr});
    }
    sort(v.begin(), v.end());
    if(!check())
    {
        g << -1;
        return 0;
    }
    for(int i = 0; i < n; ++i)
        g << v[i].second << " ";
    g << '\n';
    return 0;
}
