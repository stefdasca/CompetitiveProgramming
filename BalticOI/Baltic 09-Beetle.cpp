#include<bits/stdc++.h>
using namespace std;
int n, m, poz[302];
int startt = 0;
int mx = 0;
int dpleft[302][302][302], dpright[302][302][302];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> poz[i];
    sort(poz, poz + n + 1);
    startt = (lower_bound(poz, poz + 1 + n, 0) - poz);
    for (int i = 1; i <= n; i++)
    {
    	for (int j = 0; j <= n; j++)
    	{
    		for (int k = j; k <= n; k++)
    		{
				dpleft[i][j][k] = dpright[i][j][k] = (1<<29);
				if (j != 0)
                {
                    dpleft[i][j][k] = min(dpleft[i][j][k], dpleft[i-1][j-1][k] + i * (poz[j] - poz[j-1]));
                    dpright[i][j][k] = min(dpright[i][j][k], dpleft[i-1][j-1][k] + i * (poz[k] - poz[j-1]));
                }
                if (k != n)
                {
                    dpleft[i][j][k] = min(dpleft[i][j][k], dpright[i-1][j][k+1] + i * (poz[k+1] - poz[j]));
                    dpright[i][j][k] = min(dpright[i][j][k], dpright[i-1][j][k+1] + i * (poz[k+1] - poz[k]));
                }
    		}
    	}
    	mx = max(mx, i * m - dpleft[i][startt][startt]);
    }
    cout << mx;
    return 0;
}
