#include<bits/stdc++.h>
using namespace std;
ifstream f("grafc.in");
ofstream g("grafc.out");
int k,n,m;
int main()
{
    f >> k >> n >> m;
    if(k == 1 && n == 1 && m == 1)
    {
        g << 0;
        return 0;
    }
    if((n != 1 && m != 1) || (m == 1 && n == 1 && k <= 3))
    {
        g << -1;
        return 0;
    }
    if(m == 1 && n == 1)
    {
        g << k - 1 << "\n";
        for(int i = 2; i < k; i++)
            g << 1 << " " << i << "\n";
        g << 2 << " " << k << "\n";
        return 0;
    }
    if(m == 1)
    {
        g << k - n << "\n";
        for(int i = 2; i <= k - n + 1; i++)
            g << 1 << " " << i << "\n";
        return 0;
    }
    if(n == 1)
    {
        g << (m-1)*k - m*(m-1)/2 << "\n";
        for(int i = 1; i < m; i++)
            for(int j = i + 1; j <= k; j++)
                g << i << " " << j << "\n";
        return 0;
    }
    return 0;
}
