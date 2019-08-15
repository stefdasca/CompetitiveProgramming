/*

     * We can observe that it's optimal to take in consideration only numbers of form a^b, with a prime

     * For finding whether we have answer >= 3, we can iterate through all numbers of type a^b described in the previous line(there are only
about 1e5 of those) and check the required property in O(1)

     * For answer = 2, we have 2 cases: if b - a + 1 >= 4, we have answer 2(one of a, a+1, a+2, a+3) is multiple of 4.
Otherwise, for each number i in range [a, b], we will iterate among the primes between 2 and cbrt(i) and check whether we have a prime
such that i is multiple of p^2. Otherwise, we can check if the remaining number after division is a perfect square.

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("overpower.in");
ofstream g("overpower.out");
int q;
long long a, b, maxi = (1LL<<61);
vector<long long>v[62];
long long bs(long long val)
{
    long long s = 2;
    long long d = (1<<30);
    long long ans = 0;
    while(s <= d)
    {
        long long mi = (s + d) / 2;
        if(mi * mi <= val)
            ans = mi, s = mi + 1;
        else
            d = mi - 1;
    }
    return ans;
}
vector<int>pr;
bool p[1000002];
int main()
{
    f >> q;
    for(int i = 2; i <= 1000000; ++i)
        if(!p[i])
        {
            pr.push_back(i);
            for(int j = i+i; j <= 1000000; j += i)
                p[j] = 1;
        }
    for(int j = 2; j <= 1000000; ++j)
    {
        if(p[j])
            continue;
        long long pp = j;
        int qq = 1;
        int ct = 1;
        while(1)
        {
            ++qq;
            if(maxi / pp < j)
                break;
            pp *= j;
            if(qq >= 3)
                v[qq].push_back(pp);
        }
    }
    for(int i = 1; i <= q; ++i)
    {
        f >> a >> b;
        int ans = 1;
        if(b - a + 1 >= 4)
            ans = 2;
        else
        {
            for(long long j = a; j <= b; ++j)
            {
                long long j2 = j;
                for(long long ii = 0; ii < pr.size(); ++ii)
                {
                    int nrr = pr[ii];
                    if(j2 % nrr == 0)
                    {
                        int ee = 0;
                        while(j2 % nrr == 0)
                            j2 /= nrr, ++ee;
                        if(ee >= 2)
                            ans = ee;
                    }
                }
                long long p = bs(j2);
                if(p * p == j2)
                    ans = max(ans, 2);
            }
        }
        for(int j = 3; j <= 60; ++j)
            for(int k = 0; k < v[j].size(); ++k)
            {
                if(v[j][k] > b)
                    break;
                long long xpr = b / v[j][k] - a / v[j][k] + (a % v[j][k] == 0);
                if(xpr)
                {
                    ans = j;
                    break;
                }
            }
        g << ans << '\n';
    }
    return 0;
}
