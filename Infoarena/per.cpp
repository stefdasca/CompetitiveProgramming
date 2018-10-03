/// 25 days passed
#include<bits/stdc++.h>
using namespace std;
ifstream f("per.in");
ofstream g("per.out");
int n, k, m[6005], cnt, pr[6005];
int i, j, kk, p, tot, pref;
char s[6005];
int main()
{
    f>>n>>k;
    f>>s+1;
    for (i = 1; i <= n/k; ++i)
    {
        memset(m, 0, sizeof(m));
        memset(pr, 0, sizeof(pr));
        j=n-i+1;
        kk=n-2*i+1;
        for (pref=0;j<=n;)
            if (s[j] == s[kk])
                ++pref,++j,++kk;
            else
                break;
        pr[n-2*i+1] = pref;
        for (j = n-2*i; j; --j)
            if (s[j] == s[j+i])
            {
                pr[j] = pr[j+1] + 1;
                if (pr[j] > i)
                    pr[j] = i;
            }
            else
                pr[j] = 0;
        for (j = n-i+1; j > n-2*i+1; --j)
            m[j] = 1;
        m[n-2*i+1] = 1 + (pr[n-2*i+1] == i);
        for (j = n-2*i; j; --j)
            if (pr[j] == i)
                m[j] = m[j+i] + 1;
            else
                m[j] = 1;
        for (j = 1; j <= n; ++j)
            cnt+=(m[j]>=k);
    }
    g<<cnt;
    return 0;
}
