#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> s;
    int nrg = 0;
    for(int i = 0; i < s.size(); ++i)
        if(s[i] == 'G')
            ++nrg;
    int ans = 0;
    int len = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == 'G')
            ++len;
        else
            len = 0;
        ans = max(ans, len);
        if(nrg > len)
            ans = max(ans, len + 1);
        if(i > 0 && s[i] == 'S' && s[i-1] == 'G' && s[i+1] == 'G')
        {
            int aa = i-1;
            int qq = 0;
            while(aa >= 0 && s[aa] == 'G')
                ++qq, --aa;
            aa = i+1;
            while(aa < s.size() && s[aa] == 'G')
                ++qq, ++aa;
            if(nrg > qq)
                ++qq;
            ans = max(ans, qq);
        }
    }
    cout << ans;
    return 0;
}
