// https://www.infoarena.ro/problema/rmq

#include<bits/stdc++.h>
using namespace std;
ifstream f("rmq.in");
ofstream g("rmq.out");
int n, lg[100002], m, rmq[20][100002];
int p2[25];
int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
        f >> rmq[0][i];
    for(int i = 2; i <= n; ++i)
        lg[i] = lg[i/2] + 1;
    p2[0] = 1;
    for(int i = 1; i <= lg[n]; ++i)
        p2[i] = (p2[i-1] * 2);
    for(int i = 1; i <= lg[n]; ++i)
        for(int j = 1; j <= n - p2[i] + 1; ++j)
            rmq[i][j] = min(rmq[i-1][j], rmq[i-1][j + p2[i-1]]);
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        f >> a >> b;
        int pz = lg[b - a + 1];
        g << min(rmq[pz][a], rmq[pz][b - p2[pz] + 1]) << '\n';
    }
    return 0;
}
