// https://www.infoarena.ro/problema/euclid3

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ifstream f("euclid3.in");
ofstream g("euclid3.out");

int dc = 0;

int cmmdc(int a, int b)
{
    while(b)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int a, b, c;
pair<int, int> euclid(int xa, int ya, int xb, int yb)
{
    if(1LL * xa * a + 1LL * ya * b == dc)
        return {xa, ya};
    ll rap = (1LL * xa * a + 1LL * ya * b) / (1LL * xb * a + 1LL * yb * b);
    return euclid(xb, yb, xa-xb*rap, ya-yb*rap);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    f >> t;
    for(; t; --t)
    {
        f >> a >> b >> c;
        bool sw = 0;
        if(a < b)
            swap(a, b), sw = 1;
        dc = cmmdc(a, b);
        if(c % dc != 0)
            g << "0 0\n";
        else
        {
            pair<int, int> ans = euclid(1, 0, 0, 1);
            if(!sw)
                g << ans.first * (c / dc) << " " << ans.second * (c / dc) << '\n';
            else
                g << ans.second * (c / dc) << " " << ans.first * (c / dc) << '\n';
        }
    }
    return 0;
}
