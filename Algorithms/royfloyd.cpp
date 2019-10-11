// https://www.infoarena.ro/problema/royfloyd

#include<bits/stdc++.h>
using namespace std;
ifstream f("royfloyd.in");
ofstream g("royfloyd.out");
int n, a[102][102];
int main()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            f >> a[i][j];
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(a[i][k] && a[k][j] && (a[i][j] > a[i][k] + a[k][j] || !a[i][j]) && i != j)
                    a[i][j] = a[i][k] + a[k][j];
    for(int i = 1; i <= n; g << '\n', ++i)
        for(int j = 1; j <= n; ++j)
            g << a[i][j] << " ";
    return 0;
}
