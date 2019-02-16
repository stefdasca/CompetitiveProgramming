#include<bits/stdc++.h>
using namespace std;
ifstream f("nrsec.in");
ofstream g("nrsec.out");
int n, aib[100003];
long long k, sum[100003], sortt[100003];
int anss[100003];
void add(int nod)
{
    for(; nod <= (n + 1); nod += (nod & (-nod)))
        aib[nod]++;
}
int compute(int nod)
{
    int sum = 0;
    for(; nod; nod -= (nod & (-nod)))
        sum += aib[nod];
    return sum;
}
int cb(long long val)
{
    if(val < sortt[1])
        return 0;
    int b = 1;
    int e = (n+1);
    int ans = 0;
    while(b <= e)
    {
        int mid = (b + e) / 2;
        if(val >= sortt[mid])
            ans = mid, b = mid + 1;
        else
            e = mid - 1;
    }
    return ans;
}
bool chk(long long val)
{
    memset(aib, 0, sizeof(aib));
    long long ans = 1LL * n * (n+1) / 2;
    for(int i = 1; i <= n; ++i)
    {
        if(!anss[i-1])
            anss[i-1] = cb(sum[i-1]);
        add(anss[i-1]);
        ans -= compute(cb(sum[i] - val - 1));
    }
    if(ans >= k)
        return 1;
    return 0;
}
int main()
{
    f >> n >> k;
    for(int i = 1; i <= n; ++i)
    {
        f >> sum[i];
        sum[i] += sum[i-1];
        sortt[i] = sum[i];
    }
    sort(sortt + 1, sortt + n + 2);
    long long b = -(1LL<<47);
    long long e = (1LL<<47);
    long long ans = 0;
    while(b <= e)
    {
        long long mid = (b + e) / 2;
        if(chk(mid))
            ans = mid, e = mid - 1;
        else
            b = mid + 1;
    }
    g << ans << '\n';
    return 0;
}
