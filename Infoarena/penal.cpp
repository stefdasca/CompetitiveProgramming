#include<bits/stdc++.h>
using namespace std;
ifstream f("penal.in");
ofstream g("penal.out");
long long n, m, p, summ[200002];
struct pos
{
    int L, C, pi, fnd;
};
pos v[102];
int findd(int L, int C)
{
    int mini = 100002;
    int pp = -1;
    if(L - 1 < mini)
        mini = L - 1, pp = 1;
    if(n - C < mini)
        mini = n - C, pp = 2;
    if(n - L < mini)
        mini = n - L, pp = 3;
    if(C - 1 < mini)
        mini = C - 1, pp = 4;
    return (mini * 4 + pp);
}
int main()
{
    f >> n >> m >> p;
    for(int i = 1; i <= p; ++i)
        f >> v[i].L >> v[i].C, v[i].pi = i, v[i].fnd = findd(v[i].L, v[i].C);
    int aa = n;
    for(int i = 1; aa ; ++i)
    {
        summ[i] = summ[i-1] + aa;
        if(i % 2)
            --aa;
    }
    for(int i = 1; i <= m; ++i)
    {
        for(int j = 1; j <= p; ++j)
            v[j].fnd = findd(v[j].L, v[j].C);
        for(int j = 1; j <= p; ++j)
        {
            long long pos;
            if(v[j].fnd % 4 == 1)
                pos = summ[v[j].fnd - 1] + v[j].C - v[j].fnd / 4;
            if(v[j].fnd % 4 == 2)
                pos = summ[v[j].fnd - 1] + v[j].L - (v[j].fnd / 4 + 1);
            if(v[j].fnd % 4 == 3)
                pos = summ[v[j].fnd - 1] + (n - (v[j].fnd / 4)) - v[j].C;
            if(v[j].fnd % 4 == 0)
                pos = summ[v[j].fnd - 1] + (n - (v[j].fnd / 4) + 1) - v[j].L;
            v[j].L = pos/n + (pos%n != 0);
            v[j].C = n * (pos%n == 0) + pos % n;
        }
        for(int j = 1; j <= p; ++j)
            g << v[j].L << " " << v[j].C << " ";
        g << '\n';
    }
    return 0;
}
