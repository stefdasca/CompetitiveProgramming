#include<bits/stdc++.h>
using namespace std;
ifstream f("abx.in");
ofstream g("abx.out");
long long n, m;
set<long long>s;
int main()
{
    f >> n >> m;
    s.insert(1);
    for(int j = 2; j <= 1000000; ++j)
    {
        long long p = j;
        int qq = 1;
        while(1)
        {
            ++qq;
            p *= j;
            if(p <= m && (qq & 1))
                s.insert(p);
            if(m / p < j)
                break;
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        long long q;
        f >> q;
        set<long long> ::iterator it;
        it = s.lower_bound(q);
        if(*it > q)
            --it;
        long long ans = -(1LL<<60);
        if(it != s.end())
            if(abs(q - *it) < abs(q - ans))
                ans = *it;
            else
                if(abs(q - *it) == abs(q - ans))
                    ans = min(ans, *it);
        ++it;
        if(it != s.end())
            if(abs(q - *it) < abs(q - ans))
                ans = *it;
            else
                if(abs(q - *it) == abs(q - ans))
                    ans = min(ans, *it);
        long long pp = sqrt(q);
        pp *= pp;
        if(pp <= m)
            if(abs(q - pp) < abs(q - ans))
                ans = pp;
            else
                if(abs(q - pp) == abs(q - ans))
                    ans = min(ans, pp);
        pp = sqrt(q) + 1;
        pp *= pp;
        if(pp <= m)
            if(abs(q - pp) < abs(q - ans))
                ans = pp;
            else
                if(abs(q - pp) == abs(q - ans))
                    ans = min(ans, pp);
        g << ans << '\n';
    }
    return 0;
}
