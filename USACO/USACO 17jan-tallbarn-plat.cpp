#include<bits/stdc++.h>
using namespace std;
ifstream f("tallbarn.in");
ofstream g("tallbarn.out");
long long n, k;
long long v[100002];
double answer;
bool check(double timp)
{
    long long rm = k;
    for(int i = 1; i <= n; ++i)
        rm -= (long long)((sqrt(1 + 4*v[i]/timp)-1)/2);
    if(rm <= 0)
        return 0;
    return 1;
}
double work(double timp)
{
    double ans = 0.000000;
    long long qq = 0;
    for(int i = 1; i <= n; ++i)
    {
        long long q = (long long)((sqrt(1 + 4*v[i]/timp)-1)/2);
        qq += (long long)q;
        ans = ans + ((0.000000 + v[i]) / (q+1));
    }
    ans = ans - (k - qq) * timp;
    return ans;
}
int main()
{
    f >> n >> k;
    k -= n;
    for(int i = 1; i <= n; ++i)
        f >> v[i];
    double st = 0;
    double dr = 1e18;
    for(int i = 1; i <= 200; ++i)
    {
        double mid = st * 0.50000000 + dr * 0.50000000;
        if(check(mid))
            dr = mid;
        else
            st = mid;
    }
    double sol = work(st);
    long long ssol = round(sol);
    g << ssol;
    return 0;
}
