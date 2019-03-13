#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
struct Point
{
    long long x, y;
};
long long dist(Point a, Point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
bool test(Point a, Point b, Point c, Point d)
{
    Point m;
    m.x = (a.x + b.x + c.x + d.x) / 4;
    m.y = (a.y + b.y + c.y + d.y) / 4;
    Point p[4];
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[3] = d;
    if (dist(m, p[0]) == 0)
        return false;
    for (int i = 0; i < 4; i++)
        if (dist(m, p[i]) != dist(m, p[0]))
            return false;
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
        {
            if (dist(p[i], p[j]) == 0)
                return false;
            long long smul = (p[i].x - m.x) * (p[j].x - m.x) + (p[i].y - m.y) * (p[j].y - m.y);
            long long vmul = (p[i].x - m.x) * (p[j].y - m.y) - (p[i].y - m.y) * (p[j].x - m.x);
            if (smul != 0 && vmul != 0)
                return false;
        }
    return true;
}
Point p[42][42];
int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        for (int i = 0; i < 4; i++)
        {
            int xx, yy, aa, bb;
            cin >> xx >> yy >> aa >> bb;
            p[i][0].x = xx;
            p[i][0].y = yy;
            for (int j = 1; j < 4; j++)
            {
                p[i][j].x = aa - (p[i][j - 1].y - bb);
                p[i][j].y = bb + (p[i][j - 1].x - aa);
            }
            for (int j = 0; j < 4; j++)
            {
                p[i][j].x *= 4;
                p[i][j].y *= 4;
            }
        }
        int ans = 12345;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 4; k++)
                    for (int w = 0; w < 4; w++)
                        if (i + j + k + w < ans && test(p[0][i], p[1][j], p[2][k], p[3][w]))
                            ans = i + j + k + w;
        if(ans == 12345)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }
    return 0;
}
