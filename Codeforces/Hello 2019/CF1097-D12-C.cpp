/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
string s;
int nf[500002];
int pf[500002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> s;
        deque<int>d;
        for(int j = 0; j < s.size(); ++j)
        {
            if(s[j] == ')')
            {
                if(!d.empty() && d.back() == 0)
                    d.pop_back();
                else
                    d.push_back(1);
            }
            else
                d.push_back(0);
        }
        bool zero = 0, unu = 0;
        for(int j = 0; j < d.size(); ++j)
            if(d[j] == 0)
                zero = 1;
            else
                unu = 1;
        if(zero && unu)
            continue;
        else
            if(zero == 1)
                pf[d.size()]++;
            else
                nf[d.size()]++;
    }
    int ans = 0;
    ans += nf[0] / 2;
    for(int j = 1; j <= 500000; ++j)
        ans += min(pf[j], nf[j]);
    cout << ans;
    return 0;
}
