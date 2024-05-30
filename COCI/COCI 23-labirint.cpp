/*
  Since there are few queries and the grid is small, we can solve them using flood fill with some bitmasks
*/
#include <bits/stdc++.h>
using namespace std;

int n, m;
char gridL[102][102], gridC[102][102];
int dp[17][102][102];

int mask(char x)
{
    if(x == 'C')
        return 1;
    if(x == 'N')
        return 2;
    if(x == 'P')
        return 4;
    return 8;
}

struct node
{
    int msk, x, y;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> (gridL[i] + 1);
    for(int i = 1; i < n; i++)
        cin >> (gridC[i] + 1);
    
    int q;
    cin >> q;
    
    while(q--)
    {
        int xa, ya, xb, yb;
        cin >> xa >> ya >> xb >> yb;
        for(int msk = 0; msk <= 15; msk++)
            for(int x = 1; x <= n; x++)
                for(int y = 1; y <= m; y++)
                    dp[msk][x][y] = 0;
        
        dp[0][xa][ya] = 1;
        queue<node> q;
        q.push({0, xa, ya});
        
        while(!q.empty())
        {
            node nd = q.front();
            q.pop();
            
            if(nd.x > 1 && dp[(nd.msk | mask(gridC[nd.x - 1][nd.y]))][nd.x - 1][nd.y] == 0)
            {
                dp[(nd.msk | mask(gridC[nd.x - 1][nd.y]))][nd.x - 1][nd.y] = 1;
                q.push({(nd.msk | mask(gridC[nd.x - 1][nd.y])), nd.x - 1, nd.y});
            }
            if(nd.x < n && dp[(nd.msk | mask(gridC[nd.x][nd.y]))][nd.x + 1][nd.y] == 0)
            {
                dp[(nd.msk | mask(gridC[nd.x][nd.y]))][nd.x + 1][nd.y] = 1;
                q.push({(nd.msk | mask(gridC[nd.x][nd.y])), nd.x + 1, nd.y});
            }
            
            if(nd.y > 1 && dp[(nd.msk | mask(gridL[nd.x][nd.y - 1]))][nd.x][nd.y - 1] == 0)
            {
                dp[(nd.msk | mask(gridL[nd.x][nd.y - 1]))][nd.x][nd.y - 1] = 1;
                q.push({(nd.msk | mask(gridL[nd.x][nd.y - 1])), nd.x, nd.y - 1});
            }
            if(nd.y < m && dp[(nd.msk | mask(gridL[nd.x][nd.y]))][nd.x][nd.y + 1] == 0)
            {
                dp[(nd.msk | mask(gridL[nd.x][nd.y]))][nd.x][nd.y + 1] = 1;
                q.push({(nd.msk | mask(gridL[nd.x][nd.y])), nd.x, nd.y + 1});
            }
        }
        int ans = 4;
        for(int msk = 0; msk <= 15; msk++)
            if(dp[msk][xb][yb] == 1)
                ans = min(ans, __builtin_popcount(msk));
        cout << ans << '\n';
    }
    return 0;
}
