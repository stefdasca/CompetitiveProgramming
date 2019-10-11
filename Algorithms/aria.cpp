// https://www.infoarena.ro/problema/aria

#include<bits/stdc++.h>
using namespace std;
ifstream f("aria.in");
ofstream g("aria.out");
int n;
double S;
struct points
{
    double x, y;
};
points v[100005];
int main()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
        f >> v[i].x >> v[i].y;
    v[n + 1].x = v[1].x;
    v[n + 1].y = v[1].y;
    for(int i = 1; i <= n; ++i)
        S = S + 0.500000 * (v[i].x * v[i + 1].y - v[i + 1].x * v[i].y);
    g << fixed << setprecision(5) << S;
    return 0;
}
