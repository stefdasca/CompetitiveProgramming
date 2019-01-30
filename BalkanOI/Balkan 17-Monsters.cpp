/*
                           Balkan 17-Monsters
   
    * First compute prefix sums for each column
    * We will fix 2 lines which are the starting and the end line
    * For each pair of lines, we will do a 2-pointer like approach, where we will compute for each element in matrix the number of rectangles
which contain that element, computing also the number of submatrices a given grid has.
    * Then, after running the algorithm, we will find the position in the matrix which was the most covered and we drop from the previous answer
the value from the most covered position

*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m;
bool mat[752][752];
char c[752];
int columnsum[752][752];
long long value[752][752];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        cin >> (c + 1);
        for(int j = 1; j <= m; ++j)
            mat[i][j] = (c[j] - '0');
    }
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
            columnsum[j][i] = columnsum[j-1][i] + mat[j][i];
    long long ans = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = i; j <= n; ++j)
        {
            int L = 1;
            for(int k = 1; k <= m + 1; ++k)
            {
                if(columnsum[j][k] - columnsum[i-1][k] != (j - i + 1))
                {
                    ans += (k - L) * (k - L + 1) / 2;
                    int sum = 0;
                    for(int x = L; x < k; x++)
                    {
                        sum = sum + L + k - x - x;
                        value[i][x] += sum;
                        value[j + 1][x] -= sum;
                    }
                    L = k + 1;
                }
            }
        }
    long long mx = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            value[i][j] += value[i-1][j], mx = max(mx, value[i][j]);
    cout << ans - mx;
    return 0;
}

