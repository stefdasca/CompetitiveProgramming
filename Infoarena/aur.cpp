#include<bits/stdc++.h>
using namespace std;
ifstream f("aur.in");
ofstream g("aur.out");
int c;
int n, xx;
int nrr[990002], nr;
int cc[12], pc;
int main()
{
    f >> c;
    f >> n;
    if(c >= 2)
        f >> xx;
    for(int i = 1; i <= n; ++i)
    {
        int x;
        f >> x;
        pc = 0;
        while(x)
        {
            cc[++pc] = x % 10;
            x /= 10;
        }
        for(int j = pc; j >= 1; --j)
            nrr[++nr] = cc[j];
    }
    if(c == 1)
    {
        g << nr;
        return 0;
    }
    if(c == 2)
    {
        g << nrr[xx] << '\n';
        return 0;
    }
    if(c == 3)
    {
        long long mx = 0;
        for(int i = 1; i + xx - 1 <= nr; ++i)
        {
            long long nrrr = 0;
            for(int j = i; j <= i + xx - 1; ++j)
                nrrr = nrrr * 10 + nrr[j];
            mx = max(mx, nrrr);
        }
        g << mx;
        return 0;
    }
    return 0;
}
