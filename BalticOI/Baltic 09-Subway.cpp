/*
        Baltic 09-Subway

    Let's sort the points in increasing order of the x values. It can be observed that it's optimal to place them like

    RLRLRL....

    From this point, we can find the answer quite easily. If we know the max and min distance a train has travelled, the answer is
(abs(max) + abs(min)) / 2

*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

// #define fisier 1

using namespace std;

typedef long long ll;

int m, n;
struct pct
{
    int poz, td;
    char dir;
};
pct v[100002];
bool cmp(pct a, pct b)
{
    return a.poz < b.poz;
}
bool cmp2(pct a, pct b)
{
    return a.td < b.td;
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i].poz >> v[i].dir;
    sort(v+1, v+n+1, cmp);
    for(int i = 1; i <= n; ++i)
        if(i % 2 == 0)
            v[i].td = 2 * m - v[i].poz;
        else
            v[i].td = v[i].poz;
    sort(v+1, v+n+1, cmp2);
    long double mn = 0;
    long double mx = 0;
    long double poz = v[1].td;
    for(int i = 2; i <= n; ++i)
    {
        poz += (0.0000 + m + m) / (0.0000 + n);
        long double xd = poz - 1.000 * v[i].td;
        if(xd < mn)
            mn = xd;
        if(xd > mx)
            mx = xd;
    }
    mx += abs(mn);
    mx *= 0.5000000;
    cout << fixed << setprecision(10) << mx;
    return 0;
}
