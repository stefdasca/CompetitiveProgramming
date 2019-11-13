#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define eps 1e-9

using namespace std;

typedef long long ll;


int add(int a, int b)
{
    ll x = a+b;
    if(x >= mod)
        x -= mod;
    if(x < 0)
        x += mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a*b) % mod;
}

ll pw(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

string s;

char q[] = {'0', '1', '2', '*'};
ll dp[5][1000002]; // dp[i][j] = # de moduri daca ultimul e 0, 1, 2, *

bool valid(char a, char b)
{
    if(a == '?')
        return 1;
    if(a == b)
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    s = ' ' + s;
    for(int i = 1; i < s.size(); ++i)
    {
        if(i == 1)
        {
            if(s[i] == '?')
                for(int j = 0; j <= 3; ++j)
                    dp[j][i] = 1;
            else
                for(int j = 0; j <= 3; ++j)
                    if(s[i] == q[j])
                        dp[j][i] = 1;
            dp[2][i] = 0;
            if(i + 1 == s.size())
                dp[1][i] = 0;
        }
        else
        {
            if(i+1 == s.size() && s[i] == '2')
                continue;
            for(int j = 0; j <= 3; ++j)
            {
                if(i+1 == s.size() && j == 2)
                    continue;
                if(s[i] == '?' || s[i] == q[j])
                    for(int p = 0; p <= 3; ++p)
                    {
                        if(!valid(s[i-1], q[p]))
                            continue;
                        if(i+1 == s.size() && j == 1 && p != 3)
                            continue;
                        if(j == 0 && p == 1)
                            dp[j][i] = add(dp[j][i], dp[3][i-2]);
                        else
                            if(j == 0 && p == 2);
                            else
                                if(j == 0 && p == 3);
                                else
                                    if(j == 1 && p == 1)
                                        dp[j][i] = add(dp[j][i], dp[3][i-2]);
                                    else
                                        if(j == 1 && p == 2);
                                        else
                                            if(j == 2 && p == 0);
                                            else
                                                if(j == 2 && p == 1);
                                                else
                                                    if(j == 2 && p == 2);
                                                    else
                                                        if(j == 3 && p == 1)
                                                            dp[j][i] = add(dp[j][i], add(dp[p][i-1], -dp[3][i-2]));
                                                        else
                                                            if(j == 3 && p == 2)
                                                                dp[j][i] = add(dp[j][i], dp[3][i-2]);
                                                            else
                                                                if(j == 3 && p == 0);
                                                                else
                                                                    dp[j][i] = add(dp[j][i], dp[p][i-1]);

                    }
            }
        }
       // for(int j = 0; j <= 3; ++j)
       //     cout << dp[j][i] << " ";
      //  cout << '\n';
    }
    ll ans = 0;
    for(int i = 0; i <= 4; ++i)
        ans = add(ans, dp[i][s.size() - 1]);
    cout << ans;
    return 0;
}
