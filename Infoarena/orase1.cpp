#include<bits/stdc++.h>
using namespace std;
ifstream f("orase1.in");
ofstream g("orase1.out");
int n, k;
int v[1000002];
int cb(int tk)
{
    int b = 0;
    int e = min(1000000000, v[n]);
    int sol = 0;
    while(b <= e)
    {
        int mid = (b+e)/2;
        int aa = 0;
        int lst = -1;
        for(int i = 1; i <= n;)
        {
            if(lst == -1 || v[i] - lst > mid)
            {
                int pos = i;
                while(i <= n && v[i] - v[pos] <= mid)
                    ++i;
                lst = v[i-1];
                ++aa;
            }
            else
                ++i;
        }
        if(aa > tk)
            b = mid + 1;
        else
            sol = mid, e = mid - 1;
    }
    return sol;
}
int test(int mid, int s)
{
    int aa = 0;
    int lst = -1;
    for(int i = 1; i <= n;)
    {
        if(lst == -1 || v[i] - lst > s)
        {
            int pos = i;
            while(i <= n && v[i] - v[pos] <= s)
                ++i;
            lst = v[i-1];
            ++aa;
        }
        else
            ++i;
    }
    if(aa > mid)
        return 0;
    return 1;
}
int main()
{
    f >> n >> k;
    for(int i = 2; i <= n; ++i)
        f >> v[i], v[i] += v[i-1];
    int sol = cb(k);
    int b = 1;
    int e = k;
    int nr = 0;
    while(b <= e)
    {
        int mid = (b+e) / 2;
        if(test(mid, sol))
            nr = mid, e = mid - 1;
        else
            b = mid + 1;
    }
    g << sol << " " << nr << '\n';
    return 0;
}
