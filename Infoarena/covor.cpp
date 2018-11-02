#include<bits/stdc++.h>
using namespace std;
ifstream f("covor.in");
ofstream g("covor.out");
int n;
char a[2002][2002];
int sp[2002][2002];
int main()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
        f >> (a[i] + 1);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(a[i][j] == '0')
                sp[i][j] = sp[i-1][j] + 1;
    long long sol = 0;
    long long sum = 0;
    deque<int>sz;
    for(int i = 1; i <= n; ++i)
    {
        sz.clear();
        int ps = -1;
        sum = 0;
        for(int j = 1; j <= n; ++j)
        {
            if(a[i][j] == '1')
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
    g << sol << '\n';
    return 0;
}
