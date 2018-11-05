#include<bits/stdc++.h>
using namespace std;
ifstream f("perioada.in");
ofstream g("perioada.out");
const int mod = 1000000007;
int n, q;
char c[100002];
long long hsh[100002], p26[100002];
vector<int>v[100002];
void ciur(int mx)
{
    for(int i = 1; i <= mx; ++i)
        for(int j = i * 2; j <= n; j += i)
            v[j].push_back(i);
}
struct intrebari
{
    int st, dr;
};
intrebari z[100002];
int ans[100002];
vector<int>qu[100002];
long long getHash(long long b, long long a)
{
    long long sol = (hsh[b] - p26[b-a] * hsh[a] + p26[b-a] * mod) % mod;
    return sol;
}
long long pp[100002];
int seq[100002];
int main()
{
    f >> n;
    f >> (c+1);
    p26[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        hsh[i] = (hsh[i-1] * 26 + (c[i] - 'a')) % mod;
        p26[i] = (p26[i-1] * 26) % mod;
    }
    f >> q;
    ciur(n);
    for(int i = 1; i <= q; ++i)
    {
        f >> z[i].st >> z[i].dr;
        for(int j = 0; j < v[(z[i].dr - z[i].st + 1)].size(); ++j)
            qu[v[(z[i].dr - z[i].st + 1)][j]].push_back(i);
    }
    for(int i = 1; i <= n; ++i)
    {
        int total = 0;
        for(int j = 0; j < qu[i].size(); ++j)
        {
            int pos = qu[i][j];
            int sz = (z[pos].dr - z[pos].st + 1) / i;
            total += sz;
        }
        if(total >= n)
        {
            memset(seq, 0, sizeof(seq));
            memset(pp, 0, sizeof(pp));
            for(int j = i; j <= n; ++j)
            {
                long long nr = getHash(j, j-i);
                if(nr != pp[j - i])
                    seq[j] = seq[j-i] + 1;
                else
                    seq[j] = seq[j-i];
                pp[j] = nr;
            }
            for(int j = 0; j < qu[i].size(); ++j)
            {
                int pos = qu[i][j];
                if(seq[z[pos].st + i - 1] == seq[z[pos].dr])
                    ++ans[pos];
            }
        }
        else
        {
            for(int j = 0; j < qu[i].size(); ++j)
            {
                int pos = qu[i][j];
                bool gg = 1;
                long long mi = -1;
                for(int p = z[pos].st + i - 1; p <= z[pos].dr; p += i)
                {
                    if(mi == -1)
                        mi = getHash(p, p - i);
                    else
                        if(getHash(p, p - i) != mi)
                        {
                            gg = 0;
                            break;
                        }
                }
                if(gg)
                    ++ans[pos];
            }
        }
    }
    for(int i = 1; i <= q; ++i)
        g << ans[i] << '\n';
    return 0;
}
