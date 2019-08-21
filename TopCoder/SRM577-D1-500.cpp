/*
    editorial = https://apps.topcoder.com/wiki/display/tc/SRM+577#EllysChessboard
*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

class EllysChessboard
{
public:
    int mem[18][18][18][18];
    int n;
    vector<int> x, y;
    int rec(int minx, int maxx, int miny, int maxy)
    {
        int &res = mem[minx][maxx][miny][maxy];
        if (res == -1)
        {
            bool allIn = true;
            res = 1000000000;
            for (int i=0; i<n; i++)
            {
                if((minx <= x[i] && x[i] <= maxx) && (miny <= y[i] && y[i] <= maxy))
                    continue;
                allIn = false;
                int dx = 0, dy = 0;
                int nminx = minx, nmaxx = maxx;
                int nminy = miny, nmaxy = maxy;
                if (x[i] < minx)
                {
                    dx = maxx - x[i];
                    nminx = x[i];
                }
                else
                    if (x[i] > maxx)
                    {
                        dx = x[i] - minx;
                        nmaxx = x[i];
                    }
                    else
                        dx = max( x[i] - minx, maxx - x[i]);
                if (y[i] < miny)
                {
                    dy = maxy - y[i];
                    nminy = y[i];
                }
                else
                    if (y[i] > maxy)
                    {
                        dy = y[i] - miny;
                        nmaxy = y[i];
                    }
                    else
                        dy = max( y[i] - miny, maxy - y[i] );
                int c = max(dx,dy);
                for (int j=0; j<n; j++)
                    if ( i!=j && ( nminx <= x[j] && x[j] <= nmaxx && nminy <= y[j] && y[j] <= nmaxy))
                        if(!( minx <= x[j] && x[j] <= maxx && miny <= y[j] && y[j] <= maxy ))
                        {
                            dx = max( x[j] - nminx, nmaxx - x[j]);
                            dy = max( y[j] - nminy, nmaxy - y[j]);
                            c += max(dx,dy);
                        }
                res = min(res, c + rec(nminx, nmaxx, nminy, nmaxy));
            }
            if (allIn)
                res = 0;
        }
        return res;
    }
    int minCost(vector <string> board)
    {
        for (int i = 0; i < board.size(); i++ )
            for (int j = 0; j < board[i].size(); j++ )
                if (board[i][j] == '#')
                {
                    x.pb(i + j);
                    y.pb(i - j);
                }
        n = x.size();
        if (n == 0)
            return 0;
        int my = (1<<30);
        for(int i = 0; i < n; ++i)
            my = min(my, y[i]);
        for (int i=0; i < n; i ++)
            y[i] -= my;
        memset(mem, -1, sizeof(mem));
        int res = rec(x[0],x[0], y[0],y[0]);
        for (int i=1; i<n; i++)
            res = min(res, rec(x[i],x[i], y[i],y[i]) );
        return res;
    }
};
