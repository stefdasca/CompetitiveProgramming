#include<bits/stdc++.h>
using namespace std;
ifstream in("arbxyz.in");
ofstream out("arbxyz.out");
int t;
vector<int>v[100002];
int sum[100002];
int isy[100002], isx[100002];
int n, x, y, z;
bool gg;
void dfs(int daddy, int nod, int x, int y, int z)
{
    sum[nod] = 1;
    int xx = 0;
    int yy = 0;
    bool bad = 0;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == daddy)
            continue;
        dfs(nod, vecin, x, y, z);
        if(isx[vecin] && isy[vecin])
            ++xx, ++yy, bad = 1;
        else
            if(isx[vecin])
                ++xx;
            else
                if(isy[vecin])
                    ++yy;
        sum[nod] += sum[vecin];
        isx[nod] = max(isx[nod], isx[vecin]);
        isy[nod] = max(isy[nod], isy[vecin]);
    }
    if(xx >= 2 && yy)
        gg = 1;
    if(xx && yy >= 2)
        gg = 1;
    if(xx == 1 && yy == 1 && !bad)
        gg = 1;
    if(sum[nod] == x+y && (isy[nod] || isx[nod]))
        gg = 1;
    if(sum[nod] == x)
        isx[nod] = 1;
    if(sum[nod] == y)
        isy[nod] = 1;
}
int main()
{
    in >> t;
    for(int i = 1; i <= t; ++i)
    {
        in >> n >> x >> y >> z;
        for(int j = 1; j <= n; ++j)
            v[j].clear();
        gg = 0;
        for(int j = 1; j < n; ++j)
        {
            int a, b;
            in >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(int j = 1; j <= n; ++j)
        {
            isy[j] = 0;
            isx[j] = 0;
        }
        dfs(0, 1, x, y, z);
        for(int j = 1; j <= n; ++j)
        {
            isy[j] = 0;
            isx[j] = 0;
        }
        dfs(0, 1, x, z, y);
        for(int j = 1; j <= n; ++j)
        {
            isy[j] = 0;
            isx[j] = 0;
        }
        dfs(0, 1, y, z, x);
        out << gg << '\n';
    }
    return 0;
}
