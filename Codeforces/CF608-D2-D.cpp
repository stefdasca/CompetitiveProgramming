#include<bits/stdc++.h>
using namespace std;
int n, v[502], dp[502][502];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    for(int L = 1; L <= n; ++L)
        for(int j = 1; j + L - 1 <= n; ++j)
            if(L == 1)
                dp[j][j + L - 1] = 1;
            else
            {
                dp[j][j + L - 1] = 1 + dp[j + 1][j + L - 1];
                if (v[j] == v[j + 1])
			dp[j][j + L - 1] = min(1 + dp[j + 2][j + L - 1], dp[j][j + L - 1]);
		for (int poz = j + 2; poz <= j + L - 1; poz++)
			if (v[j] == v[poz])
				dp[j][j + L - 1] = min(dp[j + 1][poz - 1] + dp[poz + 1][j + L - 1], dp[j][j + L - 1]);
            }
    cout << dp[1][n] << '\n';
    return 0;
}
