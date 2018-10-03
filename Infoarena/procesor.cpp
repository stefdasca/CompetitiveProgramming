#include<bits/stdc++.h>
using namespace std;
ifstream fi("procesor.in");
ofstream fo("procesor.out");
int cnt,n;
pair<int,int>s[123456];
bitset<123456>b;
priority_queue<int>H;
int main()
{
    fi>>n;
    cnt=n;
    long long ans = 0;
    for (int i=1;i<=n;++i)
        fi>>s[i].first>>s[i].second,ans += s[i].second;
    sort(s+1,s+1+n);
    int cnt = n;
    for (int i = n;i>0;--i)
    {
        while (s[cnt].first >= i)
            H.push(s[cnt].second),--cnt;
        if (!H.empty())
            ans -= H.top(),H.pop();
    }
    fo << ans << '\n';
    return 0;
}
