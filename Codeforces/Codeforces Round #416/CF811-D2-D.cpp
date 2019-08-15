#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int ox[] = {-1, 0, 1, 0};
int oy[] = {0, 1, 0, -1};
char di[] = {'U', 'R', 'D', 'L'};

int n, m;
char c[102][102];
bool viz[102][102];
int dis[102][102];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> (c[i] + 1);
    deque<pair<int, int> >d;
    int fx = 0, fy = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(c[i][j] == 'F')
                d.push_back({i, j}), viz[i][j] = 1, fx = i, fy = j;
    while(!d.empty())
    {
        pair<int, int> p = d[0];
        d.pop_front();
        for(int i = 0; i <= 3; ++i)
        {
            int nX = p.fi + ox[i];
            int nY = p.se + oy[i];
            if(!(1 <= nX && nX <= n && 1 <= nY && nY <= m))
                continue;
            if(c[nX][nY] == '*' || viz[nX][nY])
                continue;
            dis[nX][nY] = dis[p.fi][p.se] + 1;
            viz[nX][nY] = 1;
            d.push_back({nX, nY});
        }
    }
    int X = 1, Y = 1;
    if(X == fx && Y == fy)
        return 0;
    if(m != 1 && (c[1][2] == '.' || c[1][2] == 'T'))
    {
        cout << "R" << endl;
        cin >> X >> Y;
        if(Y == 1)
            swap(di[1], di[3]);
        if(X == fx && Y == fy)
            return 0;
        if(n != 1)
        {
            if(c[2][1] == '.' || c[2][1] == 'F')
            {
                if(Y == 2)
                {
                    cout << di[3] << endl;
                    cin >> X >> Y;
                    if(X == fx && Y == fy)
                        return 0;
                }
                cout << "D" << endl;
                cin >> X >> Y;
                if(X == fx && Y == fy)
                    return 0;
                if(X == 1)
                    swap(di[0], di[2]);
            }
            else
            {
                while(c[X+1][Y] == '*')
                {
                    cout << di[1] << endl;
                    cin >> X >> Y;
                    if(X == fx && Y == fy)
                        return 0;
                }
                cout << "D" << endl;
                cin >> X >> Y;
                if(X == fx && Y == fy)
                    return 0;
                if(X == 1)
                {
                    swap(di[0], di[2]);
                    cout << di[2] << endl;
                    cin >> X >> Y;
                }
                if(X == fx && Y == fy)
                    return 0;
            }
        }
    }
    else
        if(n != 1 && (c[2][1] == '.' || c[2][1] == 'T'))
        {
            cout << "D" << endl;
            cin >> X >> Y;
            if(X == 1)
                swap(di[0], di[2]);
            if(X == fx && Y == fy)
                return 0;
            if(m != 1)
            {
                if(c[1][2] == '.' || c[1][2] == 'F')
                {
                    if(X == 2)
                    {
                        cout << di[0] << endl;
                        cin >> X >> Y;
                        if(X == fx && Y == fy)
                            return 0;
                    }
                    cout << "R" << endl;
                    cin >> X >> Y;
                    if(X == fx && Y == fy)
                        return 0;
                    if(Y == 1)
                        swap(di[1], di[3]);
                }
                else
                {
                    while(c[X][Y+1] == '*')
                    {
                        cout << di[2] << endl;
                        cin >> X >> Y;
                        if(X == fx && Y == fy)
                            return 0;
                    }
                    cout << "R" << endl;
                    cin >> X >> Y;
                    if(X == fx && Y == fy)
                        return 0;
                    if(Y == 1)
                    {
                        swap(di[1], di[3]);
                        cout << di[1] << endl;
                        cin >> X >> Y;
                    }
                    if(X == fx && Y == fy)
                        return 0;
                }
            }
        }
    while(X != fx || Y != fy)
    {
        for(int j = 0; j <= 3; ++j)
        {
            if(viz[X + ox[j]][Y + oy[j]] && dis[X][Y] > dis[X + ox[j]][Y + oy[j]])
            {
                cout << di[j] << endl;
                cin >> X >> Y;
                break;
            }
        }
    }
    return 0;
}

