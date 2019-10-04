/*
            AGC025-D

    * One can observe that it's way easier to solve the problem separately for each forbidden distance,
and then combine the results to find the solution for the problem.

    * In order to solve the problem for one forbidden distance, we are going to mark the squares
recursively in a chessboard-like pattern, as follows:
        - if the distance is odd, we can mark the squares, so that they resemble a chessboard
(color the square (i, j) with (i+j) % 2)
        - if the distance isn't multiple of four, we can mark the squares on odd lines with 1,
and the other ones with 0
        - if the distance is multiple of four, we will solve the problem for the lower left half,
then we will "multiply" the resulted matrix in order to compute the answer for our current n.
    * This works because squares marked with the same color will not have distance equal to d.

    * If we run this algorithm once for each color, then we are going to have four possible distinct combinations
(0, 0), (0, 1), (1, 0), (1, 1)

    * It can be proved using pigeonhole principle that we are going to have at least one combination of colors
such that at least n^2 squares are colored in the same way, thus we found the answer.

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

int n, da, db;
vector<vector<bool> > go(int n, int dist)
{
    vector<vector<bool> >a(2 * n, vector<bool>(2 * n));
    if(dist % 2 == 1)
    {
        for(int i = 0; i < 2 * n; ++i)
            for(int j = 0; j < 2 * n; ++j)
            {
                if((i + j) & 1)
                    a[i][j] = 1;
                else
                    a[i][j] = 0;
            }
    }
    else
        if(dist % 4 != 0)
        {
            for(int i = 0; i < 2 * n; i++)
                for(int j = 0; j < 2 * n; ++j)
                    if(i % 2 == 1)
                        a[i][j] = 1;
                    else
                        a[i][j] = 0;
        }
        else
        {
            vector<vector<bool> > a2 = go((n+1) / 2, dist / 4);
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    if(a2[i][j])
                    {
                        for(int ii = 0; ii < 2; ii++)
                            for(int jj = 0; jj < 2; jj++)
                                a[2 * i + ii][2 * j + jj] = 1;
                    }
        }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> da >> db;
    vector<vector<bool> >v1 = go(n, da);
    vector<vector<bool> >v2 = go(n, db);
    int s = n * n;
    for(int i = 0; i < 2 * n; i++)
        for(int j = 0; j < 2 * n; j++)
            if(!v1[i][j] && !v2[i][j] && s > 0)
            {
                s--;
                cout << i << " " << j << '\n';
            }
    return 0;
}
