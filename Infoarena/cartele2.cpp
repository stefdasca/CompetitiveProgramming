#include<bits/stdc++.h>
using namespace std;
ifstream f("cartele2.in");
ofstream g("cartele2.out");
int c;
int n;
char a, b;
int h, m, s;
int boy, girl;
int ans2;
int ans3, cm;
int main()
{
    f >> c;
    f >> n;
    int tt;
    for(int i = 1; i <= n; ++i)
    {
        f >> a >> b >> h >> m >> s;
        if(i == 1)
            tt = 3600 * h + 60 * m + s;
        if(boy == girl && boy != 0)
            ans2 += (3600 * h + 60 * m + s) - tt;
        if(boy % 2 == 1)
            cm += (3600 * h + 60 * m + s) - tt;
        else
            cm = 0;
        ans3 = max(ans3, cm);
        if(a == 'b' && b == 'i')
            ++boy;
        if(a == 'b' && b == 'e')
            --boy;
        if(a == 'f' && b == 'i')
            ++girl;
        if(a == 'f' && b == 'e')
            --girl;
        tt = (3600 * h + 60 * m + s);
    }
    if(c == 1)
    {
        g << boy << " " << girl;
        return 0;
    }
    if(c == 2)
    {
        g << ans2;
        return 0;
    }
    if(c == 3)
    {
        g << ans3;
        return 0;
    }
    return 0;
}
