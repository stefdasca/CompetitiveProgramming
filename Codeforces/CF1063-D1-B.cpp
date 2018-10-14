#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
int n, m, l, c, x, y;
string s;
char p[2002][2002];
int dist[2002][2002];
int dist2[2002][2002];
int ox[] = {-1, 0, 1, 0};
int oy[] = {0, 1, 0, -1};
struct muie
{
    int x, y, ca, cb;
    bool operator <(const muie &aux) const
    {
        if(ca==aux.ca)
            return cb>aux.cb;
        return ca>aux.ca;
    }
};
priority_queue<muie>q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin >> n >> m;
    cin >> l >> c;
    cin >> x >> y;
    for(int i = 1; i <= n; ++i)
        cin >> (p[i] + 1);
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            dist[i][j] = (1<<30), dist2[i][j] = (1<<30);
    dist[l][c] = 0;
    dist2[l][c] = 0;
    q.push({l, c, 0, 0});
    while(!q.empty())
    {
        int x=q.top().x,y=q.top().y,c=q.top().ca,c1=q.top().cb;
        q.pop();
        if(c!=dist[x][y])
            continue;
        for(int i=0;i<4;i++)
        {
            int x1=x+ox[i],y1=y+oy[i];
            if(x1<1 or x1>n or y1<1 or y1>m or p[x1][y1]=='*')
                continue;
            int cx=c,cy=c1;
            if(i==1)
                cy++;
            if(i==3)
                cx++;
            if(cx<dist[x1][y1])
            {
                dist[x1][y1]=cx, dist2[x1][y1] = cy;
                q.push({x1,y1, cx, cy});
            }
        }
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(dist[i][j] <= x && dist2[i][j] <= y)
                ++ans;
    cout << ans;
    return 0;
}
