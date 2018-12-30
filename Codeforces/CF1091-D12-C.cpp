/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n;
vector<long long>ans;
void chk(long long nr)
{
    long long rp = n / nr;
    rp = rp * (rp + 1) / 2;
    long long sum = rp * nr;
    sum = sum - (nr - 1) * (n / nr);
    ans.push_back(sum);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i * i <= n; ++i)
    {
        if(n % i == 0)
        {
            chk(i);
            if(i != n / i)
                chk(n/i);
        }
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    return 0;
}
