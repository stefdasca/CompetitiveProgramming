/*
        COI 07-Kolekcija

    Let's rephrase the problem a bit => given k points and a number m, cover the points with ranges of length at least m
such that we cover as few points as possible, while we cover all the k points.


    This can be solved using DP, after sorting the points

    let dp[i] = min cost of covering the first i points, dp[i] = min(dp[j] + max(m, ord[i] - ord[j+1] + 1)), j < i

    Let's divide all j in two groups, the ones such that ord[i] - ord[j+1] + 1 < m and the other ones. From this point
on we reduced the problem to standard deque dp.

    For building the solution, we're going downwards from the last point to the first ones while keeping the position from where we
found the best cost, while being careful at the range we have to choose to cover each of the k points.

*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

using namespace std;

typedef long long ll;

map<int, pair<int, int> >val;

int n, m, k, poz[300002], ord[300002];

int dp[300002];
int wh[300002];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> k;
    for(int i = 1; i <= k; ++i)
    {
        cin >> poz[i];
        ord[i] = poz[i];
    }
    sort(ord + 1, ord + k + 1);
    deque<int> oka, okb;
    oka.pb(0);
    int chgpos = 0;
    for(int i = 1; i <= k; ++i)
    {
        dp[i] = (1<<30);
        while(ord[i] - ord[chgpos + 1] + 1 >= m)
        {
            if(!oka.empty() && oka[0] == chgpos)
                oka.pop_front();
            while(!okb.empty() && dp[chgpos] - dp[okb.back()] < ord[chgpos + 1] - ord[okb.back() + 1])
                okb.pop_back();
            okb.pb(chgpos);
            ++chgpos;
        }
        if(!oka.empty())
        {
            if(dp[oka[0]] + m < dp[i])
            {
                dp[i] = dp[oka[0]] + m;
                wh[i] = oka[0];
            }
        }
        if(!okb.empty())
        {
            if(dp[okb[0]] + ord[i] - ord[okb[0] + 1] + 1 < dp[i])
            {
                dp[i] = dp[okb[0]] + ord[i] - ord[okb[0] + 1] + 1;
                wh[i] = okb[0];
            }
        }
        while(!oka.empty() && dp[i] < dp[oka.back()])
            oka.pop_back();
        oka.pb(i);
    }
    int pozz = k;
    while(pozz)
    {
        int pb = ord[pozz];
        int pa = ord[wh[pozz] + 1];
        for(int i = wh[pozz] + 1; i <= pozz; ++i)
        {
            int leftend = max(pa, ord[i] - m + 1);
            int rightend = leftend + m - 1;
            if(rightend > pb)
            {
                rightend = min(pb, ord[i] + m - 1);
                leftend = rightend - m + 1;
            }
            val[ord[i]] = {leftend, rightend};
        }
        pozz = wh[pozz];
    }
    cout << dp[k] << '\n';
    for(int i = 1; i <= k; ++i)
    {
        pair<int, int> rg = val[poz[i]];
        cout << rg.fi << " " << rg.se << '\n';
    }
    return 0;
}
