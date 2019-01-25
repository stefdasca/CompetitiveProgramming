/*
                            Infoarena secvbest
                (https://www.infoarena.ro/problema/secvbest)

    "Given an array of n elements, split it in k continuous sequences such that the sum of the costs of each of the
sequences is minimal. Cost of a sequence = abs(S - sum of values of sequence), where S is given in input too"

    * It is obvious that dp[i][j] = min(dp[i-1][j-1] + abs(S - sum i-1...i), dp[i-2][j-1] + abs(S - sum i-2...i) + ... + dp[j-1][j-1] + abs(S - sum j-1...i));
      Implementing this would be too slow, so we need to group the elements in array in 2 groups. 1 group will be formed of elements with sum < S, and the other
one of the other elements. An element will be at first in the first group, then as we iterate, it will reach the second group.
We can use the fact that on the first group the difference is decreasing and in the other one they increase, so we will use a stack-like approach to find the
minimal value from both groups.
      Since memory limit doesn't allow us to keep all the lines from dp, we will use just the last two lines for saving memory.

*/

#include<bits/stdc++.h>
using namespace std;
ifstream f("secvbest.in");
ofstream g("secvbest.out");
long long n, k, s, prefsum[100002];
deque<int>poz;
long long dp[100002][3];
deque<int>psmall;
deque<int>pbigger;
void insb(int poz, int pc, int pas)
{
    while(!pbigger.empty() && dp[poz][pas] + (prefsum[pc] - prefsum[poz] - s) < dp[pbigger.back()][pas] + (prefsum[pc] - prefsum[pbigger.back()] - s))
        pbigger.pop_back();
    pbigger.push_back(poz);
}
void inssm(int poz, int pc, int pas)
{
    while(!psmall.empty() && dp[poz][pas] + s - (prefsum[pc] - prefsum[poz]) < dp[psmall.back()][pas] + s - (prefsum[pc] - prefsum[psmall.back()]))
        psmall.pop_back();
    psmall.push_back(poz);
}
int main()
{
    f >> n >> k >> s;
    for(int i = 1; i <= n; ++i)
        f >> prefsum[i], prefsum[i] += prefsum[i-1];
    for(int i = 1; i <= n; ++i)
        dp[i][0] = abs(prefsum[i] - s);
    g << dp[n][0] << " ";
    for(int i = 2; i <= k; ++i)
    {
        psmall.clear();
        pbigger.clear();
        for(int j = i; j <= n; ++j)
        {
            while(!psmall.empty() && prefsum[j] - prefsum[psmall.front()] >= s)
                insb(psmall.front(), j, 0), psmall.pop_front();
            if(prefsum[j] - prefsum[j-1] >= s)
                insb(j - 1, j, 0);
            else
                inssm(j - 1, j, 0);
            dp[j][1] = (1LL<<60);
            if(!psmall.empty())
                dp[j][1] = min(dp[j][1], dp[psmall[0]][0] + s - (prefsum[j] - prefsum[psmall[0]]));
            if(!pbigger.empty())
                dp[j][1] = min(dp[j][1], dp[pbigger[0]][0] + (prefsum[j] - prefsum[pbigger[0]]) - s);
        }
        g << dp[n][1] << " ";
        for(int j = 1; j <= n; ++j)
            dp[j][0] = dp[j][1];
    }
    return 0;
}
