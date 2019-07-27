#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 998244353

using namespace std;

typedef long long ll;

ll add(ll a, ll b)
{
    ll x = a+b;
    if(x >= mod)
        x -= mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a*b) % mod;
}

int n;
vector<string>wd[12];
ll ans = 0;
ll ch[200][200];
int cod(char c)
{
    if(c >= 'a' && c <= 'z')
        return (c - 'a');
    if(c >= 'A' && c <= 'Z')
        return 26 + (c - 'A');
    if(c >= '0' && c <= '9')
        return 52 + (c - '0');
}
ll val[1000002];
int frq[102];
int fct[] = {1, 1, 2, 6, 24, 120};
ll perm(int a, int b, int c, int d)
{
    ++frq[a], ++frq[b], ++frq[c], ++frq[d];
    ll ans = 24;
    ans /= fct[frq[a]];
    if(b != a)
        ans /= fct[frq[b]];
    if(c != b)
        ans /= fct[frq[c]];
    if(d != c)
        ans /= fct[frq[d]];
    --frq[a], --frq[b], --frq[c], --frq[d];
    return ans;
}
ll dp(int len)
{
    if(!wd[len].size())
        return 0;
    int mx = 0;
    map<string, int>ss;
    memset(ch, 0, sizeof(ch));
    memset(val, 0, sizeof(val));
    for(int i = 0; i < wd[len].size(); ++i)
    {
        string s = wd[len][i];
        string rv;
        for(int j = s.size() - 1; j >= 0; --j)
            rv += s[j];
        if(rv < s)
            s = rv;
        if(ss.find(s) != ss.end())
            continue;
        ss[s] = 1;
        bool pal = 1;
        for(int j = 0; j < s.size(); ++j)
            if(s[j] != s[s.size() - j - 1])
                pal = 0, mx = max(mx, cod(s[j]));
        if(pal)
            ch[cod(s[0])][cod(s[s.size() - 1])]++;
        else
            ch[cod(s[0])][cod(s[s.size() - 1])]++, ch[cod(s[s.size() - 1])][cod(s[0])]++;
    }
    for(int k = 0; k <= 61; ++k)
        for(int i = 0; i <= 61; ++i)
        {
            if(!ch[i][k])
                continue;
            for(int j = 0; j <= 61; ++j)
            {
                if(!ch[j][k])
                    continue;
                for(int p = 0; p <= 61; ++p)
                {
                    if(!ch[p][k])
                        continue;
                    ll poz = i * 62 * 62 + j * 62 + p;
                    ll prr = ch[i][k] * ch[j][k] * ch[p][k];
                    prr %= mod;
                    val[poz] = (val[poz] + prr);
                    if(val[poz] >= mod)
                        val[poz] -= mod;
                }
            }
        }
    ll anss = 0;
    if(mx <= 52)
        for(int i = 0; i <= 61; ++i)
            for(int j = 0; j <= 61; ++j)
                for(int p = 0; p <= 61; ++p)
                {
                    ll twice[6];
                    memset(twice, 0, sizeof(twice));
                    twice[1] = val[i * 62 * 62 + j * 62 + p];
                    if(!twice[1])
                        continue;
                    for(int k = 0; k <= 61; ++k)
                    {
                        twice[2] = val[i * 62 * 62 + j * 62 + k];
                        twice[3] = val[i * 62 * 62 + p * 62 + k];
                        twice[4] = val[j * 62 * 62 + p * 62 + k];
                        ll pp = 1;
                        if(!twice[1] || !twice[2] || !twice[3] || !twice[4])
                            continue;
                        for(int kk = 1; kk <= 4; ++kk)
                            pp = (pp * twice[kk]) % mod;
                        anss = (anss + pp);
                        if(anss >= mod)
                            anss -= mod;
                    }
                }
    else
        for(int i = 0, vpoz = 0; i <= 61; ++i, vpoz += 62 * 62)
            for(int j = i; j <= 61; ++j)
                for(int p = j; p <= 61; ++p)
                {
                    if(!val[vpoz + j * 62 + p])
                        continue;
                    for(int k = p; k <= 61; ++k)
                    {
                        if(!val[vpoz + j * 62 + k] || !val[vpoz + p * 62 + k] || !val[j * 62 * 62 + p * 62 + k])
                            continue;
                        ll pp = perm(i, j, p, k) * 1LL * val[vpoz + j * 62 + p] * val[vpoz + j * 62 + k];
                        pp %= mod;
                        pp = pp * val[vpoz + p * 62 + k];
                        pp %= mod;
                        pp = pp * val[j * 62 * 62 + p * 62 + k];
                        pp %= mod;
                        anss = (anss + pp);
                        if(anss >= mod)
                            anss -= mod;
                    }
                }
    return anss;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        wd[s.size()].pb(s);
    }
    for(int i = 3; i <= 10; ++i)
        ans += dp(i), ans %= mod;
    cout << ans;
    return 0;
}
