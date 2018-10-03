#include<bits/stdc++.h>
#define MX 320002
using namespace std;
ifstream f("copii3.in");
ofstream g("copii3.out");
int n, q;
string s;
int l, r;
long long nr1[MX], nr0[MX], sum0[MX], sum1[MX];
long long pc[MX], pl[MX];
vector<int>pos;
vector<int>pos2;
void start()
{
    ios_base::sync_with_stdio(false);
    f >> n >> q;
    f >> s;
    for(int i = 0; i < n; ++i)
    {
        nr1[i+1] = nr1[i];
        nr0[i+1] = nr0[i];
        sum0[i+1] = sum0[i];
        sum1[i+1] = sum1[i];
        if(s[i] == '0')
        {
            nr0[i+1]++;
            sum0[i+1] += (i+1);
            pos.push_back(i+1);
        }
        else
        {
            nr1[i+1]++;
            sum1[i+1] += (i+1);
            pos2.push_back(i+1);
        }
        pc[i+1] = pos.size() - 1;
        pl[i+1] = pos2.size() - 1;
    }
}
long long fct(long long l, long long r, long long sta)
{
    long long sol = 0;
    long long unu = nr1[r] - nr1[l-1];
    long long sum2 = sum1[r] - sum1[l-1];
    if(sta)
    {
        long long sum00, sum11;
        if(nr0[l-1] == sta)
            sum00 = sum0[l-1];
        else
            sum00 = sum0[l-1] - sum0[pos[pc[l-1]-sta+1]-1];
        sum11 = sum1[pos2[pl[l-1]+sta]] - sum1[l-1];
        sum2 -= sum11;
        sol = sol + sum11 - sum00;
    }
    if(unu - sta)
    {
        long long sum00, sum11;
        if(nr0[n] - nr0[r] == unu - sta)
            sum00 = sum0[n] - sum0[r];
        else
            sum00 = sum0[pos[pc[r]+unu-sta]] - sum0[r];
        sum11 = sum2;
        sol = sol + sum00 - sum11;
    }
    return sol;
}
long long ternary(long long st, long long dr)
{
    int ddr = (nr0[n] - nr0[dr]);
    long long b = max(0LL, (nr1[r] - nr1[l-1]) - ddr);
    long long e = min(nr0[l-1], nr1[r] - nr1[l-1]);
    long long sol = (1LL<<60);
    if(nr1[r] - nr1[l-1] == 0)
        return 0;
    int nrrr = 0;
    while(b <= e)
    {
        long long mid = b + (e-b)/3;
        long long mid2 = e - (e-b)/3;
        if(mid == b && mid2 == e)
        {
            for(int i = b; i <= e; ++i)
                sol = min(sol, fct(st, dr, i));
            break;
        }
        long long x1 = fct(st, dr, mid);
        long long x2 = fct(st, dr, mid2);
        if(x1 == x2)
            b = mid, e = mid2;
        else
            if(x1 > x2)
                b = mid;
            else
                e = mid2;
    }
    if(sol == (1LL<<60))
        return -1;
    return sol;
}
void solve()
{
    for(int i = 1; i <= q; ++i)
    {
        f >> l >> r;
        int aa = nr0[n];
        int bb = nr0[r] - nr0[l-1];
        int cc = nr1[r] - nr1[l-1];
        long long sol = ternary(l, r);
        g << sol << '\n';
    }
}
int main()
{
    start();
    solve();
    return 0;
}
