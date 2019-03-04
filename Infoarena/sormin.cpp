/*
        Infoarena sormin(https://www.infoarena.ro/problema/sormin)
        
    "Given n, s and an array a of n elements, find a subset of array a such that the sum of the elements in that subset is s and the OR
sum of the values in the array is as small as possible"

    We can search for the each bit from the answer, and if we can't get to the sum s without using elements which have that bit, we will
add that bit to the answer. The classical knapsack approach is too slow, so we will use the fact that a[i] <= 5000 and create items
with value 1 * a[i], 2 * a[i], 4 * a[i] and so on to improve the running time, because a OR a OR a OR a = a, for each integer a



*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("sormin.in");
ofstream g("sormin.out");
int n, s;
int frq[5002];
bool dp[50002];
bool bd[50002];
int fw[50002], nr[50002];
int main()
{
    f >> n >> s;
    for(int i = 1; i <= n; ++i)
    {
        int nr;
        f >> nr;
        frq[nr]++;
    }
    for(int i = 1; i <= 5000; ++i)
        frq[i] = min(frq[i], s / i);
    int p2 = 1;
    int b = 0;
    int mx = 5000;
    while(!frq[mx])
        --mx;
    while(p2 < mx)
        p2 = p2 * 2 + 1, ++b;
    int ans = 0;
    for(int j = b; j >= 0; --j)
    {
        memset(dp, 0, sizeof(dp)), dp[0] = 1;
        for(int p = mx; p >= 1; --p)
        {
            if((p & (1<<(j + 1))) && !(ans & (1<<(j + 1))))
                bd[p] = 1;
            if(dp[s])
                break;
            if(bd[p])
                continue;
            if(p & (1<<j))
                continue;
            int lft = frq[p];
            int ss = p, vl = 1;
            while(lft)
            {
                for(int j = s - ss; j >= 0; --j)
                    if(dp[j])
                        dp[j + ss] = 1;
                lft -= vl;
                if(lft >= vl * 2)
                {
                    vl *= 2;
                    ss *= 2;
                }
                else
                {
                    vl = lft;
                    ss = lft * p;
                }
                if(dp[s])
                    break;
            }
        }
        if(!dp[s])
            ans += (1<<j);
    }
    g << ans << " ";
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = mx; i >= 1; --i)
    {
        int lft = frq[i];
        int ss = i, vl = 1;
        if(bd[i])
            continue;
        while(lft)
        {
            for(int j = s - ss; j >= 0; --j)
                if(dp[j] && !dp[j + ss])
                {
                    fw[j + ss] = i;
                    dp[j + ss] = 1;
                    nr[j + ss] = vl;
                }
            lft -= vl;
            if(lft >= vl * 2)
            {
                vl *= 2;
                ss *= 2;
            }
            else
            {
                vl = lft;
                ss = lft * i;
            }
            if(dp[s])
                break;
        }
        if(dp[s])
           break;
    }
    vector<int>sol;
    while(s)
    {
        for(int j = 1; j <= nr[s]; ++j)
            sol.push_back(fw[s]);
        s -= fw[s] * nr[s];
    }
    g << sol.size() << '\n';
    for(int i = 0; i < sol.size(); ++i)
        g << sol[i] << " ";
    return 0;
}
