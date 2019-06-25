#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
int n;
int ax, ay;
int bx, by;
int cx, cy;
bool gg[1002][1002], rau[1002][1002];
deque<pair<int, int> >d;
int ox[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int oy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool bad(int a, int b)
{
    if(gg[a][b] || rau[a][b])
        return 0;
    if(a <= 0 || a > n || b <= 0 || b > n)
        return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n;
    cin >> ax >> ay;
    for(int i = 1; i <= n; ++i)
        rau[ax][i] = 1;
    for(int i = 1; i <= n; ++i)
        rau[i][ay] = 1;
    for(int i = 1, j = ay - (ax - 1); i <= n && j <= n; ++j, ++i)
        rau[i][j] = 1;
    for(int i = ax, j = ay; i <= n && j >= 1; ++i, --j)
        rau[i][j] = 1;
    for(int i = ax, j = ay; i >= 1 && j <= n; --i, ++j)
        rau[i][j] = 1;
    cin >> bx >> by;
    cin >> cx >> cy;
    gg[bx][by] = 1;
    d.push_back({bx, by});
    while(!d.empty())
    {
        int x = d[0].first;
        int y = d[0].second;
        d.pop_front();
        for(int i = 0; i <= 7; ++i)
        {
            int xa = x + ox[i];
            int xb = y + oy[i];
            if(!bad(xa, xb))
                continue;
            gg[xa][xb] = 1;
            d.push_back({xa, xb});
        }
    }
    if(gg[cx][cy])
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
