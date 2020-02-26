/*
        USACO 17jan-subrev-plat

    We can use recursive dp in O(n^4) to solve the problem.

    Let dp[st][dr][sm][bg] = the max length of a increasing subarray if we choose range [st, dr] and the biggest element is bg and the smallest element
is sm

    From dp[st][dr][sm][bg], we must take the max value of several possible cases, based on whether we swap the elements or not and whether we choose
to take the leftmost or the rightmost element or both or none.

    This can be implemented quite easily using state memoization.
*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("subrev.in");
ofstream g("subrev.out");
int n, v[52], dp[52][52][52][52];

bool viz[52][52][52][52];

int solve(int st, int dr, int sm, int bg)
{
    if(st > dr)
        return 0;
    if(st == dr)
        return (sm <= v[st] && v[st] <= bg);
    if(viz[st][dr][sm][bg])
        return dp[st][dr][sm][bg];
    viz[st][dr][sm][bg] = 1;
    if(sm <= v[st] && v[st] <= bg)
    {
        dp[st][dr][sm][bg] = max(dp[st][dr][sm][bg], 1 + solve(st + 1, dr - 1, sm, v[st]));
        dp[st][dr][sm][bg] = max(dp[st][dr][sm][bg], 1 + solve(st + 1, dr, v[st], bg));
    }
    if(sm <= v[dr] && v[dr] <= bg)
    {
        dp[st][dr][sm][bg] = max(dp[st][dr][sm][bg], 1 + solve(st, dr - 1, sm, v[dr]));
        dp[st][dr][sm][bg] = max(dp[st][dr][sm][bg], 1 + solve(st + 1, dr - 1, v[dr], bg));
    }
    if(sm <= v[st] && v[st] <= bg && sm <= v[dr] && v[dr] <= bg)
        dp[st][dr][sm][bg] = max(dp[st][dr][sm][bg], 2 + solve(st + 1, dr - 1, min(v[dr], v[st]), max(v[st], v[dr])));
    dp[st][dr][sm][bg] = max(dp[st][dr][sm][bg], solve(st + 1, dr - 1, sm, bg));
    dp[st][dr][sm][bg] = max(dp[st][dr][sm][bg], solve(st + 1, dr, sm, bg));
    dp[st][dr][sm][bg] = max(dp[st][dr][sm][bg], solve(st, dr - 1, sm, bg));
    return dp[st][dr][sm][bg];
}
int main()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
        f >> v[i];
    g << solve(1, n, 1, 50) << '\n';
    return 0;
}
