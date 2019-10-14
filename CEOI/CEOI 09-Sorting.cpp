/*

    https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/CEOI/official/2009/solutions-converted.pdf

*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1234567

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

int gauss(int nr)
{
    return nr * (nr + 1) / 2;
}
int d[33][33][530], dp[33][530][530];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nmax = 32;
    int lmax = gauss(nmax);
    d[0][0][0] = 1;
    for(int i = 0; i < nmax; i++)
        for(int j = 0; j < nmax; j++)
            for(int k = 0; k < lmax; k++)
            {
                if(i - 1 >=0 && k - j >= 0)
                    d[i][j][k] = add(d[i][j][k], d[i - 1][j][k - j]);
                if(j - 1 >= 0)
                    d[i][j][k] = add(d[i][j][k], d[i][j - 1][k]);
            }
    dp[0][0][0] = 1;
    for(int N = 0; N <= 31; N++)
    {
        for(int L1 = 0; L1 < N; L1++)
        {
            int L2 = N - 1 - L1;
            for(int Q1 = 0; Q1 <= gauss(L1); Q1++)
            {
                for(int Q2 = 0; Q2 <= gauss(L2); Q2++)
                {
                    vector<int> S(gauss(L1) + gauss(L2) + 1);
                    vector<int> I2Options;
                    for(int I2 = 0; I2 <= gauss(L2); I2++)
                        if(dp[L2][Q2][I2] != 0)
                            I2Options.pb(I2);
                    for(int I1 = 0; I1 <= gauss(L1); I1++)
                    {
                        if(dp[L1][Q1][I1] == 0)
                            continue;
                        for(int x = 0; x < I2Options.size(); ++x)
                        {
                            int I2 = I2Options[x];
                            S[I1 + I2] = add(S[I1+I2], mul(dp[L1][Q1][I1], dp[L2][Q2][I2]));
                        }
                    }
                    vector<int> IcOptions;
                    for(int Ic = 0; Ic <= L1 * L2; Ic++)
                        if(d[L1][L2][Ic]!=0)
                            IcOptions.pb(Ic);
                    int Q = Q1 + Q2 + N -1;
                    for(int SI = 0; SI <= gauss(L1) + gauss(L2); SI++)
                    {
                        if(S[SI]==0)
                            continue;
                        for(int x = 0; x < IcOptions.size(); ++x)
                        {
                            int Ic = IcOptions[x];
                            int I = SI + Ic + L1;
                            dp[N][Q][I] = add(dp[N][Q][I], mul(S[SI], d[L1][L2][Ic]));
                        }
                    }
                }
            }
        }
    }
    vector<pair<int,int> > a= {{5, 1}, {12, 2}, {18, 3}, {20, 1}, {22, 5}, {23, 3}, {24, 4}, {29, 2}, {30, 5}, {31, 1}};
    for(int i = 0; i < 10; i++)
    {
        int n=a[i].fi,x=a[i].se;
        int sol=0;
        for(int Q = 0; Q <= gauss(n); Q++)
            for(int I = min(gauss(n),Q*x); I >= n-1; I--)
                sol=add(sol, dp[n][Q][I - n + 1]);
        cout << i << " " << sol << '\n';
    }
    return 0;
}
