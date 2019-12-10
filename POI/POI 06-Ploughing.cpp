/*
        POI 06-Ploughing

    https://github.com/thecodingwizard/competitive-programming/blob/master/POI/POI06-Ploughing.cpp

*/
#include<bits/stdc++.h>
using namespace std;
int k, n, m, a[2002][2002], spL[2002][2002], spC[2002][2002];
int memo[2002][2002];
int ans;
int findsp1(int La, int Ca, int Lb, int Cb)
{
    return spL[La][Cb] - spL[La][Ca - 1];
}
int findsp2(int La, int Ca, int Lb, int Cb)
{
    return spC[Lb][Cb] - spC[La - 1][Cb];
}
int solve(int tip, int La, int Lb, int Ca, int Cb)
{
    if(La > Lb || Ca > Cb)
        return 0;
    if(tip == 0)
    {
        if(memo[Ca][Cb] != -1)
            return memo[Ca][Cb];
        if(findsp1(La, Ca, La, Cb) <= k)
            return solve(tip, La + 1, Lb, Ca, Cb);
        if(findsp1(Lb, Ca, Lb, Cb) <= k)
            return solve(tip, La, Lb - 1, Ca, Cb);
        int mx = (1<<20);
        if(findsp2(La, Ca, Lb, Ca) <= k)
            mx = min(mx, 1 + solve(tip, La, Lb, Ca + 1, Cb));
        if(findsp2(La, Cb, Lb, Cb) <= k)
            mx = min(mx, 1 + solve(tip, La, Lb, Ca, Cb - 1));
        return memo[Ca][Cb] = mx;
    }
    else
    {
        if(memo[La][Lb] != -1)
            return memo[La][Lb];
        if(findsp2(La, Ca, Lb, Ca) <= k)
            return solve(tip, La, Lb, Ca + 1, Cb);
        if(findsp2(La, Cb, Lb, Cb) <= k)
            return solve(tip, La, Lb, Ca, Cb - 1);
        int mx = (1<<20);
        if(findsp1(La, Ca, La, Cb) <= k)
            mx = min(mx, 1 + solve(tip, La + 1, Lb, Ca, Cb));
        if(findsp1(Lb, Ca, Lb, Cb) <= k)
            mx = min(mx, 1 + solve(tip, La, Lb - 1, Ca, Cb));
        return memo[La][Lb] = mx;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k >> n >> m;
    swap(n, m);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            spL[i][j] = spL[i][j-1] + a[i][j];
            spC[i][j] = spC[i-1][j] + a[i][j];
        }
    ans = n + m - 1;
    memset(memo, -1, sizeof(memo));
    ans = min(ans, n + solve(0, 1, n, 1, m));
    memset(memo, -1, sizeof(memo));
    ans = min(ans, m + solve(1, 1, n, 1, m));
    cout << ans;
    return 0;
}
