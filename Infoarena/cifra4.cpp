/*
    infoarena cifra4(https://www.infoarena.ro/problema/cifra4)
    
    "Given 2 integers n and c, we will write the list of the natural numbers which don't have digit c, in increasing order, we have to find:
         1. the nth number in the array
         2. given another 2 integers x and y, find the number of removed numbers between x and y"
  
    This is a classical digit dp problem, which also involves binary search for the first part of the problem. At each step of the digit dp
we will keep dp[i][0/1] = number of integers of i digits such that they have(or don't have) digit c

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("cifra4.in");
ofstream g("cifra4.out");
long long pd[20][3];
int t;
long long c, a, b;
long long dp(long long mid, long long c)
{
    if(mid <= 9)
        return (mid >= c);
    long long ans = 0;
    if(c == 0)
        ++ans;
    deque<int>d;
    long long rp = mid;
    while(rp)
    {
        d.push_front(rp % 10);
        rp /= 10;
    }
    memset(pd, 0, sizeof(pd));
    pd[1][0] = 8;
    if(c == 0)
        pd[1][0]++;
    else
        pd[1][1]++;
    ans += pd[1][1];
    for(int i = 1; i + 1 < d.size(); ++i)
    {
        pd[i+1][0] = pd[i][0] * 9;
        pd[i+1][1] = pd[i][0] + pd[i][1] * 10;
        ans += pd[i+1][1];
    }
    bool isC = 0;
    for(int i = 0; i < d.size(); ++i)
    {
        memset(pd, 0, sizeof(pd));
        if(isC == 0)
        {
            for(int j = (i == 0); j < d[i]; ++j)
                if(j == c)
                    pd[i][1]++;
                else
                    pd[i][0]++;
        }
        else
            for(int j = (i == 0); j < d[i]; ++j)
                pd[i][1]++;
        for(int j = i; j + 1 < d.size(); ++j)
        {
            pd[j+1][0] = pd[j][0] * 9;
            pd[j+1][1] = pd[j][0] + pd[j][1] * 10;
        }
        ans += pd[d.size() - 1][1];
        if(d[i] == c)
            isC = 1;
    }
    if(isC)
        ++ans;
    return ans;
}
int main()
{
    f >> t;
    f >> c >> a;
    if(t == 2)
        f >> b;
    if(t == 1)
    {
        long long st = 0;
        long long dr = (1LL<<60);
        long long ans = 0;
        while(st <= dr)
        {
            long long mid = (st + dr) / 2;
            if(mid + 1 - dp(mid, c) < a)
                st = mid + 1;
            else
                ans = mid, dr = mid - 1;
        }
        g << ans << '\n';
    }
    else
    {
        if(a > b)
            swap(a, b);
        g << dp(b, c) - dp(a - 1, c);
    }
    return 0;
}
