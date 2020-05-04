#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long t, n, m;
long long xa, ya, xb, yb;
long long xc, yc, xd, yd;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        cin >> n >> m;
        cin >> xa >> ya >> xb >> yb;
        cin >> xc >> yc >> xd >> yd;
        long long ss = n * m;
        long long wh = 0;
        long long bl = 0;
        if(ss % 2 == 1)
            wh = ss / 2 + 1;
        else
            wh = ss / 2;
        bl = ss - wh;
        ss = (xb - xa + 1) * (yb - ya + 1);
        if(ss % 2 == 1)
        {
            wh -= ss / 2;
            bl -= ss / 2;
            if((xa + ya) % 2 == 0)
                --wh;
            else
                --bl;
        }
        else
            wh -= ss / 2, bl -= ss / 2;
        wh += ss;
        ss = (xd - xc + 1) * (yd - yc + 1);
        if(ss % 2 == 1)
        {
            wh -= ss / 2;
            bl -= ss / 2;
            if((xc + yc) % 2 == 0)
                --wh;
            else
                --bl;
        }
        else
            wh -= ss / 2, bl -= ss / 2;
        bl += ss;
        long long a, b, c, d;
        a = max(xa, xc);
        b = max(ya, yc);
        c = min(xb, xd);
        d = min(yb, yd);
      //  cout << wh << " " << bl << '\n';
        if(a <= c && b <= d)
        {
            ss = (c - a + 1) * (d - b + 1);
            wh -= ss;
            wh += ss / 2;
            bl += ss / 2;
            if(ss % 2 == 1)
            {
                if((a + b) % 2 == 0)
                    ++wh;
                else
                    ++bl;
            }
        }
        cout << wh << " " << bl << '\n';
    }
    return 0;
}
