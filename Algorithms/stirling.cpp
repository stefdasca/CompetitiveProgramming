// https://www.infoarena.ro/problema/stirling

#include<bits/stdc++.h>
using namespace std;
ifstream f("stirling.in");
ofstream g("stirling.out");
int t, tip, a, b;
int unu[202][202], doi[202][202];
const int mod = 98999;
int main()
{
    unu[1][1] = doi[1][1] = 1;
    for(int i = 2; i <= 200; ++i)
        for(int j = 1; j <= i; ++j)
        {
            unu[i][j] = unu[i-1][j-1] - (i - 1) * unu[i-1][j];
            unu[i][j] %= mod;
        }
    for(int i = 2; i <= 200; ++i)
        for(int j = 1; j <= i; ++j)
            doi[i][j] = (doi[i-1][j-1] + j * doi[i-1][j]) % mod;
    f >> t;
    for(int i = 1; i <= t; ++i)
    {
        f >> tip >> a >> b;
        if(tip == 1)
            g << unu[a][b] << '\n';
        else
            g << doi[a][b] << '\n';
    }
    return 0;
}
