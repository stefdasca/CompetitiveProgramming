#include<bits/stdc++.h>
using namespace std;
ifstream f("carti.in");
ofstream g("carti.out");
int t, dp[10002], n, k;
int nr;
int main()
{
    f >> t;
    for(; t; --t)
    {
        f >> n >> k;
        nr = 0;
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; ++i)
        {
            char x[5];
            f >> x;
            if(strlen(x) == 2)
                nr ^= (1<<9);
            else
                if(x[0] <= '9')
                    nr ^= (1<<(x[0] - '0' - 1));
                else
                    if(x[0] == 'A')
                        nr ^= 1;
                    else
                        if(x[0] == 'K')
                            nr ^= (1<<12);
                        else
                            if(x[0] == 'Q')
                                nr ^= (1<<11);
                            else
                                if(x[0] == 'J')
                                    nr ^= (1<<10);
        }
        for(int i = 0; i < nr; ++i)
        {
            for(int j = 1; j <= k; ++j)
            {
                int fn = (1<<j) - 1;
                for(int p = 1; p + j - 1 <= 13; ++p)
                {
                    if(!(i & fn) && dp[i] == 0 && (nr & fn) == fn)
                            dp[i + fn] = 1;
                    fn <<= 1;
                }
            }
        }
        if(dp[nr] == 1)
            g << "Alice\n";
        else
            g << "Bob\n";
    }
    return 0;
}
