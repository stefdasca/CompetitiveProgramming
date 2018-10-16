#include<bits/stdc++.h>
using namespace std;
ifstream f("bvarcolaci.in");
ofstream g("bvarcolaci.out");
int n, v[250002], frq[250002], xx[500002];
vector<int>pos[250002];
long long fct(long long a, long long b, long long c)
{
    if(a > b)
        swap(a, b);
    a = min(a, c);
    b = min(b, c);
    if(a + b <= c)
        return (a+1) * (b+1);
    long long sol = (a+1);
    sol = sol + 1LL * (c - b + 1) * b;
    int mx = (b-1);
    int mn = max(0LL, c - a - 1);
    sol = sol + 1LL * mx * (mx+1)/2;
    sol = sol - 1LL * mn * (mn+1)/2;
    return sol;
}
int main()
{
    long long sol = 0;
    f >> n;
    int rad = (int)sqrt(n);
    for(int i = 1; i <= n; ++i)
    {
        f >> v[i];
        pos[v[i]].push_back(i);
    }
    for(int i = 1; i <= n; ++i)
    {
        if(pos[i].size() <= rad)
        {
            for(int j = 0; j < pos[i].size(); ++j)
            {
                for(int k = j; k < pos[i].size(); ++k)
                {
                    int st = pos[i][j];
                    int dr = pos[i][k];
                    int len = (dr - st + 1);
                    int frq = k - j + 1;
                    if(frq < len / 2 + 1)
                        continue;
                    int disp = frq * 2 - len - 1;
                    int catest;
                    if(j != 0)
                        catest = st - pos[i][j-1] - 1;
                    else
                        catest = st - 1;
                    int catedr;
                    if(k + 1 == pos[i].size())
                        catedr = n - dr;
                    else
                        catedr = pos[i][k + 1] - dr - 1;
                    sol += fct(catest, catedr, disp);
                }
            }
        }
        else
        {
            memset(xx, 0, sizeof(xx));
            int st = 249999;
            int nr = 0;
            for(int j = 1; j <= n; ++j)
            {
                if(v[j] == i)
                    frq[j] = frq[j-1] + 1;
                else
                    frq[j] = frq[j-1] - 1;
                ++xx[250000 + frq[j-1]];
                if(250000 + frq[j-1] <= st)
                    ++nr;
                while(frq[j] + 250000 <= st)
                    nr -= xx[st], --st;
                while(frq[j] + 250000 > st + 1)
                    ++st, nr += xx[st];
                sol += nr;
            }
        }
    }
    g << sol;
    return 0;
}
