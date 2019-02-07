#include<bits/stdc++.h>
using namespace std;
int n, m, frq[1000009], dp[1000009][3][3];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin >> x;
        frq[x]++;
    }
    if (m <= 2)
    {
        cout << (frq[1] / 3) + (frq[2] / 3);
        return 0;
    }
    int ans = 0;
    for (int i=1; i<=m; i++)
        ans += (frq[i] / 3);
    for (int i=1; i<=m; i++)
        for (int j=0; j<=2; j++)
            for (int k=0; k<=2; k++)
                dp[i][j][k] = -1000000000;
    for (int j=0; j<=2; j++)
        for (int k=0; k<=2; k++)
            if (j <= frq[1] && j + k <= frq[2] && j + k <= frq[3])
                dp[3][j][k] = j + k + (frq[1] - j) / 3 + (frq[2] - j - k) / 3;
            else
                dp[3][j][k] = -1000000000;
    for (int i=3; i < m; i++)
        for (int j=0; j<=2; j++)
            for (int k=0; k<=2; k++)
                if (dp[i][j][k] >= 0)
                    for (int p=0; p<=2; p++)
                        if (j + k + p <= frq[i])
                            dp[i + 1][k][p] = max (dp[i + 1][k][p], p + dp[i][j][k] + (frq[i] - j - k - p) / 3);
    for (int j=0; j<3; j++)
        if (j <= frq[m])
            ans = max (ans, dp[m][j][0] + (frq[m] - j) / 3);
    cout << ans;
    return 0;
}
