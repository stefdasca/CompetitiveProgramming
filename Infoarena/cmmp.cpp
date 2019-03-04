#include<bits/stdc++.h>
using namespace std;
ifstream f("cmmp.in");
ofstream g("cmmp.out");
long long ans[100002];
bool pus[100002];
int rm = 99999;
int v[22], pz, n;
int main()
{
    pus[0] = 1;
    for(int i = 1; ; ++i)
    {
        long long val = 1LL * i * i;
        pz = 0;
        while(val)
        {
            v[++pz] = val % 10;
            val /= 10;
        }
        for(int j = pz; j >= 1; --j)
        {
            int nr = 0;
            for(int q = j; q >= 1; --q)
            {
                nr = nr * 10 + v[q];
                if(nr >= 100000)
                    break;
                if(!pus[nr])
                {
                    pus[nr] = 1;
                    ans[nr] = 1LL * i * i;
                    --rm;
                }
            }
        }
        if(rm == 0)
            break;
    }
    f >> n;
    for(int i = 1; i <= n; ++i)
    {
        int x;
        f >> x;
        g << ans[x] << " ";
    }
    return 0;
}
