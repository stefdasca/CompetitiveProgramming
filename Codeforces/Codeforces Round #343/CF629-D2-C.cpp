#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int add(int a, int b)
{
    int x = a+b;
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

int n, m;

int ct[2002][2002];

string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    cin >> s;
    ct[0][0] = 1;
    for(int i = 0; i < 2000; ++i)
        for(int j = 0; j <= i; ++j)
        {
            ct[i+1][j+1] = add(ct[i+1][j+1], ct[i][j]);
            if(j != 0)
                ct[i+1][j-1] = add(ct[i+1][j-1], ct[i][j]);
        }
    int ct1 = 0, ctm1 = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == ')')
        {
            if(ct1)
                --ct1;
            else
                ++ctm1;
        }
        else
            ++ct1;
    }
    int ans = 0;
    for(int L1 = 0; L1 <= n-m; ++L1)
        for(int D1 = ctm1; D1 <= L1; ++D1)
        {
            int remlen = (n - m) - L1;
            int reqdif = (D1 - ctm1) + ct1;
            if(remlen >= reqdif)
                ans = add(ans, mul(ct[L1][D1], ct[remlen][reqdif]));
        }
    cout << ans;
    return 0;
}
