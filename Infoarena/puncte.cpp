/*
            Infoarena puncte(https://www.infoarena.ro/problema/puncte)

    "Given N points on 2D plane and M points on Ox axis, find for each of the M points
the farthest point among the N points. Distance between 2 points is square of their Euclidean
distance"

    Let's say we are solving the query for a certain point among the M points, which has coordinates
(xA, 0). The distance between this point and one of the N points(coordinates (xB, yB) ) is
(xA - xB) ^ 2 + yB^2. After doing some computations, we can reduce this formula to a function of type
ax + b, so that we can apply convex hull trick. We need to run this algorithm twice, for the points left and
right of each point. The complexity will be O(M log M + N), because we need to sort the M points and run
an O(n) algorithm twice.

*/

#include<bits/stdc++.h>
using namespace std;
ifstream f("puncte.in");
ofstream g("puncte.out");
long long n, m;
struct puncte
{
    int x, y;
};
puncte v[100002], q[200002];
long long ans[200002];
bool cmp(puncte a, puncte b)
{
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}
vector<long long>slope;
vector<long long>stp;
vector<long long>pos;
bool irrl(int a, int b, int c)
{
    double rap = (0.000000 + stp[b] - stp[a]) / (0.00000 + slope[a] - slope[b]);
    double rap2 = (0.000000 + stp[c] - stp[a]) / (0.00000 + slope[a] - slope[c]);
    if(rap >= rap2)
        return 1;
    return 0;
}
int lst = -1;
int nrlst = -1;
void baga(long long x, long long y, long long i)
{
    long long a = (-2) * x;
    long long b = y * y + x * x;
    slope.push_back(a);
    stp.push_back(b);
    pos.push_back(i);
    while(slope.size() >= 3 && irrl(slope.size() - 3, slope.size() - 2, slope.size() - 1))
    {
        if(slope.size() - 2 == lst)
            --lst;
        slope.erase(slope.end() - 2);
        stp.erase(stp.end() - 2);
        pos.erase(pos.end() - 2);
    }
}
long long query(long long poz)
{
    if(slope.size() == 0)
        return (1LL<<62) + (1LL<<61);
    if(lst == -1)
        lst = 0;
    while(lst + 1 < slope.size() && 1LL * poz * slope[lst] + stp[lst] > 1LL * poz * slope[lst + 1] + stp[lst + 1])
        ++lst;
    nrlst = pos[lst];
    long long aans = 1LL * poz * slope[lst] + stp[lst] + 1LL * poz * poz;
    return aans;
}
int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
        f >> v[i].x >> v[i].y;
    for(int i = 1; i <= m; ++i)
        f >> q[i].x, q[i].y = i;
    sort(q + 1, q + m + 1, cmp);
    int Lst = 1;
    for(int i = 1; i <= m; ++i)
    {
        while(Lst <= n && v[Lst].x <= q[i].x)
            baga(v[Lst].x, v[Lst].y, Lst), ++Lst;
        ans[q[i].y] = query(q[i].x);
    }
    slope.clear();
    stp.clear();
    pos.clear();
    int val = v[n].x;
    for(int i = 1; i <= n; ++i)
        v[i].x = val - v[i].x;
    for(int i = 1; i <= m; ++i)
        q[i].x = val - q[i].x;
    Lst = n;
    lst = -1;
    for(int i = m; i >= 1; --i)
    {
        while(Lst && v[Lst].x <= q[i].x)
            baga(v[Lst].x, v[Lst].y, Lst), --Lst;
        ans[q[i].y] = min(ans[q[i].y], query(q[i].x));
    }
    for(int i = 1; i <= m; ++i)
        g << ans[i] << '\n';
    return 0;
}
