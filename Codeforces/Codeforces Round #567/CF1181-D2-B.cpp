#include<bits/stdc++.h>
using namespace std;
#pragma gcc optimize("O3")
string s;
int n, ss[100002], lg, ans[100002], lg2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> s;
    s = ' ' + s;
    int mid = n/2;
    int mid2 = n/2 + n%2;
    lg2 = 1000000;
    while(mid)
    {
        if(s[mid+1] != '0')
        {
            memset(ss, 0, sizeof(ss));
            lg = 0;
            for(int i = 1; i <= mid; ++i)
                ss[mid - i + 1] += (s[i] - '0');
            for(int i = mid + 1; i <= n; ++i)
                ss[n - i + 1] += (s[i] - '0');
            lg = max(mid, n - (mid + 1) + 1);
            for(int i = 1; i <= lg; ++i)
            {
                if(ss[i] >= 10)
                {
                    ss[i+1] += ss[i]/10;
                    ss[i] %= 10;
                    if(i == lg)
                        ++lg;
                }
            }
            lg2 = lg;
            for(int i = 1; i <= lg; ++i)
                ans[i] = ss[i];
            break;
        }
        --mid;
    }
    while(mid2 < n)
    {
        if(s[mid2+1] != '0')
        {
            memset(ss, 0, sizeof(ss));
            lg = 0;
            for(int i = 1; i <= mid2; ++i)
                ss[mid2 - i + 1] += (s[i] - '0');
            for(int i = mid2 + 1; i <= n; ++i)
                ss[n - i + 1] += (s[i] - '0');
            lg = max(mid2, n - (mid2 + 1) + 1);
            for(int i = 1; i <= lg; ++i)
            {
                if(ss[i] >= 10)
                {
                    ss[i+1] += ss[i]/10;
                    ss[i] %= 10;
                    if(i == lg)
                        ++lg;
                }
            }
            if(lg < lg2)
            {
                lg2 = lg;
                for(int i = 1; i <= lg; ++i)
                    ans[i] = ss[i];
            }
            else
                if(lg == lg2)
                {
                    bool ok = 0;
                    for(int i = lg; i >= 1; --i)
                    {
                        if(ans[i] != ss[i])
                        {
                            if(ss[i] < ans[i])
                                ok = 1;
                            break;
                        }
                    }
                    if(ok)
                    {
                        lg2 = lg;
                        for(int i = 1; i <= lg; ++i)
                            ans[i] = ss[i];
                    }
                }
                break;
        }
        ++mid2;
    }
    for(int i = lg2; i >= 1; --i)
        cout << ans[i];
    return 0;
}
