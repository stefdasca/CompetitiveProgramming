// https://www.infoarena.ro/problema/disjoint

#include<bits/stdc++.h>
using namespace std;

ifstream f("disjoint.in");
ofstream g("disjoint.out");
int n, m, tt[100002], sz[100002];

int Find(int nod)
{
    if(tt[nod] == nod)
        return nod;
    return tt[nod] = Find(tt[nod]);
}

void Union(int a, int b)
{
    if(a == b)
        return;
    if(sz[a] >= sz[b])
        sz[a] += sz[b], tt[b] = a;
    else
        sz[b] += sz[a], tt[a] = b;
}
int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        tt[i] = i;
        sz[i] = 1;
    }
    for(int i = 1; i <= m; i++)
    {
        int tip, x, y;
        f >> tip >> x >> y;
        if(tip == 2)
        {
            if(Find(x) == Find(y))
                g << "DA" << '\n';
            else
                g << "NU" << '\n';
        }
        else
            Union(Find(x), Find(y));
    }
    return 0;
}
