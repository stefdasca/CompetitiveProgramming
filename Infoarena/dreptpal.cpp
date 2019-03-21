#include<bits/stdc++.h>
using namespace std;
ifstream f("dreptpal.in");
ofstream g("dreptpal.out");
int n, m;
int a[1002][1002];
int lps[1002][1002];
int dp[1002][1002];
int st[1002][1002], dr[1002][1002];
int L[2005]; // longest palindromic substring starting at position i
int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            f >> a[i][j];
    for(int j = 1; j <= n; ++j)
    {
        int N = 2*m + 1;
        L[0] = 0, L[1] = 1;
        lps[j][1] = 1;
        int C = 1;
        int R = 2;
        int i = 0;
        int maxLPSLength = 0;
        int maxLPSCenterPosition = 0;
        for (i = 2; i < N; i++)
        {
            int iMirror  = 2*C-i;
            L[i] = 0;
            int diff = R - i;
            if(diff > 0)
                L[i] = min(L[iMirror], diff);
            while (((i + L[i]) < N && (i - L[i]) > 0) && ( ((i + L[i] + 1) % 2 == 0) || (a[j][1 + (i + L[i] + 1)/2] == a[j][1 + (i - L[i] - 1)/2])))
                L[i]++;
            if (i + L[i] > R)
            {
                C = i;
                R = i + L[i];
            }
            if(i % 2 == 1)
                lps[j][i / 2 + 1] = L[i];
        }
    }
    int mx = 0;
    for(int i = 1; i <= m; ++i)
    {
        deque<int>d;
        for(int j = 1; j <= n; ++j)
        {
            while(!d.empty() && lps[j][i] <= lps[d.back()][i])
                d.pop_back();
            if(!d.empty())
                st[j][i] = d.back();
            d.push_back(j);
        }
        d.clear();
        for(int j = n; j >= 1; --j)
        {
            while(!d.empty() && lps[j][i] <= lps[d.back()][i])
                d.pop_back();
            if(!d.empty())
                dr[j][i] = d.back();
            else
                dr[j][i] = n+1;
            d.push_back(j);
        }
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            mx = max(mx, lps[i][j] * (dr[i][j] - st[i][j] - 1));
    g << mx << '\n';
    return 0;
}
