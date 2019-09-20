/*
        Infoarena Xreverse

    * Let's compute dp[i][j][k] = number of way to write a number of i digits, if the remainder is j and the reminder of the
reverse is k. Obviously, computing it from dp[i-1] values will TLE.

    * But, we can compute the dp array in a divide-and-conquer approach, thus computing the dp values for values n, n/2, n/4 and so on.

    * Let's say we have to compute dp[n] matrix. dp[n] matrix will be the product of dp[n/2], dp[n/2] and dp[n%2].

    * We can unite two dp matrixes in O(k^4) using some formulas, therefore the total complexity will be O(k^4 log n)
*/

#include<bits/stdc++.h>
#define pb push_back

using namespace std;

typedef long long ll;

ifstream f("xreverse.in");
ofstream g("xreverse.out");

int n, k, rest, p10[1000002], p102[1000002], rst[100002];

map<int, vector<vector<int> >> sum, dp;

vector<vector<int> >zero;
void dc(int n)
{
    if(n == 1)
    {
        vector<vector<int> >v, v2;
        v = zero;
        v2 = zero;
        for(int i = 1; i <= 9; ++i)
        {
            v[rst[i]][rst[i]] += i;
            v2[rst[i]][rst[i]] ++;
        }
        sum[n] = v;
        dp[n] = v2;
        return;
    }
    int mid = n / 2;
    dc(mid);
    vector<vector<int> >v, v2, vv, vv2;
    v = sum[mid];
    v2 = dp[mid];
    bool impar = (n % 2 == 1);
    if(impar)
    {
        vv = zero;
        vv2 = zero;
        for(int j = 0; j < k; ++j)
            for(int p = 0; p < k; ++p)
            {
                int nnr = rst[(j * 10)];
                int ninv = p;
                for(int next_digit = 1; next_digit <= 9; ++next_digit)
                {
                    nnr = rst[nnr + 1];
                    ninv = rst[ninv + p102[n / 2]];
                    vv2[nnr][ninv] += v2[j][p];
                    if(vv2[nnr][ninv] >= rest)
                        vv2[nnr][ninv] -= rest;
                    vv[nnr][ninv] += (v[j][p] * 10) + (v2[j][p] * next_digit);
                    vv[nnr][ninv] %= rest;
                }
            }
        v = vv;
        v2 = vv2;
    }
    vv = sum[mid];
    vv2 = dp[mid];
    vector<vector<int> > ans1, ans2;
    ans1 = zero;
    ans2 = zero;
    for(int j = 0; j < k; ++j)
        for(int p = 0; p < k; ++p)
        {
            if(!v[j][p] && !v2[j][p])
                continue;
            for(int r = 0; r < k; ++r)
                for(int s = 0; s < k; ++s)
                {
                    if(!vv[r][s] && !vv2[r][s])
                        continue;
                    int new_remainder = rst[j * p102[mid] + r];
                    int new_remainder_reverse = rst[p + s * p102[mid + impar]];
                    int ways = (v2[j][p] * vv2[r][s]) % rest;
                    ll new_sum = 1LL * v[j][p] * p10[mid] * vv2[r][s] + vv[r][s] * v2[j][p];
                    new_sum %= rest;
                    ans1[new_remainder][new_remainder_reverse] += new_sum;
                    if(ans1[new_remainder][new_remainder_reverse] >= rest)
                        ans1[new_remainder][new_remainder_reverse] -= rest;
                    ans2[new_remainder][new_remainder_reverse] += ways;
                    if(ans2[new_remainder][new_remainder_reverse] >= rest)
                        ans2[new_remainder][new_remainder_reverse] -= rest;
                }
        }
    sum[n] = ans1;
    dp[n] = ans2;
}
int main()
{
    f >> n >> k >> rest;
    for(int i = 0; i < 100000; ++i)
        rst[i] = i % k;
    for(int i = 0; i < k; ++i)
    {
        vector<int>va(k);
        for(int j = 0; j < k; ++j)
            va[j] = 0;
        zero.pb(va);
    }
    p10[0] = 1;
    p102[0] = rst[1];
    for(int i = 1; i <= n; ++i)
    {
        p10[i] = (p10[i-1] * 10) % rest;
        p102[i] = rst[(p102[i-1] * 10)];
    }
    dc(n);
    vector<vector<int> >v, v2;
    v = sum[n];
    v2 = dp[n];
    g << v[0][0] << '\n';
    return 0;
}
