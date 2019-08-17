/*
    "Given n dwarfs, each one having a height and a length of hands, find the maximum number of dwarfs which can get out of a hole
with height D. A dwarf can get out of the hole if he can get to a height >= D, using his hands, his height and possibly the heights of other
dwarfs"

    * Since n isn't very big, we will try to use DP to find the answer. Let dp[i][j] = maximum height we are still left with if we tried to help
dwarfs from set {1, 2, ..., i} and we got j dwarfs out of the hole.

    * Before running the DP, it's worth mentioning that it's always more optimal to help the weakest dwarfs(those with the smallest sum of height and
length of hands) so we will sort the dwarfs increasingly by this sum.

    * Therefore, the recurrence isn't very hard, dp[i][0] = sum of heights, and dp[i][j] = max(dp[1][j-1], dp[2][j-1], ..., dp[i-1][j-1]) - height[i],
as long as we can actually help dwarf i to get out of the hole. In order to avoid O(n^3) runtime, we are going to keep prefix maximum.

    * The answer will be the biggest j such that there is some dp[i][j] which can be reached

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("pitici3.in");
ofstream g("pitici3.out");
int n, h;
pair<int, int> p[2002];
int ans;
long long mx[3][2002];
bool viz[3][2002];
long long sum = 0;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return (a.first + a.second) < (b.first + b.second);
}
void runDP()
{
    memset(mx, 0, sizeof(mx));
    memset(viz, 0, sizeof(viz));
    mx[1][0] = sum;
    viz[1][0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(!viz[1][j])
                continue;
            if(mx[1][j] + p[i].second >= h)
            {
                viz[2][j + 1] = 1;
                mx[2][j + 1] = max(mx[2][j + 1], mx[1][j] - p[i].first);
                ans = max(ans, j+1);
            }
        }
        for(int j = 0; j <= i; ++j)
        {
            viz[1][j] |= viz[2][j];
            mx[1][j] = max(mx[1][j], mx[2][j]);
        }
        memset(viz[2], 0, sizeof(viz[2]));
        memset(mx[2], 0, sizeof(mx[2]));
    }
}
int main()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
        f >> p[i].first >> p[i].second, sum += p[i].first;
    f >> h;
    sort(p+1, p+n+1, cmp);
    runDP();
    g << ans;
    return 0;
}
