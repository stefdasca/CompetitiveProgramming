/*
            BOI 12-brackets

    editorial = https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/Baltic/official/boi2012_solutions/brackets-sol.pdf

*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000009

using namespace std;

typedef long long ll;


int add(int a, int b)
{
    int x = a+b;
    if(x >= mod)
        x -= mod;
    return x;
}

int n, dp[2][30002];
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> s;
    if(n%2 == 1)
    {
        cout << 0;
        return 0;
    }
    dp[0][0] = 1;
    for(int i = 0; i < n; ++i)
    {
        if(s[i] == ')')
            for(int j = 0; j < n; ++j)
                dp[0][j] = dp[0][j+1];
        else
        {
            dp[1][0] = dp[0][1];
            for(int j = 1; j < n; ++j)
                dp[1][j] = add(dp[0][j-1], dp[0][j+1]);
            memcpy(dp[0], dp[1], sizeof(dp[1]));
        }
    }
    cout << dp[0][0];
    return 0;
}
