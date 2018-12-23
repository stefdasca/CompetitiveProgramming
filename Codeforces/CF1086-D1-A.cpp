/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int xa, ya, xb, yb, xc, yc;
bool viz[1002][1002];
bool viz2[1002][1002];
int ox[] = {-1, 0, 1, 0};
int oy[] = {0, 1, 0, -1};
void lee1(int L, int C)
{
    deque<pair<int, int> >d;
    d.push_back({L, C});
    viz[L][C] = 1;
    while(!d.empty())
    {
        int L = d[0].first;
        int C = d[0].second;
        d.pop_front();
        for(int i = 0; i <= 3; ++i)
        {
            int L2 = L + ox[i];
            int C2 = C + oy[i];
            if(L2 < 0 || C2 < 0 || L2 > 1000 || C2 > 1000)
                continue;
            if(viz[L2][C2])
                continue;
            if(abs(xb - L) + abs(yb - C) - 1 == abs(L2 - xb) + abs(C2 - yb))
            {
                viz[L2][C2] = 1;
                d.push_back({L2, C2});
            }
        }
    }
}
void build(int a, int b, int c, int d)
{
    if(b <= d)
    {
        while(b <= d)
            viz2[a][b] = 1, ++b;
        --b;
    }
    else
    {
        while(b >= d)
            viz2[a][b] = 1, --b;
        ++b;
    }
    if(a <= c)
        while(a <= c)
            viz2[a][b] = 1, ++a;
    else
        while(a >= c)
            viz2[a][b] = 1, --a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> xa >> ya;
    cin >> xb >> yb;
    cin >> xc >> yc;
    lee1(xa, ya);
    int mini = 12054;
    int cl = 0;
    int cc = 0;
    for(int i = 0; i <= 1000; ++i)
        for(int j = 0; j <= 1000; ++j)
            if(viz[i][j] && (abs(i - xc) + abs(j - yc) <= mini))
                mini = abs(i - xc) + abs(j - yc), cl = i, cc = j;
    cout << abs(xa - xb) + abs(ya - yb) + mini + 1 << '\n';
    build(xa, ya, cl, cc);
    build(cl, cc, xb, yb);
    build(cl, cc, xc, yc);
    for(int i = 0; i <= 1000; ++i)
        for(int j = 0; j <= 1000; ++j)
            if(viz2[i][j])
                cout << i << " " << j << '\n';
    return 0;
}
