#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, k;
long long val[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> val[i];
    string s;
    cin >> s;
    long long ans = 0;
    for(int i = 0; i < n;)
    {
        vector<int>v;
        int j = i;
        while(j < n && s[j] == s[i])
            v.push_back(val[j + 1]), ++j;
        sort(v.begin(), v.end());
        int lft = k;
        for(int j = v.size() - 1; j >= 0; --j)
        {
            if(lft == 0)
                break;
            ans += v[j];
            --lft;
        }
        i = j;
    }
    cout << ans;
    return 0;
}


