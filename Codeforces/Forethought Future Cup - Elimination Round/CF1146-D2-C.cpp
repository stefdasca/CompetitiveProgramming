#include<bits/stdc++.h>
using namespace std;
int t, n;
vector<int>ans1, ans2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(; t; --t)
    {
        cin >> n;
        int mx = 0;
        for(int i = 8; i >= 0; --i)
        {
            ans1.clear();
            ans2.clear();
            for(int j = 1; j <= n; ++j)
                if(j & (1<<i))
                    ans1.push_back(j);
                else
                    ans2.push_back(j);
            if(ans1.size() == 0 || ans2.size() == 0)
                continue;
            cout << ans1.size() << " " << ans2.size() << " ";
            for(int j = 0; j < ans1.size(); ++j)
                cout << ans1[j] << " ";
            for(int j = 0; j < ans2.size(); ++j)
                cout << ans2[j] << " ";
            cout << endl;
            int aa;
            cin >> aa;
            mx = max(mx, aa);
        }
        cout << -1 << " " << mx << endl;
    }
    return 0;
}

