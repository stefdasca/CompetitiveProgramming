/*
        IOI 17-nowruz(79.91+ points)

    Let's split the problem in two cases, the case when the grid is empty and the case when the grid isn't empty.

    * For the first case, we can fill the matrix based on some parity cases in order to maximize the number of leaves resulted.

    * For the second case, we can run the following randomized algorithm:
        While we are still trying to find better answer, we will start our run from a random cell which is not #,
    and mark the cells in some BFS-like manner. The more iterations we're doing, the better our score is going to get.

    * There are also other randomized approaches which work better in general case but they're usually not worth the time for some 10-15 extra
points, especially in a 5 hour contest.

*/

#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 0, +1, -1};
int dy[] = {-1, +1, 0, 0};

int n, m, k;
char arr[1200][1200];
int good[1200][1200];

ifstream f("nowruz.in");
ofstream g("nowruz.out");
int mrk(int i, int j)
{
    return (good[i - 1][j] + good[i + 1][j] + good[i][j - 1] + good[i][j + 1]) == 1;
}

int grid(int i, int j)
{
    return 1 <= i && i <= n && 1 <= j && j <= m && arr[i][j] == '.';
}

int solve_empty()
{
    int T = (m & 1 == 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if(((!(i % 3) && (j & 1) == T) || j == m - 1 || (i % 3 == 2 && j != m-2 && j % 2 == !T) || (i % 3 == 2 && j == m-3) || (i == n-1 && i % 3 == 0)) && !(i % 3 == 2 && j == m-2))
                good[i + 1][j + 1] = 0;
            else
                good[i + 1][j + 1] = 1;
    for (int i = 4; i <= n; i += 3)
    {
        good[i][1] = 1;
        good[i][2] = 0;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (good[i][j] == 0)
                arr[i][j] = 'X';
            else
                cnt += mrk(i, j);
    return cnt;
}

int good_tmp[1200][1200];
vector <pair <int, int>> cells;
int solve_general()
{
    int res = 0;
    for (int it = 1; it <= 1000; it++)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                good[i][j] = 0;
        int x = rand() % n + 1, y = rand() % m + 1;
        while (arr[x][y] == '#')
        {
            x = rand() % n + 1;
            y = rand() % m + 1;
        }
        good[x][y] = 1;
        random_shuffle(cells.begin(), cells.end());
        int need;
        do
        {
            need = 0;
            for (pair <int, int> cur : cells)
            {
                if (good[cur.first][cur.second] == 0 && mrk(cur.first, cur.second) == 1)
                {
                    good[cur.first][cur.second] = 1;
                    need = 1;
                }
            }
        }
        while(need == 1);
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (good[i][j] == 1 && mrk(i, j) == 1)
                    cnt++;
        if (cnt > res)
        {
            res = cnt;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    good_tmp[i][j] = good[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            good[i][j] = good_tmp[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (good[i][j] == 1)
                arr[i][j] = '.';
            else if (arr[i][j] != '#')
                arr[i][j] = 'X';

    return res;
}

int main()
{
    srand(3169);
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    f >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            f >> arr[i][j];
            if (arr[i][j] == '.')
                cells.push_back({i, j});
        }
    int cnt;
    if(cells.size() == n*m)
        cnt = solve_empty();
    else
        cnt = solve_general();
    for(int i = 1; i <= n; g << '\n', i++)
        for(int j = 1; j <= m; j++)
            g << arr[i][j];
    return 0;
}
