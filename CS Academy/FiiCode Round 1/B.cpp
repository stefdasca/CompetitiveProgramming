#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n;
string s;
int frq[28];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> s;
    long long ans = 0;
    for(int i = 1; i <= 26; ++i)
    {
        memset(frq, 0, sizeof(frq));
        for(int j = 0; j < n; ++j)
        {
            ++frq[s[j] - 'a'];
            if(j >= i)
                --frq[s[j - i] - 'a'];
            bool gg = 1;
            if(j >= i - 1)
            {
                for(int p = 0; p <= 25; ++p)
                    if(frq[p] >= 2)
                        gg = 0;
                ans += gg;
            }
        }
    }
    cout << ans;
    return 0;
}

