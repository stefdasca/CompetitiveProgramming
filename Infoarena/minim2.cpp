#include<bits/stdc++.h>
#define Nmax 100010
using namespace std;
ifstream f("minim2.in");
ofstream g("minim2.out");
int n;
int z[Nmax];
long double dist[Nmax], p[20010], a, b, r;
long double eps = 1e-10;
int itt;
int pz;
int mx;
long double timp;
bool check(long double c)
{
    ++pz;
    timp = 0.00000000;
    for(int i = n; i >= 1; --i)
    {
        int st = 0;
        int dr = mx - 1;
        int ans = 0;
        long double aa = dist[i];
        if(aa - aa * a - c >= eps)
            aa *= a, ++itt;
        while(st <= dr)
        {
            int mid = (st + dr) / 2;
            long double diff = aa * p[mid] - aa * p[mid + 1];
            if(c - diff >= eps)
                ans = mid, dr = mid - 1;
            else
                st = mid + 1;
        }
        timp = timp + aa * p[ans];
        itt += ans;
        if(timp - r > eps)
            return 0;
    }
    return 1;
}
int main()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
        f >> z[i];
    sort(z + 1, z + n + 1);
    for(int i = 1; i <= n; ++i)
        dist[i] = z[i];
    f >> a >> b >> r;
    p[0] = 1.0000000;
    for(int i = 1; i <= 20001; ++i)
    {
        p[i] = p[i-1] * b;
        if(p[i] > eps)
            ++mx;
        else
            break;
    }
    long double st = 0.0000000;
    long double dr = 1000000000.0000000;
    long long ans = 0;
    for(int i = 1; i <= 1000; ++i)
    {
        if(dr - st <= eps)
            break;
        itt = 0;
        long double mid = (st + dr) * 0.500000000;
        if(check(mid))
            st = mid, ans = itt;
        else
            dr = mid;
    }
    check(st);
    g << ans - (int)((r - timp) / st);
    return 0;
}
