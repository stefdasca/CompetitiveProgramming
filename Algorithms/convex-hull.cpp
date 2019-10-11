// https://www.infoarena.ro/problema/infasuratoare

#include<bits/stdc++.h>
using namespace std;
ifstream f("infasuratoare.in");
ofstream g("infasuratoare.out");
int n;
struct xy
{
    double x, y;
};
xy v[120005];
xy st[120005];
xy sol[120005];
int vf,lf;
bool cmp(xy a, xy b)
{
    if (a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}
xy jos, sus;
bool semn(xy a, xy b, xy c)
{
    return (a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x) >= 0;
}
int main()
{
    f >> n;
    for (int i = 1; i <= n; ++i)
        f >> v[i].x >> v[i].y;
    sort(v + 1, v + n + 1,cmp);
    jos = v[1];
    sus = v[n];
    st[++vf] = v[1];
    for (int i = 2; i <= n; ++i)
    {
        while (vf > 1 && !semn(st[vf - 1],st[vf],v[i]))
            --vf;
        st[++vf] = v[i];
    }
    for (int i = 1; i <= vf; ++i)
        sol[i] = st[i];
    lf = vf;
    vf = 0;
    st[++vf] = v[n];
    for (int i = n - 1; i >= 1; --i)
    {
        while (vf > 1 && !semn(st[vf - 1],st[vf],v[i]))
            --vf;
        st[++vf] = v[i];
    }
    for (int i = 2; i <= vf; ++i)
        sol[i + lf - 1] = st[i];
    lf = lf + vf - 2;
    g << lf << '\n';
    g << fixed << setprecision(6);
    for (int i = 1; i <= lf; ++i)
        g << sol[i].x << " " << sol[i].y << '\n';
    return 0;
}
