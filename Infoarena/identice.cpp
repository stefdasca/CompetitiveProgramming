#include<bits/stdc++.h>
using namespace std;
ifstream f("identice.in");
ofstream g("identice.out");
int t, n, d;
char a[1002][1002];
int sp[1002][1002];
long long sol, sum;
void prec(char k)
{
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(a[i][j] == k)
                sp[i][j] = sp[i-1][j] + 1;
            else
                sp[i][j] = 0;
    deque<int>sz;
    for(int i = 1; i <= n; ++i)
    {
        sz.clear();
        int ps = -1;
        sum = 0;
        for(int j = 1; j <= n; ++j)
        {
            if(a[i][j] != k)
                sz.clear(), sum = 0, ps = -1;
            else
            {
                if(ps == -1)
                    ps = j - 1;
                while(!sz.empty() && sp[i][j] <= sp[i][sz.back()])
                {
                    int prev;
                    int pp = sz.back();
                    sz.pop_back();
                    if(sz.size() == 0)
                        prev = ps;
                    else
                        prev = sz.back();
                    sum -= 1LL * (pp - prev) * sp[i][pp];
                    sum += 1LL * (pp - prev) * sp[i][j];
                }
                sum += sp[i][j];
                sz.push_back(j);
            }
            sol += sum;
        }
    }
}
int mingr(char x)
{
    memset(sp, 0, sizeof(sp));
    int sol = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            sp[i][j] = sp[i][j] + sp[i-1][j] + sp[i][j-1] - sp[i-1][j-1];
            if(sp[i][j] % 2 == 0 && a[i][j] != x)
            {
                if(n - i + 1 < d || n - j + 1 < d)
                    return 100000000;
                sp[i][j]++;
                sp[i+d][j]--;
                sp[i][j+d]--;
                sp[i+d][j+d]++;
                ++sol;
            }
            if(sp[i][j] % 2 == 1 && a[i][j] == x)
            {
                if(n - i + 1 < d || n - j + 1 < d)
                    return 100000000;
                sp[i][j]++;
                sp[i+d][j]--;
                sp[i][j+d]--;
                sp[i+d][j+d]++;
                ++sol;
            }
        }
    return sol;
}
int main()
{
    f >> t >> n >> d;
    for(int i = 1; i <= n; ++i)
        f >> (a[i] + 1);
    if(t == 1)
    {
        prec('0');
        prec('1');
        g << sol;
    }
    else
    {
        int x = min(mingr('0'), mingr('1'));
        if(x == 100000000)
            g << -1;
        else
            g << x;
    }
    return 0;
}
