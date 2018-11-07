#include<bits/stdc++.h>
using namespace std;
ifstream f("greutati.in");
ofstream g("greutati.out");
const int mod = 1000000007;
int n, p;
struct puteri
{
    int pu, fr;
};
puteri v[100002];
long long sum[100002];
long long modpow(long long b, long long ex)
{
    long long sol = 1;
    while(ex)
    {
        if(ex & 1)
            sol = (sol * b) % mod;
        b = (b * b) % mod;
        ex >>= 1;
    }
    return sol;
}
bool cmp(puteri a, puteri b)
{
    return a.pu < b.pu;
}
int main()
{
    f >> n >> p;
    for(int i = 1; i <= n; ++i)
    {
        int pu, fr;
        f >> pu >> fr;
        v[i] = {pu, fr};
    }
    sort(v+1, v+n+1, cmp);
    for(int i = 1; i <= n; ++i)
        sum[i] = sum[i-1] + v[i].fr;
    long long dif = 0;
    long long care = 0;
    long long sol = 0;
    for(int i = n; i >= 1; --i)
    {
        if(dif == 0)
        {
            dif = v[i].fr % 2;
            care = v[i].pu;
        }
        else
        {
            while(care > v[i].pu && dif < sum[i])
                --care, dif *= 2;
            if(dif >= sum[i])
            {
                sol = ( (dif % mod) * modpow(2, care)) % mod;
                for(int j = i; j >= 1; --j)
                {
                    long long qx = (v[j].fr * modpow(2, v[j].pu)) % mod;
                    sol = (sol - qx + mod) % mod;
                }
                g << sol;
                return 0;
            }
            else
            {
                if(dif >= v[i].fr)
                    dif -= v[i].fr;
                else
                {
                    v[i].fr -= dif;
                    dif = 0;
                    dif = v[i].fr % 2;
                }
            }
        }
    }
    sol = (dif % mod);
    sol = (sol * modpow(2, care)) % mod;
    g << sol;
    return 0;
}
