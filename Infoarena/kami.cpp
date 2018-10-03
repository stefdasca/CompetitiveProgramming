#include<bits/stdc++.h>
using namespace std;
ifstream f("kami.in");
ofstream g("kami.out");
int n, m, x;
int v[100002];
int main()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
        f >> v[i], x = max(v[i], x);
    f >> m;
    for(int i = 1; i <= m; ++i)
    {
        int tip;
        f >> tip;
        if(tip == 0)
        {
            int a, b;
            f >> a >> b;
            v[a] = b;
            x = max(v[i], x);
        }
        else
        {
            int nr;
            f >> nr;
            int pos = nr-1;
            int sum = v[nr];
            int sol = 0;
            while(1)
            {
                if(pos == 0)
                {
                    g << 0 << '\n';
                    break;
                }
                if(sum <= v[pos])
                {
                    g << pos << '\n';
                    break;
                }
                else
                {
                    if(sum > x)
                    {
                        g << 0 << '\n';
                        break;
                    }
                    sum += v[pos];
                    --pos;
                }
            }
        }
    }
    return 0;
}
