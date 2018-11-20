
#include<bits/stdc++.h>
using namespace std;
ifstream f("meneaito.in");
ofstream g("meneaito.out");
int n;
struct kaka
{
    int a, b, pi;
};
kaka v[200002];
bool cmp(kaka a, kaka b)
{
    return (a.b - a.a) < (b.b - b.a);
}
bool arr[400002];
map<int, int>rau;
int mex = 0;
void prec(int perioada)
{
    if(perioada == 0)
        return;
    map<int, int> ::iterator it;
    int prev_rest = 2 * perioada;
    int qz = (mex / prev_rest) * prev_rest;
    int modd = mex % prev_rest;
    for(it = rau.begin(); it != rau.end(); ++it)
    {
        int vall = it -> first;
        int bg = qz + vall;
        for(int j = bg; j <= 200000; j += prev_rest)
            arr[j] = 1;
    }
    rau.clear();
    while(arr[mex])
    {
        ++mex;
        if(mex == 200001)
        {
            g << -1;
            exit(0);
        }
    }
}
int main()
{
    f >> n;
    for(int i = 2; i < n; ++i)
        f >> v[i-1].a, v[i-1].pi = i;
    for(int i = 2; i < n; ++i)
        f >> v[i-1].b;
    n -= 2;
    sort(v+1, v+n+1, cmp);
    for(int i = 1; i <= n; ++i)
    {
        if(v[i].a == v[i].b)
        {
            if(v[i].a == v[i].pi)
            {
                g << -1;
                return 0;
            }
            continue;
        }
        if(v[i].b - v[i].a != v[i-1].b - v[i-1].a)
            prec(v[i-1].b - v[i-1].a);
        int ppi = v[i].pi;
        if(v[i].a == ppi)
            rau[0] = 1;
        else
            if(v[i].b == ppi)
                rau[v[i].b - v[i].a] = 1;
            else
                if(v[i].a <= ppi && ppi <= v[i].b)
                    rau[ppi - v[i].a] = 1, rau[v[i].b - v[i].a + v[i].b - ppi] = 1;
    }
    prec(v[n].b - v[n].a);
    g << mex;
    return 0;
}
