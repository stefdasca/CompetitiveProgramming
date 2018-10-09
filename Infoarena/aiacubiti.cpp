#include<bits/stdc++.h>
using namespace std;
ifstream f("aiacubiti.in");
ofstream g("aiacubiti.out");
int n, v[100002], dp[1025][1025][5], bts[1025];
int main()
{
    f >> n;
    for(int i = 1; i <= 1023; ++i)
        bts[i] = __builtin_popcount(i);
    long long sol = 0;
    for(int i = 1; i <= n; ++i)
    {
        f >> v[i];
        int aa = v[i] >> 10;
        int bb = v[i] & (1024 - 1);
        for (int j = 0; j <= 1023; j++)
        {
            int dist = bts[j ^ bb];
            if(dist <= 4)
                sol += dp[aa][j][4 - dist];
        }

        for (int j = 0; j <= 1023; j++)
            if (bts[j ^ aa] <= 4)
                dp[j][bb][bts[j ^ aa]]++;
    }
    g << sol << '\n';
    return 0;
}
