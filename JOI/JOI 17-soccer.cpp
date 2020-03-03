/*
        JOI 17-soccer

    One can observe that for any optimal solution, we are not going to kick the ball with the same player twice, so we can precompute
dist[i][j] = the smallest distance from (i, j) to some player using multisource BFS.

    Based on this precomputation, we can run now Dijkstra's in the given matrix, our goal being to get to the last player as fast as possible.

    The state will be dp[i][j][k] = the smallest cost to get to (i, j) from direction k(direction 4 = we will change the direction at the current step)

    Based on the value of the direction, we can either kick the ball again, keep kicking or move with the ball somewhere else.

*/
#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

ll n, m, a, b, c, dist[502][502];

pair<int, int> plc[100002];

struct str
{
    int x, y, tip;
    ll cost;
};
struct cmp
{
    bool operator()(str a, str b)
    {
        return a.cost > b.cost;
    }
};
priority_queue<str, vector<str>, cmp> pq;

ll dp[502][502][5];
bool viz[502][502][5];
int ox[] = {-1, 0, 1, 0};
int oy[] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> a >> b >> c;
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= m; ++j)
        {
            for(int dir = 0; dir <= 4; ++dir)
                dp[i][j][dir] = (1LL<<60);
            dist[i][j] = (1<<20);
        }
    int cnt;
    cin >> cnt;
    queue<pair<int, int> >q;
    for(int i = 1; i <= cnt; ++i)
    {
        cin >> plc[i].fi >> plc[i].se;
        dist[plc[i].fi][plc[i].se] = 0;
        q.push({plc[i].fi, plc[i].se});
    }
    while(!q.empty())
    {
        pair<int, int> poz = q.front();
        q.pop();
        for(int i = 0; i <= 3; ++i)
        {
            int nxt_x = poz.fi + ox[i];
            int nxt_y = poz.se + oy[i];
            if(nxt_x < 0 || nxt_x == n+1 || nxt_y < 0 || nxt_y == m+1)
                continue;
            if(dist[nxt_x][nxt_y] == (1<<20))
            {
                dist[nxt_x][nxt_y] = dist[poz.fi][poz.se] + 1;
                q.push({nxt_x, nxt_y});
            }
        }
    }
    dp[plc[1].fi][plc[1].se][4] = 0;
    pq.push({plc[1].fi, plc[1].se, 4, 0});
    while(!pq.empty())
    {
        str state = pq.top();
        pq.pop();
        if(viz[state.x][state.y][state.tip])
            continue;
        viz[state.x][state.y][state.tip] = 1;
        if(state.tip == 4)
        {
            for(int i = 0; i < 4; ++i)
            {
                int nxt_x = state.x + ox[i];
                int nxt_y = state.y + oy[i];
                if(nxt_x < 0 || nxt_x == n+1 || nxt_y < 0 || nxt_y == m+1)
                    continue;
                if(dp[nxt_x][nxt_y][4] > dp[state.x][state.y][4] + c)
                {
                    dp[nxt_x][nxt_y][4] = dp[state.x][state.y][4] + c;
                    pq.push({nxt_x, nxt_y, 4, dp[nxt_x][nxt_y][4]});
                }
            }
            for(int i = 0; i < 4; ++i)
                if(dp[state.x][state.y][4] + b < dp[state.x][state.y][i])
                {
                    dp[state.x][state.y][i] = dp[state.x][state.y][4] + b;
                    pq.push({state.x, state.y, i, dp[state.x][state.y][i]});
                }
        }
        else
        {
            if(dp[state.x][state.y][state.tip] + c * dist[state.x][state.y] < dp[state.x][state.y][4])
            {
                dp[state.x][state.y][4] = dp[state.x][state.y][state.tip] + c * dist[state.x][state.y];
                pq.push({state.x, state.y, 4, dp[state.x][state.y][4]});
            }
            int nxt_x = state.x + ox[state.tip];
            int nxt_y = state.y + oy[state.tip];
            if(nxt_x < 0 || nxt_x == n+1 || nxt_y < 0 || nxt_y == m+1)
                continue;
            if(dp[state.x][state.y][state.tip] + a < dp[nxt_x][nxt_y][state.tip])
            {
                dp[nxt_x][nxt_y][state.tip] = dp[state.x][state.y][state.tip] + a;
                pq.push({nxt_x, nxt_y, state.tip, dp[nxt_x][nxt_y][state.tip]});
            }
        }
    }
    cout << dp[plc[cnt].fi][plc[cnt].se][4] << '\n';
    return 0;
}
